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

