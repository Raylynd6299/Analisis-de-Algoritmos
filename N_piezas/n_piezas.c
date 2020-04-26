//Pulido Bejarano Raymundo
//las piezas utilizadas son: P = Peones, A = Alfiles, K = Rey(King), Q = Reyna(Queen)
//T = Torre , C = Caballos

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definicion de Estructuras 
typedef struct piezas{
    char Tipo;
}pz;

//Definicion de Funciones
void inicializar_tablero(char **, int );
void mostrar_tablero(char **,int );
int Colocar_pieza(pz ,char **,int ,int ,int );



void main(int argc, char ** argv){
    if (argc == 2){
        int N = atoi(argv[1]);
        int i = 0;
        pz piezas[N]; //Creamos arreglo del numero N de piezas 
        char **tablero = (char**)malloc(sizeof(char*) * N);
        for(int j = 0; j < N ; j++)
            *(tablero + j) = (char*)malloc(sizeof(char) * N); 

        //Registramos las piezas necesarias 
        while (i < N){
            char Tipo_pz;
            printf("Ingrese el Tipo de Pieza que guste :\n");
            printf("P = peon\n");
            printf("A = Alfiles\n");
            printf("K = Rey\n");
            printf("Q = Reyna\n");
            printf("T = Torre\n");
            printf("C = Caballo\n");
            scanf("%c",&Tipo_pz); while(getchar() != '\n');
            if(Tipo_pz == 'P' || Tipo_pz == 'A' || Tipo_pz == 'K' || Tipo_pz == 'Q' || Tipo_pz == 'T' || Tipo_pz == 'C'){
                piezas[i].Tipo = Tipo_pz;
                i++;
            }else
                printf("%c no es un tipo aceptado\n",Tipo_pz);
        }

        printf("Las piezas a colocar son:\n");

        for (int j = 0; j < N; j++){
            printf("%d .- pieza = %c\n",j,piezas[j].Tipo);
        }

        inicializar_tablero(tablero,N);
        mostrar_tablero(tablero,N);
        pz prueba;
        prueba.Tipo = 'P'; 
        printf("Respuesta = %d\n",Colocar_pieza(prueba,tablero,N,1,1));
        mostrar_tablero(tablero,N);


    }else 
        printf("Ingrese el parametro N = numero de piezas\n");
}
void inicializar_tablero(char **Tablero, int tam_tablero){
    //Inializamos el tablero a posiciones limpias con: L
    for (int filas = 0; filas < tam_tablero ; filas++)
        for(int columnas = 0; columnas < tam_tablero ; columnas++)
            Tablero[filas][columnas] = 'L';
}

void mostrar_tablero(char **Tablero,int tam_tablero){
    for (int columna = 0; columna < tam_tablero ;columna++)
        if (columna == 0)
            printf("    %c",65+columna);
        else
            printf("   %C",65+columna);
     printf("\n");       
    
    for(int fila = 0; fila < tam_tablero ;fila++){
        printf("%d",fila+1);
        for (int columna = 0; columna < tam_tablero ;columna++)
            printf("   %c",Tablero[fila][columna]);
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

    if(Tablero[fila][columna] == 'L')
        if(pieza.Tipo == 'P'){
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
        }else if(pieza.Tipo == 'T'){

            return 1;
        }else if(pieza.Tipo == 'C'){

            return 1;
        }else if(pieza.Tipo == 'A'){

            return 1;
        }else if(pieza.Tipo == 'K'){

            return 1;
        }else if(pieza.Tipo == 'Q'){

            return 1;
        }else{
            //No se encontro el tipo de pieza 
            return -1;
        }
    else{
        return 0; // La posicion esta atacada o en posicion ya existe una pieza 
    }
    
}