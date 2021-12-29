#include "p0.h"

int main(int argc, char **argv)
{
	int ej=1;
	int n=0;
	int maxV=0;
	int cont=0;
	char a[]="berenjena\0";
	char b[]="hola\0";
	char cad[100];
	char c='n';
	char sus[]="hola";
	while(ej!=0){
		std::cout << "1 - Ej 1\n";
		std::cout << "2 - Ej 2\n";
		std::cout << "3 - Ej 3\n";
		std::cout << "4 - Ej 4\n";
		std::cout << "5 - Ej 5\n";
		std::cout << "6 - Ej 6\n";
		std::cout << "7 - Ej 7\n";
		std::cout << "8 - Ej 8\n";
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
				
			case 3:
				n=0;
				std::cout << "Introduce altura del triángulo: ";
				std::cin >> n;
				triangle(n);
				break;
				
			case 4:
				n=0;
				std::cout << "Introduce posición nº primo: ";
				std::cin >> n;
				std::cout << nPrime(n) << "\n";
				break;
				
			case 5:
				n=0;
				std::cout << "Introduce nº a descomponer: ";
				std::cin >> n;
				deco(n);
				break;
				
			case 6:{
				std::cout <<"Introduce el nº de elementos del vector:";
				std::cin >> maxV;
				int v[maxV];
				int iv[maxV];
				for(cont=0;cont<maxV;cont++){
					std::cout <<"Introduce elemento nº"<< cont<< ": ";
					std::cin >> v[cont];
				}
				for(int i=0;i<maxV;i++){
					iv[i]=0;
				}
				std::cout << odds(v, maxV, iv) << "\n";
				for(cont=0;cont<maxV;cont++){
					std::cout << iv[cont]<< " ";
				}
				std::cout << "\n";
			}
				break;
				
			case 7:
				std::cout << search(a,b) << "\n";
				break;
				
			case 8:
				std::cout << "Introduce la cadena: ";
				std::cin >> cad;
				std::cout << "\n";
				std::cout << "Introduce el caracter: ";
				std::cin >> c;
				std::cout << "\n";
				std::cout << "Introduce la sustituta: ";
				std::cin >> sus;
				std::cout << "\n";
				std::cout << "Longitud cad: " << strlen(cad) << "\n";
				subs(cad,c,sus);
				break;
				
			default:
				ej=0;
				break;
		}
	}
	
	return 0;
}
