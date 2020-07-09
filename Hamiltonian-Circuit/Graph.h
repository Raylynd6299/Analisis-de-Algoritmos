//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"

// Estructutas y nuevos tipos de Dato
typedef char index_nodo;

typedef struct Nodo{
    index_nodo index;
    int Num_connections;
    struct Nodo ** Connections; 
}node;

typedef struct Grafo{
    int Num_Nodos;
    node ** Nodos;
}graph;

//Prototipos de funcionnes
graph *Crear_Grafo(void);
node *Crear_Nodo(graph *,index_nodo);
void Conectar_Nodos(node *,node*);
int NodeExist(graph *,int,int);
void Simular(graph *);
void Mostrar_Grafo(graph *);
void Mostrar_Circuito(node **,int);

graph *Crear_Grafo(void){
    graph *grafito = (graph *)malloc(sizeof(graph));
    if (grafito != NULL){
        grafito->Num_Nodos = 0;
        grafito->Nodos = NULL;
        return grafito;
    }else{
       printf("Error al crear el Grafo");
       return NULL; 
    }  
}
node *Crear_Nodo(graph * G,index_nodo index){
    node * New_Node = NULL;
    New_Node = (node *)malloc(sizeof(node));
    if(New_Node != NULL){
        New_Node->index = index;
        New_Node->Num_connections = 0;
        New_Node->Connections = NULL;
        G->Num_Nodos ++;
        G->Nodos = (node **)realloc((node*)G->Nodos,sizeof(node*)*G->Num_Nodos);
        *(G->Nodos+G->Num_Nodos-1) = New_Node;
        return New_Node;
    }else{
        printf("Error Creando el Primer Nodo");
        return NULL;
    }
}
void Conectar_Nodos(node *A,node* B){ 
    A->Num_connections++;
    B->Num_connections++;
    A->Connections = (node**)realloc((node*)A->Connections,sizeof(node*)*A->Num_connections);
    B->Connections = (node**)realloc((node*)B->Connections,sizeof(node*)*B->Num_connections);
    *(A->Connections+A->Num_connections-1) = B;
    *(B->Connections+B->Num_connections-1) = A;
}
int NodeExist(graph *G,int A,int B){
    //A ya esta conectado a B
    //1 <= No esta Conectado
    //0 <= Esta conectado
    for (int i = 0; i < (*(G->Nodos+A))->Num_connections ; i++ ){
        if ( (*((*(G->Nodos+A))->Connections+i))->index == (*(G->Nodos+B))->index ){
            return 0;
        }
    }
    return 1;
}
void Simular(graph * G){
    srand(time(NULL));
    int N_Nodos = rand() % 22 +2;//57
    //int N_Nodos = 10;
    //Crear los Nodos
    for (int n = 0 ; n < N_Nodos ; n++)
        Crear_Nodo(G,65+n);
        
    //Conectar Nodos
    for (int i = 0; i < G->Num_Nodos; i++){//Evitar que se conecte dos o mas veces
        int j = 0,N_I = rand() % (N_Nodos) +1;//Numero de nodos a conectar con nodo i
        while (j < N_I){
            int N_A = rand() % (N_Nodos);
            if (N_A != i){
                if (NodeExist(G,i,N_A))
                    Conectar_Nodos(*(G->Nodos+N_A),*(G->Nodos+i));
                j++;
            } 
        }
    }
}

void Mostrar_Grafo(graph * G){
    for(int i = 0; i < G->Num_Nodos ; i++){
        printf("%s%2d%s--%sNode: %s%c  ->  %s",COLOR_ROJO,i,COLOR_BASE,COLOR_AZUL,COLOR_CYANC,(*(G->Nodos+i))->index,COLOR_BASE);
        if ((*(G->Nodos+i))->Num_connections != 0){
            for(int j = 0; j < (*(G->Nodos+i))->Num_connections ; j++){
                printf("%s%c%s->%s",COLOR_BASE,(*((*(G->Nodos+i))->Connections+j))->index,COLOR_ROJO,COLOR_BASE);
            }
        }
        printf("\n");
    }
}

void Mostrar_Circuito(node **H,int N_nodes){
    for(int h = 0 ; h < N_nodes; h++){
        printf("%s%c%s -> %s",COLOR_AZUL,(*(H+h))->index,COLOR_BLANCO,COLOR_BASE);
    }
    printf("\n");
}