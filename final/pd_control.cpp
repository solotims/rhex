#include "pd_control.h"
#include <stdio.h>
#include <math.h>

float pd_controller(float err, float t1, float t2, float theta_act, float theta_des, float d_speed, float c_speed, float p, float d, float ks){
 	float diff = fmod(theta_des - theta_act, 360);   //Разность между желаемым и текущим углом поворота 
 	float shortest_distance = 180 - fabs(fabs(diff) - 180);   //Кратчаешее расстояние на окружности между углами
 	float theta_dis = fmodf(diff + 360, 360) < 180 ? shortest_distance : -shortest_distance;  //В зависимости от того, спешит ли или опаздыет ли двигатель, выбирается знак
	float der = (theta_dis - err) / (t1 - t2)
 	return {theta_dis, p * theta_dis + d * der + ks * (d_speed - c_speed)};  
}
