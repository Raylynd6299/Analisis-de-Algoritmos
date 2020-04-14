//Creado por Raymundo Pulido Bejarano
//correo: ray_lynd_6299@gmail.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

void imp(int,char*);
char Regla(char,char,char);
void aplirul(char *,int,FILE *);

void main(int argc,char *argv[]){//Argumentos Nombre del archivo , numero de iteraciones, cadena
	if(argc ==4){	
			int i;
			short m=atoi(argv[2]);
			FILE *Res=fopen(argv[1],"w+");
			if(Res != NULL){
				fputs(argv[3],Res);
				int n = strlen(argv[3]);
				char *semilla = argv[3];
				imp(n,semilla);
				for(i=0;i<m;i++)
					aplirul(semilla,n,Res);		
				fclose(Res);
			}else
				perror("El archivo no se pudo crear u abrir");
	}else
		perror("Ingrese UNICAMENTE el nombre del archivo, el numero de iteraciones, la cadena ");
}
void aplirul(char *cadena_org,int num,FILE * file){
	int i;
	char cadena_Final[num];
	for (i=0;i<num;++i){
		if(i==0){
		cadena_Final[i] = Regla(cadena_org[num-1],cadena_org[i],cadena_org[i+1]);
		}else if(i == (num-1)){
		cadena_Final[i] = Regla(cadena_org[i-1],cadena_org[i],cadena_org[0]);
		}else if(i>0 && i<(num-1)){
		cadena_Final[i] = Regla(cadena_org[i-1],cadena_org[i],cadena_org[i+1]);
		}
	}
	imp(num,cadena_Final);
	for(i=0;i<num;i++){
		cadena_org[i]=cadena_Final[i];
	}
	fputs(cadena_org,file);
	fputs("\n",file);
}
void imp(int num,char *cad){
	int i;
	for (i=0;i<num;i++){
		if(i != (num-1))
			(cad[i] == '0')?printf("%s%c%s",BRED,cad[i],KNRM):printf("%s%c%s",BBLU,cad[i],KNRM);
		else
			(cad[i] == '0')?printf("%s%c%s\n",BRED,cad[i],KNRM):printf("%s%c%s\n",BBLU,cad[i],KNRM);
	}
}
char Regla (char n1,char n2,char n3){
	if(n1=='0'){
		if(n2=='0'){
			if(n3=='0'){
				return '0';
			}else if(n3=='1'){
				return '1';	
			}
		}else if(n2=='1'){
			return '1';
		}
	}else if(n1=='1'){
		if(n2=='0'){
			if(n3=='0'){
				return '0';
			}else if (n3=='1'){
				return '1';	
			}
		}else if(n2=='1'){
			if(n3=='0'){
				return '1';
			}else if (n3=='1'){
				return '0';	
			}
		}
			
	}
}
