//made by Abhishek Tiwari
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h" //error
#include "driver/gpio.h"

#include "MCP4922.h"
static const char *MCP_4922_DAC = "mcp4922";
void voltageSet();

void app_main(void) {
mcp4922_init(13,14,32);    // (MOSI,SCK,CS,LDAC) define Connections for MEGA_board, 
ESP_LOGI(MCP_4922_DAC, "DAC SET");
setDacVoltageMcp4922_CHA(2000,1,1,1);  // bit, gain,buffered,shutDown 
setDacVoltageMcp4922_CHB(2000,1,1,1);  // bit, gain,buffered,shutDown
while (1) {
vTaskDelay(10 / portTICK_PERIOD_MS);
}
}