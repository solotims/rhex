#include "leg_info.h"
#include "desired_values.h"
#include "conversions.h"
#include "pd_control.h"

float actual_theta;
float desired_theta;
float control_signal;
int t_cycle;
int finput;
int standby; 
int gait;


void setup(){

	// Здесь должна происходить подготовка драйвера моторов к работе
	
	t_cycle = 2000; //Время, за которое двигатель должен сделать один оборот
	
	gait = WALK; //Начальное состояние - ходьба вперед
	
	standby = 0;
	
	//Задаем параметры каждой ноге
	for (int i = 0; i < 5; i++){ 
		set_legs(i, millis(), gait, t_cycle);
	}

void change_gait(){  //Изменение поведения

	gait = ;
	t_cycle = ;
	
	standby = actual_theta;  // Значение угла поворота при изменение поведения, нужно для плавного перехода
	
	for (int i = 0; i < 5; i++){ 
		set_legs(i, millis(), gait, t_cycle);
}	

void loop(){ 
	
	//Если подается команда, то выполянется void change_gait()
	if () {
	};

    for(int i = 0; i <= 5; i++){  
  
		actual_theta = //Текущий угол двигателя в градусах;
	
		desired_theta = get_values(millis(), legs[i], gait, standby) //Угол, который в идеале должен быть в данный момент
	
		c_s = //Текущая скорость;

		t_prv[i] = millis();
	
		pdctrl = pd_controller(prv_err[i], millis(), t_prv, actual_theta, desired_theta, leg[i].speed, c_s, leg[i].kp, leg[i].kd, leg[i].kspeed); //Ошибка и ПД-регулятор
	
		control_signal = pdctrl[2];  //ПД-регулятор
		prv_err[i] = pdctrl[1]; //Ошибка по углу поворота, нужно задать как нулевой список в void setup() 
	
		finput = prev_voltage + control_signal;   //Подаваемый сигнал - сумма текущего напряжения, ПД-регулятора и П-регулятора по скорости
		prev_voltage = finput; //Если задний ход, то движение в обратную сторону
	
		//Подача сигнала finput на двигатель, нужно учесть, что у противоположных двигателей напряжение должно быть разных знаков 
	
}