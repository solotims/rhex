#ifndef leg_info
#define leg_info
#include <math.h>

typedef struct leg_info leg;

struct leg_info{
  bool right;  //Находится ли двигатель справа
  float phase;  //Фаза нужна для обеспечения синхронного движения триплетов
  int kp  //Коэффициент П-регулятора для конкретного двигателя
  int t_c;
  int t_s;
  int speed;
  int b_v;
};

void set_legs(int indx, int t_start, int t_cycle);
extern leg legs[6];


#endif