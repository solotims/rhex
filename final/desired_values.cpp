#include "desired_values.h"
#include <math.h>
#include <fstream>


float get_values(int t, leg l, int g, int snap){  //Рассчет угла, которой должен быть в данный момент времени 
  int t_e = t - l.t_s;  //Время, прошедшее со старта текущей конфигурации
  t = fmodf(t_e + l.phase * l.t_c, l.t_c);  //Ограничение времени в пределах от 0 до желаемого времени оборота
  switch(g) {
	case 0: 
		return snap; //при остановке угол поворота постоянен
		break;
	case 1:
		return t * l.speed + snap; //ходьба вперед, + snap (значение угла в момент изменения режима) сохраняет плавный переход, так как при изменении режима счетчик времени и, соответственно, нужный угол обнуляются
		break;
	case 2:
		return t * l.speed + snap ;  //ходьба назад 
		break;
	case 3:
		return t * l.speed + snap ; //поворот налево
		break;
	case 4:
		return t * l.speed + snap; //направо
		break;	
  }
}