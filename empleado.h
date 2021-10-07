#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <vector>
#include <string>
#include <sstream>

class Empleado{
    
    public:

        ~Empleado();
        virtual void agregueSupervisado(Empleado *supervisado);
        virtual void calculeMontoNeto(std::string &datos);
        double totales();
        virtual double subtotales();
        virtual double retenciones();
        std::string getNombre();
        std::string getApellido();

        friend std::ostream& operator << (std::ostream &o,const Empleado &e);

    protected:

        int id,id_supervisor;
        double montoNeto;
        std::string nombre,apellido,correo,nombre_supervisor,apellido_supervisor;
        std::vector<Empleado*>supervisados;

        Empleado();
        
        
};

#endif