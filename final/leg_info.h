#ifndef leg_info
#define leg_info
#include <math.h>

typedef struct leg_info leg;

struct leg_info{
  bool right;  //Находится ли двигатель справа
  float phase;  //Фаза нужна для обеспечения синхронного движения триплетов
  int kp; //Коэффициент П-регулятора для конкретного двигателя
  int kd; //Коэффициент Д-регулятора
  int kspeed; //Коэффициент П-регулятора по скорости
  int t_c;
  int t_s;
  int speed;
};

void set_legs(int indx, int t_s, t_c);
extern leg legs[6];

extern const int STAND;
extern const int WALK;
extern const int LEFT;
extern const int REVERSE;
extern const int RIGHT;

#endif