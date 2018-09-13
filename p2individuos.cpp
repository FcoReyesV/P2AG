#include <iostream>
#include <stdlib.h>     
#include <time.h>       
#include <iomanip>
using namespace std;

void decToBin(int num){//Decimal a binario
	int dividendo, resto, divisor = 2,i=9;
 	int bin[10];
 	dividendo = num;
 	for(int k=0;k<10;k++)
 		bin[k]=0;
 
 	while(dividendo >= divisor){ 
		resto = dividendo % 2;
		if(resto == 1)
			bin[i] = 1; 
		else
	   		bin[i] = 0; 
		dividendo = dividendo/divisor; 
		i--;
 	}
  	if(dividendo == 1)
   		bin[i] = 1;
  	else
   		bin[i] = 0;
   	for(int j=0;j<10;j++){
		cout<<bin[j]<<"|";
	}
}

void rBinaria(){
	int alelo, rbin[10];
	srand (time(NULL));
	cout<<"Representacion Binaria"<<endl;
	for(int i=0;i<10;i++){
		alelo = rand() % 2;
		rbin[i] = alelo;
		cout<<rbin[i]<<"|";
	}
}

void rGray(){ //2^10= 1024 
	int num,numgray,rgray[10];
	srand (time(NULL));
	num= rand() % 1024+1;
	numgray= num ^ (num >> 1); //Desplazamos el bit y aplicamos xor
	cout<<"Codificacion de Gray"<<endl;
	cout<<"Binario: "<<endl;
	decToBin(num);
	
	cout<<endl<<"Gray: "<<endl;
	decToBin(numgray);
}

void rDecimal(){
	float alelo, rdec[10];
	srand (time(NULL));
	cout<<"Codificacion en numeros reales"<<endl;
	cout << fixed << setprecision(2) << endl;
	for(int i=0;i<10;i++){
		alelo = ((rand() % 10000 + 1)/(float)100);
		rdec[i]=alelo;
		cout<<rdec[i]<<"|";
	}
}

void rEntero(){
	int alelo, rent[10];
	srand (time(NULL));
	cout<<"Codificacion en numeros enteros"<<endl;
	for(int i=0;i<10;i++){
		alelo = (rand() % 100 + 1);
		rent[i]=alelo;
		cout<<rent[i]<<"|";
	}
}


int main(int argc, char** argv) {
	int opc;
	char res;
	bool menu=true;
	do{
		cout<<"Practica 2: Representacion de individuos"<<endl;
		cout<<"1.- Representacion Binaria"<<endl<<"2.- Codificacion de Gray"<<endl<<"3.- Codificacion en numeros reales"<<endl<<"4.- Codificacion en numeros enteros"<<endl<<"5.- Salir"<<endl;
		cout<<"Escoge una opcion: ";
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
			
				rBinaria();
				break;
			case 2:
				rGray();
				break;
			case 3:
				rDecimal();
				break;
			case 4:
				rEntero();
				break;
			case 5:
				exit(0);
				break;
		}
		cout<<endl<<"Desea volver al menu?(s/n)"<<endl;
		cin>>res;
		system("cls");
	}while(res=='s');
	return 0;
}
