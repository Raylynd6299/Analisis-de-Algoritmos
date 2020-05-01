//Pulido Bejarano Raymundo
//las piezas utilizadas son: P = Peones, A = Alfiles, K = Rey(King), Q = Reyna(Queen)
//T = Torre , C = Caballos

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

//Definicion de Estructuras 
typedef struct piezas{
    char Tipo;
}pz;

//Definicion de Funciones
char** Crear_Tablero(int);
void inicializar_tablero(char **, int );
void mostrar_tablero(char **,int );
int Colocar_pieza(pz ,char **,int ,int ,int );
int Probar_Peon(char **,int ,int , int );
int Probar_Torre(char **,int ,int , int );
int Probar_Alfil(char **,int ,int , int );
int Probar_Rey(char **,int ,int , int );
int Probar_Reyna(char **,int ,int , int );
int Probar_Caballo(char **,int ,int , int );


void main(int argc, char ** argv){
    if (argc == 2){
        int N = atoi(argv[1]);
        int i = 0;
        pz piezas[N]; //Creamos arreglo del numero N de piezas 
        
        //Creamos el tablero
        char **Tablero = Crear_Tablero(N);
        
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
                i++;
            }else
                printf("%c no es un tipo aceptado\n",Tipo_pz);
        }

        //Mostramos piezas que vamos a colocar
        printf("Las piezas a colocar son:\n");
        for (int j = 0; j < N; j++)
            printf("%d .- pieza = %c\n",j,piezas[j].Tipo);
        
        //Inicializamos el tablero
        inicializar_tablero(Tablero,N);
        
        //mostramos el tablero inicial
        mostrar_tablero(Tablero,N);

        
        // pz prueba;
        // prueba.Tipo = 'C'; 
        // printf("Respuesta = %d\n",Colocar_pieza(prueba,Tablero,N,4,4));
        // mostrar_tablero(Tablero,N);
        // pz prueba2;
        // prueba2.Tipo = 'P'; 
        // printf("Respuesta = %d\n",Colocar_pieza(prueba2,Tablero,N,4,5));
        // mostrar_tablero(Tablero,N);
    }else 
        printf("Ingrese el parametro N = numero de piezas\n");
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

void mostrar_tablero(char **Tablero,int tam_tablero){
    //P <-- Naranja
    //T <-- Magenta
    //C <-- Cyan
    //A <-- Amarillo
    //Q <-- Magenta claro (Rosa)
    //K <-- verde 
    //L <-- Azul
    //X <-- Rojo
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
        }
        printf("\n");
    }
}

int Colocar_pieza(pz pieza,char **Tablero,int tam_tablero,int fila,int columna){
    //Las piezas se distinguen con  P = Peones, A = Alfiles, K = Rey(King), Q = Reyna(Queen)
    // y con T = Torre , C = Caballos
    //Las posiciones atacadas son marcadas con: X
    // y las libres con: L

    //Output
    //  0 <-- La posicion ya esta ocupada o esta atacada
    // -1 <-- El tipo de pieza no existe
    //  1 <-- La pieza fue colocada correctamente
    //  2 <-- La pieza atacaria una pieza anterior

    if(Tablero[fila][columna] == 'L')
        if(pieza.Tipo == 'P'){
            if(Probar_Peon(Tablero,tam_tablero,fila,columna) == 0){
                Tablero[fila][columna] = pieza.Tipo;

                //Diagonal Inferior Derecha            
                if(fila+1 < tam_tablero && columna+1 < tam_tablero)
                    Tablero[fila+1][columna+1] = 'X';

                //Diagonal Inferior Izquierda
                if(fila+1 < tam_tablero && columna-1 > -1)
                    Tablero[fila+1][columna-1] = 'X';
                
                //Diagonal Superior Izquierda
                if(fila-1 > -1 && columna-1 > -1)
                    Tablero[fila-1][columna-1] = 'X';

                //Diagonal Superior Derecha
                if(fila-1 > -1 && columna+1 < tam_tablero)
                    Tablero[fila-1][columna +1] = 'X';
                
                return 1;
            }else{
                return 2;
            }
            
        }else if(pieza.Tipo == 'T'){
            if(Probar_Torre(Tablero,tam_tablero,fila,columna) == 0){
                //Asignamos el valor a el espacio
                Tablero[fila][columna] = pieza.Tipo;

                //Columan hacia ABAJO
                for(int fi = fila+1; fi < tam_tablero ; fi++)
                    Tablero[fi][columna] = 'X';
                
                //Columna hacia ARRIBA
                for(int fi = fila-1; fi > -1 ; fi--)
                    Tablero[fi][columna] = 'X';

                //Columans hacia la Derecha
                for(int co = columna+1 ; co < tam_tablero ; co++)
                    Tablero[fila][co] = 'X';
                
                //Columna hacia la Izquierda
                for(int co = columna-1 ; co > -1 ; co --)
                    Tablero[fila][co] = 'X';

                //Columan
                return 1;
            }else
                return 2;
        }else if(pieza.Tipo == 'C'){
            if (Probar_Caballo(Tablero,tam_tablero,fila,columna) == 0){   
                //Asignamos el valor a el espacio
                Tablero[fila][columna] = pieza.Tipo;

                //Arriba
                if(fila+2 > -1){
                    if(columna-1 > -1)
                        Tablero[fila+2][columna-1] = 'X';
                    if(columna+1 < tam_tablero)
                        Tablero[fila+2][columna+1] = 'X';
                }
                //Abajo
                if(fila-2 > -1){
                    if(columna+1 < tam_tablero)
                        Tablero[fila-2][columna+1] = 'X';
                    if(columna-1 > -1)
                        Tablero[fila-2][columna-1] = 'X';
                }
                //Derecha
                if(columna+2 < tam_tablero){
                    if(fila+1 < tam_tablero)
                        Tablero[fila+1][columna+2] = 'X';
                    if(fila-1 > -1)
                        Tablero[fila-1][columna+2] = 'X';
                }
                //Izquierda
                if(columna-2 > -1){
                    if(fila+1 < tam_tablero)
                        Tablero[fila+1][columna-2] = 'X';
                    if(fila-1 > -1)
                        Tablero[fila-1][columna-2] = 'X';
                }
                return 1;
            }else
                return 2;
        }else if(pieza.Tipo == 'A'){
            if (Probar_Alfil(Tablero,tam_tablero,fila,columna) == 0){   
                //Asignamos el valor a el espacio
                Tablero[fila][columna] = pieza.Tipo;

                //Diagonal Derecha-Abajo
                for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
                    Tablero[fi][co] = 'X';
                    
                //Diagonal Derecha-Arriba
                for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
                    Tablero[fi][co] = 'X';

                //Diagonal Izquierda-Abajo
                for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
                    Tablero[fi][co] = 'X';
                
                //Diagonal Izquierda-Arriba
                for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
                    Tablero[fi][co] = 'X';
                
                return 1;
            }else
                return 2;
            
        }else if(pieza.Tipo == 'K'){
            if(Probar_Rey(Tablero,tam_tablero,fila,columna) == 0){
                Tablero[fila][columna] = pieza.Tipo;
                
                //Arriba
                if(fila-1 > -1)
                    Tablero[fila-1][columna] = 'X';

                //Derecha Arriba
                if(fila-1 > -1 && columna+1 < tam_tablero)
                    Tablero[fila-1][columna+1] = 'X';

                //Derecha
                if(columna+1 < tam_tablero)
                    Tablero[fila][columna+1] = 'X';

                //Derecha-Abajo
                if(fila+1 < tam_tablero && columna+1 < tam_tablero)
                    Tablero[fila+1][columna+1] = 'X';

                //Abajo
                if(fila+1 < tam_tablero)
                    Tablero[fila+1][columna] = 'X';

                //Abajo-Izquierda
                if(fila+1 < tam_tablero && columna-1 > -1)
                    Tablero[fila+1][columna-1] = 'X';

                //Izquierda
                if(columna-1 > -1)
                    Tablero[fila][columna-1] = 'X';

                //Arriba-Izquierda
                if(fila-1 > -1 && columna-1 > -1)
                    Tablero[fila-1][columna-1] = 'X';

                return 1;
            }else
                return 2;
        }else if(pieza.Tipo == 'Q'){

            if(Probar_Reyna(Tablero,tam_tablero,fila,columna) == 0){    
                //Asignamos el valor a el espacio
                Tablero[fila][columna] = pieza.Tipo;

                //Columan hacia ABAJO
                for(int fi = fila+1; fi < tam_tablero ; fi++)
                    Tablero[fi][columna] = 'X';
                
                //Columna hacia ARRIBA
                for(int fi = fila-1; fi > -1 ; fi--)
                    Tablero[fi][columna] = 'X';

                //Columans hacia la Derecha
                for(int co = columna+1 ; co < tam_tablero ; co++)
                    Tablero[fila][co] = 'X';
                
                //Columna hacia la Izquierda
                for(int co = columna-1 ; co > -1 ; co --)
                    Tablero[fila][co] = 'X';

                //Diagonal Derecha-Abajo
                for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
                    Tablero[fi][co] = 'X';
                    
                //Diagonal Derecha-Arriba
                for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
                    Tablero[fi][co] = 'X';

                //Diagonal Izquierda-Abajo
                for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
                    Tablero[fi][co] = 'X';
                
                //Diagonal Izquierda-Arriba
                for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
                    Tablero[fi][co] = 'X';
                return 1;
            }else
                return 2;
        }else{
            //No se encontro el tipo de pieza 
            return -1;
        }
    else{
        return 0; // La posicion esta atacada o en posicion ya existe una pieza 
    }   
}

int Probar_Caballo(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Arriba
    if(fila+2 > -1){
        if(columna-1 > -1)
            if(Tablero[fila+2][columna-1] != 'X' && Tablero[fila+2][columna-1] != 'L' )
                return -1;
        if(columna+1 < tam_tablero)
            if(Tablero[fila+2][columna+1] != 'X' && Tablero[fila+2][columna+1] != 'L' )
                return -1;
    }
    //Abajo
    if(fila-2 > -1){
        if(columna+1 < tam_tablero)
            if(Tablero[fila-2][columna+1] != 'X' && Tablero[fila-2][columna+1] != 'L' )
                return -1;
        if(columna-1 > -1)
            if(Tablero[fila-2][columna-1] != 'X' && Tablero[fila-2][columna-1] != 'L' )
                return -1;
    }
    //Derecha
    if(columna+2 < tam_tablero){
        if(fila+1 < tam_tablero)
            if(Tablero[fila+1][columna+2] != 'X' && Tablero[fila+1][columna+2] != 'L' )
                return -1;
        if(fila-1 > -1)
            if(Tablero[fila-1][columna+2] != 'X' && Tablero[fila-1][columna+2] != 'L' )
                return -1;
    }
    //Izquierda
    if(columna-2 > -1){
        if(fila+1 < tam_tablero)
            if(Tablero[fila+1][columna-2] != 'X' && Tablero[fila+1][columna-2] != 'L' )
                return -1;
        if(fila-1 > -1)
            if(Tablero[fila-1][columna-2] != 'X' && Tablero[fila-1][columna-2] != 'L' )
                return -1;
    }

    return 0;
}

int Probar_Reyna(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Diagonal Derecha-Abajo
    for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
        
    //Diagonal Derecha-Arriba
    for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;

    //Diagonal Izquierda-Abajo
    for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
    
    //Diagonal Izquierda-Arriba
    for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
    //Columan hacia ABAJO
    for(int fi = fila+1; fi < tam_tablero ; fi++)
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' )
            return -1;

    //Columna hacia ARRIBA
    for(int fi = fila-1; fi > -1 ; fi--)
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' )
            return -1;

    //Columans hacia la Derecha
    for(int co = columna+1 ; co < tam_tablero ; co++)
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' )
            return -1;
    
    //Columna hacia la Izquierda
    for(int co = columna-1 ; co > -1 ; co --)
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' )
            return -1;

    return 0;
}

int Probar_Rey(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Arriba
    if(fila-1 > -1)
        if(Tablero[fila-1][columna] != 'X' && Tablero[fila-1][columna] != 'L' )
            return -1;

    //Derecha Arriba
    if(fila-1 > -1 && columna+1 < tam_tablero)
        if(Tablero[fila-1][columna+1] != 'X' && Tablero[fila-1][columna+1] != 'L' )
            return -1;

    //Derecha
    if(columna+1 < tam_tablero)
        if(Tablero[fila][columna+1] != 'X' && Tablero[fila][columna+1] != 'L' )
            return -1;

    //Derecha-Abajo
    if(fila+1 < tam_tablero && columna+1 < tam_tablero)
        if(Tablero[fila+1][columna+1] != 'X' && Tablero[fila+1][columna+1] != 'L' )
            return -1;

    //Abajo
    if(fila+1 < tam_tablero)
        if(Tablero[fila+1][columna] != 'X' && Tablero[fila+1][columna] != 'L' )
            return -1;

    //Abajo-Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1)
        if(Tablero[fila+1][columna-1] != 'X' && Tablero[fila+1][columna-1] != 'L' )
            return -1;

    //Izquierda
    if(columna-1 > -1)
        if(Tablero[fila][columna-1] != 'X' && Tablero[fila][columna-1] != 'L' )
            return -1;

    //Arriba-Izquierda
    if(fila-1 > -1 && columna-1 > -1)
        if(Tablero[fila-1][columna-1] != 'X' && Tablero[fila-1][columna-1] != 'L' )
            return -1;

    return 0;
}

int Probar_Alfil(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Diagonal Derecha-Abajo
    for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
        
    //Diagonal Derecha-Arriba
    for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;

    //Diagonal Izquierda-Abajo
    for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
    
    //Diagonal Izquierda-Arriba
    for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' )
            return -1;
    
    return 0;
}

int Probar_Torre(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Columan hacia ABAJO
    for(int fi = fila+1; fi < tam_tablero ; fi++)
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' )
            return -1;

    //Columna hacia ARRIBA
    for(int fi = fila-1; fi > -1 ; fi--)
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' )
            return -1;

    //Columans hacia la Derecha
    for(int co = columna+1 ; co < tam_tablero ; co++)
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' )
            return -1;
    
    //Columna hacia la Izquierda
    for(int co = columna-1 ; co > -1 ; co --)
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' )
            return -1;

    return 0;
}

int Probar_Peon(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Diagonal Inferior Derecha            
    if(fila+1 < tam_tablero && columna+1 < tam_tablero)
        if(Tablero[fila+1][columna+1] != 'X' && Tablero[fila+1][columna+1] != 'L' )
            return -1;

    //Diagonal Inferior Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1)
        if(Tablero[fila+1][columna-1] != 'X' && Tablero[fila+1][columna-1] != 'L')
            return -1;
    
    //Diagonal Superior Izquierda
    if(fila-1 > -1 && columna-1 > -1)
        if(Tablero[fila-1][columna-1] != 'X' && Tablero[fila-1][columna-1] != 'L')
            return -1;
    //Diagonal Superior Derecha
    if(fila-1 > -1 && columna+1 < tam_tablero)
        if(Tablero[fila-1][columna +1] != 'X' && Tablero[fila-1][columna +1] != 'L')
            return -1;
    
    return 0;
}