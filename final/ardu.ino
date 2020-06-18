#include "leg_info.h"
#include "desired_values.h"
#include "conversions.h"
#include "pd_control.h"

float actual_theta;
float desired_theta;
float control_signal;
int set_cycle;
int f_input;
int standby; 
int gait;


void setup(){

	// Здесь должна происходить подготовка драйвера моторов к работе
	
	set_cycle = 2000; //Время, за которое двигатель должен сделать один оборот
	
	gait = WALK; //Начальное состояние - ходьба вперед
	
	standby = 0;
	
	//Задаем параметры каждой ноге
	for (int i = 0; i < 5; i++){ 
		set_legs(i, millis(), gait, set_cycle);
}

void change_gait(){  //Изменение поведения

	gait = ;
	set_cycle = ;
	
	standby = desired_theta(millis(), legs[0], gait, standby);
	for (int i = 0; i < 5; i++){ 
		  // Значение угла поворота при изменение поведения, нужно для плавного перехода
		set_legs(i, millis(), gait, set_cycle);
}	

void loop(){ 
	
	//Если подается команда, то выполянется void change_gait()
	if () {
	};

    for(int i = 0; i <= 5; i++){  
  
		actual_theta[i] = //Текущий угол двигателя в градусах;
	
		desired_theta = get_values(millis(), legs[i], gait, standby) //Угол, который в идеале должен быть в данный момент
	
		c_s = //Текущая скорость;
	
		pdctrl = pd_controller(error[i], millis(), t_prv[i], actual_theta, desired_theta[i], leg[i].speed, c_s, leg[i].kp, leg[i].kd, leg[i].kspeed); //Ошибка и ПД-регулятор

		t_prv[i] = millis();
		
		control_signal = pdctrl[2];  //ПД-регулятор
		error[i] = pdctrl[1]; //Ошибка по углу поворота, нужно задать как нулевой список в void setup() 
	
		f_input = prev_voltage[i] + control_signal;   //Подаваемый сигнал - сумма текущего напряжения, ПД-регулятора и П-регулятора по скорости
		prev_voltage[i] = f_input; //Если задний ход, то движение в обратную сторону
	
		//Подача сигнала f_input на двигатель, нужно учесть, что у противоположных двигателей напряжение должно быть разных знаков 
	
}