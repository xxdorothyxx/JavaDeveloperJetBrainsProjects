/**
 * @author Doroteea
 * @group 30221
 *
 * COMPLEXITY OF BFS:
 * Since the operations on enqueue and dequeue take O(1) and we apply them for the number of
 * vertices( let it be V) => the time dedicated to the queue becomes O(V).Since we also
 * have to go through the adj list of each vertex and the sum of the len of all the adj lists
 * is O(E) => the time dedicated to the adj list is O(E)
 *  => the complexity of BFS is : O(V+E)
 */

#include <stdlib.h>
#include <string.h>
#include "bfs.h"
#include <queue>
#include <ctime>
#include <fstream>
using std :: queue;
using namespace std;

int get_neighbors(const Grid *grid, Point p, Point neighb[])
{
    int number=0; //for counting neighbours
    //upper cell
    if(grid->mat[p.row-1][p.col]==0)//if it isn't a wall we add the upper adj cell to the neighb array
    {
        neighb[number].row=p.row-1;
        neighb[number].col=p.col;
        number++; //increase the number of the neighbours
    }
    //lower cell
    if(grid->mat[p.row+1][p.col]==0)//if it isn't a wall we add the lower adj cell to the neighb array
    {
        neighb[number].row=p.row+1;
        neighb[number].col=p.col;
        number++;//increase the number of the neighbours
    }
    //left cell
    if(grid->mat[p.row][p.col-1]==0)//if it isn't a wall we add the left adj cell to the neighb array
    {
        neighb[number].row=p.row;
        neighb[number].col=p.col-1;
        number++;//increase the number of the neighbours
    }
    //right cell
    if(grid->mat[p.row][p.col+1]==0)//if it isn't a wall we add the right adj cell to the neighb array
    {
        neighb[number].row=p.row;
        neighb[number].col=p.col+1;
        number++;//increase the number of the neighbours
    }
    return number;
}

void grid_to_graph(const Grid *grid, Graph *graph)
{
    //we need to keep the nodes in a matrix, so we can easily refer to a position in the grid
    Node *nodes[MAX_ROWS][MAX_COLS];
    int i, j, k;
    Point neighb[4];

    //compute how many nodes we have and allocate each node
    graph->nrNodes = 0;
    for(i=0; i<grid->rows; ++i)
    {
        for(j=0; j<grid->cols; ++j)
        {
            if(grid->mat[i][j] == 0)
            {
                nodes[i][j] = (Node*)malloc(sizeof(Node));
                memset(nodes[i][j], 0, sizeof(Node)); //initialize all fields with 0/NULL
                nodes[i][j]->position.row = i;
                nodes[i][j]->position.col = j;
                ++graph->nrNodes;
            }
            else
            {
                nodes[i][j] = NULL;
            }
        }
    }
    graph->v = (Node**)malloc(graph->nrNodes * sizeof(Node*));
    k = 0;
    for(i=0; i<grid->rows; ++i)
    {
        for(j=0; j<grid->cols; ++j)
        {
            if(nodes[i][j] != NULL)
            {
                graph->v[k++] = nodes[i][j];
            }
        }
    }

    //compute the adjacency list for each node
    for(i=0; i<graph->nrNodes; ++i)
    {
        graph->v[i]->adjSize = get_neighbors(grid, graph->v[i]->position, neighb);
        if(graph->v[i]->adjSize != 0)
        {
            graph->v[i]->adj = (Node**)malloc(graph->v[i]->adjSize * sizeof(Node*));
            k = 0;
            for(j=0; j<graph->v[i]->adjSize; ++j)
            {
                if( neighb[j].row >= 0 && neighb[j].row < grid->rows &&
                        neighb[j].col >= 0 && neighb[j].col < grid->cols &&
                        grid->mat[neighb[j].row][neighb[j].col] == 0)
                {
                    graph->v[i]->adj[k++] = nodes[neighb[j].row][neighb[j].col];
                }
            }
            if(k < graph->v[i]->adjSize)
            {
                //get_neighbors returned some invalid neighbors
                graph->v[i]->adjSize = k;
                graph->v[i]->adj = (Node**)realloc(graph->v[i]->adj, k * sizeof(Node*));
            }
        }
    }
}

void free_graph(Graph *graph)
{
    if(graph->v != NULL)
    {
        for(int i=0; i<graph->nrNodes; ++i)
        {
            if(graph->v[i] != NULL)
            {
                if(graph->v[i]->adj != NULL)
                {
                    free(graph->v[i]->adj);
                    graph->v[i]->adj = NULL;
                }
                graph->v[i]->adjSize = 0;
                free(graph->v[i]);
                graph->v[i] = NULL;
            }
        }
        free(graph->v);
        graph->v = NULL;
    }
    graph->nrNodes = 0;
}

void bfs(Graph *graph, Node *s, Operation *op)
{
    //init the start node
    s->color=COLOR_GRAY;
    s->dist=0;
    s->parent=NULL;
    if(op!=NULL){ op->count(4); }
    queue<Node*>*q = new queue <Node*>;//we have a queue
    q->push(s);//we add the start node
    while(q->empty()==false) //as long as the queue is not empty
    {
        Node *u=q->front();//we take the first element of the queue
        if(op!=NULL){ op->count(1); }
        q->pop();//and then pop it
       for(int i=0 ; i<u->adjSize; i++) //for every of its neighbours
        {
            if(op!=NULL){ op->count(2); }
            Node *v=u->adj[i];
            if(v->color==COLOR_WHITE) //if we didn't visit it before(hence it is white)
            {
                v->color=COLOR_GRAY;//we mark it as visited(so we make it grey)
                v->dist=u->dist+1;//we make its dist with 1 bigger than it's neighb as it should be:)
                if(op!=NULL){ op->count(4); }
                v->parent=u;
                q->push(v);//we add it to queue
            }
            u->color=COLOR_BLACK;//we make the node black so we know that we wnt through all its neighb
            if(op!=NULL){ op->count(1); }
        }
    }
    }

void PrettyPrint(int *p,int nod,int level,int n,Point *repr){ //printing the bfs with the help of the parent array
 //we print all the children of a node and then we go to another node
 for(int i=0;i<n;i++){
    if(p[i]==nod){
        for(int j=0;j<level;j++){//spaces to look pretty because a pretty node is a happy node
            printf(" ");
        }
        printf("(%d,%d)\n",repr[i].row,repr[i].col);//we print the coordinates of the node
        PrettyPrint(p,i,level+1,n,repr);
    }
 }
}

void print_bfs_tree(Graph *graph)
{
    //first, we will represent the BFS tree as a parent array
    int n = 0; //the number of nodes
    int *p = NULL; //the parent array
    Point *repr = NULL; //the representation for each element in p

    //some of the nodes in graph->v may not have been reached by BFS
    //p and repr will contain only the reachable nodes
    int *transf = (int*)malloc(graph->nrNodes * sizeof(int));
    for(int i=0; i<graph->nrNodes; ++i)
    {
        if(graph->v[i]->color == COLOR_BLACK)
        {
            transf[i] = n;
            ++n;
        }
        else
        {
            transf[i] = -1;
        }
    }
    if(n == 0)
    {
        //no BFS tree
        free(transf);
        return;
    }

    int err = 0;
    p = (int*)malloc(n * sizeof(int));
    repr = (Point*)malloc(n * sizeof(Node));
    for(int i=0; i<graph->nrNodes && !err; ++i)
    {
        if(graph->v[i]->color == COLOR_BLACK)
        {
            if(transf[i] < 0 || transf[i] >= n)
            {
                err = 1;
            }
            else
            {
                repr[transf[i]] = graph->v[i]->position;
                if(graph->v[i]->parent == NULL)
                {
                    p[transf[i]] = -1;
                }
                else
                {
                    err = 1;
                    for(int j=0; j<graph->nrNodes; ++j)
                    {
                        if(graph->v[i]->parent == graph->v[j])
                        {
                            if(transf[j] >= 0 && transf[j] < n)
                            {
                                p[transf[i]] = transf[j];
                                err = 0;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    free(transf);
    transf = NULL;

    if(!err)
    {
        // TODO: pretty print the BFS tree
        // the parrent array is p (p[k] is the parent for node k or -1 if k is the root)
        // when printing the node k, print repr[k] (it contains the row and column for that point)
        // you can adapt the code for transforming and printing multi-way trees from the previous labs
        int k;
        for(k=0; k<n; k++)
        {
            if(p[k]==-1)
            {
                break;
            }
        }
        PrettyPrint(p,p[k],0,n,repr);
    }

    if(p != NULL)
    {
        free(p);
        p = NULL;
    }
    if(repr != NULL)
    {


        free(repr);
        repr = NULL;
    }
}

int shortest_path(Graph *graph, Node *start, Node *end, Node *path[])
{
    //the idea here is that after we create the bfs tree, we begin with the end node and keep going
    //through its parents until we reach the start node
    queue<Node*>*q = new queue <Node*>;
        bfs(graph,start,NULL);//we make the bfs tree
        Node *path1[end->dist+1];
        end->dist=0;
        q->push(end);
        Node *currently=end;//we select the last element
        while(currently!=start){//as long as we didn't reach the start node
            currently=currently->parent;//the current node becomes its parent
            q->push(currently);//we add it to the queue
            path1[end->dist]=q->front();
            q->pop();//pop it
            end->dist++;
        }
        for(int i=0;i<end->dist;i++){//we create the path
            path[i]=path1[end->dist-1-i];
        }
        if(end->dist==0){
           return -1;
        }
        else
        return end->dist;
}


void performance()
{
    int n, i;
    Profiler p("bfs");
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    // vary the number of edges
    for(n=1000; n<=4500; n+=100)
    {

        Operation op = p.createOperation("bfs-edges", n);
        Graph graph;
        graph.nrNodes = 100;
        //initialize the nodes of the graph
        graph.v = (Node**)malloc(graph.nrNodes * sizeof(Node*));
        for(i=0; i<graph.nrNodes; ++i)
        {
            graph.v[i] = (Node*)malloc(sizeof(Node));
            memset(graph.v[i], 0, sizeof(Node));
        }
        // TODO: generate n random edges
        // make sure the generated graph is connected
        for(i=0;i<graph.nrNodes;++i){
            graph.v[i]->adj=(Node**)malloc(200*sizeof(Node*));
        }
        for(i=0;i<graph.nrNodes-1;i++){//we make sure that the graph is connected by making edges : 0-1,1-2,2-3...
            graph.v[i]->adj[graph.v[i]->adjSize++]=graph.v[i+1];
            graph.v[i+1]->adj[graph.v[i+1]->adjSize++]=graph.v[i];
        }
        for(int j=graph.nrNodes;j<=n;j++){//we put the other edges randomly
            int x=rand()%(graph.nrNodes);
            int y=rand()%(graph.nrNodes);

            graph.v[x]->adj[graph.v[x]->adjSize++]=graph.v[y];
            graph.v[y]->adj[graph.v[y]->adjSize++]=graph.v[x];
        }

        bfs(&graph, graph.v[0], &op);
        free_graph(&graph);

    }
    // vary the number of vertices
    for(n=100; n<=200; n+=10)
    {
        Operation op = p.createOperation("bfs-vertices", n);
        Graph graph;
        graph.nrNodes = n;
        //initialize the nodes of the graph
        graph.v = (Node**)malloc(graph.nrNodes * sizeof(Node*));
        for(i=0; i<graph.nrNodes; ++i)
        {
            graph.v[i] = (Node*)malloc(sizeof(Node));
            memset(graph.v[i], 0, sizeof(Node));
        }
        // TODO: generate 4500 random edges
        // make sure the generated graph is connected
        for(i=0;i<graph.nrNodes;++i){
            graph.v[i]->adj=(Node**)malloc(200*sizeof(Node*));
        }
        for(i=0;i<graph.nrNodes-1;i++){//we make sure that the graph is connected by making edges : 0-1,1-2,2-3...
            graph.v[i]->adj[graph.v[i]->adjSize++]=graph.v[i+1];
            graph.v[i+1]->adj[graph.v[i+1]->adjSize++]=graph.v[i];
        }
        for(int j=graph.nrNodes;j<4500;j++){//we put the other edges randomly
             int x=rand()%(graph.nrNodes);
             int y=rand()%(graph.nrNodes);

            graph.v[x]->adj[graph.v[x]->adjSize++]=graph.v[y];
            graph.v[y]->adj[graph.v[y]->adjSize++]=graph.v[x];
        }
        bfs(&graph, graph.v[0], &op);
        free_graph(&graph);
    }

    p.showReport();
}
