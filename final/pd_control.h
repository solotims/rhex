#ifndef pd_control
#define pd_control

float pd_controller(float err, float t1, float t2, float theta_act, float theta_des, float d_speed, float c_speed, float kp, float kd, float ks);

#endif