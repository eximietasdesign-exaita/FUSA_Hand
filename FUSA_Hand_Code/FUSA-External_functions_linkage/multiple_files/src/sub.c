#include "../include/engine_management.h"
#include "../ccm/ClimateControlModule.h"
#include "../include/arithmetic.h"
//#include<stdint.h>
//static int subtract(uint8_t f_var_1, uint8_t f_var_2) ;
int subtract(uint8_t f_var_1, uint8_t f_var_2) 
{
    uint8_t l_resultOfSub;
    l_resultOfSub=f_var_1 - f_var_2;
    //Navya
    int l_final_speed = manage_engine_idle_speed();
    if(l_final_speed >= 0) 
    {
        start_transmission_control_simulation();
        g_final_speed = l_final_speed;
    } 
    else
    {
        g_final_speed = -1;
    }
    

    return l_resultOfSub;
}
 
	