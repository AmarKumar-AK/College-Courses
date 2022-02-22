///////////Amar Kumar///////////////
//////////CED17I029////////////////

#include<linux/module.h>
static int amar = 22;

int init_module(void)
{
    printk("Module is inserted by Amar Kumar\n");
    printk("Interger parameter :  %d\n",amar);
    return 0;
}

void cleanup_module(void)
{
    printk("Module is removed by Amar Kumar\n");
}

module_param(amar,int,0);
MODULE_LICENSE("GPL");
