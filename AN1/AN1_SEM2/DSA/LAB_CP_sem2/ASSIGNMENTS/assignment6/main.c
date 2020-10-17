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

typedef struct edge {
    int source;
    int destination;
    int weight;
} edgeT;

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited);

void printEdges(edgeT *edges, int n);

void prim(int startNode) {
    printf("Prim's Algorithm started\n");

    int nrVertexesVisited = 0, i, minCost = 0;
    int *visited = (int *) malloc(sizeof(int) * nrOfVertexes);
    for (i = 0; i < nrOfVertexes; i++) {
        visited[i] = UNVISITED;
    }
    edgeT *edges = (edgeT *) malloc(sizeof(edgeT) * (nrOfVertexes - 1));
    visited[startNode] = VISITED;
    while (nrVertexesVisited < nrOfVertexes - 1) {
        edgeT minEdge = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination] = VISITED;
        edges[nrVertexesVisited++] = minEdge;
        minCost += minEdge.weight;
    }
    printEdges(edges, nrVertexesVisited);
    printf("Cost of MST by Prim's Algorithm: %d\n", minCost);
    printf("Prim's algorithm ended\n\n");
}

void printEdges(edgeT *edges, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %c\t", edges[i].source + 'A', edges[i].destination + 'A');
    }
    printf("\n");
}

edgeT getMinimumEdgeForCurrentlyVisitedNodes(const int *visited) {
    edgeT minimumEdge;
    minimumEdge.weight = MAX;
    for (int i = 0; i < nrOfVertexes; i++) {
        for (int j = 0; j < nrOfVertexes; j++) {
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] > 0) {
                if (adjMatrix[i][j] < minimumEdge.weight) {
                    minimumEdge.source = i;
                    minimumEdge.destination = j;
                    minimumEdge.weight = adjMatrix[i][j];
                }
            }
        }
    }

    return minimumEdge;
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
/*
 edgeT *sort(int **adjMatrix){
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVertexes-1)*nrOfVertexes);
    int k=0;
    int i,j;
    for(i=0;i<nrOfVertexes-1;i++){
        for(j=i+1;j<nrOfVertexes;j++){
            if(adjMatrix[i][j]){
                edges[k].source=i;
                edges[k].destination=j;
                edges[k].weight=adjMatrix[i][j];
                k++;
            }
        }
    }
    for(i=0;i<k-1;i++){
        for(j=i+1;j<k;j++){
            if(edges[i].weight > edges[j].weight){
                edgeT aux=edges[i];
                edges[i]=edges[j];
                edges[j]=aux;
            }
        }
    }
    return edges;
}
*/
int main() {
    FILE *f=fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    prim(0);
    dijkstra(0);
    //a=kruskal(adjMatrix);
    return 0;
}