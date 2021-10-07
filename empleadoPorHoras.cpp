#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(int id,int id_supervisor,std::string nombre,std::string apellido,std::string correo,std::string nombre_supervisor,std::string apellido_supervisor)
{
    this->id = id;
    this->id_supervisor = id_supervisor;
    this->nombre = nombre;
    this->apellido = apellido;
    this->correo = correo;
    this->nombre_supervisor=nombre_supervisor;
    this->apellido_supervisor = apellido_supervisor;
}

void EmpleadoPorHoras::calculeMontoNeto(std::string &datos)
{
    int id {0};// <-- inutil

    std::istringstream stream(datos);
    stream >> id >> this->montoPorHora >> this->horasTrabajadas;

    this->montoNeto = this->montoPorHora * this->horasTrabajadas;
}

void EmpleadoPorHoras::agregueSupervisado(Empleado *empleado)
{
    this->supervisados.push_back(empleado);
}

double EmpleadoPorHoras::subtotales(){return 0.0;}
double EmpleadoPorHoras::retenciones(){return 0.0;}