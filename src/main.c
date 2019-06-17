#include <zephyr.h>
#include <device.h>
#include <uart.h>
#include "uart_driver.h"

K_MSGQ_DEFINE(bt_uart_input_msgq, sizeof(u8_t), 512, 4);
K_MSGQ_DEFINE(bt_uart_output_msgq, sizeof(u8_t), 512, 4);

uart_t bt_uart = {0};

void main(void) {

    /* int err = uart_open(&bt_uart, DT_UART_STM32_USART_2_NAME); */
    int err = uart_open(&bt_uart, DT_UART_SHELL_ON_DEV_NAME);
    if (err) {
        return;
    }

    err = uart_add_input(&bt_uart, &bt_uart_input_msgq);
    if (err) {
        return;
    }

    err = uart_add_output(&bt_uart, &bt_uart_output_msgq);
    if (err) {
        return ;
    }

    u8_t data = 0;

    while (1) {
        printk("haha -> %c\n", data);
        k_sleep(K_MSEC(100));
    }
}
