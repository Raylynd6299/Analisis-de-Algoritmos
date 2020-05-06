#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

typedef struct posiciones{
    int fila;
    int columna;
}pos;

unsigned long int num_sol=0;
void mostrar (int **,int,int);
int Prueba_Reina(int **,int,int);
int Colocar_Reina(int **,int,int,int,int,pos*);
int Lugar_Reina(int **,int,int,int,int,int,pos *);
void copiar_tablero(int**,int**,int,int);


void main(){
    int **matriz,i;
    int f,c,N;
    pos * soluciones;
    //char valores = {'N','V','R','r','C','T','A','P'};
    printf("NxN : ");
    scanf("%d",&N);

    soluciones = (pos * )malloc(N*sizeof(pos));
    matriz = (int **)calloc(N,sizeof(int *));
    for(i=0;i<N;i++)
        *(matriz+i) = calloc(N,sizeof(int));

    Lugar_Reina(matriz,N,N,0,0,0,soluciones);
    printf("Numero de soluciones encontradas : %ld\n",num_sol);

    free(matriz);
}
int Lugar_Reina(int ** matriz,int NF,int NC,int PF,int PC,int count,pos *pos_reinas){
    int **matriz_cp;
    int f,c,i;
    matriz_cp = (int **)calloc(NF,sizeof(int *));
    for(i=0;i<NF;i++)
        *(matriz_cp+i) = calloc(NC,sizeof(int));
    
    copiar_tablero(matriz,matriz_cp,NF,NC);
  
    //printf("PF : %d, PC :%d, count : %d \n",PF,PC,count);

    for(c=0,f=0;c<NC;c++){
        if(Prueba_Reina(matriz,PF,c)==0){
            if(Colocar_Reina(matriz_cp,NF,NC,PF,c,pos_reinas+count)==0){
            //printf("PF:%d, c : %d\n",PF,c);
            //mostrar(matriz_cp,NF,NC);
            f++;
            count++;
            }
            if(count==NF){
                for(i=0;i<NF;i++){
                    printf("Reina %d,F:%d,C:%d\n",i,(pos_reinas+i)->fila,(pos_reinas+i)->columna);
                }
                mostrar(matriz_cp,NF,NC);
                num_sol++;
                printf("NS : %ld\n",num_sol);
                free(matriz_cp);
                return 0;
            }else{
                if (PF+1<NF){
                    if(Lugar_Reina(matriz_cp,NF,NC,PF+1,0,count,pos_reinas) == -1){
                        copiar_tablero(matriz,matriz_cp,NF,NC);
                        f--;
                        count--;
                    }else{
                        copiar_tablero(matriz,matriz_cp,NF,NC);
                        count--;
                    }  
                }          
            }
        }else if (c == (NC-1)&& f == 0){
            free(matriz_cp);
            return -1;
        }else if(c == (NC-1)&& f != 0){
            free(matriz_cp);
            return 0;
        } 
    }
    free(matriz_cp);
    return 0;

}
void copiar_tablero(int **orginal,int **copia,int NF,int NC){
    for(int f=0;f<NF;f++)
        for(int c=0;c<NC;c++)
            *(*(copia+f)+c)=*(*(orginal+f)+c);


}
void mostrar (int **matrice,int filas,int columnas){
    int f,c;
    for(f = 0;f < filas;f++){
        for(c = 0;c < columnas;c++){
            if(*(*(matrice+f)+c) == 0){
                printf("%s %2d %s",BWHT, *(*(matrice+f)+c) ,KNRM);
            }else if(*(*(matrice+f)+c) == -1){
                printf("%s %2d %s",BRED, *(*(matrice+f)+c) ,KNRM);
            }else if (*(*(matrice+f)+c) == 1){
                printf("%s %2d %s",BBLU, *(*(matrice+f)+c) ,KNRM);
            }
        }
        printf("\n");
    }
    printf("\n");
}
int Prueba_Reina(int **matriz,int PF,int PC){// regresa 0->Todo salio bien, -1->Error
    //matriz[PF][PC] == 0 ->Posicion libre / matriz[PF][PC] !=0 -> atacada o ya hay una reina
    return (*(*(matriz+PF)+PC)  ==0)?0:-1;
}
int Colocar_Reina(int ** matriz,int NF,int NC,int PF,int PC,pos *lugar){// regresa 0->Todo salio bien, -1->Error
    int f,c,i;
    if(Prueba_Reina(matriz,PF,PC)==0){
        //Derecha
        for(c = PC; c < NC ;c++)
            *(*(matriz+PF)+c) = -1;
        
        //Izquierda
        for(c = PC; c >= 0 ;c--)
            *(*(matriz+PF)+c) = -1;

        //Arriba
        for(f = PF; f >= 0;f--)
            *(*(matriz+f)+PC) = -1;
        
        //Abajo
        for(f = PF; f < NF; f++)
            *(*(matriz+f)+PC) = -1;

        
        //Diagonal derecha arriba
        for( i = 0;(PC+i) < NC && (PF-i) >= 0; i++)
            *(*(matriz+(PF-i))+(PC+i)) = -1;
        
        //Diagonal derecha inferior
        for( i = 0;(PC+i) < NC && (PF+i) < NF; i++)
            *(*(matriz+(PF+i))+(PC+i)) = -1;
        
        //Diagonal Izquierda abajo
        for( i = 0;(PC-i) >= 0 && (PF+i) < NF; i++)
            *(*(matriz+(PF+i))+(PC-i)) = -1;
        
        //Diagonal Izquierda arriba
        for( i = 0;(PC-i) >= 0 && (PF-i) >= 0; i++)
            *(*(matriz+(PF-i))+(PC-i)) = -1;
        
        lugar->fila=PF;
        lugar->columna=PC;
        matriz[PF][PC] = 1;//asigno la posicion a la reina
        *(*(matriz+(PF))+(PC)) = -1;
        return 0;
    }else{
        return -1;
    }
    
}