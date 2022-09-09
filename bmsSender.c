#include <stdio.h>
#include <stdlib.h>
#include "bmsSender.h"

void generateBatteryData(batteryParameters *ptr_BatteryParam)
{
	//generate data for Battery parameters
	for(int index = 0; index < NUM_OF_READINGS; index++)
    {
		ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
        printBatteryData(index + 1, ptr_BatteryParam->temperature[index], ptr_BatteryParam->soc[index]);
        writeToCsv(index + 1, ptr_BatteryParam->temperature[index], ptr_BatteryParam->soc[index]);
	}
}

void printBatteryData(int count, float batteryTemp, float batterySoc)
{

	//Print BaterryParameters data to console
	printf("%d - Temperature: %.f, SOC: %.f\n",count, batteryTemp, batterySoc);
}

status_en writeToCsv(int count, float batteryTemp, float batterySoc)
{
    FILE *fd = fopen(CSV_FILE, "a");
    if(f==NULL) 
        return FAILURE;
        
    fprintf(fd,"%d,%s,%f\n",count, batteryTemp, batterySoc);
    fclose(fd);
    return SUCCESS;
}

status_en createCsvFile(void)
{
    FILE *f=fopen(CSV_FILE, "w");
    if(f==NULL) 
        return FAILURE;

    fclose(f);
    return SUCCESS;
}

status_en senderProcess(void)
{
    printf("Inside sender process\n");
	batteryParameters BatteryParam;

    createCsvFile();
	//Generate data for Battery parameters and print to console
	generateBatteryData(&BatteryParam);

	return SUCCESS;
}