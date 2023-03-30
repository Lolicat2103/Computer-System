#ifndef ASSIGNMENT_4_H
#define ASSIGNMENT_4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif