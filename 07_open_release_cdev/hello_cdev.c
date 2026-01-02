#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int my_init(void);
static void my_exit(void);

static int major;

// override function to read char device file
// called whenever cat is called on device file
static int my_open(struct inode *inode, struct file *fileptr) {
	pr_info("hello_cdev - Major: %d, hello_cdev - Minor: %d\n", imajor(inode), iminor(inode));

	pr_info("hello_cdev - fpos: %lld\n", fileptr->f_pos);
	pr_info("hello_cdev - f_mode: 0x%x\n", fileptr->f_mode);
	pr_info("hello_cdev - f_flags: 0x%x\n", fileptr->f_flags);

	return 0;
}

static int my_release(struct inode *inode, struct file *fileptr) {
	pr_info("hello_cdev - releasing file");
	return 0;
}

// specify file operations
static struct file_operations fops = {
	.open = my_open,
	.release = my_release
};

// on driver initialization, register new character device
static int __init my_init(void) {
	major = register_chrdev(0, "hello_cdev", &fops);
	if (major < 0) {
		printk("Error registering device: %d\n", major);
		return major;
	}
	printk("Successfully registered chrdev %d\n", major);
	return 0;
}

// on exit, unregister device
static void __exit my_exit(void) {
	printk("Unregistering device, goodbye!\n");
	unregister_chrdev(major, "hello_cdev");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("srikar-eranky");
MODULE_DESCRIPTION("Character device driver");

