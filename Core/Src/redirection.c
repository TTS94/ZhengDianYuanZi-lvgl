
#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"

__asm(".global __use_no_heap_region\n\t"); //声明不使用C库的堆

extern huart1;
int _write (int fd, char *pBuffer, int size){
    HAL_UART_Transmit(&huart1, (uint8_t*)pBuffer, size, 100);   // 所有字节的超时为lenms

    return size;
}

void *malloc (size_t size){
    void *p = pvPortMalloc(size);

    // printf("malloc 0x%08X size: %d, %d\r\n", (int)p, size, xPortGetFreeHeapSize());
    if(p == NULL){
      printf("malloc error\r\n");
    }
    memset(p, 0, size);
    return p;
}

void free(void* p){
    vPortFree(p);
}

void *realloc(void *p, size_t size){
    void *pNew = pvPortMalloc(size);
    if(pNew == NULL){
      printf("realloc error %d\r\n", size);
    }
    memcpy(pNew, p, size);
    vPortFree(p);
    return pNew;
}

