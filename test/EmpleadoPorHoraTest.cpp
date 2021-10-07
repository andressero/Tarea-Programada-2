#include <gtest/gtest.h>
#include "../empleadoPorHoras.h"

namespace{
    TEST(EmpleadoHorasTest,MontoNetoCorrecto){
        //500 Maxwell Fowler Maxwell_Fowler569@muall.tech 2 245
        //500 42.40 5
        Empleado empleado = EmpleadoPorHoras(500,245,"Maxwell","Fowler","Maxwell_Fowler569@muall.tech","","");
        empleado.calculeMontoNeto("500 42.40 5");

        EXPECT_DOUBLE_EQ(empleado.totales(),212.0);
    }
}
