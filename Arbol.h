#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include "conio.h"
#include "fstream"
#include "windows.h"
#include "Nodo.h"
using namespace std;

class Arbol
{
	private:
		Nodo *raiz;
	public:
		Arbol();
		ofstream archivo;
		bool estadoArbol();
		void insertar(int);
		void buscarPosicion(Nodo *,int);
		Nodo * buscarNodo(int,Nodo *);
		void eliminar(int);
		void eliminarNodo(Nodo *);
	 	Nodo * encontrarMinimo(Nodo *);
	 	void intercambiarNodo(Nodo*,Nodo*);
	 	void olvidarNodo(Nodo *);
		
		void preorden(Nodo *);
		void inorden(Nodo *);
		void postorden(Nodo *);
		
		void crearArbol(Nodo *);
		void generarDot();
		void generarPNG();
		void abrirPNG();
		~Arbol();
	protected:
};

#endif
