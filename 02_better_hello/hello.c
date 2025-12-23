#include <linux/module.h>
#include <linux/init.h>

static int my_init(void);
static void my_exit(void);

static int my_init(void) {
	printk("Hello world from the kernel\n");
	return 0;
}

static void my_exit(void) {
	printk("Exiting kernel, goodbye!\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srikar-eranky");
MODULE_DESCRIPTION("Simple hello world kernel module");

