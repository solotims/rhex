#ifndef leg_info
#define leg_info

#include <math.h>

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

void update_gait(int leg_index, int gait, int startMillis);
void update_gait_internal_params(leg& l, int startTime);

extern leg legs[6];
extern int num_gaits;
extern const int STAND;
extern const int WALK;


#endif