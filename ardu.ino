#include "leg_info.h"
#include "desired_values.h"
#include "conversions.h"
#include "pd_control.h"
#include "gait_parameters.h"

/*

Подготовка двигателя dynamixel, взято как пример

#define DXL_BUS_SERIAL1 1 
Dynamixel Dxl(DXL_BUS_SERIAL1); 

void setup(){

	Dxl.begin(3); 
    Serial2.begin(57600); 
    int t_start = millis();
    for (int i = 0; i <= 5; i++){ 
		Dxl.wheelMode(legs[i].id); 
		update_gate(i, new_gait, millis())
	}
}
*/

void loop(){
  for(int i = 0; i <= 5; i++){
    packet[i * 2] = legs[i].id;
    actual_p = Dxl.readWord(legs[i].id, PRESENT_POS);
    actual_theta = P_to_Theta(actual_p); 
    actual_vel = dynV_to_V(Dxl.readWord(legs[i].id, PRESENT_SPEED));
	vals v = get_desired_vals(millis(), legs[i]);
    if (legs[i].right_side){
        desired_vel = -v.global_velocity; 
        desired_theta = Theta_to_ThetaR(v.global_theta); 
    }
    else{ 
        desired_vel = v.global_velocity;
        desired_theta = v.global_theta;
    }
    actual_theta = actual_theta - legs[i].zero;
        
    control_signal = pd_controller(actual_theta, desired_theta, actual_vel, desired_vel, kp, kd);  
    int new_vel = V_to_dynV(actual_vel + control_signal);
    packet[(i-1) * 2 + 1] = new_vel;
    Dxl.syncWrite(MOVING_SPEED, 1, packet, packet_length);
}
