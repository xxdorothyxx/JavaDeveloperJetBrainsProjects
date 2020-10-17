#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 100
typedef struct {
    char *code;
    char *name;
    char *unit;
    int amount;
    int pricePerUnit;
} item;
void initialize(item *product){
    product->code=(char*)malloc(100*sizeof(char));
    product->name=(char*)malloc(100*sizeof(char));
    product->unit=(char*)malloc(100*sizeof(char));
}
void *readItem(item *product,int n){
    initialize(product);
    

}
int main() {


    return 0;
}