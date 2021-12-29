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
