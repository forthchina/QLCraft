
#include "board_pin_mux.h"
#include "board_clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#define EXAMPLE_LED_GPIO     BOARD_USER_LED_GPIO
#define EXAMPLE_LED_GPIO_PIN BOARD_USER_LED_GPIO_PIN

volatile bool g_pinSet = false;

void _close(void)
{
}

void _lseek(void)
{
}

void _read(void)
{
}

void _write(void)
{
}

int main(void)
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};

    /* Board pin, clock, debug console init */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */

    PRINTF("\r\n GPIO Driver example\r\n");
    PRINTF("\r\n The LED is blinking.\r\n");

    /* Init output LED GPIO. */
    GPIO_PinInit(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, &led_config);

    while (1)
    {
        SDK_DelayAtLeastUs(100000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#if (defined(FSL_FEATURE_IGPIO_HAS_DR_TOGGLE) && (FSL_FEATURE_IGPIO_HAS_DR_TOGGLE == 1))
        GPIO_PortToggle(EXAMPLE_LED_GPIO, 1u << EXAMPLE_LED_GPIO_PIN);
#else
        if (g_pinSet)
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 0U);
            g_pinSet = false;
        }
        else
        {
            GPIO_PinWrite(EXAMPLE_LED_GPIO, EXAMPLE_LED_GPIO_PIN, 1U);
            g_pinSet = true;
        }
#endif /* FSL_FEATURE_IGPIO_HAS_DR_TOGGLE */
    }
}
