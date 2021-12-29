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
		if(v[count]%2==0){
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
 
 //  5 
/** Dado un número entero positivo imprime la descomposición del nº en
 *  factores primos
 **/ 
void deco(int n){
	int count=0;
	if(n<0){
		std::cout << "Error\n";
	}
	else if(isPrime(n)){
		std::cout << n << " ";
	}
	else if(n==0){
		std::cout << "0 ";
	}
	else if(n==1){
		std::cout << "1 ";
	}
	else{
		while(n!=1){
			for(count=1;nPrime(count)<=n;count++){
				if(n%nPrime(count)==0){
					n=n/nPrime(count);
					std::cout << nPrime(count) << " ";
					break;
				}
			}
		}
	}
	return;
}

//  6
/** Obtiene los números impares del vector 'v' y los almacena en 'iv'.
 *  Devuelve la cantidad de números impares encontrados. Además, 'n' es
 *  el número de elementos de los vectores 'v' y 'iv'
 **/
int odds(int v[], int n, int iv[]){
	int count=0;
	int ret=0;
	int ivPosition=0;
	for(count=0;count<n;count++){
		iv[count]=0;
	}
	for(count=0;count<n;count++){
		if(v[count]%2!=0){
			iv[ivPosition]=v[count];
			ivPosition++;
			ret++;
		}
	}
	return ret;
}

//  7
/** Encuentra la primera aparición de la cadena 'b' en la cadena 'a' y
 *  devuelve su posición
 **/
int search(char a[], char b[]){
	unsigned int counta=0;
	unsigned int countb=0;
	int ret=-2;
	if(strlen(b)>strlen(a)){
		return -1;
	}
	else{
		for(counta=0;counta<strlen(a);counta++){
			if(a[counta]==b[0]){
				for(countb=1;countb<strlen(b);countb++){
					if(a[counta+countb]!=b[countb]){
						ret=-1;
					}
				}
				if(ret!=-1){
					ret=counta;
				}
			}
			if(ret>=0){
				break;
			}
			else{
				ret=-2;//El valor vuelve a ser -2 para evitar problemas
			}
		}
		if(ret<0){
			ret=-1;
		}
		return ret;
	}
}

//  8
/** Dada una cadena 'cad[]', sustituye los carácteres 'c' por la cadena
 *  'sus[]'. Se asume que la cadena original tiene espacio suficiente 
 *  para almacenar la cadena resultante de la sustitucion 
 **/
int subs(char cad[], char c, char sus[]){
	unsigned int i=0;
	unsigned int j=0;
	unsigned int k=0;
	char end[1]="";
	int ret=0;
	char aux[strlen(cad)+1];
	for(i=0;i<=strlen(cad);i++){
		aux[i]=cad[i];
	}
	
	std::cout << "Longitud de cad[]: "<< strlen(cad) << "\n";
	for(i=0;i<strlen(cad);i++){
		std::cout << cad[i] << "\n";
	}
	std::cout << "Longitud de aux[]: "<< strlen(aux) << "\n";
	for(i=0;i<strlen(aux);i++){
		std::cout << aux[i] << "\n";
	}
	for(i=0;i<strlen(aux);i++){
		if(aux[i]==c){
			for(j=0;j<strlen(sus);j++){
				cad[i+j]=sus[j];
				for(unsigned int count=0;count<strlen(aux);count++){
					std::cout << cad[count];
				}
				std::cout << "\n";
			}
			ret++;
			for(k=0;k<strlen(aux)-i-1;k++){
				cad[i+ret*strlen(sus)+k]=aux[i+k+1];
				cad[i+ret*strlen(sus)+k+1]=end[0];
				for(unsigned int count=0;count<strlen(aux);count++){
					std::cout << cad[count];
				}
				std::cout << "\n";
			}
		}
	}	
	std::cout << cad << "\n";
	std::cout << aux << "\n";
	std::cout << ret << "\n";
	return ret;
}

