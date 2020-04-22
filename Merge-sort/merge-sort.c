#include <stdio.h>
#include <stdlib.h>
int *Merge_sort(int*,int);
int *Merge(int*,int*,int,int);
void printf_array(int*,int);


void main(int argc,char **argv){
    int prueba[] = {3,5,2,5,1,5,7,2,8,9,3,0};
    int tam;
    int *resultado;
    tam = sizeof(prueba)/sizeof(int);
    resultado = Merge_sort(prueba,sizeof(prueba)/sizeof(int));
    printf_array(resultado,tam);
}
void printf_array(int*array,int tam){
    printf("Tamaño del arreglo es %d\n",tam);
    for(int t = 0;t < tam;t++){
        printf("%d",array[t]);
    }
    printf("\n");
}


int *Merge_sort(int *array, int tam){
    int tam_array_a = 0;
    int tam_array_b = 0;
    int k;
    int *array_a = NULL;
    int *array_b = NULL;

    if (tam <=1){
        return array;
    }
    
    if(tam%2 == 0){
        tam_array_b = tam_array_a = tam/2;
    }else{
        tam_array_a = (tam/2) + 1;
        tam_array_b = (tam/2);
    }
    array_a = (int*)malloc(sizeof(int)*tam_array_a);
    array_b = (int*)malloc(sizeof(int)*tam_array_b);
    
    for (k=0; k< tam_array_a;k++)
        array_a[k] = array[k];

    for (int z = k; z < k+tam_array_b;z++)
        array_b[z-k] = array[z];

    array_a = Merge_sort(array_a,tam_array_a);
    array_b = Merge_sort(array_b,tam_array_b);
    
    return Merge(array_a,array_b,tam_array_a,tam_array_b);
}

int * Merge(int*A,int*B,int tam_A,int tam_B){
    int q = 0,w = 0,e = 0;
    int *C = (int*)malloc(sizeof(int)*(tam_A+tam_B));
    
    for (e = 0; e < (tam_A+tam_B); e++){
        if(A[q] < B[w] && q < tam_A ){
            C[e] = A[q];
            q ++;
        }else if( w < tam_B) {
            C[e] = B[w];
            w++;
        }else{
            C[e] = A[q];
            q ++;
        }
    }
    return C;
}