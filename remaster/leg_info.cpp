#include "leg_info.h"
#include <fstream>

 
 void set_legs(int indx, int t_s, t_c){
  
    legs[indx].t_c = t_c; //Время, за которое двигатель должен сделать 1 оборот
    legs[indx].t_s = t_s;  //Время старта
	legs[indx].speed = 360 / t_c; //Рассчетная скорость при данном времени оборота
	legs[indx].b_v = ;  //Напряжение, при котором подвешенный двигатель будет двигаться с рассчетной скоростью
}


//См. leg_info.h
leg leg0 = {false, 0, 0.3};
leg leg1 = {false, 0.5, 0.3};
leg leg2 = {false, 0, 0.3};
leg leg3 = {true, 0.5, 0.3};
leg leg4 = {true, 0, 0.3};
leg leg5 = {true, 0.5, 0.3};
leg legs[] = {leg0, leg1, leg2, leg3, leg4, leg5};