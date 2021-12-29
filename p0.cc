#include "p0.h"


//  1
/** Devuelve 'true' si 'n' es un entero positivo múltiplo de 2 o 5 pero
 *  no de 30.
 **/
bool multiple2or5not30(int n){
	if(n<=0){
		return false;
	}
	else if(n%30==0){
		return false;
	}
	else if(n%2==0||n%5==0){
		return true;
	}
	else
		return false;
}

//  2
/** Imprime en pantalla los números pares de un vector 'v[]' hasta que
 *  llega a un 51. Devuelve el número de pares que ha impreso por
 *  pantalla. Debe usar un único 'for' o 'while' y terminar el bucle con
 *  una variable booleana
 **/
int printPairs(int v[], int maxV){
	bool reached51 = false;
	int ret = 0;
	for(int count=0;count<maxV&&!reached51;count++){
		if(v[count]==51){
			reached51=true;
		}
		else if(v[count]%2==0){
			ret++;
		}
	}
	return ret;
}

//  3
/** Imprime un triángulo de altura 'n' como en los ejemplos.
 **/
void triangle(int n){
	int i=0;
	int j=0;
	if(n<0){
		return;
	}
	for(i=1;i<n;i++){
		std::cout <<"*";
		for(j=1;j<i;j++){
			if(j!=i-1){
				std::cout <<" ";
			}
			else{
				std::cout <<"*";
			}
		}
		std::cout <<"\n";
	}
	for(i=0;i<n;i++){
		std::cout <<"*";
	}
	std::cout <<"\n";
	return;
}

/** Comprueba si un número es primo. Devuelve 'true' si es primo, 
 *  o 'false' en caso contrario
 **/
 bool isPrime(int n){
	 int count = 0;
	 bool isPrime = true;
	 if(n<2){
		 return false;
	 }
	 else{
		 for(count=n-1;count>1;count--){
			 if(n%count==0){
				 isPrime=false;
				 break;
			 }
		 }
		 return isPrime;
	 }
 }

//  4
/** Dado un número 'n' devuelve el n-ésimo nº primo
 **/
 int nPrime(int n){
	 int count=0;
	 int ret=0;
	 int oldPrime = 0;
	 for(count=0;count<n;count++){
		 oldPrime=ret;
		 while(!isPrime(ret)||ret==oldPrime){
			 ret++;
		 }
	 }
	 return ret;
 } 
