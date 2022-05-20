/*
 * terrarium.h
 *
 * Created: 16-05-2022 10:27:11
 *  Author: Solaiman
 */ 


#include <stdio.h>
#include <stdlib.h>
#include "ATMEGA_FreeRTOS.h" 
#include <semphr.h>


// laver struct
typedef struct Terrariumdata* Terrariumdata_p;

void updateTerrariumTemperature(float temp );

int16_t getTerrariumTemp(Terrariumdata_p terrariumdata);

Terrariumdata_p prepareTerrariumData();

 SemaphoreHandle_t semaphore;
