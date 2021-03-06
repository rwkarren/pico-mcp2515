//CAN Read example for MCP2515 boards and Pi Pico

#include "pico/stdlib.h"
#include "mcp2515.h"
#include <cstdio>

#define SPI_PORT    (PICO_DEFAULT_SPI_INSTANCE) // spi0
#define PIN_CS      (PICO_DEFAULT_SPI_CSN_PIN)  // pin 17
#define PIN_MISO    (PICO_DEFAULT_SPI_RX_PIN)   // pin 16
#define PIN_MOSI    (PICO_DEFAULT_SPI_TX_PIN)   // pin 19
#define PIN_SCK     (PICO_DEFAULT_SPI_SCK_PIN)  // pin 18

MCP2515 can(SPI_PORT, PIN_CS, PIN_MISO, PIN_MOSI, PIN_SCK);
struct can_frame canMsg;

void init()
{
    stdio_init_all();
    can.reset();
    can.setBitrate(CAN_250KBPS, MCP_12MHZ);
    can.setNormalMode();

    printf("------- CAN Read ----------\n");
    printf("ID         DLC  DATA\n");
}


int main()
{
    init();
    while (true) {
        if (can.readMessage(&canMsg) == MCP2515::ERROR_OK) {
            if (canMsg.can_id >> 31) { // extended frame
                printf("0x%08X   %01X    ", (canMsg.can_id & 0x01FFFFFFF), canMsg.can_dlc); // print ID and DLC
            } else { // standard frame
                printf("     0x%03X   %01X    ", canMsg.can_id, canMsg.can_dlc); // print ID and DLC
            }
            for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
                printf("%02X", canMsg.data[i]);
                printf(" ");
            }
            printf("\n");      
        }
    }
}

