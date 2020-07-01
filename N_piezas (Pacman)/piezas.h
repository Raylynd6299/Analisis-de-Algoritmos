//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definicion de Estructuras 
typedef struct piezas{
    char Tipo;
    int usada; // 1 Si, 0 No
}pz;

//Definicion de Funciones

int Colocar_pieza(pz ,char **,int ,int ,int ,char);

int Probar_Peon(char **,int ,int , int );
int Probar_Torre(char **,int ,int , int );
int Probar_Alfil(char **,int ,int , int );
int Probar_Rey(char **,int ,int , int );
int Probar_Reyna(char **,int ,int , int );
int Probar_Caballo(char **,int ,int , int );

void Colocar_Peon(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);
void Colocar_Torre(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);
void Colocar_Alfil(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);
void Colocar_Rey(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);
void Colocar_Reyna(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);
void Colocar_Caballo(char **Tablero,int tam_tablero,int fila, int columna, char t_asignar);

int Colocar_pieza(pz pieza,char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    //Las piezas se distinguen con  P = Peones, A = Alfiles, K = Rey(King), Q = Reyna(Queen)
    // y con T = Torre , C = Caballos
    //Las posiciones atacadas son marcadas con: X
    // y las libres con: L
    //Las Bombas estan con: B

    //Output
    // -2 <-- Fila o Columna invalida
    // -1 <-- El tipo de pieza no existe
    //  0 <-- La posicion ya esta ocupada o esta atacada
    //  1 <-- La pieza fue colocada correctamente
    //  2 <-- La pieza atacaria una pieza anterior
    if (fila < tam_tablero && columna < tam_tablero){
        if(Tablero[fila][columna] == 'L')
            if(pieza.Tipo == 'P'){
                if(Probar_Peon(Tablero,tam_tablero,fila,columna) == 0){
                    Tablero[fila][columna] = pieza.Tipo;

                    Colocar_Peon(Tablero,tam_tablero,fila,columna,t_asignar);
                    
                    return 1;
                }else{
                    return 2;
                }
                
            }else if(pieza.Tipo == 'T'){
                if(Probar_Torre(Tablero,tam_tablero,fila,columna) == 0){
                    //Asignamos el valor a el espacio
                    Tablero[fila][columna] = pieza.Tipo;

                    Colocar_Torre(Tablero,tam_tablero,fila,columna,t_asignar);

                    //Columan
                    return 1;
                }else
                    return 2;
            }else if(pieza.Tipo == 'C'){
                if (Probar_Caballo(Tablero,tam_tablero,fila,columna) == 0){   
                    //Asignamos el valor a el espacio
                    Tablero[fila][columna] = pieza.Tipo;

                    Colocar_Caballo(Tablero,tam_tablero,fila,columna,t_asignar);

                    return 1;
                }else
                    return 2;
            }else if(pieza.Tipo == 'A'){
                if (Probar_Alfil(Tablero,tam_tablero,fila,columna) == 0){   
                    //Asignamos el valor a el espacio
                    Tablero[fila][columna] = pieza.Tipo;

                    Colocar_Alfil(Tablero,tam_tablero,fila,columna,t_asignar);
                    
                    return 1;
                }else
                    return 2;
                
            }else if(pieza.Tipo == 'K'){
                if(Probar_Rey(Tablero,tam_tablero,fila,columna) == 0){
                    Tablero[fila][columna] = pieza.Tipo;
                    
                    Colocar_Rey(Tablero,tam_tablero,fila,columna,t_asignar);

                    return 1;
                }else
                    return 2;
            }else if(pieza.Tipo == 'Q'){

                if(Probar_Reyna(Tablero,tam_tablero,fila,columna) == 0){    
                    //Asignamos el valor a el espacio
                    Tablero[fila][columna] = pieza.Tipo;

                    Colocar_Reyna(Tablero,tam_tablero,fila,columna,t_asignar);

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
    }else{
        return -2; // La fila o la columna esta fuera de rango
    }
 
}

//Modificada Toroidal y bombas
int Probar_Caballo(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Abajo
    if(fila+2 < tam_tablero){
        if(columna-1 > -1){
            if (Tablero[fila+2][columna-1] != 'L' && Tablero[fila+2][columna-1] != 'X' && Tablero[fila+2][columna-1] != 'B')
                return -1;
        }else{
            if (Tablero[fila+2][tam_tablero-1] != 'L' && Tablero[fila+2][tam_tablero-1] != 'X' && Tablero[fila+2][tam_tablero-1] != 'B')
                return -1;
        }
        if(columna+1 < tam_tablero){
            if (Tablero[fila+2][columna+1] != 'L' && Tablero[fila+2][columna+1] != 'X' && Tablero[fila+2][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[fila+2][0] != 'L' && Tablero[fila+2][0] != 'X' && Tablero[fila+2][0] != 'B')
                return -1;
        }
    }else if (fila+1 < tam_tablero){
        if(columna-1 > -1){
            if (Tablero[0][columna-1] != 'L' && Tablero[0][columna-1] != 'X' && Tablero[0][columna-1] != 'B' )
                return -1;
        }else{
            if (Tablero[0][tam_tablero-1] !='L' && Tablero[0][tam_tablero-1] !='X' && Tablero[0][tam_tablero-1] !='B')
                return -1;
        }   
        if(columna+1 < tam_tablero){
            if (Tablero[0][columna+1] != 'L' && Tablero[0][columna+1] != 'X' && Tablero[0][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[0][0] != 'L' && Tablero[0][0] != 'X' && Tablero[0][0] != 'B')
                return -1;
        }
    }else{
        if(columna-1 > -1){
            if (Tablero[1][columna-1] != 'L' && Tablero[1][columna-1] != 'X' && Tablero[1][columna-1] != 'B')
                return -1;
        }else{
            if (Tablero[1][tam_tablero-1] != 'L' && Tablero[1][tam_tablero-1] != 'X'  && Tablero[1][tam_tablero-1] != 'B')
                return -1;
        }
        if(columna+1 < tam_tablero){
            if (Tablero[1][columna+1] != 'L' && Tablero[1][columna+1] != 'X' && Tablero[1][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[1][0] != 'L' && Tablero[1][0] != 'X' && Tablero[1][0] != 'B')
                return -1;
        }
    }

    //Arriba
    if(fila-2 > -1){
        if(columna+1 < tam_tablero){
            if (Tablero[fila-2][columna+1] != 'L' && Tablero[fila-2][columna+1] != 'X' && Tablero[fila-2][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[fila-2][0] != 'L' && Tablero[fila-2][0] != 'X' && Tablero[fila-2][0] != 'B')
                return -1;
        }    
        if(columna-1 > -1){
            if (Tablero[fila-2][columna-1] != 'L' && Tablero[fila-2][columna-1] != 'X' && Tablero[fila-2][columna-1] != 'B')
                return -1;
        }else{
            if (Tablero[fila-2][tam_tablero-1] != 'L' && Tablero[fila-2][tam_tablero-1] != 'X' && Tablero[fila-2][tam_tablero-1] != 'B')
                return -1;
        }    
    }else if (fila-1 > -1){
        if(columna+1 < tam_tablero){
            if (Tablero[tam_tablero-1][columna+1] != 'L' && Tablero[tam_tablero-1][columna+1] != 'X' && Tablero[tam_tablero-1][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][0] != 'L' && Tablero[tam_tablero-1][0] != 'X' && Tablero[tam_tablero-1][0] != 'B')
                return -1;
        }
        if(columna-1 > -1){
            if (Tablero[tam_tablero-1][columna-1] != 'L' && Tablero[tam_tablero-1][columna-1] != 'X' && Tablero[tam_tablero-1][columna-1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-1] != 'L' && Tablero[tam_tablero-1][tam_tablero-1] != 'X' && Tablero[tam_tablero-1][tam_tablero-1] != 'B')
                return -1;
        }
    }else{
        if(columna+1 < tam_tablero){
            if (Tablero[tam_tablero-2][columna+1] != 'L' && Tablero[tam_tablero-2][columna+1] != 'X' && Tablero[tam_tablero-2][columna+1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-2][0] != 'L' && Tablero[tam_tablero-2][0] != 'X' && Tablero[tam_tablero-2][0] != 'B')
                return -1;
        }    
        if(columna-1 > -1){
            if (Tablero[tam_tablero-2][columna-1] != 'L' && Tablero[tam_tablero-2][columna-1] != 'X' && Tablero[tam_tablero-2][columna-1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-2][tam_tablero-1] != 'L' && Tablero[tam_tablero-2][tam_tablero-1] != 'X' && Tablero[tam_tablero-2][tam_tablero-1] != 'B')
                return -1;
        }
    }
    
     //Derecha
    if(columna+2 < tam_tablero){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][columna+2] != 'L' && Tablero[fila+1][columna+2] != 'X' && Tablero[fila+1][columna+2] != 'B')
                return -1;
        }else{
            if (Tablero[0][columna+2] != 'L' && Tablero[0][columna+2] != 'X' && Tablero[0][columna+2] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][columna+2] != 'L' && Tablero[fila-1][columna+2] != 'X' && Tablero[fila-1][columna+2] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][columna+2] != 'L' && Tablero[tam_tablero-1][columna+2] != 'X' && Tablero[tam_tablero-1][columna+2] != 'B')
                return -1;
        }
    }else if (columna+1 < tam_tablero){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][0] != 'L' && Tablero[fila+1][0] != 'X' && Tablero[fila+1][0] != 'B')
                return -1;
        }else{
            if (Tablero[0][0] != 'L' && Tablero[0][0] != 'X' && Tablero[0][0] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][0] != 'L' && Tablero[fila-1][0] != 'X' && Tablero[fila-1][0] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][0] != 'L' && Tablero[tam_tablero-1][0] != 'X' && Tablero[tam_tablero-1][0] != 'B')
                return -1;
        }
    }else{
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][1] != 'L' && Tablero[fila+1][1] != 'X' && Tablero[fila+1][1] != 'B')
                return -1;
        }else{
            if (Tablero[0][1] != 'L' && Tablero[0][1] != 'X' && Tablero[0][1] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][1] != 'L' && Tablero[fila-1][1] != 'X' && Tablero[fila-1][1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][1] != 'L' && Tablero[tam_tablero-1][1] != 'X' && Tablero[tam_tablero-1][1] != 'B')
                return -1;
        }
    }

    //Izquierda
    if(columna-2 > -1){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][columna-2] != 'L' && Tablero[fila+1][columna-2] != 'X' && Tablero[fila+1][columna-2] != 'B')
                return -1;
        }else{
            if (Tablero[0][columna-2] != 'L' && Tablero[0][columna-2] != 'X' && Tablero[0][columna-2] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][columna-2] != 'L' && Tablero[fila-1][columna-2] != 'X' && Tablero[fila-1][columna-2] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][columna-2] != 'L' && Tablero[tam_tablero-1][columna-2] != 'X' && Tablero[tam_tablero-1][columna-2] != 'B')
                return -1;
        }
    }else if (columna-1 > -1){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][tam_tablero-1] != 'L' && Tablero[fila+1][tam_tablero-1] != 'X' && Tablero[fila+1][tam_tablero-1] != 'B')
                return -1;
        }else{
            if (Tablero[0][tam_tablero-1] != 'L' && Tablero[0][tam_tablero-1] != 'X' && Tablero[0][tam_tablero-1] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][tam_tablero-1] != 'L' && Tablero[fila-1][tam_tablero-1] != 'X' && Tablero[fila-1][tam_tablero-1] != 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-1] != 'L' && Tablero[tam_tablero-1][tam_tablero-1] != 'X' && Tablero[tam_tablero-1][tam_tablero-1] != 'B')
                return -1;
        }
    }else{
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][tam_tablero-2] != 'L' && Tablero[fila+1][tam_tablero-2] != 'X' && Tablero[fila+1][tam_tablero-2] != 'B')
                return -1;
        }else{
            if (Tablero[0][tam_tablero-2] != 'L' && Tablero[0][tam_tablero-2] != 'X' && Tablero[0][tam_tablero-2] != 'B')
                return -1;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][tam_tablero-2] != 'L' && Tablero[fila-1][tam_tablero-2] != 'X' && Tablero[fila-1][tam_tablero-2]!= 'B')
                return -1;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-2] != 'L' && Tablero[tam_tablero-1][tam_tablero-2] != 'X' && Tablero[tam_tablero-1][tam_tablero-2] != 'B')
                return -1;
        }
    }
    

    return 0;
}

//Modificada Toroidal y bombas
int Probar_Reyna(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Variables
    int fi=fila,co=columna;
    
    //Diagonal Derecha-Abajo
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Derecha-Arriba
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Izquierda-Abajo
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    fi = fila;
    co = columna;
    
    //Diagonal Izquierda-Arriba
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    fi = fila;
    co = columna;

    //Columnas hacia ABAJO
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    while(fila != fi){
        if( Tablero[fi][columna] == 'B')
            break;
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' && Tablero[fi][columna] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++; 
    }
    fi = fila;

    //Columnas hacia ARRIBA
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    while(fila != fi){
        if( Tablero[fi][columna] == 'B')
            break;
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' && Tablero[fi][columna] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
    }
    fi = fila;

    //Columnas hacia la Derecha
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(columna != co){
        if(Tablero[fila][co] == 'B')
            break;
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' && Tablero[fila][co] != 'B' )
            return -1;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    co = columna;
    
    //Columnas hacia la Izquierda
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(columna != co){
        if(Tablero[fila][co] == 'B')
            break;
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' && Tablero[fila][co] != 'B' )
            return -1;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    co = columna;

    return 0;
}

//Modificada Toroidal y bombas
int Probar_Rey(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida


    //Arriba
    if(fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna] != 'X' && Tablero[tam_tablero-1][columna] != 'L' && Tablero[tam_tablero-1][columna] != 'B' )
            return -1;
    }else{
        if(Tablero[fila-1][columna] != 'X' && Tablero[fila-1][columna] != 'L' && Tablero[fila-1][columna] != 'B' )
            return -1;
    }

    //Derecha Arriba
    if(fila-1 <= -1 && columna+1 >= tam_tablero){
        if(Tablero[tam_tablero-1][0] != 'X' && Tablero[tam_tablero-1][0] != 'L' && Tablero[tam_tablero-1][0] != 'B' )
            return -1;
    }else if (fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna+1] != 'X' && Tablero[tam_tablero-1][columna+1] != 'L' && Tablero[tam_tablero-1][columna+1] != 'B' )
            return -1;
    }else if(columna+1 >= tam_tablero){
        if(Tablero[fila-1][0] != 'X' && Tablero[fila-1][0] != 'L' && Tablero[fila-1][0] != 'B' )
            return -1;
    }else{
        if(Tablero[fila-1][columna+1] != 'X' && Tablero[fila-1][columna+1] != 'L' && Tablero[fila-1][columna+1] != 'B' )
            return -1;
    }
    
    //Derecha
    if(columna+1 >= tam_tablero){
        if(Tablero[fila][0] != 'X' && Tablero[fila][0] != 'L' && Tablero[fila][0] != 'B' )
            return -1;
    }else{
        if(Tablero[fila][columna+1] != 'X' && Tablero[fila][columna+1] != 'L' && Tablero[fila][columna+1] != 'B' )
            return -1;
    }
    
    //Derecha-Abajo
    if(fila+1 < tam_tablero && columna+1 < tam_tablero){
        if(Tablero[fila+1][columna+1] != 'X' && Tablero[fila+1][columna+1] != 'L' && Tablero[fila+1][columna+1] != 'B' )
            return -1;
    }else if(fila+1 < tam_tablero){
        if(Tablero[fila+1][0] != 'X' && Tablero[fila+1][0] != 'L' && Tablero[fila+1][0] != 'B' )
            return -1;
    }else if(columna+1 < tam_tablero){
        if(Tablero[0][columna+1] != 'X' && Tablero[0][columna+1] != 'L' && Tablero[0][columna+1] != 'B' )
            return -1;
    }else{
        if(Tablero[0][0] != 'X' && Tablero[0][0] != 'L' && Tablero[0][0] != 'B' )
            return -1;
    }

    //Abajo
    if(fila+1 < tam_tablero){
        if(Tablero[fila+1][columna] != 'X' && Tablero[fila+1][columna] != 'L' && Tablero[fila+1][columna] != 'B' )
            return -1;
    }else{
        if(Tablero[0][columna] != 'X' && Tablero[0][columna] != 'L' && Tablero[0][columna] != 'B')
            return -1;
    }

    //Izquierda
    if(columna-1 <= -1){
        if(Tablero[fila][tam_tablero-1] != 'X' && Tablero[fila][tam_tablero-1] != 'L' && Tablero[fila][tam_tablero-1] != 'B' )
            return -1;
    }else{
        if(Tablero[fila][columna-1] != 'X' && Tablero[fila][columna-1] != 'L' && Tablero[fila][columna-1] != 'B' )
            return -1;   
    }

    //Abajo-Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1){
        if(Tablero[fila+1][columna-1] != 'X' && Tablero[fila+1][columna-1] != 'L' && Tablero[fila+1][columna-1] != 'B')
            return -1;
    }else if(fila+1 < tam_tablero){
        if(Tablero[fila+1][tam_tablero-1] != 'X' && Tablero[fila+1][tam_tablero-1] != 'L' && Tablero[fila+1][tam_tablero-1] != 'B')
            return -1;
    }else if(columna-1 > -1){
        if(Tablero[0][columna-1] != 'X' && Tablero[0][columna-1] != 'L' && Tablero[0][columna-1] != 'B')
            return -1;
    }else{
        if(Tablero[0][tam_tablero-1] != 'X' && Tablero[0][tam_tablero-1] != 'L' && Tablero[0][tam_tablero-1] != 'B')
            return -1;
    }

    //Arriba-Izquierda 
    if(fila-1 > -1 && columna-1 > -1){
        if(Tablero[fila-1][columna-1] != 'X' && Tablero[fila-1][columna-1] != 'L' && Tablero[fila-1][columna-1] != 'B' )
            return -1;
    }else if(fila-1 > -1){
        if(Tablero[fila-1][tam_tablero-1] != 'X' && Tablero[fila-1][tam_tablero-1] != 'L' && Tablero[fila-1][tam_tablero-1] != 'B' )
            return -1;
    }else if(columna-1 > -1){
        if(Tablero[tam_tablero-1][columna-1] != 'X' && Tablero[tam_tablero-1][columna-1] != 'L' && Tablero[tam_tablero-1][columna-1] != 'B' )
            return -1;
    }else{
        if(Tablero[tam_tablero-1][tam_tablero-1] != 'X' && Tablero[tam_tablero-1][tam_tablero-1] != 'L' && Tablero[tam_tablero-1][tam_tablero-1] != 'B' )
            return -1;
    }

    return 0;
}

//Modificadi Toroidal y bombas
int Probar_Alfil(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Variables
    int fi=fila,co=columna;
    
    //Diagonal Derecha-Abajo
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Derecha-Arriba
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Izquierda-Abajo
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    fi = fila;
    co = columna;
    
    //Diagonal Izquierda-Arriba
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(fila != fi && columna != co){
        if( Tablero[fi][co] == 'B')
            break;
        if(Tablero[fi][co] != 'X' && Tablero[fi][co] != 'L' && Tablero[fi][co] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    fi = fila;
    co = columna;
    
    return 0;
}

//Modificadi Toroidal y bombas
int Probar_Torre(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Variables
    int fi=fila,co=columna;
    
    //Columnas hacia ABAJO
    if(fi+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    while(fila != fi){
        if( Tablero[fi][columna] == 'B')
            break;
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' && Tablero[fi][columna] != 'B' )
            return -1;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++; 
    }
    fi = fila;

    //Columnas hacia ARRIBA
    if(fi-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    while(fila != fi){
        if( Tablero[fi][columna] == 'B')
            break;
        if(Tablero[fi][columna] != 'X' && Tablero[fi][columna] != 'L' && Tablero[fi][columna] != 'B' )
            return -1;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
    }
    fi = fila;

    //Columnas hacia la Derecha
    if(co+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(columna != co){
        if(Tablero[fila][co] == 'B')
            break;
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' && Tablero[fila][co] != 'B' )
            return -1;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    co = columna;
    
    //Columnas hacia la Izquierda
    if(co-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(columna != co){
        if(Tablero[fila][co] == 'B')
            break;
        if(Tablero[fila][co] != 'X' && Tablero[fila][co] != 'L' && Tablero[fila][co] != 'B' )
            return -1;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    co = columna;

    return 0;
}

//Modificado Toroidal y bombas
int Probar_Peon(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida
           
    //Diagonal Inferior Derecha Toroidal
    if(fila+1 >= tam_tablero && columna+1 >= tam_tablero){ //Desborde en ambos extremos
        if(Tablero[0][0] != 'X' && Tablero[0][0] != 'L' && Tablero[0][0] != 'B')
            return -1;
    }else if(fila+1 >= tam_tablero){
        if(Tablero[0][columna+1] != 'X' && Tablero[0][columna+1] != 'L' && Tablero[0][columna+1] != 'B')
            return -1;
    }else if(columna+1 >= tam_tablero){
        if(Tablero[fila+1][0] != 'X' && Tablero[fila+1][0] != 'L' && Tablero[fila+1][0] != 'B')
            return -1;
    }else{
        if(Tablero[fila+1][columna+1] != 'X' && Tablero[fila+1][columna+1] != 'L' && Tablero[fila+1][columna+1] != 'B')
            return -1;
    }
 
    //Diagonal Inferior Izquierda Toroidal
    if(fila+1 >= tam_tablero && columna-1 <= -1){ //Desborde en ambos extremos
        if(Tablero[0][tam_tablero-1] != 'X' && Tablero[0][tam_tablero-1] != 'L' && Tablero[0][tam_tablero-1] != 'B')
            return -1;
    }else if(fila+1 >= tam_tablero){
        if(Tablero[0][columna-1] != 'X' && Tablero[0][columna-1] != 'L' && Tablero[0][columna-1] != 'B')
            return -1;
    }else if(columna-1 <= -1){
        if(Tablero[fila+1][tam_tablero-1] != 'X' && Tablero[fila+1][tam_tablero-1] != 'L' && Tablero[fila+1][tam_tablero-1] != 'B')
            return -1;
    }else{
        if(Tablero[fila+1][columna-1] != 'X' && Tablero[fila+1][columna-1] != 'L' && Tablero[fila+1][columna-1] != 'B')
            return -1;
    }

    //Diagonal Superior Izquierda Toroidal
    if(fila-1 <= -1 && columna-1 <= -1){ //Desborde en ambos extremos
        if(Tablero[tam_tablero-1][tam_tablero-1] != 'X' && Tablero[tam_tablero-1][tam_tablero-1] != 'L' && Tablero[tam_tablero-1][tam_tablero-1] != 'B')
            return -1;
    }else if(fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna-1] != 'X' && Tablero[tam_tablero-1][columna-1] != 'L' && Tablero[tam_tablero-1][columna-1] != 'B')
            return -1;
    }else if(columna-1 <= -1){
        if(Tablero[fila-1][tam_tablero-1] != 'X' && Tablero[fila-1][tam_tablero-1] != 'L' && Tablero[fila-1][tam_tablero-1] != 'B')
            return -1;
    }else{
        if(Tablero[fila-1][columna-1] != 'X' && Tablero[fila-1][columna-1] != 'L' && Tablero[fila-1][columna-1] != 'B')
            return -1;
    }

    //Diagonal Superior Derecha Toroidal
    if(fila-1 <= -1 && columna+1 >= tam_tablero){
        if(Tablero[tam_tablero-1][0] != 'X' && Tablero[tam_tablero-1][0] != 'L' && Tablero[tam_tablero-1][0] != 'B')
            return -1;
    }else if (fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna+1] != 'X' && Tablero[tam_tablero-1][columna+1] != 'L' && Tablero[tam_tablero-1][columna+1] != 'B')
            return -1;
    }else if (columna+1 >= tam_tablero){
        if(Tablero[fila-1][0] != 'X' && Tablero[fila-1][0] != 'L' && Tablero[fila-1][0] != 'B')
            return -1;
    }else{
        if(Tablero[fila-1][columna +1] != 'X' && Tablero[fila-1][columna +1] != 'L' && Tablero[fila-1][columna +1] != 'B')
            return -1;
    }
    
    return 0;
}

//Modificado Toroidal y bombas
void Colocar_Caballo(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Abajo
    if(fila+2 < tam_tablero){
        if(columna-1 > -1){
            if (Tablero[fila+2][columna-1] == 'L')
                Tablero[fila+2][columna-1] = t_asignar;
        }else{
            if (Tablero[fila+2][tam_tablero-1] == 'L')
                Tablero[fila+2][tam_tablero-1] = t_asignar;
        }
        if(columna+1 < tam_tablero){
            if (Tablero[fila+2][columna+1] == 'L')
                Tablero[fila+2][columna+1] = t_asignar;
        }else{
            if (Tablero[fila+2][0] == 'L')
                Tablero[fila+2][0] = t_asignar;
        }
    }else if (fila+1 < tam_tablero){
        if(columna-1 > -1){
            if (Tablero[0][columna-1] == 'L')
                Tablero[0][columna-1] = t_asignar;
        }else{
            if (Tablero[0][tam_tablero-1] =='L')
                Tablero[0][tam_tablero-1] = t_asignar;
        }   
        if(columna+1 < tam_tablero){
            if (Tablero[0][columna+1] == 'L')
                Tablero[0][columna+1] = t_asignar;
        }else{
            if (Tablero[0][0] == 'L')
                Tablero[0][0] = t_asignar;
        }
    }else{
        if(columna-1 > -1){
            if (Tablero[1][columna-1] == 'L')
                Tablero[1][columna-1] = t_asignar;
        }else{
            if (Tablero[1][tam_tablero-1] == 'L')
                Tablero[1][tam_tablero-1] = t_asignar;
        }
        if(columna+1 < tam_tablero){
            if (Tablero[1][columna+1] == 'L')
                Tablero[1][columna+1] = t_asignar;
        }else{
            if (Tablero[1][0] == 'L')
                Tablero[1][0] = t_asignar;
        }
    }

    //Arriba
    if(fila-2 > -1){
        if(columna+1 < tam_tablero){
            if (Tablero[fila-2][columna+1] == 'L')
                Tablero[fila-2][columna+1] = t_asignar;
        }else{
            
            if (Tablero[fila-2][0] == 'L')
                Tablero[fila-2][0] = t_asignar;
        }    
        if(columna-1 > -1){
            if (Tablero[fila-2][columna-1] == 'L')
                Tablero[fila-2][columna-1] = t_asignar;
        }else{
            if (Tablero[fila-2][tam_tablero-1] == 'L')
                Tablero[fila-2][tam_tablero-1] = t_asignar;
        }    
    }else if (fila-1 > -1){
        if(columna+1 < tam_tablero){
            if (Tablero[tam_tablero-1][columna+1] == 'L')
                Tablero[tam_tablero-1][columna+1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][0] == 'L')
                Tablero[tam_tablero-1][0] = t_asignar;
        }
        if(columna-1 > -1){
            if (Tablero[tam_tablero-1][columna-1] == 'L')
                Tablero[tam_tablero-1][columna-1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-1] == 'L')
                Tablero[tam_tablero-1][tam_tablero-1] = t_asignar;
        }
    }else{
        if(columna+1 < tam_tablero){
            if (Tablero[tam_tablero-2][columna+1] == 'L')
                Tablero[tam_tablero-2][columna+1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-2][0] == 'L')
                Tablero[tam_tablero-2][0] = t_asignar;
        }    
        if(columna-1 > -1){
            if (Tablero[tam_tablero-2][columna-1] == 'L')
                Tablero[tam_tablero-2][columna-1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-2][tam_tablero-1] == 'L')
                Tablero[tam_tablero-2][tam_tablero-1] = t_asignar;
        }
    }
    
     //Derecha
    if(columna+2 < tam_tablero){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][columna+2] == 'L')
                Tablero[fila+1][columna+2] = t_asignar;
        }else{
            if (Tablero[0][columna+2] == 'L')
                Tablero[0][columna+2] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][columna+2] == 'L')
                Tablero[fila-1][columna+2] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][columna+2] == 'L')
                Tablero[tam_tablero-1][columna+2] = t_asignar;
        }
    }else if (columna+1 < tam_tablero){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][0] == 'L')
                Tablero[fila+1][0] = t_asignar;
        }else{
            if (Tablero[0][0] == 'L')
                Tablero[0][0] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][0] == 'L')
                Tablero[fila-1][0] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][0] == 'L')
                Tablero[tam_tablero-1][0] = t_asignar;
        }
    }else{
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][1] == 'L')
                Tablero[fila+1][1] = t_asignar;
        }else{
            if (Tablero[0][1] == 'L')
                Tablero[0][1] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][1] == 'L')
                Tablero[fila-1][1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][1] == 'L')
                Tablero[tam_tablero-1][1] = t_asignar;
        }
    }

    //Izquierda
    if(columna-2 > -1){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][columna-2] == 'L')
                Tablero[fila+1][columna-2] = t_asignar;
        }else{
            if (Tablero[0][columna-2] == 'L')
                Tablero[0][columna-2] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][columna-2] == 'L')
                Tablero[fila-1][columna-2] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][columna-2] == 'L')
                Tablero[tam_tablero-1][columna-2] = t_asignar;
        }
    }else if (columna-1 > -1){
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][tam_tablero-1] == 'L')
                Tablero[fila+1][tam_tablero-1] = t_asignar;
        }else{
            if (Tablero[0][tam_tablero-1] == 'L')
                Tablero[0][tam_tablero-1] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][tam_tablero-1] == 'L')
                Tablero[fila-1][tam_tablero-1] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-1] == 'L')
                Tablero[tam_tablero-1][tam_tablero-1] = t_asignar;
        }
    }else{
        if(fila+1 < tam_tablero){
            if (Tablero[fila+1][tam_tablero-2] == 'L')
                Tablero[fila+1][tam_tablero-2] = t_asignar;
        }else{
            if (Tablero[0][tam_tablero-2] == 'L')
                Tablero[0][tam_tablero-2] = t_asignar;
        }
        if(fila-1 > -1){
            if (Tablero[fila-1][tam_tablero-2] == 'L')
                Tablero[fila-1][tam_tablero-2] = t_asignar;
        }else{
            if (Tablero[tam_tablero-1][tam_tablero-2] == 'L')
                Tablero[tam_tablero-1][tam_tablero-2] = t_asignar;
        }
    }
    
}

//Modificado Toroidal y bombas
void Colocar_Reyna(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){

    //Variables
    int fi = fila, co = columna;

    //Diagonal Derecha-Abajo
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fi][co] != 'Q'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Derecha-Arriba
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fi][co] != 'Q'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Izquierda-Abajo
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fi][co] != 'Q'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--;
    }
    fi = fila;
    co = columna;
    
    //Diagonal Izquierda-Arriba
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fi][co] != 'Q'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--; 
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--;
    }
    fi = fila;
    co = columna;

    //Columan hacia ABAJO
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    while(Tablero[fi][columna] != 'Q'){
        if( Tablero[fi][columna] == 'B')
            break;
        Tablero[fi][columna] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++; 
    }
    fi = fila;
    
    //Columan hacia ARRIBA
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    while(Tablero[fi][columna] != 'Q'){
        if( Tablero[fi][columna] == 'B')
            break;
        Tablero[fi][columna] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
    }
    fi = fila;

    //Columna hacia la DERECHA
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fila][co] != 'Q'){
        if(Tablero[fila][co] == 'B')
            break;
        Tablero[fila][co] = t_asignar;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    co = columna;
    
    //Columna hacia la IZQUIERDA
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fila][co] != 'Q'){
        if(Tablero[fila][co] == 'B')
            break;
        Tablero[fila][co] = t_asignar;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    co = columna;

}

//Modificado Toroidal y bombas
void Colocar_Rey(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Arriba
    if(fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna] == 'L')
            Tablero[tam_tablero-1][columna] = t_asignar;
    }else{
        if(Tablero[fila-1][columna] == 'L')
            Tablero[fila-1][columna] = t_asignar;
    }

    //Derecha Arriba
    if(fila-1 <= -1 && columna+1 >= tam_tablero){
        if(Tablero[tam_tablero-1][0] == 'L')
            Tablero[tam_tablero-1][0] = t_asignar;
    }else if (fila-1 <= -1){
        if (Tablero[tam_tablero-1][columna+1] == 'L')
            Tablero[tam_tablero-1][columna+1] = t_asignar;
    }else if(columna+1 >= tam_tablero){
        if(Tablero[fila-1][0] == 'L')
            Tablero[fila-1][0] = t_asignar;
    }else{
        if(Tablero[fila-1][columna+1] == 'L')
            Tablero[fila-1][columna+1] = t_asignar;
    }
    
    //Derecha
    if(columna+1 >= tam_tablero){
        if(Tablero[fila][0] == 'L')
            Tablero[fila][0] = t_asignar;
    }else{
        if(Tablero[fila][columna+1] == 'L')
            Tablero[fila][columna+1] = t_asignar;
    }
    
    //Derecha-Abajo
    if(fila+1 < tam_tablero && columna+1 < tam_tablero){
        if(Tablero[fila+1][columna+1] == 'L')
            Tablero[fila+1][columna+1] = t_asignar;
    }else if(fila+1 < tam_tablero){
        if(Tablero[fila+1][0] == 'L')
            Tablero[fila+1][0] = t_asignar;
    }else if(columna+1 < tam_tablero){
        if( Tablero[0][columna+1] == 'L')
            Tablero[0][columna+1] = t_asignar;
    }else{
        if(Tablero[0][0] == 'L')
            Tablero[0][0] = t_asignar;
    }

    //Abajo
    if(fila+1 < tam_tablero){
        if(Tablero[fila+1][columna] == 'L')
            Tablero[fila+1][columna] = t_asignar;
    }else{
        if(Tablero[0][columna] == 'L')
            Tablero[0][columna] = t_asignar;
    }

    //Izquierda
    if(columna-1 <= -1){
        if(Tablero[fila][tam_tablero-1] == 'L')
            Tablero[fila][tam_tablero-1] = t_asignar;
    }else{
        if(Tablero[fila][columna-1] == 'L')
            Tablero[fila][columna-1] = t_asignar;
    }

    //Abajo-Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1){
        if(Tablero[fila+1][columna-1] == 'L')
            Tablero[fila+1][columna-1] = t_asignar;
    }else if(fila+1 < tam_tablero){
        if(Tablero[fila+1][tam_tablero-1] == 'L')
            Tablero[fila+1][tam_tablero-1] = t_asignar;
    }else if(columna-1 > -1){
        if(Tablero[0][columna-1] == 'L')
            Tablero[0][columna-1] = t_asignar;
    }else{
        if(Tablero[0][tam_tablero-1] == 'L')
            Tablero[0][tam_tablero-1] = t_asignar;
    }

    //Arriba-Izquierda 
    if(fila-1 > -1 && columna-1 > -1){
        if(Tablero[fila-1][columna-1] == 'L')
            Tablero[fila-1][columna-1] = t_asignar;
    }else if(fila-1 > -1){
        if(Tablero[fila-1][tam_tablero-1] == 'L')
            Tablero[fila-1][tam_tablero-1] = t_asignar;
    }else if(columna-1 > -1){
        if (Tablero[tam_tablero-1][columna-1] == 'L')
            Tablero[tam_tablero-1][columna-1] = t_asignar;
    }else{
        if(Tablero[tam_tablero-1][tam_tablero-1] == 'L')
            Tablero[tam_tablero-1][tam_tablero-1] = t_asignar;
    }

}

//Modificado Toroidal y bombas
void Colocar_Alfil(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Variables
    int fi = fila, co = columna;

    //Diagonal Derecha-Abajo
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fi][co] != 'A'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Derecha-Arriba
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fi][co] != 'A'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    fi = fila;
    co = columna;

    //Diagonal Izquierda-Abajo
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fi][co] != 'A'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--;
    }
    fi = fila;
    co = columna;
    
    //Diagonal Izquierda-Arriba
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fi][co] != 'A'){
        if( Tablero[fi][co] == 'B')
            break;
        Tablero[fi][co] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--; 
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--;
    }
    fi = fila;
    co = columna;
    
}

//Modificado Toroidal y bombas
void Colocar_Torre(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Variables
    int fi=fila,co=columna;
    
    //Columan hacia ABAJO
    if(fila+1 >= tam_tablero)
        fi = 0;
    else
        fi++;
    while(Tablero[fi][columna] != 'T'){
        if( Tablero[fi][columna] == 'B')
            break;
        Tablero[fi][columna] = t_asignar;
        if(fi+1 >= tam_tablero)
            fi = 0;
        else
            fi++; 
    }
    fi = fila;
    
    //Columan hacia ARRIBA
    if(fila-1 <= -1)
        fi = tam_tablero-1;
    else
        fi--;
    while(Tablero[fi][columna] != 'T'){
        if( Tablero[fi][columna] == 'B')
            break;
        Tablero[fi][columna] = t_asignar;
        if(fi-1 <= -1)
            fi = tam_tablero-1;
        else
            fi--;
    }
    fi = fila;

    //Columna hacia la DERECHA
    if(columna+1 >= tam_tablero)
        co = 0;
    else
        co++;
    while(Tablero[fila][co] != 'T'){
        if(Tablero[fila][co] == 'B')
            break;
        Tablero[fila][co] = t_asignar;
        if(co+1 >= tam_tablero)
            co = 0;
        else
            co++; 
    }
    co = columna;
    
    //Columna hacia la IZQUIERDA
    if(columna-1 <= -1)
        co = tam_tablero-1;
    else
        co--;
    while(Tablero[fila][co] != 'T'){
        if(Tablero[fila][co] == 'B')
            break;
        Tablero[fila][co] = t_asignar;
        if(co-1 <= -1)
            co = tam_tablero-1;
        else
            co--; 
    }
    co = columna;   
}

//Modificado Toroidal y bombas
void Colocar_Peon(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){

    //Diagonal Inferior Derecha Toroidal
    if(fila+1 >= tam_tablero && columna+1 >= tam_tablero){ //Desborde en ambos extremos
        if(Tablero[0][0] == 'L')
            Tablero[0][0] = t_asignar;
    }else if(fila+1 >= tam_tablero){
        if(Tablero[0][columna+1] == 'L')
            Tablero[0][columna+1] = t_asignar;
    }else if(columna+1 >= tam_tablero){
        if(Tablero[fila+1][0] == 'L')
            Tablero[fila+1][0] = t_asignar;
    }else{
        if(Tablero[fila+1][columna+1] == 'L')
            Tablero[fila+1][columna+1] = t_asignar;
    }
 
    //Diagonal Inferior Izquierda Toroidal
    if(fila+1 >= tam_tablero && columna-1 <= -1){ //Desborde en ambos extremos
        if(Tablero[0][tam_tablero-1] == 'L')
            Tablero[0][tam_tablero-1] = t_asignar;
    }else if(fila+1 >= tam_tablero){
        if(Tablero[0][columna-1] == 'L')
            Tablero[0][columna-1] = t_asignar;
    }else if(columna-1 <= -1){
        if(Tablero[fila+1][tam_tablero-1] == 'L')
            Tablero[fila+1][tam_tablero-1] = t_asignar;
    }else{
        if(Tablero[fila+1][columna-1] == 'L')
            Tablero[fila+1][columna-1] = t_asignar;
    }

    //Diagonal Superior Izquierda Toroidal
    if(fila-1 <= -1 && columna-1 <= -1){ //Desborde en ambos extremos
        if(Tablero[tam_tablero-1][tam_tablero-1] == 'L')
            Tablero[tam_tablero-1][tam_tablero-1] = t_asignar;
    }else if(fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna-1] == 'L')
            Tablero[tam_tablero-1][columna-1] = t_asignar;
    }else if(columna-1 <= -1){
        if(Tablero[fila-1][tam_tablero-1] == 'L')
            Tablero[fila-1][tam_tablero-1] = t_asignar;
    }else{
        if(Tablero[fila-1][columna-1] == 'L')
            Tablero[fila-1][columna-1] = t_asignar;
    }

    //Diagonal Superior Derecha Toroidal
    if(fila-1 <= -1 && columna+1 >= tam_tablero){
        if(Tablero[tam_tablero-1][0] == 'L')
            Tablero[tam_tablero-1][0] = t_asignar;
    }else if (fila-1 <= -1){
        if(Tablero[tam_tablero-1][columna+1] == 'L')
            Tablero[tam_tablero-1][columna+1] = t_asignar;
    }else if (columna+1 >= tam_tablero){
        if(Tablero[fila-1][0] == 'L')
            Tablero[fila-1][0] = t_asignar;
    }else{
        if(Tablero[fila-1][columna +1] == 'L')
            Tablero[fila-1][columna +1] = t_asignar;
    }

}