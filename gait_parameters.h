#include "leg_info.h"

//Начальное состояние - простой
int initial_gait = STAND;

//Коэффициенты ПД-регулятора
float kp_walk = .03; 
float kd_walk = 1.0;
//период цикла в миллисекундах
int walk_period = 2000;

/*
Параметры для 6 ног, где:
dutyf - время, в течение которого нога касается земли (в процентах)
sweep - ширина "медленной фазы" в градусах
down - центральное положение "медленной фазы" в градусах
phase - нужен для постановки ног в противофазы
*/


float leg1_dutyf = .42;
int leg1_sweep = 40;
int leg1_down = 20;
float leg1_phase = 0.5;
 
float leg2_dutyf = .42;
int leg2_sweep = 40;
int leg2_down = 20;
float leg2_phase = 0;

float leg3_dutyf = .42;
int leg3_sweep = 40;
int leg3_down = 20;
float leg3_phase = 0.5;

float leg4_dutyf = .42;
int leg4_sweep = 40;
int leg4_down = 20;
float leg4_phase = 0;

float leg5_dutyf = .42;
int leg5_sweep = 40;
int leg5_down = 20;
float leg5_phase = 0.5;

float leg6_dutyf = .42;
int leg6_sweep = 40;
int leg6_down = 20;
float leg6_phase = 0;

//создание структуры для хранения параметров походки
typedef struct gait_container Gait;
struct gait_container{
  float theta_s[7];
  float theta_d[7];
  int t_cc[7];
  float duty_f[7];
  float phases[7];
  float kp;
  float kd;
};
Gait walk_gait = {{0, leg1_sweep, leg2_sweep, leg3_sweep, leg4_sweep, leg5_sweep, leg6_sweep}, {0, leg1_down, leg2_down, leg3_down, leg4_down, leg5_down, leg6_down}, {0, walk_period, walk_period, walk_period, walk_period, walk_period, walk_period}, {0, leg1_dutyf, leg2_dutyf, leg3_dutyf, leg4_dutyf, leg5_dutyf, leg6_dutyf}, {0, leg1_phase, leg2_phase, leg3_phase, leg4_phase, leg5_phase, leg6_phase}, kp_walk, kd_walk};
