
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Declare C struct named "USB" with four members: a character array "name" to hold the name of the USB (up to 30 characters), 
an integer "capacity" to hold the capacity of the USB, an integer "serial_number" to hold the serial number of the USB, 
and an integer "number_of_uses" to store the number of times the USB has been used.
*/
struct USB {
    char name[31];
    int capacity;
    int serial_number;
    int number_of_uses;
};

typedef struct USB USB;

void display_USB_infomation(USB *usb, int i);
void input_USB_infomation(USB *usb, int i);
int find_index_USB_max_uses(USB *usbs_list, int number_of_USB);
