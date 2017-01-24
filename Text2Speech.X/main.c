#include "config.h"
#define getPeripheralClock() 40000000
#define getSystemClock() 40000000
#define getUartBaud() 9600

void setupUART(void) {
    PPSInput (1, U1RX, RPB9);
    PPSOutput(2, RPB3, U1TX);
    mPORTBSetPinsDigitalIn(BIT_9);
    mPORTBSetPinsDigitalOut(BIT_3);

    UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART1, getPeripheralClock(), getUartBaud());
    UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
        __XC_UART = 1; // configured to use UART1 by default
}

void EMIC_setup(void){
	printf("R\r\n");
}

void EMIC_speak(char* text){
	printf("S%s\r\n", text);
}

#define VOLUME_MIN	-48
#define VOLUME_MAX	18
void EMIC_setVolume_dB(int volume){
	if (volume < VOLUME_MIN) volume = VOLUME_MIN;
	if (volume > VOLUME_MAX) volume = VOLUME_MAX;
	printf("V%d\r\n", volume);
}

int EMIC_selectVoice(int voice){
	if (voice < 0 || voice > 8) return -1;
	printf("N%d\r\n", voice);
}

void main(void){
    INTEnableSystemMultiVectoredInt();
    SYSTEMConfigPerformance(getSystemClock());
    setupUART();
    
    EMIC_setup();
    EMIC_setVolume_dB(VOLUME_MAX);
    EMIC_selectVoice(1);
    
    OpenTimer1(T1_ON | T1_PS_1_256, 0xFFFF);
    mT1ClearIntFlag();
    
    while (1){
        EMIC_speak("Hello. Cornell Mars Rover.");
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
        while (mT1GetIntFlag() == 0);
        mT1ClearIntFlag();
    }
}
