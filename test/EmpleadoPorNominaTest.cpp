#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../empleadoPorNomina.h"
//#include "../empleado.h"

namespace {
    TEST(EmpleadoNominaTest,StringsCorrectos){
        std::ifstream lector("Personas.txt",std::ifstream::in);
        std::string linea{};
        getline(lector,linea);

        int id {0}; int id_supervisor {0};
        std::string nombre {""}; std::string apellido {""}; std::string correo {""};

        std::istringstream stream(linea);
        stream >> id >> id_supervisor >> nombre >> apellido >> correo;

        Empleado empleado = EmpleadoPorNomina(id,id_supervisor,nombre,apellido,correo,nombre,apellido);
        nombre = empleado.getNombre();
        apellido = empleado.getApellido();

        EXPECT_EQ(nombre,"Denis");
        EXPECT_EQ(apellido,"Tyler");
        EXPECT_EQ(correo,"denis_tyler@biz.com");

    }

    TEST(EmpleadoNominaTest,RetencionCorrecta){
        
        Empleado empleado = EmpleadoPorNomina(44,12,"Rose","Abbey","rose_abbey@biz.com","","");
        empleado.calculeMontoNeto("44 3570.42");
        
        EXPECT_DOUBLE_EQ(empleado.retenciones(),249.9294);
    }

    TEST(EmpleadoNominaTest,MontoNetoCorrecto){
        //200 Doris Mcnally doris_mcnally@biz.com 1 95
        Empleado empleado = EmpleadoPorNomina(200,95,"Doris","Mcnally","doris_mcnally@biz.com","","");
        empleado.calculeMontoNeto("100 2931.07");

        EXPECT_DOUBLE_EQ(empleado.totales(),2725.8951);
    }
}
