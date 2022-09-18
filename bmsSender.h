#define NUM_OF_READINGS		50
#define TEMP_MIN			0
#define TEMP_MAX			45
#define SOC_MIN				20
#define SOC_MAX				80
#define CSV_FILE "BMSData.csv"

typedef struct{
   int index;
   float temperature[NUM_OF_READINGS];
   float soc[NUM_OF_READINGS];
}batteryParameters;

typedef enum{
	SUCCESS,
	FAILURE
}status_en;

void generateBatteryData(batteryParameters *ptr_BatteryParam);
void printBatteryData(int count, float batteryTemp, float batterySoc);
status_en writeToCsv(int count, float batteryTemp, float batterySoc);
status_en senderProcess(void);
status_en createCsvFile(void);

