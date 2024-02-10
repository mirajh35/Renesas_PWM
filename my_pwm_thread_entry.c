#include "my_pwm_thread.h"

/* My Pwm Thread entry function */
void my_pwm_thread_entry(void)
{
    g_timer0.p_api->open (g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->dutyCycleSet (g_timer0.p_ctrl, 5, TIMER_PWM_UNIT_PERCENT, 1);
    g_timer0.p_api->start (g_timer0.p_ctrl);
    uint8_t dutycycle = 2;
    while (1)
    {
        tx_thread_sleep (100);
        dutycycle += 2;
        g_timer0.p_api->dutyCycleSet (g_timer0.p_ctrl, (dutycycle % 100), TIMER_PWM_UNIT_PERCENT, 1);
        if(dutycycle == 100)dutycycle = 2;
    }
}
