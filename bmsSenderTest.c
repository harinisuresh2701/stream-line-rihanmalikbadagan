#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "bmsSender.h"

void TEST_generateBatteryData(void)
{
    int result;
    batteryParameters *batteryParam;

    batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = generateBatteryData(batteryParam);
    assert(result == SUCCESS);

    batteryParam = NULL;
    result = generateBatteryData(batteryParam);
    assert(result == FAILURE);
}

void TEST_writeToCsv(void)
{
    int result;
    batteryParameters *batteryParam;

    batteryParam = (batteryParameters *)malloc(sizeof(batteryParameters));
    result = writeToCsv(batteryParam);
    assert(result == SUCCESS);

    batteryParam = NULL;
    result = writeToCsv(batteryParam);
    assert(result == FAILURE);
}

void TEST_senderProcess(void)
{
    int result;
    result = senderProcess();
    assert(result == SUCCESS);
}

void TEST_SENDER(void)
{
    TEST_generateBatteryData();
    TEST_writeToCsv();
    TEST_senderProcess();
}