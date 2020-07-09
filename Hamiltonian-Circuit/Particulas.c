//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Graph.h"

//Numero de Circuitos Hamiltonianos
long long int sol = 0;
//Modelaremos Descompocision de particulas por una lluvia de Electrones

int YaVisite(node**H,int tam,index_nodo index){
    //Comprobar si el nodo ya es parte del Circuito Hamiltonianol 
    //1 <- No es parte del Circuito Hamiltonianol 
    //0 <- Si es parte del Circuito Hamiltonianol 
    for(int i = 0 ; i < tam ; i++){
        //printf("%c",(*(H+i))->index);
        if ( (*(H+i))->index == index ){
            //printf("Error %c",(*(H+i))->index);
            return 0;
        }
    }
    return 1;
}

int Hamiltonian_Circuit(graph *G, node**H,int * conteo){
    int intentos_C = 0;
    for ( int SN = 0; SN < (*(H+(*conteo)-1))->Num_connections ; SN ++){
        if (YaVisite(H,*conteo,(*((*(H+(*conteo)-1))->Connections+SN))->index)){
            (*(H+(*conteo))) = (*((*(H+(*conteo)-1))->Connections+SN));
            (*conteo)++;
            intentos_C++;
            if(*conteo == G->Num_Nodos){   
                if (YaVisite((*(H+(*conteo)-1))->Connections,(*(H+(*conteo)-1))->Num_connections,(*(H))->index) == 0 ){  
                    sol++;    
                    Mostrar_Circuito(H,*conteo);
                }
            }
            Hamiltonian_Circuit(G,H,conteo);
            (*conteo)--;
            (*(H+(*conteo))) = NULL;
        }
    }
    if(intentos_C >0){
        return 1;
    }
    return 0;
}


void main(void){
    graph *Grafo = Crear_Grafo();
    node ** Hamilton ;
    int cont = 1;
    Simular(Grafo);
    
    Hamilton = (node**)malloc(Grafo->Num_Nodos*sizeof(node*));
    (*(Hamilton)) = (*(Grafo->Nodos));
    
    Hamiltonian_Circuit(Grafo,Hamilton,&cont);
    
    printf("Existen %lld Circuitos Hamiltonianos\nPara Este Grafo:\n",sol);
    
    Mostrar_Grafo(Grafo);
}