#include "Arbol.h"

Arbol::Arbol()
{
	this->raiz = NULL;
}

// verficacion actual del arbol binario
bool Arbol::estadoArbol()
{
	if(this->raiz==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// metodo para insertar un nuevo nodo
void Arbol::insertar(int dato)
{
	if(estadoArbol()==true)
	{
		Nodo *nuevoElemento = new Nodo(dato);
		this->raiz = nuevoElemento;
	}
	else 
	{
		buscarPosicion(this->raiz,dato);
	}
}

// metodo recuersivo para buscar posicion donde poder insertar un nodo
void Arbol::buscarPosicion(Nodo *nodo,int dato)
{
	// 1. elementos iguales
	// 2. nuevo elemento sea mayor
	// 3. nuevo elemento sea menor
	if(dato < nodo->getDato())
	{
		if(nodo->getIzquierda()==NULL)
		{
			Nodo *nuevoElemento = new Nodo(dato);
			nodo->setIzquierda(nuevoElemento);
			nuevoElemento->setPadre(nodo);
		}
		else
		{
			nodo = nodo->getIzquierda();
			buscarPosicion(nodo,dato);
		}
	}
	else if(dato > nodo->getDato())
	{
		if(nodo->getDerecha()==NULL)
		{
			Nodo *nuevoElemento = new Nodo(dato);
			nodo->setDerecha(nuevoElemento);
			nuevoElemento->setPadre(nodo);
		}
		else
		{
			nodo = nodo->getDerecha();
			buscarPosicion(nodo,dato);
		}
	}
}



// eliminacion del nodo
void Arbol::eliminar(int dato)
{
	if(estadoArbol()==true)
	{
		cout<<"No hay nodos en el arbol"<<endl;
	}
	else
	{
		Nodo *auxRaiz = this->raiz;
		eliminarNodo(buscarNodo(dato,auxRaiz));
	}	
}

// buscar un nodo dentro del arbol
Nodo * Arbol::buscarNodo(int dato,Nodo *nodo)
{
	if(dato < nodo->getDato())
	{
		return buscarNodo(dato,nodo->getIzquierda());
	}
	else if(dato > nodo->getDato())
	{
		return buscarNodo(dato,nodo->getDerecha());
	}
	else
	{
		cout<<"Nodo encontrado"<<endl; // hemos encontrado el nodo que buscamos
		return nodo;
		//eliminarNodo(nodo);
	}
}

// eliminacion del nodo encontrado
void Arbol::eliminarNodo(Nodo *nodoEncontrado)
{
	// nodo padre con ambos hijos
	if(nodoEncontrado->getIzquierda()!=NULL && nodoEncontrado->getDerecha()!= NULL)
	{
		Nodo *nodoMinimo = encontrarMinimo(nodoEncontrado->getDerecha());
		nodoEncontrado->setDato(nodoMinimo->getDato());
		eliminarNodo(nodoMinimo);
	}
	else if(nodoEncontrado->getIzquierda() != NULL && nodoEncontrado->getDerecha() == NULL)
	{
		intercambiarNodo(nodoEncontrado,nodoEncontrado->getIzquierda());
		olvidarNodo(nodoEncontrado);
	}
	else if(nodoEncontrado->getDerecha() != NULL && nodoEncontrado->getIzquierda() == NULL)
	{
		intercambiarNodo(nodoEncontrado,nodoEncontrado->getDerecha());
		olvidarNodo(nodoEncontrado);
	}
	else
	{	
		intercambiarNodo(nodoEncontrado,NULL);
		olvidarNodo(nodoEncontrado);
	}
}

//
void Arbol::intercambiarNodo(Nodo *nodoOrigen,Nodo *predecesor)
{
	if(nodoOrigen->getPadre()!=NULL)
	{
		Nodo *nodoPadre = nodoOrigen->getPadre();
		if(nodoOrigen == nodoPadre->getIzquierda())
		{
			nodoPadre->setIzquierda(predecesor);
		}
		else if(nodoOrigen == nodoPadre->getDerecha())
		{
			nodoPadre->setDerecha(predecesor);
		}	
	}
	else
	{// NODO RAIZ
		this->raiz = NULL;
	}
	
	if(predecesor!=NULL)
	{
		predecesor->setPadre(nodoOrigen->getPadre());
	}
}

//
void Arbol::olvidarNodo(Nodo *nodo)
{
	nodo->setIzquierda(NULL);
	nodo->setDerecha(NULL);
	nodo->setPadre(NULL);
	delete nodo;
}

// buscar el nodo minimo con respecto a otro nodo hoja
// predecesor al hijo que deciendo del nodo
Nodo * Arbol::encontrarMinimo(Nodo *nodo)
{
	if(nodo->getIzquierda()!=NULL)
	{
		return encontrarMinimo(nodo->getIzquierda());
	}
	else
	{
		return nodo;
	}
}

// metodo crear todos los nodos del arbol
void Arbol::crearArbol(Nodo *inicio)
{
	if (inicio != NULL)
	{
		// ejemplo: nodo0 [label = "<C0>|dato|<C1>"];        
        archivo<<"nodo"<<inicio->getDato()<<"[ label = "<<inicio->getDato()<<"]; "<<endl;
        if(inicio->getIzquierda() != NULL)
		{
            Nodo *nodoIzquierdo = inicio->getIzquierda();
            archivo<<"nodo"<<inicio->getDato()<<"->nodo"<<nodoIzquierdo->getDato()<<endl;
            crearArbol(inicio->getIzquierda());
        }
        if(inicio->getDerecha() != NULL)
		{
            Nodo *nodoDerecho = inicio->getDerecha();
            archivo<<"nodo"<<inicio->getDato()<<"->nodo"<<nodoDerecho->getDato()<<endl;
            crearArbol(inicio->getDerecha());
        }
    }
}

// metodo para recorrido preorden
// raiz-izquierda-derecha
void Arbol::preorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		cout<<"nodo: "<<nodo->getDato()<<"--->"<<endl;
		preorden(nodo->getIzquierda());
		preorden(nodo->getDerecha());
	}
}

// metodo para recorrido postorden
// izquierda-derecha-raiz
void Arbol::postorden(Nodo *nodo)
{
	if(nodo != NULL)
	{		
		postorden(nodo->getIzquierda());
		postorden(nodo->getDerecha());
		cout<<"nodo: "<<nodo->getDato()<<"--->"<<endl;
	}
}

// metodo para recorrido inorden
// izquierda-raiz-derecha
void Arbol::inorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		inorden(nodo->getIzquierda());
		cout<<"nodo: "<<nodo->getDato()<<"--->"<<endl;
		inorden(nodo->getDerecha());
	}
}

// metodo para genera el archivo dot 
void Arbol::generarDot()
{	
	archivo.open("Tree\\Arbol.dot",ios::out);
	if(archivo.fail())
	{
		cout<<"No se puede abrir el archivo"<<endl;
	}
	else
	{
		archivo<<"digraph arbol"<<endl;
		archivo<<"{"<<endl;
		archivo<<"rankdir=TB;"<<endl;
		crearArbol(this->raiz);
		archivo<<"label = \" Arbol Binario \" "<<endl;
		archivo<<"}"<<endl;
		archivo.close();
	}
}

// metodo para la conversion del dot a png
void Arbol::generarPNG()
{
	system("dot.exe -Tpng Tree\\Arbol.dot -o Tree\\Arbol.png");
}

// metodo para aperturar la imagen png
void Arbol::abrirPNG()
{
	system("Tree\\Arbol.png");
}

Arbol::~Arbol()
{
}
