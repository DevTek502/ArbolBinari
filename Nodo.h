#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo
{
	private:
		int dato;
		Nodo *izquierda;
		Nodo *derecha;
		Nodo *padre;
	public:
		Nodo(int);
		int getDato();
		Nodo * getIzquierda();
		Nodo * getDerecha();
		Nodo * getPadre();
		void setDato(int);
		void setIzquierda(Nodo *);
		void setDerecha(Nodo *);
		void setPadre(Nodo *);
		~Nodo();
	protected:
};

#endif
