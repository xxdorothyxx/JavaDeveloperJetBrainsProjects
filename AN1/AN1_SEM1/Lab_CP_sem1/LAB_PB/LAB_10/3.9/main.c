
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMBER_OF_MATERIALS 100
/*3.9.A lorry can carry at most m kilograms. The name of the materials, the amounts in kilograms,
 and the price per kilo are known.Find a load composition such a way the value of the load is maximum*/


typedef struct{
    char *name;
    int quantity;
    float price;
}material;
void initializeMaterial(material *g){
    g->name=(char *)malloc(100*sizeof(char));
}
material* readMaterials(int n){
    material *m=(material*)malloc(NUMBER_OF_MATERIALS*sizeof(material));
    int i;
    for(i=0;i<n;i++) {
        initializeMaterial(&m[i]);
        printf("Introduce the name of the material %d :\n",i+1);
        getchar();
        gets(m[i].name);
        printf("Introduce the amount in kilograms:\n");
        scanf("%d",&m[i].quantity);
        printf("Introduce the price per kilogram:\n");
        scanf("%f",&m[i].price);
        printf("\n");
    }
    return m;
}

material* sortDecreasing(material *m,int n) {
    material x;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (m[i].price < m[j].price) {
                x = m[i];
                m[i] = m[j];
                m[j] = x;
            }
        }
    }
    return m;
}
material* arrange(material *a,int n,int m){
    material *x=(material*)malloc(NUMBER_OF_MATERIALS*sizeof(material));
    int i;
        for (i = 0; i < n; i++) {
            initializeMaterial(&x[i]);
            x[i] = a[i];
            m=m-a[i].quantity;
            if(m<0){
                x[i].quantity=a[i].quantity+m;
                break;
            }
        }
    return x;
}

void printArrangement(material *x,int n,int m){
    int i;
    printf("Load composition so that the load is maximum is:\n ");
    for(i=0;i<n;i++){
        printf("\n %d kilograms of: ",x[i].quantity);
        m=m-x[i].quantity;
            puts(x[i].name);
        if(!m)
            break;
    }
}

int main(){
    int n;
    printf("Introduce the number of the materials in the lorry:\n");
    scanf("%d",&n);
    int m;
    printf("Introduce the number of kilograms the lorry can carry :\n");
    scanf("%d",&m);
    material *a=readMaterials(n);
    a=sortDecreasing(a,n);
    material *b=arrange(a,n,m);
    printArrangement(b,n,m);
    return 0;
}