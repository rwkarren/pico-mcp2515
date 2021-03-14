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

    printf("------- CAN WRITE ----------\n");
    printf("ID       DLC   DATA\n");
}


int main()
{
    int count = 0;
    int sendrate_ms = 500;

    init();
    while (true) {
        uint8_t offset = count * 8;
        canMsg.can_id   = 0x420;
        canMsg.can_dlc  = 8;
        canMsg.data[0]  = 0 + offset;
        canMsg.data[1]  = 1 + offset;
        canMsg.data[2]  = 2 + offset;
        canMsg.data[3]  = 3 + offset;
        canMsg.data[4]  = 4 + offset;
        canMsg.data[5]  = 5 + offset;
        canMsg.data[6]  = 6 + offset;
        canMsg.data[7]  = 7 + offset;
        count++;
        can.sendMessage(&canMsg);
        printf("%08X %02X    ",canMsg.can_id, canMsg.can_dlc); // print ID and DLC
            for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
                printf("%02X", canMsg.data[i]);
                printf(" ");
            }
        printf("\n");
        sleep_ms(sendrate_ms);
    }
}


