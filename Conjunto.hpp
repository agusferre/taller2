#ifndef CONJUNTO_HPP_
#define CONJUNTO_HPP_

#include <iostream>
using namespace std;

template <class Elem>
class Conjunto
{
	public:

		// Constructor. Genera un conjunto vacío.
		Conjunto();

		// Destructor. Debe dejar limpia la memoria.
		~Conjunto();

		// Inserta un elemento en el conjunto. Si éste ya existe,
		// el conjunto no se modifica.
		void agregar(const Elem&);

		// Decide si un elemento pertenece al conjunto o no.
		bool pertenece(const Elem&) const;

		// Borra un elemento del conjunto. Si éste no existe,
		// el conjunto no se modifica.
		void remover(const Elem&);

		// Devuelve el mínimo elemento del conjunto según <.
		const Elem& minimo() const;

		// Devuelve el máximo elemento del conjunto según <.
		const Elem& maximo() const;

		// Devuelve la cantidad de elementos que tiene el conjunto.
		unsigned int cardinal() const;

		// Muestra el conjunto como una secuencia ordenada de menor a mayor.
    // por ejemplo:
    //  {3,2,5,1,6}.to_string() = "1 2 3 5 6 "
    //  {}.to_string() == " "
    //  Sin las comillas
    //  Hint: pueden usar estructuras adicionales para resolverlo (o no)
		void to_string(std::ostream&) const;

    std::string show() const {
    std::ostringstream os;
   	os << "{ ";
   	// complete
   	os << "}" << std::endl;
    

    //  os << *this;
      return os.str();	

    }

friend ostream& operator<<(ostream& os, const Conjunto<Elem> &c) {
	c.to_string(os);
	return os;
}

	private:

		// La representación de un nodo interno.
		struct Nodo {
			// El constructor, toma el elemento al que representa el nodo.
			Nodo(const Elem& v);
			// El elemento al que representa el nodo.
			Elem valor;
			// Puntero a la raíz del subárbol izq.
			Nodo* izq;
			// Puntero a la raíz del subárbol der.
			Nodo* der;


            unsigned int cantElems();


        };

		// Puntero a la raíz de nuestro árbol.
    // Pueden completarlo con más variables
		Nodo* raiz_;
		unsigned int cardinal_;


};

template <class Elem>
Conjunto<Elem>::Nodo::Nodo(const Elem& v) : valor(v), izq(NULL), der(NULL) {}

template <class Elem>
unsigned int Conjunto<Elem>::Nodo::cantElems(){
    unsigned int res = 0;
    if (this != NULL) {
        res += 1 + izq->cantElems() + der->cantElems();
    }
    return res;
}

template <class Elem>
Conjunto<Elem>::Conjunto() : raiz_(NULL) { 
cardinal_ = 0;}

template <class Elem>
Conjunto<Elem>::~Conjunto() {
	while(raiz_ != NULL){
		remover(maximo());
	}
}

template <class Elem>
bool Conjunto<Elem>::pertenece(const Elem& clave) const {
		Nodo* indice = raiz_;
    bool booleanoFormalDeAlgo2 = false;
    while (indice != NULL){
        if (clave == indice->valor) booleanoFormalDeAlgo2 = true;
        if (clave < indice->valor) indice = indice->izq;
        else indice = indice->der;
    }
    return booleanoFormalDeAlgo2;
}

template <class Elem>
void Conjunto<Elem>::agregar(const Elem& clave) {
   
    if (!pertenece(clave)){
     Nodo* nuevo = new Nodo(clave);
    
    Nodo* kaka = raiz_;
    if (raiz_ == NULL) raiz_ = nuevo;
    while (not pertenece(clave)) {
        if (kaka->valor < clave) {
            if (kaka->der == NULL){
            	kaka->der = nuevo;

         } else 
            	kaka = kaka->der;
        } else {
            if (kaka->izq == NULL){
            	kaka->izq = nuevo;

            }
           else kaka = kaka->izq;
        }
            
    }
    cardinal_++;
}
}

template <class Elem>
unsigned int Conjunto<Elem>::cardinal() const {
    //unsigned int res = 0;
    //if (raiz_ != NULL){
     //   res += 1 + raiz_->der->cantElems() + raiz_->izq->cantElems();
    //}
    //return res;
	return cardinal_;
}

template <class Elem>
void Conjunto<Elem>::remover(const Elem& clave) {
		 // if (pertenece(clave)){
			// Nodo* padre;
			// Nodo* rm;
			// 	if (raiz_->valor != clave) {
			// 		//Nodo* padre = raiz_;
			// 		padre = raiz_;
			// 		// BUSCO EL VALOR A BORRAR
			// 		while (not (padre->der != NULL && padre->der->valor == clave) || 
			// 			(padre->izq != NULL && padre->izq->valor == clave)) {
			// 			if (padre->valor < clave)
			// 				padre = padre->izq;
			// 			else
			// 	  		padre = padre->der;
			//   	}
			//   		// SI EL NODO RM TIENE 1 o 0 HIJOS
			//   		if (padre->der->valor == clave)
			//   			rm = padre->der;
			//   		else
			//   			rm = padre->izq;


			// 		if (rm->der == NULL && rm->izq != NULL){
			// 			if 	(padre->der == rm)
			// 				padre->der = rm->izq;
			// 			else 	
			// 				padre->izq = rm->izq;
			// 			rm->izq = NULL;
		
			// 			delete rm;
			// 		} else if (rm->izq == NULL && rm->der != NULL) {
 		// 				if (padre->der == rm)
			// 				padre->der = rm->der;
			// 			else 	
			// 				padre->izq = rm->der; 							
			// 			rm->der = NULL;

			// 			delete rm;

			// 	}


			// 	} else {
			// 		rm = raiz_;
			// 			if (rm->der == NULL){
			// 				raiz_ = rm->izq;
			// 				rm->izq = NULL;
;
			// 				delete rm;

			// 			} else if (rm ->izq == NULL){
			// 			raiz_ = rm->der;

			// 			rm->der = NULL;
			// 			delete rm;
			// 	}		

			// 	} 
			// 	// 

			// 	if (rm->der != NULL && rm->izq != NULL){
			// 			Nodo* padre_sucesor;
			// 			Nodo* sucesor;
			// 				if (rm->der->izq != NULL) {
			// 				padre_sucesor = rm->der;
			// 					while (padre_sucesor->izq->izq != NULL)
			// 					padre_sucesor = padre_sucesor->izq;
			// 				sucesor = padre_sucesor->izq;
			// 				padre_sucesor->izq = sucesor->der;
			// 				} else {
			// 				padre_sucesor = rm;
			// 				sucesor = padre_sucesor->der;
			// 				rm->valor = sucesor->valor;
			// 				padre_sucesor->der = sucesor->der;
			// 			}
			// 				sucesor->der = NULL;
			// 				sucesor->izq = NULL;

			// 				delete sucesor;
			// 			}
			// 			cardinal_--;
			// 		}
if (pertenece(clave)){
	Nodo* rm = raiz_;
	Nodo* padre = raiz_;
	while (rm->valor != clave){
		if (rm->valor < clave ){
			rm = rm->der;
			if (rm->valor != clave) padre=padre->der;
		} else {
			rm = rm->izq;
			if(rm->valor !=clave) padre = padre->izq;
		}
	}
	//encontre el nodo a borrar, evaluo casos:
	//un hijo A LO SUMO:
	 if (rm->der == NULL){
	 
		if (raiz_->valor != clave){
			if (padre->valor < clave){
			padre->der = padre->der->izq;
			} else { 
			padre->izq = padre->izq->izq;
			}
		} else { 
		raiz_ = raiz_->izq;
	}
	rm->izq = NULL;

	delete rm;
	
	}
	else if (rm->izq == NULL){
	
			if (raiz_->valor != clave){
				if (padre->valor < clave)
					padre->der = padre->der->der;
				else
					padre->izq = padre->izq->der;
				
			} else {
				raiz_ = raiz_->der;
			}
			rm->der = NULL;

			delete rm;
	} else {
	// caso dos hijos (rm tiene izq y der) :
	// busco el sucesor inmediato
		Nodo* sucesor = rm-> der;
		Nodo* padreDeSucesor;
		if (rm->der->izq == NULL)
			padreDeSucesor = rm;
		else 
			padreDeSucesor = rm->der;
				
		while (sucesor->izq != NULL){
		sucesor = sucesor->izq;
		if (sucesor->izq != NULL) padreDeSucesor = padreDeSucesor->izq;
		}
		// encontre el sucesor. pego el padre del sucesor con el hijo del sucesor (puede ser null)
		if (padreDeSucesor != rm){
			padreDeSucesor->izq = padreDeSucesor->izq->der;
		} else {
			padreDeSucesor->der = padreDeSucesor->der->der;
		}
		// cambio los valores y borro el sucesor
		
		rm->valor = sucesor->valor;
		sucesor->der = NULL;
		sucesor->izq = NULL;

		delete sucesor;	
	}
	cardinal_--;
	}



}

template <class Elem>
const Elem&  Conjunto<Elem>::minimo() const {
	Nodo* indice = raiz_;
	while (indice->izq != NULL)
	 	indice = indice->izq;
  return indice->valor;
}

template <class Elem>
const Elem&  Conjunto<Elem>::maximo() const {
	Nodo* indice = raiz_;
	while (indice->der != NULL)
	 	indice = indice->der;
	return indice->valor;
}

template <class Elem>
void Conjunto<Elem>::to_string(std::ostream& os) const {
	//Nodo* indice = raiz_;
	//while (indice != NULL) {
		//os << maximo();
//		remover(maximo());
	}




#endif // CONJUNTO_HPP_
