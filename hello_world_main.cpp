#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "untitled.h"
#define UDA1334A
extern "C" {
    void app_main(void);
}

void app_main(void)
{
    esp_wifi_stop();
    int SR = 44100;
    int BS = 32;
    untitled untitled(SR,BS);  
    untitled.start();
    while(1) {
            untitled.setParamValue("freq",rand()%(2000-50 + 1) + 50);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
    }
}