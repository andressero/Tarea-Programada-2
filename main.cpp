#include <iostream>
#include <fstream>
#include "arbol.h"
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoPorNomina.h"

using namespace std;
int main()
{
    Arbol *arbol = new Arbol();
    string linea {};
    
    //1. "Personas.txt"
    ifstream lectorPersonas("/home/andres/Desktop/Test/Homework/Emergency/obj/Personas.txt",ifstream::in);
    if(!lectorPersonas.is_open()){cerr << "No logró abrirse \"Personas.txt\"" << endl;return -1;}

    getline(lectorPersonas,linea);
    arbol->agregueDirector(linea);

    while(getline(lectorPersonas,linea))
    {
        arbol->agregueEmpleado(linea);
    }

    lectorPersonas.close();

    //2. "Nomina.txt"
    ifstream lectorNomina("/home/andres/Desktop/Test/Homework/Emergency/obj/Nomina.txt",ifstream::in);
    if(!lectorNomina.is_open()){cerr << "No logró abrirse \"Nomina.txt\"" << endl;return -1;}

    while(getline(lectorNomina,linea))
    {
        arbol->genereMonto(linea);
    }

    lectorNomina.close();

    //3. "HorasTrabajadas.txt"
    ifstream lectorHoras("/home/andres/Desktop/Test/Homework/Emergency/obj/HorasTrabajadas.txt",ifstream::in);    
    if(!lectorHoras.is_open()){cerr << "No logró abrirse \"HorasTrabajadas.txt\"" << endl;return -1;}

    while(getline(lectorHoras,linea))
    {
        arbol->genereMonto(linea);
    }

    lectorHoras.close();

    //4. Salida
    ofstream escritor("/home/andres/Desktop/Test/Homework/Emergency/obj/Reporte.csv",ostream::out);
    escritor << *arbol;
    escritor.close();

    delete arbol;
}