#ifndef EMPLEADOPORNOMINA_H
#define EMPLEADOPORNOMINA_H

#include "empleado.h"

class EmpleadoPorNomina : public Empleado {
    private:

        double montoBruto,retencion;

    public:

        EmpleadoPorNomina(int id,int id_supervisor,std::string nombre,std::string apellido,std::string correo,std::string nombre_supervisor,std::string apellido_supervisor);
        void agregueSupervisado(Empleado *empleado);
        void calculeMontoNeto(std::string &datos);
        double subtotales();
        double retenciones();

        //friend std::ostream& operator << (std::ostream &o,const EmpleadoPorNomina &e);
};

#endif