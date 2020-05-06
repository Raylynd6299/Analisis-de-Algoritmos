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

int Probar_Caballo(char **Tablero,int tam_tablero,int fila,int columna){
    // -1 <-- Esta posicion atacaria una pieza anteriormente colocada
    //  0 <-- Esta posicion es valida

    //Abajo
    if(fila+2 < tam_tablero){
        if(columna-1 > -1)
            if(Tablero[fila+2][columna-1] != 'X' && Tablero[fila+2][columna-1] != 'L' )
                return -1;
        if(columna+1 < tam_tablero)
            if(Tablero[fila+2][columna+1] != 'X' && Tablero[fila+2][columna+1] != 'L' )
                return -1;
    }
    //Arriba
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


void Colocar_Caballo(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Abajo
    if(fila+2 < tam_tablero){
        if(columna-1 > -1)
            Tablero[fila+2][columna-1] = t_asignar;
        if(columna+1 < tam_tablero)
            Tablero[fila+2][columna+1] = t_asignar;
    }
    //Abajo
    if(fila-2 > -1){
        if(columna+1 < tam_tablero)
            Tablero[fila-2][columna+1] = t_asignar;
        if(columna-1 > -1)
            Tablero[fila-2][columna-1] = t_asignar;
    }
    //Derecha
    if(columna+2 < tam_tablero){
        if(fila+1 < tam_tablero)
            Tablero[fila+1][columna+2] = t_asignar;
        if(fila-1 > -1)
            Tablero[fila-1][columna+2] = t_asignar;
    }
    //Izquierda
    if(columna-2 > -1){
        if(fila+1 < tam_tablero)
            Tablero[fila+1][columna-2] = t_asignar;
        if(fila-1 > -1)
            Tablero[fila-1][columna-2] = t_asignar;
    }

}

void Colocar_Reyna(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){


    //Columan hacia ABAJO
    for(int fi = fila+1; fi < tam_tablero ; fi++)
        Tablero[fi][columna] = t_asignar;
    
    //Columna hacia ARRIBA
    for(int fi = fila-1; fi > -1 ; fi--)
        Tablero[fi][columna] = t_asignar;

    //Columans hacia la Derecha
    for(int co = columna+1 ; co < tam_tablero ; co++)
        Tablero[fila][co] = t_asignar;
    
    //Columna hacia la Izquierda
    for(int co = columna-1 ; co > -1 ; co --)
        Tablero[fila][co] = t_asignar;

    //Diagonal Derecha-Abajo
    for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
        Tablero[fi][co] = t_asignar;
        
    //Diagonal Derecha-Arriba
    for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
        Tablero[fi][co] = t_asignar;

    //Diagonal Izquierda-Abajo
    for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
        Tablero[fi][co] = t_asignar;
    
    //Diagonal Izquierda-Arriba
    for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
        Tablero[fi][co] = t_asignar;

}

void Colocar_Rey(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Arriba
    if(fila-1 > -1)
        Tablero[fila-1][columna] = t_asignar;

    //Derecha Arriba
    if(fila-1 > -1 && columna+1 < tam_tablero)
        Tablero[fila-1][columna+1] = t_asignar;

    //Derecha
    if(columna+1 < tam_tablero)
        Tablero[fila][columna+1] = t_asignar;

    //Derecha-Abajo
    if(fila+1 < tam_tablero && columna+1 < tam_tablero)
        Tablero[fila+1][columna+1] = t_asignar;

    //Abajo
    if(fila+1 < tam_tablero)
        Tablero[fila+1][columna] = t_asignar;

    //Abajo-Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1)
        Tablero[fila+1][columna-1] = t_asignar;

    //Izquierda
    if(columna-1 > -1)
        Tablero[fila][columna-1] = t_asignar;

    //Arriba-Izquierda
    if(fila-1 > -1 && columna-1 > -1)
        Tablero[fila-1][columna-1] = t_asignar;

}

void Colocar_Alfil(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){

    //Diagonal Derecha-Abajo
    for (int fi = (fila+1),co = columna+1; fi < tam_tablero && co < tam_tablero; fi++,co++)
        Tablero[fi][co] = t_asignar;
        
    //Diagonal Derecha-Arriba
    for(int fi = fila-1, co = columna+1; fi > -1 && co < tam_tablero; fi --,co++)
        Tablero[fi][co] = t_asignar;

    //Diagonal Izquierda-Abajo
    for(int fi = fila+1, co = columna-1; fi < tam_tablero && co > -1 ; fi++, co--)
        Tablero[fi][co] = t_asignar;
    
    //Diagonal Izquierda-Arriba
    for(int fi = fila-1, co = columna-1; fi > -1 && co > -1; fi--,co--)
        Tablero[fi][co] = t_asignar;

}

void Colocar_Torre(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Columan hacia ABAJO
    for(int fi = fila+1; fi < tam_tablero ; fi++)
        Tablero[fi][columna] = t_asignar;
    
    //Columna hacia ARRIBA
    for(int fi = fila-1; fi > -1 ; fi--)
        Tablero[fi][columna] = t_asignar;

    //Columans hacia la Derecha
    for(int co = columna+1 ; co < tam_tablero ; co++)
        Tablero[fila][co] = t_asignar;
    
    //Columna hacia la Izquierda
    for(int co = columna-1 ; co > -1 ; co --)
        Tablero[fila][co] = t_asignar;

}

void Colocar_Peon(char **Tablero,int tam_tablero,int fila,int columna,char t_asignar){
    
    //Diagonal Inferior Derecha            
    if(fila+1 < tam_tablero && columna+1 < tam_tablero)
        Tablero[fila+1][columna+1] = t_asignar;

    //Diagonal Inferior Izquierda
    if(fila+1 < tam_tablero && columna-1 > -1)
        Tablero[fila+1][columna-1] = t_asignar;
    
    //Diagonal Superior Izquierda
    if(fila-1 > -1 && columna-1 > -1)
        Tablero[fila-1][columna-1] = t_asignar;

    //Diagonal Superior Derecha
    if(fila-1 > -1 && columna+1 < tam_tablero)
        Tablero[fila-1][columna +1] = t_asignar;

}