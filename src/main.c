#include <assert.h>
#include <errno.h>
#include <soc.h>
#include <stddef.h>
#include <string.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/settings/settings.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/poweroff.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/types.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/uuid.h>

#include <bluetooth/services/hids.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/bluetooth/services/dis.h>

static void bt_ready(int err)
{
    if (err) {
        printk("Bluetooth init failed (err %d)\n", err);
        return;
    }
    printk("Bluetooth initialized\n");

    /* Start advertising */
    err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, NULL, 0, NULL, 0);
    if (err) {
        printk("Advertising failed to start (err %d)\n", err);
        return;
    }
    printk("Advertising successfully started\n");
}

void main(void)
{
    printk("Starting Bluetooth Peripheral example\n");

    int err = bt_enable(bt_ready);
    if (err) {
        printk("Bluetooth enable failed (err %d)\n", err);
    }

    /* main loop */
    while (1) {
        k_sleep(K_SECONDS(1));
    }
}
