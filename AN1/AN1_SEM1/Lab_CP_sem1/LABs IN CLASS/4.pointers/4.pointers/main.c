//
//  main.c
//  4.pointers
//
//  Created by Sandor Doroteea on 10/23/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
void swap(int i,int j){
    int aux=i;
    i=j;
    j=aux;
}
void swap2(int *i,int *j){
    int aux=*i;
    *i=*j;
    *j=aux;
}

int main(int argc, const char * argv[]) {
    int n = 0 ;
    //ALOCARE STATICA & DINAMICA
    //1)
    //STATICA:
    int s[20];
    //DINAMICA
    int *s2=(int*)(malloc(sizeof(int)*n));
    //2)
    //STATICA
    int i=10;
    //DINAMICA
    int *j=(int*)malloc(sizeof(int));
    j[0]=8;
    //sau
    *j=8;
    
    
    return 0;
}
