#include "leg_info.h"
#include <fstream>

const int STAND = 0;
const int WALK = 1;
const int REVERSE = 2;
const int LEFT = 3;
const int RIGHT = 4;
 
 void set_legs(int indx, int t_start, int g, int t_cycle){
  
    legs[indx].t_c = t_cycle; //Время, за которое двигатель должен сделать 1 оборот
    legs[indx].t_s = t_start;  //Время старта
	
	//Если режим поворота, то одна сторона должна двигаться медленее
    if (g == 3) {
		if (!legs[indx].right) {
			legs[indx].t_c = t_cycle * 0.7;
		}
			
	}
    if (g == 4) {
		if (legs[indx].right) {
			legs[indx].t_c = t_cycle * 0.7;
		}
			
	}
	legs[indx].speed = g == 0 ? 0 : 360 / t_c; //Рассчетная скорость при данном времени оборота, если режим остановки, то она равна 0
}


//См. leg_info.h
leg leg0 = {false, 0, 0.3, 0.1, 1};
leg leg1 = {false, 1, 0.3, 0.1, 1};
leg leg2 = {false, 0, 0.3, 0.1, 1};
leg leg3 = {true, 1, 0.3, 0.1, 1};
leg leg4 = {true, 0, 0.3, 0.1, 1};
leg leg5 = {true, 1, 0.3, 0.1, 1};
leg legs[] = {leg0, leg1, leg2, leg3, leg4, leg5};