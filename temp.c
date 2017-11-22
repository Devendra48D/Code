#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/uaccess.h>



/* kernel variables*/
unsigned int my_accumulator;
char* my_string;

EXPORT_SYMBOL(my_string);
EXPORT_SYMBOL(my_accumulator);

/*
	@descr     Changes the value of the kernel spaces variables my_string and 
		my_accumulator. Makes free previous memory allocated from my_string 
		and reallocates memory from the size of the new string.

	@param    (int) - accumulator: an integer 
	@param    (char *) - the_string: 

	@return   (int) - (0) for success, (-EINVAL) for failure

 */

asmlinkage long sys_my_set_state(char *the_string, int accumulator) {
	
	if (accumulator < 0) {
		return -EINVAL;
	}
	my_accumulator = accumulator;
	printk("\nReceived user value: %d\n", accumulator);
	printk("Value of my_accumulator set as: %d\n\n", my_accumulator);
	// accumulator is passed by value hence needs no locking or copy_from_user()
	unsigned int len_string = strlen_user(the_string);
	// zero out memory
	if (my_string)
        	kfree(my_string);
	// check if allocation fails
	if ((my_string = (char *) kmalloc(len_string, GFP_KERNEL)) == NULL) {
		return -EFAULT;
	}
	//check if copy fails
	if (copy_from_user(my_string, the_string, len_string))
    	{	
		kfree(my_string);
		return -EFAULT;
    	}
	//return success.
	printk("Succeeded in Copying.\n");
	printk("Received user string: %s\n", the_string);
	printk("\nValue of my_string set as: %s\n", my_string);
	return 0;
}

/*
	@descr      Adds the user supplied inc_value to the my_accumulator kernel space variable.

	@param (int*) -  my_value
	@param (int) -  inc_value: value from the user that increments the my_accumulator

	@return (int) - (0) for success, (-EOVERFLOW) for failure

*/

asmlinkage long sys_my_get_and_sum(int *my_value, int inc_value) {
	
	if (inc_value < 0) {
		
		return -EINVAL;
	}
	printk(KERN_INFO "\nCurrent value for my_accumulator: %d\n", my_accumulator);
	printk(KERN_INFO "Given inc_value: %d\n", inc_value);
	if ((my_accumulator + inc_value) >= INT_MAX) {
		return -EOVERFLOW;
	}
	*my_value = my_accumulator + inc_value;
	my_accumulator = my_accumulator + inc_value;
	printk(KERN_INFO "Accumulator new value: %d\n", my_accumulator);
	
	//safely copy to user from kernel
	if (copy_to_user(my_value, &my_accumulator, sizeof(int))) {
		return -EFAULT;
	}
	printk(KERN_INFO "CUrrently my_value pointer points to a value of %d\n", *my_value);
	return 0;
}


/*

	@descr      Adds the user supplied inc_value to the my_accumulator kernel space variable.

	@param (char*) -  buf: The buffer
	@param (int) -  bsize: buffer size supplied by user

	@return (int) - (0) for success, (-ENODATA or -EFAULT) for failure

*/

asmlinkage long sys_my_get_string(char *buf, int bsize) {
	
	unsigned int copylen, slen;
	char* temp_str;
	if (my_string == NULL) {
		return -ENODATA;
	}
	slen = strlen(my_string);
	copylen = min(slen, bsize-1);
	if (copylen == slen) {
		if ((temp_str = (char *) kmalloc(sizeof(slen), GFP_KERNEL)) != NULL) {
			return -EFAULT;
		}
		strcpy(temp_str, my_string);
		if (copy_to_user(buf, temp_str, slen)){
			return -EFAULT;
		}
	}
	else {
		if ((temp_str == (char *) kmalloc(sizeof(bsize), GFP_KERNEL)) != NULL) {
			return -EFAULT;
		}
		strcpy(temp_str, my_string);
		if (copy_to_user(buf, my_string, bsize)) {
			return -EFAULT;
		}
	}
	printk(KERN_INFO "\nmy_string: : %s\n", my_string);
	printk(KERN_INFO "buffer size: %d\n", copylen);
	printk(KERN_INFO "Buffer Value %s\n", buf);
	return 0;
}
