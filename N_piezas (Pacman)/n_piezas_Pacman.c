//Pulido Bejarano Raymundo
//las piezas utilizadas son: P = Peones, A = Alfiles, K = Rey(King), Q = Reyna(Queen)
//T = Torre , C = Caballos

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"
#include "piezas.h"

long int num_soluciones = 0;

//Definicion de Funciones
char** Crear_Tablero(int);
void inicializar_tablero(char **, int );
void mostrar_tablero(char **,int );
void Colocar_Bombas(char **Tablero,int tam_tablero);
void Restablecer_tablero(char ** Tablero,int tam_tablero,int fila,int columna,pz pieza);
int Sol_N_piezas(char **Tablero,int tam_tablero,int fila,int columna,pz *n_piezas);
int Todas_las_piezas_usadas(pz *n_piezas,int Num_piezas);
int todas_iguales(pz *n_piezas,int Num_piezas);
long long factorial(int n);

void main(int argc, char ** argv){
    if (argc == 3){
        int N = atoi(argv[1]);
        int R = atoi(argv[2]);
        pz piezas[N]; //Creamos arreglo del numero N de piezas 
        
        //Creamos el tablero
        char **Tablero = Crear_Tablero(N);

        //Tipo de Ingreso de Datos
        if (R == 0) { //Manual
            int i = 0;

            //Registramos las piezas necesarias 
            while (i < N){
                char Tipo_pz;
                printf("Ingrese el Tipo de Pieza que guste :\n");
                printf("%sP%s = peon\n",COLOR_NARANJA,COLOR_BASE);
                printf("%sT%s = Torre\n",COLOR_MAGENTA,COLOR_BASE);
                printf("%sC%s = Caballo\n",COLOR_CYAN,COLOR_BASE);
                printf("%sA%s = Alfiles\n",COLOR_AMARILLO,COLOR_BASE);
                printf("%sQ%s = Reyna\n",COLOR_MAGENTAC,COLOR_BASE);
                printf("%sK%s = Rey\n",COLOR_VERDE,COLOR_BASE);
                scanf("%c",&Tipo_pz); while(getchar() != '\n');
                if(Tipo_pz == 'P' || Tipo_pz == 'A' || Tipo_pz == 'K' || Tipo_pz == 'Q' || Tipo_pz == 'T' || Tipo_pz == 'C'){
                    piezas[i].Tipo = Tipo_pz;
                    piezas[i].usada = 0;
                    i++;
                }else
                    printf("%c no es un tipo aceptado\n",Tipo_pz);
            }

            //Mostramos piezas que vamos a colocar
            printf("Las piezas a colocar son:\n");
            for (int j = 0; j < N; j++)
                printf("Pieza[%d] = %c\n",j,piezas[j].Tipo);

        }else if (R == 1){ // Aleatorio
            srand (time(NULL));
            int num;
            // 0-10 <- Peon
            // 11-20 <- Caballos
            // 21-30 <- Alfiles
            // 31-40 <- Torres
            // 41-50 <- Reyna
            // 51-60 <- Rey
            for (int j = 0; j < N; j++){
                num = rand() % (61) ;
                if (num >= 0 && num <= 10){
                    piezas[j].Tipo = 'P';
                    piezas[j].usada = 0;
                }else if (num >= 11 && num <= 20){
                    piezas[j].Tipo = 'C';
                    piezas[j].usada = 0;
                }else if (num >= 21 && num <= 30){
                    piezas[j].Tipo = 'A';
                    piezas[j].usada = 0;
                }else if (num >= 31 && num <= 40){
                    piezas[j].Tipo = 'T';
                    piezas[j].usada = 0;
                }else if (num >= 41 && num <= 50){
                    piezas[j].Tipo = 'Q';
                    piezas[j].usada = 0;
                }else if (num >= 51){
                    piezas[j].Tipo = 'K';
                    piezas[j].usada = 0;
                }
                
            }

            //Mostramos piezas que vamos a colocar
            printf("Las piezas a colocar son:\n");
            for (int j = 0; j < N; j++)
                printf("Pieza[%d] = %c\n",j,piezas[j].Tipo);
                      
        }else{
           printf("Opcion Invalida\n");
           exit(EXIT_FAILURE); 
        }
        
        //Inicializamos el tablero
        inicializar_tablero(Tablero,N);
        
        //mostramos el tablero inicial
        printf("\nTablero Inicial\n");
        Colocar_Bombas(Tablero,N);
        mostrar_tablero(Tablero,N);
        printf("---------------------------------------------------------------------\n");
        
        //Llamamos la Recusion
        Sol_N_piezas(Tablero,N,0,0,piezas);

        //Mostramos el numero de soluciones
        printf("Para un Tablero de %d X %d , con estas piezas:\n",N,N);

        for (int j = 0; j < N; j++)
            printf("Pieza[%d] = %c\n",j,piezas[j].Tipo);

        if(todas_iguales(piezas,N) == 0){
            printf("Se encontraron %lld Soluciones\n",num_soluciones/factorial(N));
        }else
            printf("Se encontraron %ld Soluciones\n",num_soluciones);
        
    }else 
        printf("Ingrese el parametro N = numero de piezas y R = 1 -> Lista de piezas Aleatoria o 0 -> Elegir las piezas Manualmente\n");
}

long long factorial(int n){
    long long f = 1;
    for (int i = n;i>=1;i--){
        f=f*i;
    }
}

char **Crear_Tablero(int N){
    char **tablero = (char**)malloc(sizeof(char*) * N);
        for(int j = 0; j < N ; j++)
            *(tablero + j) = (char*)malloc(sizeof(char) * N); 
    return tablero;
}

void inicializar_tablero(char **Tablero, int tam_tablero){

    //Inializamos el tablero a posiciones limpias con: L
    for (int filas = 0; filas < tam_tablero ; filas++)
        for(int columnas = 0; columnas < tam_tablero ; columnas++)
            Tablero[filas][columnas] = 'L';

}

void Colocar_Bombas(char **Tablero, int tam_tablero){

    //Colocamos Bombas Aleatoriamente
    srand (time(NULL));

    //Cuantas Bombas pondremos por fila 
    int num_bombas = rand() % ((tam_tablero+1)/2) +1;

    for (int filas = 0; filas < tam_tablero ; filas++){
        for(int b = 1,columna; b <= num_bombas; b++){
            columna = rand() % (tam_tablero+1);
            Tablero[filas][columna] = 'B';
        }
    }
}

void mostrar_tablero(char **Tablero,int tam_tablero){
    //P <-- Naranja
    //T <-- Magenta
    //C <-- Cyan
    //A <-- Amarillo
    //Q <-- Magenta claro (Rosa)
    //K <-- verde 
    //L <-- Azul
    //X <-- Rojo
    //B <-- Blancas
    //indices blanco

    //Formato para mostrar las columnas 
    for (int columna = 0; columna < tam_tablero ;columna++)
        if (columna == 0)
            printf("      %c",65+columna);
        else
            printf("   %C",65+columna);
     printf("\n");       
    
    //Mostrar la tabla en general
    for(int fila = 0; fila < tam_tablero ;fila++){
        //mostramos el incice de las filas
        printf("%3d",fila+1);
        for (int columna = 0; columna < tam_tablero ;columna++){
            char caracter = Tablero[fila][columna];
            if( caracter == 'P')
                printf("%s   %c%s",COLOR_NARANJA,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'T')
                printf("%s   %c%s",COLOR_MAGENTA,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'C')
                printf("%s   %s%c%s",COLOR_CYAN,FONDO_ROJO,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'A')
                printf("%s   %c%s",COLOR_AMARILLO,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'Q')
                printf("%s   %c%s",COLOR_AMARILLOC,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'K')
                printf("%s   %c%s",COLOR_VERDE,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'L')
                printf("%s   %c%s",COLOR_CYANC,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'X')
                printf("%s   %c%s",COLOR_ROJO,Tablero[fila][columna],COLOR_BASE);
            else if(caracter == 'B')
                printf("   %c",Tablero[fila][columna]);
        }
        printf("\n");
    }
}

void Restablecer_tablero(char ** Tablero,int tam_tablero,int fila,int columna,pz pieza){
    pz aux;

    //primero limpiamos las posiciones atacadas
    Tablero[fila][columna] = 'L';
    Colocar_pieza(pieza,Tablero,tam_tablero,fila,columna,'L');

    //limpiamos la posicion de la pieza
    Tablero[fila][columna] = 'L';

    //Restablecemos todo el tablero
    for (int fi = 0 ; fi < tam_tablero ; fi++)
        for (int colu  = 0 ;  colu < tam_tablero ; colu++){
            if(Tablero[fi][colu] != 'X' && Tablero[fi][colu] != 'L' && Tablero[fi][colu] != 'B'){
                aux.Tipo = Tablero[fi][colu];
                Tablero[fi][colu] = 'L';
                Colocar_pieza(aux,Tablero,tam_tablero,fi,colu,'X');
            }
        }
}

int Todas_las_piezas_usadas(pz *n_piezas,int Num_piezas){
    //Valores de Retorno
    // 0 <-- Todas las piezas usadas
    // num_sin_usar <-- No todas las piezas son usadas

    //Variables
    int cont = 0;

    for (int npz = 0 ; npz < Num_piezas ; npz++)
        if(n_piezas[npz].usada == 1)
            cont ++;

    if(cont == Num_piezas)
        return 0;
    else
        return Num_piezas-cont;
    
}

int todas_iguales(pz *n_piezas,int Num_piezas){
    char aux=n_piezas[0].Tipo;
    for (int i = 0; i < Num_piezas ; i++){
        if(aux != n_piezas[i].Tipo)
            return 1;
    }
    return 0;
}

int Sol_N_piezas(char **Tablero,int tam_tablero,int fila,int columna,pz *n_piezas){
    //Valores de Retorno
    //  1 <-- Se logro colocar al menos una pieza, una vez correctamente
    //  0 <-- No se logro colocar al menos una pieza, una vez correctamente

    //Variables aux
    int acomodos = 0;
    int columna_n = columna;

    //Explorar Tablero
    for (int fi = fila ; fi < tam_tablero ; fi++ ){
        for (int col = columna_n ; col < tam_tablero ; col++){
            if(Tablero[fi][col] == 'L'){
                for(int npz = 0; npz < tam_tablero ; npz ++){
                    if(n_piezas[npz].usada == 0){//La pieza no esta usada anteriormente
                        n_piezas[npz].usada = 1;
                        int res = Colocar_pieza(n_piezas[npz],Tablero,tam_tablero,fi,col,'X');
                        if(res == 1){// La pieza fue colocada correctamente sin atacar otra
                            if(Todas_las_piezas_usadas(n_piezas,tam_tablero) != 0){
                                Sol_N_piezas(Tablero,tam_tablero,fi,col,n_piezas);
                                //printf("acomodos %d,",Sol_N_piezas(Tablero,tam_tablero,fi,col,n_piezas));
                                n_piezas[npz].usada = 0;
                                Restablecer_tablero(Tablero,tam_tablero,fi,col,n_piezas[npz]);
                                acomodos ++;
                            }else{
                                mostrar_tablero(Tablero,tam_tablero);
                                printf("%ld ---------------------------------------------------------------------\n",num_soluciones+1);
                                num_soluciones++;
                                n_piezas[npz].usada = 0;
                                Restablecer_tablero(Tablero,tam_tablero,fi,col,n_piezas[npz]);
                                acomodos ++;
                            }
                        }else if (res == 2){//La pieza atacaria una pieza anteriormente colocada
                            
                            n_piezas[npz].usada = 0;
                            Restablecer_tablero(Tablero,tam_tablero,fi,col,n_piezas[npz]);
                            
                        }
                    }
                }
            }
        }
        columna_n = 0;
    }
    if(acomodos > 0){
        return 1;
    }else{
        return 0;
    }
}