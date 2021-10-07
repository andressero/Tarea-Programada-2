#include "empleado.h"

Empleado::Empleado(){}

Empleado::~Empleado()
{
    for(Empleado *supervisado : supervisados)
    {
        delete supervisado;
    }
}


void Empleado::agregueSupervisado(Empleado *supervisado){}
void Empleado::calculeMontoNeto(std::string &datos){}

std::string Empleado::getNombre()
{
    return this->nombre;
}
std::string Empleado::getApellido()
{
    return this->apellido;
}

double Empleado::totales()
{
    double totales = this->montoNeto;

    for(Empleado *empleado : supervisados)
    {
        totales+= empleado->totales();
    }
    return totales;
}

double Empleado::subtotales(){return 0.0;}
double Empleado::retenciones(){return 0.0;}

std::ostream& operator << (std::ostream& out, const Empleado &empleado)
{
    out << empleado.id << ",";
    out << empleado.nombre << " " << empleado.apellido << ",";
    out << empleado.nombre_supervisor << " " << empleado.apellido_supervisor << ",";
    out << empleado.montoNeto << std::endl;
    
    for(Empleado *supervisado : empleado.supervisados)
    {
        out << *supervisado;
    }

    return out;
}