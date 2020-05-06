#include "control_parameters.h"
#include "conversions.h"
#include <algorithm>   
#include <stdio.h>
#include <math.h>


float VMax = 0.8; 

float dynV_to_V(int dynV){
	float result = dynV;
  if (dynV > 1023) result = 1024 - dynV; 
  result = result * VMax / 1024.0;
  return result;
}

int V_to_dynV(float V){
  V = std::max(std::min(V, VMax), -VMax); 
  int result = V/VMax * 1023; 
  if (result < 0) result = 1024 - result; 
  return result;
}

float P_to_Theta(int P){
  return P * (theta_circle - theta_dead) / 1024 - 5 * (theta_circle) / 12.0; 
}

int Theta_to_P(float theta){
	int P = 512 + theta * 1024/(theta_circle - theta_dead);
	if (P < 0) return 0;
	if (P > 1023) return 1023;
	return P;
}


float Theta_to_ThetaR(float theta){
  return -theta;
}

float ThetaR_to_Theta(float thetaR){
  return -thetaR;
  
}