#include "leg_info.h"
#include "desired_values.h"
#include "conversions.h"
#include "p_control.h"

float actual_theta;
float desired_theta;
float control_signal;
int t_cycle;
int finput;



void setup(){

	// Здесь должна происходить подготовка драйвера моторов к работе
	
	t_cycle = 2000; //Время, за которое двигатель должен сделать один оборот
	
	//Задаем параметры каждой ноге
	for (int i = 0; i < 5; i++){ 
		set_legs(i, millis(), t_cycle);
	}

void loop(){
  for(int i = 0; i <= 5; i++){  
  
    actual_theta = //Текущий угол двигателя в градусах;
	
	desired_theta = get_angle(millis(), legs[i]); //желаемый в данный момент угол
	
    control_signal = p_controller(actual_theta, desired_theta, kp);  //П-регулятор
	
    finput = legs[i].b_v + control_signal;   //Подаваемый сигнал - сумма постоянной составляющей и П-регулятора
	
    //Подача сигнала finput на двигатель, нужно учесть, что у противоположных двигателей напряжение должно быть разных знаков 
	
}