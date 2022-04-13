#include <Arduino.h>
#include "esp_system.h"

void WaffleMakingTask(void *pvParameter) { //void *pvParameter required per reference manual page 38
	for (;true;) {
	Serial.println("We Made Waffles!");
	vTaskDelay(10); //Delay the task
	}
}
void BaconCookingTask(void *pvParameter) { //void *pvParameter required per reference manual page 38
	for (;true;) {
	Serial.println("We Made Bacon!");
	vTaskDelay(10); //Delay the task
	}
}

void ExecuteCookingTasks() {
	xTaskCreate( //Create higher priority task for WaffleMakingTask
	&WaffleMakingTask, //pointer to the task
	"hello_task", //Descriptive name for the task
	2048, //Number of words stack can hold (allocated to the task)
	NULL, //*pvParameter that can be passed to the function task (if needed)
	0, //Task priority, ranges from 0 (lowest) to (configMAX_PRIORITIES-1) (highest)
	NULL); //pass out a handle to the task being created

	xTaskCreate( //Create higher priority task for WaffleMakingTask
	&BaconCookingTask, //pointer to the task
	"hello_task", //Descriptive name for the task
	2048, //Number of words stack can hold (allocated to the task)
	NULL, //*pvParameter that can be passed to the function task (if needed)
	5, //Task priority, ranges from 0 (lowest) to (configMAX_PRIORITIES-1) (highest)
	NULL); //pass out a handle to the task being created
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	ExecuteCookingTasks();
}

void loop() {
	// put your main code here, to run repeatedly:
	//Serial.println("I LIKE EGGS AND BACON");
}
