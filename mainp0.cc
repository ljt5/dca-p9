#include "p0.h"

int main(int argc, char **argv)
{
	int ej=1;
	int n=0;
	while(ej!=0){
		std::cout << "1 - Ej 1\n";
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
				
			default:
				ej=0;
				break;
		}
	}
	
	return 0;
}
