#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long int num_dig(long int );
long int numero_de_digitos_pot2(long int );
long int karatsuba(long int,long int );

void main(int argc, char**argv){

long int resultado = 0;

resultado = karatsuba(atol(argv[1]),atol(argv[2]));
printf("El resultado es: %ld \n",resultado);

}

long int karatsuba(long int numero1,long int numero2){
    long int num_digitos,ac,bd,adbc;

    if(numero1>=numero2)
        num_digitos =numero_de_digitos_pot2(num_dig(numero1));
    else
        num_digitos =numero_de_digitos_pot2(num_dig(numero2));

    if(num_digitos == 1)
        return (numero1*numero2);
    else{
        ac = karatsuba(((numero1/pow(10,num_digitos/2))),(numero2 / pow(10,num_digitos/2)));
        bd = karatsuba((numero1 - ((long)(numero1 / pow(10,num_digitos/2)) * pow(10,num_digitos/2))),(numero2 - ((long)(numero2 / pow(10,num_digitos/2)) * pow(10,num_digitos/2))));
        adbc = karatsuba(((numero1 / pow(10,num_digitos/2))+(numero1 - ((long)(numero1 / pow(10,num_digitos/2)) * pow(10,num_digitos/2)))),((numero2 / pow(10,num_digitos/2))+(numero2 - ((long)(numero2 / pow(10,num_digitos/2)) * pow(10,num_digitos/2))))) - ac - bd;

        return (pow(10,num_digitos)*ac) + (pow(10,num_digitos/2)*adbc) + bd;
    }
}

long int numero_de_digitos_pot2(long int numero){
    if (numero & (numero-1) == 0){
        return numero;
    }else{
        return (long int)pow(2,(int)((log2(numero)/1)+1));  
    }         
}
long int num_dig(long int numero){
    int num_digitos = 0;
    int div = 1;
    while(1){
        if (numero/div != 0)
            num_digitos ++,div *=10;
        else
            return num_digitos;
    }
}