#include "Nodo.h"

Nodo::Nodo(int dato)
{
	this->dato = dato;
	this->izquierda = NULL;
	this->derecha = NULL;
	this->padre = NULL;
}

int Nodo::getDato()
{
	return dato;
}

Nodo * Nodo::getIzquierda()
{
	return izquierda;
}

Nodo * Nodo::getDerecha()
{
	return derecha;
}

Nodo * Nodo::getPadre()
{
	return padre;
}

void Nodo::setDato(int dato)
{
	this->dato = dato;
}

void Nodo::setIzquierda(Nodo *nodoIzquierda)
{
	this->izquierda = nodoIzquierda;
}

void Nodo::setDerecha(Nodo *nodoDerecha)
{
	this->derecha = nodoDerecha;
}

void Nodo::setPadre(Nodo *nodoPadre)
{
	this->padre = nodoPadre;
}

Nodo::~Nodo()
{
}
