/*
 * terrarium.c
 *
 * Created: 16-05-2022 10:29:32
 *  Author: Solaiman
 */ 

#include "terrarium.h"
#include "temperature_Sensor.h"

float static temperature; 
int static temperatureCount;

typedef struct Terrariumdata {
	int16_t  temperature;
//	int16_t  humidity;
	
} Terrariumdata;



void updateTerrariumTemperature(float temp )
{
	temperature += temp;
	temperatureCount++;
	
}


int16_t getTerrariumTemp(Terrariumdata_p terrariumdata)
{
	
	return terrariumdata->temperature;
}




Terrariumdata_p prepareTerrariumData()
{

		Terrariumdata_p newTerrarium = pvPortMalloc(sizeof(Terrariumdata));		
		if(newTerrarium == NULL)
		{
			printf("could not allocate memory in terrium.c \n" );
			return NULL;
		}
		
		printf("succes");
		
		
		float tempAvg =  temperature/temperatureCount;
		int16_t tempAvgX10 = tempAvg*10;
		 newTerrarium->temperature = tempAvgX10;
		 
		return newTerrarium;

}