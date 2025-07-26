#include <zephyr.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <sys/printk.h>

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
