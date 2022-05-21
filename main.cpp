#include <iostream>
#include <conio.h>
#include "Arbol.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Arbol arbolBinario;
	int numero;
	int opMenu;	 	
	 do{
        system("cls");//para borrar en pantalla cuando repita el menu
        cout<<"--Menu--"<<endl;
        cout<<"1. Insertar Nodo "<<endl;
        cout<<"2. Eliminar Nodo "<<endl;
        cout<<"3. Crear Arbol "<<endl;
        cout<<"4. Salir"<<endl<<endl;
        cout<<"INGRESE LA OPCION QUE DESEE REALIZAR: ";
        cin>>opMenu;

        switch (opMenu)
        {
            case 1:
            	cout<<"Ingrese un numero: ";
            	cin>>numero;
            	arbolBinario.insertar(numero);
                break;

            case 2:
            	cout<<"Ingrese el numero del nodo: ";
            	cin>>numero;
            	arbolBinario.eliminar(numero);
            	getch();
            	break;
            	
            case 3:
            	arbolBinario.generarDot();
            	arbolBinario.generarPNG();
            	arbolBinario.abrirPNG();
            	break;
        }

    }while(opMenu != 4);
	return 0;
}
