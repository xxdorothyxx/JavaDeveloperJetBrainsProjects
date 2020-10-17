#include <stdio.h>
#include <stdlib.h>

#define UNVISITED 0
#define VISITED 1

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

int getNumberOfNeighborsOfVertexFromList(int v,NodeT **list) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = 0,i;
       NodeT *currentElement=(NodeT*)malloc(sizeof(NodeT));
        for(i=0;i<nrOfVertexes;i++){
            if(v==i) {
                currentElement = list[i];
            }
        }
        while(currentElement){
            nrOfNeighbors++;
            currentElement=currentElement->next;
        }
        //printf("\nNr neigh of node list is:%d from node %c",nrOfNeighbors,v+'A');
        return nrOfNeighbors;
    } else {
        return 0;
    }
}

int *getAllNeighborsOfVertexFromList(int v,NodeT **list) {
    if (v < nrOfVertexes) {
        int nrOfNeighbors = getNumberOfNeighborsOfVertexFromList(v,list);
        int *neighbors = (int *) malloc(sizeof(int) * nrOfNeighbors);
        int i, j = 0;
        NodeT *currentElement=(NodeT*)malloc(sizeof(NodeT));
        for(int i=0;i<nrOfVertexes;i++){
            if(v==i)
                currentElement=list[i];
        }
        while(currentElement){
                neighbors[j++] = currentElement->key;
                currentElement=currentElement->next;
        }
        return neighbors;
    }
    else {
        return NULL;
    }
}

void bfsFromList(int startNode,NodeT **list) {
    printf("BFS from List started :\n");
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
        int nrOfNeighbors = getNumberOfNeighborsOfVertexFromList(v,list);
        int *neighbors = getAllNeighborsOfVertexFromList(v,list);
        for (i = 0; i < nrOfNeighbors; i++) {
            w = neighbors[i];
            if (visited[w] == UNVISITED) {
                printf("%c ", w + 'A');
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }
    printf("\nBFS from List ended\n\n");
}

void dfsForList(int startNode,NodeT **list) {
    printf("DFS from List started :\n");
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
            int nrOfNeighbors = getNumberOfNeighborsOfVertexFromList(v,list);
            int *neighbors = getAllNeighborsOfVertexFromList(v,list);
            for (i = nrOfNeighbors - 1; i >= 0; i--) {
                w = neighbors[i];
                if (visited[w] == UNVISITED) {
                    push(w);
                }
            }
            printf("%c ", v + 'A');
        }
    }
    printf("\nDFS from List ended\n\n");
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

int main() {
    FILE *f=fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs('G' - 'A');
    dfs('G' - 'A');
    dfsRecurs('G' - 'A');
    NodeT **list=(NodeT**)malloc(sizeof(NodeT*)*nrOfVertexes);
    for(int i=0;i<nrOfVertexes;i++){
        list[i]=fromMatrixToList(nrOfVertexes,adjMatrix[i]);
    }
    printAdjList(nrOfVertexes,list);
    bfsFromList('G'-'A',list);
    dfsForList('G'-'A',list);
    return 0;
}
