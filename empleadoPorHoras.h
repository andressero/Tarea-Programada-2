#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"

class EmpleadoPorHoras: public Empleado {

    private:

        double montoPorHora, horasTrabajadas;

    public:

        EmpleadoPorHoras(int id, int id_supervisor,std::string nombre,std::string apellido,std::string correo,std::string nombre_supervisor,std::string apellido_supervisor);
        void agregueSupervisado(Empleado *empleado);
        void calculeMontoNeto(std::string &datos);
        double subtotales();
        double retenciones();

        

};

#endif