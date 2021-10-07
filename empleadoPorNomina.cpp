#include "empleadoPorNomina.h"

EmpleadoPorNomina::EmpleadoPorNomina(int id, int id_supervisor,std::string nombre,std::string apellido,std::string correo,std::string nombre_supervisor,std::string apellido_supervisor)
{
    this->id = id;
    this->id_supervisor = id_supervisor;
    this->nombre = nombre;
    this->apellido = apellido;
    this->correo = correo;
    this->nombre_supervisor = nombre_supervisor;
    this->apellido_supervisor = apellido_supervisor;

}

void EmpleadoPorNomina::calculeMontoNeto(std::string &datos)
{
    int id {0};//<-- inutil

    std::istringstream stream(datos);
    stream >> id >> this->montoBruto;
    this->retencion = this->montoBruto * (7.0/100.0);
    this->montoNeto = this->montoBruto - this->retencion;
}

void EmpleadoPorNomina::agregueSupervisado(Empleado * empleado)
{
    this->supervisados.push_back(empleado);
}

double EmpleadoPorNomina::subtotales()
{
    double subtotales = this->montoBruto;

    for(Empleado *empleado : this->supervisados)
    {
        subtotales += empleado->subtotales();
    }

    return subtotales;
}

double EmpleadoPorNomina::retenciones()
{
    double retenciones = this->retencion;

    for(Empleado *empleado : this->supervisados)
    {
        retenciones += empleado->retenciones();
    }
    return retenciones;
}