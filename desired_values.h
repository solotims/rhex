#include "control_parameters.h"
#include <math.h>
#include <fstream>

vals get_desired_vals_internal(int t, leg){

  int forward = leg.forwards[leg.gait - 1]; 
  float theta;
  float velocity;

  if (t < leg.ts[1]){
    theta = leg.thetas[0] + t * leg.recovery_speed;
    velocity = leg.recovery_speed;
  }
  else if (t < leg.ts[2]){
    theta = leg.thetas[1] + (t - leg.ts[1]) * leg.ground_speed;
    velocity = leg.ground_speed;
  }
  else if (t < leg.ts[3]){
    theta = leg.thetas[2] + (t - leg.ts[2]) * leg.ground_speed;
    velocity = leg.ground_speed;
  }
  else{
    theta = leg.thetas[3] + (t - leg.ts[3]) * leg.recovery_speed;
    velocity = leg.recovery_speed;
  }

  if (theta < theta_up - theta_circle) theta = theta_circle + theta;
  else if (theta >= theta_up) theta = -theta_circle + theta;
  theta = theta * forward;
  velocity = velocity * forward;
  vals result = {theta, velocity};
  return result;
}

vals get_desired_vals(int t, leg leg){ 
  int elapsed_time = t - leg.startMillis;

  float phase = leg.phase;
  t = fmodf(elapsed_time + phase * leg.t_c, leg.t_c);
  
  return get_desired_vals_internal(t, leg);
}