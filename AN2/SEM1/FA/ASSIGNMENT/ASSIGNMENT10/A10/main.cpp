#include <iostream>

typedef struct g{
    int V;
    int E;
    int adjSize;
    struct g **adj;
    struct g *parent;
} Graph;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
