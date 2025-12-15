#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>  
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "esp_log.h"
//#include "esp32/rom/uart.h"


void app_main(void)
{
 esp_sleep_enable_timer_wakeup(5000000);
 printf("grem na tirolsko\n"); 

int64_t prej = esp_timer_get_time();

esp_light_sleep_start;

int64_t sedaj = esp_timer_get_time();

printf("prespal sem %lld mikrosekund\n", sedaj - prej);

}