#include <zephyr.h>
#include <sys/printk.h>
#include <logging/log.h>

LOG_MODULE_REGISTER(minimal_usb, LOG_LEVEL_INF);

void main(void)
{
    printk("Starting minimal USB CDC ACM example...\n");
    LOG_INF("USB logging initialized");

    while (1) {
        LOG_INF("Hello from USB CDC ACM");
        k_sleep(K_SECONDS(2));
    }
}
