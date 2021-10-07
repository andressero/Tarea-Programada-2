#ifndef ARBOL_H
#define ARBOL_H

#include <map>
#include <sstream>
#include <iostream>
#include "empleado.h"
#include "empleadoPorHoras.h"
#include "empleadoPorNomina.h"

class Arbol{
    private:
    
        Empleado *director;
        std::map<int,Empleado*> empleados;

    public:

        Arbol();
        ~Arbol();

        void agregueDirector(std::string &datos);
        void agregueEmpleado(std::string &datos);
        void genereMonto(std::string &datos);
        std::string resumen();

        friend std::ostream& operator << (std::ostream &o, Arbol &a);

};

#endif