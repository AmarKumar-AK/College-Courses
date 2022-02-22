#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h> //for char driver support

int fopen(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return 0;

}

ssize_t fread(struct file *pfile, char __user *buffer, size_t length, loff_t *offset){
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return 0;

}

ssize_t fwrite(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return length;//return the no. of bytes in the buffer

}

int fclose(struct inode *pinode, struct file *pfile){
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    return 0;

}

//to hold the file operations performed on the device
struct file_operations file_ops = {
    .owner = THIS_MODULE,
    .open = fopen,
    .read = fread,
    .write = fwrite,
    .release = fclose,
};//functions




int amar_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    //register with the kernel and indicate that we registered a char dd
    register_chrdev(210 ,"lab6 Amar Kumar - ced17i029", &file_ops);/*major num, name of driver , file operations*/
    //registered device should be a pointer to the file operation.
    return 0;
}

void amar_module_exit(void){
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
    //unregister the char dd
    unregister_chrdev(210,"lab6 Amar Kumar - ced17i029");
}
module_init(amar_module_init);
module_exit(amar_module_exit);
