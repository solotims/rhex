#include "p_control.h"
#include <stdio.h>
#include <math.h>

float p_controller(float theta_act, float theta_des, float k){
 	float diff = theta_des - theta_act;   //Разность между желаемым и текущим углом поворота 
 	float shortest_distance = 180 - fabs(fabs(diff) - 180);   //Кратчаешее расстояние на окружности между углами
 	float theta_dist = diff < 180 ? shortest_distance : -shortest_distance;  //В зависимости от того, спешит ли или опаздыет ли двигатель, выбирается знак
 	return k * theta_dist;  
}
