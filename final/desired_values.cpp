#include "desired_values.h"
#include <math.h>
#include <fstream>


float get_values(int t, leg, gait, snap){  //Рассчет угла, которой должен быть в данный момент времени 
  int t_e = t - leg.t_s;  //Время, прошедшее со старта текущей конфигурации
  t = fmodf(t_e + leg.phase * leg.t_c, leg.t_c);  //Ограничение времени в пределах от 0 до желаемого времени оборота
  switch(gait) {
	case 0: 
		return snap; //при остановке угол поворота постоянен
		break;
	case 1:
		return fmodf(t * leg.speed + snap , 360); //ходьба вперед, + snap (значение угла в момент изменения режима) сохраняет плавный переход, так как при изменении режима счетчик времени и, соответственно, нужный угол обнуляются
		break;
	case 2:
		return fmodf(fabs(360 - t * leg.speed) + snap , 360);  //ходьба назад 
		break;
	case 3:
		return fmodf(t * leg.speed + snap , 360); //поворот налево
		break;
	case 4:
		return fmodf(t * leg.speed + snap , 360); //направо
		break;	
  }
}