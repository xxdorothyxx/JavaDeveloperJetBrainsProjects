#include <stdio.h>
#include <stdlib.h>

#define UNVISITED 0
#define VISITED 1
#define MAX 9999
#define UNDEFINED -1

typedef struct node {
    int key;
    int dist;
    struct node *next;
} NodeT;

NodeT *createNode(int key) {
    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}
NodeT *queue=NULL, *stack=NULL;

void enqueue(int content) {
    if (queue == NULL) {
        queue = createNode(content);
    } else {
        NodeT *aux = queue;
        while (aux->next != NULL) { // !!aux->next !=NULL!!
            aux = aux->next;
        }
        aux->next = createNode(content);
    }
}

void dequeue() {
    if (queue != NULL) {
        queue = queue->next;
    }
}

NodeT *peekQueue(){
    return queue;
}
int isEmptyQueue() {
    return queue == NULL;
}

void push(int key) {
    NodeT *newNode = createNode(key);
    newNode->next = stack;
    stack = newNode;
}

void pop() {
    if (stack != NULL) {
        stack = stack->next;
    }
}

NodeT *peekStack(){
    return stack;
}

int isEmptyStack() {
    return stack == NULL;
}

int **adjMatrix;
int nrOfVertexes;

void readFromAdjMatrix(FILE *f) {
    int n;
    fscanf(f,"%d", &n);
    nrOfVertexes = n;
    int i, j;
    adjMatrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        adjMatrix[i] = (int *) malloc(n * sizeof(int));
    } // !
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(f,"%d", &adjMatrix[i][j]);
}

void printAdjMatrix() {
    int i, j;
    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < nrOfVertexes; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < nrOfVertexes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

int getNumberOfNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0;
        int i;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertex(int v) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        for (i = 0; i < nrOfVertexes; i++) {
            if (adjMatrix[v][i] > 0 && i != v) {
                neighbors[j] = i;
                j++;
            }
        }
        return neighbors;
    } else {
        return NULL;
    }
}

NodeT *fromMatrixToList(int nrOfVertexes,int *adjMatrix){
        NodeT *first=NULL;
        NodeT *last=NULL;
        for(int j=0;j<nrOfVertexes;j++) {
            if (adjMatrix[j]) {
                if (first == NULL) {
                    first = (NodeT *) malloc(sizeof(NodeT));
                    first->key = j;
                    first->dist = adjMatrix[j];
                    first->next = last;
                    last = first;
                } else {
                    NodeT *newNode = (NodeT *) malloc(sizeof(NodeT));
                    newNode->key = j;
                    newNode->dist = adjMatrix[j];
                    last->next = newNode;
                    last = newNode;
                }
            }
        }
        return first;
    }
void printAdjList(int nrOfVertexes, NodeT **list) {
    printf("The list is:\n");
    NodeT *currentElement = (NodeT *) malloc(sizeof(NodeT));
    for (int i = 0; i < nrOfVertexes; i++) {
        printf("%c  ", 'A' + i);
        currentElement = list[i];
        while (currentElement) {
            printf("%4d", currentElement->dist);
            currentElement = currentElement->next;
        }
        printf("\n");
    }
    printf("\n");
}
int **fromListToMatrix(int nrOfVertex,NodeT **list){
    int i,j;
    NodeT *currentElement=(NodeT*)malloc(sizeof(NodeT));
    int **matrix=(int**)malloc(sizeof(int*)*nrOfVertex);
    for(i=0;i<nrOfVertex;i++){
        currentElement=list[i];
        matrix[i]=(int*)malloc(sizeof(int)*nrOfVertex);
        for(j=0;j<nrOfVertex;j++){
            if( currentElement && j==currentElement->key){
                matrix[i][j]=currentElement->dist;
                currentElement=currentElement->next;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

void bfs(int startNode) {
    printf("BFS started :\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;
    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    enqueue(startNode);
    visited[startNode] = VISITED;
    printf("%c ", startNode + 'A');
    while (!isEmptyQueue()) {
        v = peekQueue()->key;
        dequeue();
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int *neighbors = getAllNeighborsOfVertex(v);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }
    printf("\nBFS ended\n\n");
}

void dfs(int startNode) {
    printf("DFS started :\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int i, v, w;
    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    push(startNode);
    while (!isEmptyStack()) {
        v = peekStack()->key;
        pop();
        if (visited[v] == UNVISITED) {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int *neighbors = getAllNeighborsOfVertex(v);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }
    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int *visited) {
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int *neighbors = getAllNeighborsOfVertex(v);
    printf("%c ", v + 'A');
    for (i = 0; i < nrOfNeighbors; i++) {
        int w = neighbors[i];
        if (visited[w] == UNVISITED) {
            dfsRec(w, visited);
        }
    }
}

void dfsRecurs(int startNode) {
    printf("DFS recursive started\n");
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    for (int i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    dfsRec(startNode, visited);
    printf("\nDFS recursive ended\n\n");
}

typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;


//edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited);

void printEdges(edgeT *edges, int n);

edgeT  getMinimumEdgeForCurrentlyVisitedNodes(int *visited){
    edgeT minimumEdge;
    minimumEdge.weight=MAX;
    for(int i=0;i<nrOfVertexes;i++){
        for(int j=0;j<nrOfVertexes;j++){
            if(visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j]>0){
                if(adjMatrix[i][j]<minimumEdge.weight){
                    minimumEdge.source=i;
                    minimumEdge.destination=j;
                    minimumEdge.weight=adjMatrix[i][j];
                }
            }
        }
    }
    return minimumEdge;
}

void printEdges(edgeT *edges, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

void prim(int startNode) {
    printf("Prim's Algorithm started:\n");
    int nrVertexesVisited = 0, i,minCost=0;
    int *visited = (int *) malloc(sizeof(int) * nrVertexesVisited);
    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVertexes-1));
    visited[startNode] = VISITED;
    while (nrVertexesVisited < nrOfVertexes-1) {
        edgeT minEdge = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination]=VISITED;
        edges[nrVertexesVisited++]=minEdge;
        minCost+=minEdge.weight;
    }
    printEdges(edges,nrVertexesVisited);
    printf("The minimum cost by Prim's algorithm : %d\n",minCost);
    printf("Prim's algorithm ended.\n\n");
}

int getMinDistanceVertex(const int *distances, const int *visited) {
    int min = MAX, i;
    int minV = 0;
    for (i = 0; i < nrOfVertexes; i++) {
        if (distances[i] < min && visited[i] == UNVISITED) {
            minV = i;
        }
    }
    return minV;
}

void dijkstra(int startNode) {
    printf("Dijkstra's Algorithm started\n");

    int *distances = (int *) malloc(nrOfVertexes * sizeof(int));
    int *previous = (int *) malloc(nrOfVertexes * sizeof(int));
    int *visited = (int *) malloc(nrOfVertexes * sizeof(int));
    int nrOfVertexesVisited = 0, i;
    for (i = 0; i < nrOfVertexes; i++) {
        distances[i] = MAX;
        previous[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;
    while (nrOfVertexesVisited < nrOfVertexes) {
        int u = getMinDistanceVertex(distances, visited);
        visited[u] = VISITED;
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int *neighbors = getAllNeighborsOfVertex(u);
        for (i = 0; i < nrOfNeighbors; i++) {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if (alt < distances[w]) {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVertexesVisited++;
    }

    for (i = 0; i < nrOfVertexes; i++) {
        int u = i;
        if (i != startNode) {
            while (previous[u] != UNDEFINED) {
                push(u);
                u = previous[u];
            }

            printf("Path from %c to %c is: %c ", startNode + 'A', i + 'A', startNode + 'A');
            while (!isEmptyStack()) {
                printf(" -> %c ", peekStack()->key + 'A');
                pop();
            }
            printf("\n");
        }
    }
    printf("Dijkstra's Algorithm ended\n");
}

int main() {
    FILE *f=fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    prim(0);
    dijkstra(6);
    return 0;
}