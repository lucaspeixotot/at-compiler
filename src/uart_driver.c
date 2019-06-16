#include "uart_driver.h"
#include <uart.h>

static void uart_callback(struct device *dev)
{
    u8_t data = 0;

    if (!uart_irq_update(dev)) {
        printk("UART is not working properly\n");
        return;
    }

    uart_t *uart = CONTAINER_OF(dev, uart_t, device);

    if (uart_irq_rx_ready(dev)) {
        while(uart_fifo_read(dev, &data, 1)) {
            k_msgq_put(uart->in, &data, K_NO_WAIT);
        }
    }
}

int uart_open(uart_t *uart, char *dev_label)
{
    struct device *dev = device_get_binding(dev_label);
    uart->device = *dev;

    if (&uart->device == NULL) {
        printk("The UART device was not found.\n");
        return -EINVAL;
    }

    uart_irq_callback_set(&uart->device, uart_callback);
    uart_irq_rx_enable(&uart->device);

    return 0;
}

int uart_add_input(uart_t *uart, struct k_msgq *msgq) {
    if (uart == NULL || msgq == NULL)  {
        printk("error adding input msgq\n");
        return -EINVAL;
    }

    uart->in = msgq;

    return 0;
}

int uart_add_output(uart_t *uart, struct k_msgq *msgq) {
    if (uart == NULL || msgq == NULL)  {
        printk("error adding output msgq\n");
        return -EINVAL;
    }

    uart->out = msgq;

    return 0;
}
