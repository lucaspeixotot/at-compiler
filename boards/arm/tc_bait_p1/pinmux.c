/*
 * Copyright (c) 2017 RnDity Sp. z o.o.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <device.h>
#include <init.h>
#include <kernel.h>
#include <pinmux.h>
#include <pinmux/stm32/pinmux_stm32.h>
#include <sys_io.h>

/* pin assignments for NUCLEO-F091RC board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_1
    {STM32_PIN_PB6, STM32F0_PINMUX_FUNC_PB6_USART1_TX},
    {STM32_PIN_PB7, STM32F0_PINMUX_FUNC_PB7_USART1_RX},
#endif /* CONFIG_UART_1 */
#ifdef CONFIG_UART_2
    {STM32_PIN_PA2, STM32F0_PINMUX_FUNC_PA2_USART2_TX},
    {STM32_PIN_PA3, STM32F0_PINMUX_FUNC_PA3_USART2_RX},
#endif /* CONFIG_UART_2 */
// #ifdef CONFIG_UART_3
// 	{STM32_PIN_PB10, (STM32_PINMUX_ALT_FUNC_4 | STM32_PUSHPULL_PULLUP)},
// 	{STM32_PIN_PB11, (STM32_PINMUX_ALT_FUNC_4 | STM32_PUPDR_NO_PULL)},
// #endif	/* CONFIG_UART_3 */
#ifdef CONFIG_UART_4
    {STM32_PIN_PA0, (STM32_PINMUX_ALT_FUNC_4 | STM32_PUSHPULL_PULLUP)},
    {STM32_PIN_PA1, (STM32_PINMUX_ALT_FUNC_4 | STM32_PUPDR_NO_PULL)},
#endif /* CONFIG_UART_4 */
#ifdef CONFIG_I2C_1
    {STM32_PIN_PB8, STM32F0_PINMUX_FUNC_PB8_I2C1_SCL},
    {STM32_PIN_PB9, STM32F0_PINMUX_FUNC_PB9_I2C1_SDA},
#endif /* CONFIG_I2C_1 */
};

static int pinmux_stm32_init(struct device *port)
{
    ARG_UNUSED(port);

    stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

    return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
         CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
