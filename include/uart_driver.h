#ifndef _UART_DRIVER_H_
#define _UART_DRIVER_H_

#include <zephyr.h>
#include <device.h>

typedef struct {
    struct device device;
    struct k_msgq *in;
    struct k_msgq *out;
    u8_t n;
} uart_t;


int uart_open(uart_t *uart, char *dev_label);

int uart_add_input(uart_t *uart, struct k_msgq *in);

int uart_add_output(uart_t *uart, struct k_msgq *out);


#endif
