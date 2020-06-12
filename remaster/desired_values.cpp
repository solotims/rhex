#include "desired_values.h"
#include <math.h>
#include <fstream>


float get_angle(int t, leg){  //Рассчет угла, которой должен быть в данный момент времени для обеспечения нужной скорости
  int t_e = t - leg.t_s;  //Время, прошедшее со старта
  t = fmodf(t_e + leg.phase * leg.t_c, leg.t_c);  //Ограничение времени в пределах от 0 до желаемого времени оборота
  return t * leg.speed;  //Угол равен времени в цикле, умноженный на требуюмую угловую скорость двигателя
}