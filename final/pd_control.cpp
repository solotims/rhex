#include "pd_control.h"
#include <stdio.h>
#include <math.h>

float pd_controller(float err, float t1, float t2, float theta_act, float theta_des, float d_speed, float c_speed, float kp, float kd, float ks){
 	float diff = theta_des - theta_act;   //Разность между желаемым и текущим углом поворота 
 	float shortest_distance = 180 - fabs(fabs(diff) - 180);   //Кратчаешее расстояние на окружности между углами
 	float dtheta = diff < 180 ? shortest_distance : -shortest_distance;  //В зависимости от того, спешит ли или опаздыет ли двигатель, выбирается знак
	float der = (diff - err) / (t1 - t2)
 	return {diff, kp * dtheta + kd * der + ks * (d_speed - c_speed)};  
}
