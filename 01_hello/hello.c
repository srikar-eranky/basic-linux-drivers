#include <linux/module.h>
#include <linux/init.h>

int my_init(void) {
	printk("Hello world from the kernel");
	return 0;
}

void my_exit(void) {
	printk("Exiting kernel, goodbye!");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");


