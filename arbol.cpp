#include "arbol.h"

Arbol::Arbol(){}

Arbol::~Arbol()
{
    delete this->director;
}

void Arbol::agregueDirector(std::string &datos)
{   
    int id{0};
    int tipo_empleado{0};
    std::string nombre{""};
    std::string apellido{""};
    std::string correo{""};
    
    std::istringstream procesador(datos);
    procesador >> id >> nombre >> apellido >> correo >> tipo_empleado;

    this->director = new EmpleadoPorNomina(id,id,nombre,apellido,correo,nombre,apellido);
    this->empleados.insert(std::pair<int,Empleado*>(id,director));
}

void Arbol::agregueEmpleado(std::string &datos)
{
    int id{0};
    int id_supervisor{0};
    int tipo_empleado{0};
    std::string nombre{""};
    std::string apellido{""};
    std::string correo{""};

    std::istringstream procesador(datos);
    procesador >> id >> nombre >> apellido >> correo >> tipo_empleado >> id_supervisor;

    Empleado * supervisor = this->empleados.at(id_supervisor);//Nodo padre
    Empleado *supervisado;//Empleado que se va a agregar; Nodo hijo

    std::string nombre_supervisor = supervisor->getNombre();
    std::string apellido_supervisor = supervisor->getApellido();

    if(tipo_empleado==1)
    {
        supervisado = new EmpleadoPorNomina(id,id_supervisor,nombre,apellido,correo,nombre_supervisor,apellido_supervisor);
    }
    else
    {
        supervisado = new EmpleadoPorHoras(id,id_supervisor,nombre,apellido,correo,nombre_supervisor,apellido_supervisor);
    }
    supervisor->agregueSupervisado(supervisado);
    this->empleados.insert(std::pair<int,Empleado*>(id,supervisado));
}

void Arbol::genereMonto(std::string &datos)
{
    int id {0};
    std::istringstream procesador(datos);
    procesador >> id;

    Empleado *empleado = this->empleados.at(id);
    empleado->calculeMontoNeto(datos);
}

std::string Arbol::resumen()
{
    double subtotal = this->director->subtotales();//solo nomina
    double retencion = this->director->retenciones();//solo nomina
    double total = this->director->totales();//montoNeto

    std::string resumen = "Resumen:\n\tSubtotal = "+std::to_string(subtotal)+"\n\tTotal Retenciones = "+std::to_string(retencion)+"\n\tTotal = "+std::to_string(total);
    return resumen; 
}

std::ostream& operator << (std::ostream &out, Arbol &arbol)
{
    Empleado *empleadoRaiz = arbol.director;
    std::string resumen = arbol.resumen();
    out << *empleadoRaiz;
    out << resumen;
    return out;
}
