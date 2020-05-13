#include "control_parameters.h"
#include "gait_parameters.h"
#include <fstream>

const int STAND = 0;
const int WALK = 1;

//Выбор текущего типа передвижения (Хождение, поворот, простой и т.д.)
void update_gait(int leg_index, int gait, int startMillis){
  Gait new_gait = walk_gait;
  legs[leg_index].gait = gait;
  legs[leg_index].theta_slow = new_gait.theta_s[leg_index];
  legs[leg_index].theta_down = new_gait.theta_d[leg_index];
  legs[leg_index].t_c = new_gait.t_cc[leg_index];
  legs[leg_index].duty_factor = new_gait.duty_f[leg_index];
  legs[leg_index].phase = new_gait.phases[leg_index];
  legs[leg_index].kp = new_gait.kp;
  legs[leg_index].kd = new_gait.kd;
  update_gait_internal_params(legs[leg_index], startMillis);
}


void update_gait_internal_params(leg, int startTime){
  float ground_speed;
  float recovery_speed;
  int t_s = round(leg.t_c * leg.duty_factor);

 
  
  ground_speed = leg.theta_slow / t_s;
  recovery_speed = (theta_circle - leg.theta_slow) / (leg.t_c - t_s);

  leg.thetas[0] = leg.theta_down - theta_circle + theta_up;
  leg.ts[0] = 0;

  leg.thetas[1] = leg.theta_down - leg.theta_slow/2;
  leg.ts[1] = leg.ts[0] + (leg.thetas[1] - leg.thetas[0]) / recovery_speed;

  leg.thetas[2] = leg.theta_down;
  leg.ts[2] = leg.ts[1] + (leg.thetas[2] - leg.thetas[1]) / ground_speed;

  leg.thetas[3] = leg.theta_down + leg.theta_slow/2;
  leg.ts[3] = leg.ts[2] + (leg.thetas[3] - leg.thetas[2]) / ground_speed;

  leg.thetas[4] = leg.theta_down + theta_up;
  leg.ts[4] = leg.t_c;

  }
  leg.startMillis = startTime;
  leg.ground_speed = ground_speed;
  leg.recovery_speed = recovery_speed;

}

typedef struct leg_info_header leg;

struct leg_info_header{
  int id;
  float desired_theta;
  int forwards[5]; 
  int gait; 
  float zero;
  bool right_side; 
  bool deadzone;
  bool dead_from_neg;
  //следующие параметры обновляются для каждого нового типа движения
  float theta_slow;
  float theta_down;
  int t_c;
  float duty_factor;
  float phase;
  int startMillis;
  float kp;
  float kd;
  float recovery_speed;
  float ground_speed;
  float thetas[5]; 
  float ts[5];
};

float mini1Zeros[6] = {0.29, 1.46, 0.29, -2.34, 1.17, 0.29}; 
float mini2Zeros[6] = {-0.59, -17.87, -1.76, 0.88, -5.27, -1.76};
float *zeros = (active_mini == 1) ? mini1Zeros : mini2Zeros;
leg leg1 =      {IDS[0], 0, {1, -1, -1,  1, 1},    0, zeros[0],  false, false, false};
leg leg2 =      {IDS[1], 0, {1, -1, -1,  1, 1},    0, zeros[1],  false, false, false};
leg leg3 =      {IDS[2], 0, {1, -1, -1,  1, 1},    0, zeros[2],  false, false, false};
leg leg4 =      {IDS[3], 0, {1,  1, -1, -1, 1},    0, zeros[3],  true,  false, false};
leg leg5 =      {IDS[4], 0, {1,  1, -1, -1, 1},    0, zeros[4],  true,  false, false};
leg leg6 =      {IDS[5], 0, {1,  1, -1, -1, 1},    0, zeros[5],  true,  false, false};
leg legs[] = {leg1, leg2, leg3, leg4, leg5, leg6};
