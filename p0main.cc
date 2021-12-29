#include "p0.h"

int main(int argc, char **argv)
{
	int ej=1;
	int n=0;
	int maxV=0;
	int cont=0;
	while(ej!=0){
		std::cout << "1 - Ej 1\n";
		std::cout << "2 - Ej 2\n";
		std::cout << "0 - Salir\n";
		std::cout << "Introduce el Ej: ";
		std::cin >> ej;
	
		switch(ej){
			case 1:
				n=0;
				std::cout << "Introduce el número\n";
				std::cin >> n;
				if(multiple2or5not30(n)){
					std::cout <<"true\n";
				}
				else{
					std::cout <<"false\n";
				}
				break;
				
			case 2:{
				std::cout <<"Introduce el nº de elementos del vector:";
				std::cin >> maxV;
				int vector[maxV];
				for(cont=0;cont<maxV;cont++){
					std::cout <<"Introduce elemento nº"<< cont<< ": ";
					std::cin >> vector[cont];
				}
				std::cout <<"El vector:\n[";
				for(cont=0;cont<maxV;cont++){
					std::cout << vector[cont]<< " ";
				}
				std::cout <<"]\n";
				std::cout << "nº pares: "<< printPairs(vector, maxV)<<"\n";
			}
				break;
				
			default:
				ej=0;
				break;
		}
	}
	
	return 0;
}
