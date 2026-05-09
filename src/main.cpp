
#include "FreeRTOS.h"
#include "task.h"      // xTaskCreate, vTaskDelay, etc.
// #include "queue.h"     // xQueueCreate, xQueueSend, etc.
// #include "semphr.h"    // semaphores/mutexes
// #include "timers.h"    // software timers

extern "C" {
    void SystemInit(void) {}  // stub if you commented it out above
    static const char msg[] = "main reached\n";
    int main(void) {
        while(1) {}
    }
}