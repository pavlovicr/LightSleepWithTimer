## 10.1 LightSleepWithTimer
**V nalogi smo izmerili čas v katerem je bil esp32S3 v načinu Light Sleep. Dodatno smo funkciji za začeteh spanja onemogočili štart dokler se ni spraznil predpomnilnik in dokončalo predhodno začeto printanje.**

S funkcijami modula [ESP Timer (High Resolution Timer)](https://docs.espressif.com/projects/esp-idf/en/release-v6.0/esp32s3/api-reference/system/esp_timer.html#) izmerimo trenutni čas.

glavna datoteka : `#include "esp_timer.h"`
funkcije :  
`int64_t esp_timer_get_time(void)`

S funkcijami modula [Sleep Modes](https://docs.espressif.com/projects/esp-idf/en/release-v6.0/esp32s3/api-reference/system/sleep_modes.html#_CPPv421esp_light_sleep_startv) nastavimo trajanje spanja in start spanja.
glavna datoteka : `#include "esp_sleep.h"`
funkcije :
`esp_sleep_enable_timer_wakeup(5000000);`
`esp_light_sleep_start();`

Lahko se zgodi , da start spanja prekine izvajanje kode, ki je še v Bufferju. V našem primeru printanje. 
To preprečimo z ukazom v modulu [UART](https://docs.espressif.com/projects/esp-idf/en/release-v6.0/esp32s3/api-reference/peripherals/uart.html) , ki onemogoči nadaljevanje kode dokler ne izprazni Bufferja. 
glavna datoteka: `#include "driver/uart.h"`
funkcije :
`uart_wait_tx_idle_polling(CONFIG_ESP_CONSOLE_UART_NUM);`