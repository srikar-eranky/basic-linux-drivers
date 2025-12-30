#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int my_init(void);
static void my_exit(void);

static int major;

static ssize_t my_read(struct file *f, char __user *u, size_t t, loff_t *l) {
	printk("Reading from file\n");
	return 0;
}

static struct file_operations fops = {
	.read = my_read
};

static int __init my_init(void) {
	major = register_chrdev(0, "hello_cdev", &fops);
	if (major < 0) {
		printk("Error registering device: %d\n", major);
		return major;
	}
	printk("Successfully registered chrdev %d\n", major);
	return 0;
}

static void __exit my_exit(void) {
	printk("Unregistering device, goodbye!\n");
	unregister_chrdev(major, "hello_cdev");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srikar-eranky");
MODULE_DESCRIPTION("Character device driver");

