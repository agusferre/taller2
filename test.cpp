#include <iostream>
#include <vector>
#include <cassert>
#include "Conjunto.hpp"


void test_remover(){
	Conjunto<int> ar;
	ar.agregar(3);
	assert(ar.cardinal() == 1);

	ar.agregar(5);
	ar.agregar(1);
	assert(ar.cardinal() == 3);
	assert(ar.maximo() == 5);
	assert(ar.minimo() == 1);
	ar.agregar(4);
	ar.agregar(2);
	ar.remover(3);
	std::cout << ar.maximo() << std::endl;

}






int main(){
	
test_remover();


	return 0;
}