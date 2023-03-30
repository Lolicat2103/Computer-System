/**
 * Student name: Nguyen Ngoc Phuc Tien
 * Number of assignment: 4
 * Name of file: NguyenNgocPhucTien_Assignment_4.c
*/

#include "NguyenNgocPhucTien_Assignment_4.h"

int count = 0;

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

/*
Rename the structure data type "structure USB" with shorter name "USB"
*/
typedef struct USB USB; 


/*
The function display_USB_infomation takes two parameters: a pointer to a structure USB named "usb" and an integer i, 
representing the index of the USB is called (Note that if i=-1, it means the user wants to print the maximum number of uses). 
The function only prints the information about the USB on the standard output stream using printf function.

The function does not have any checked runtime errors. 
*/
void display_USB_infomation(USB *usb, int i) {
    if (i != -1) {
        printf("The information on USB %d are: \n", i+1);
    }
    else {
        printf("The USB with max number of uses has infomation: \n");
    };
    printf("Name of USB: %s", usb->name);
    printf("Real capacity: %d\n", usb->capacity);
    printf("Serial num: %d\n", usb->serial_number);
    printf("Number of uses: %d\n", usb->number_of_uses);
    printf("\n");
}


/*
The function input_USB_infomation takes two parameters: a pointer to a structure USB named "usb" and an integer i, representing 
the index of the USB is called. 

The function using while loop to read and check input from the user about the information on the usb, including: 
its name (while loop is not applied to this one), its capacity, its serial number and its number of uses, with the condition 
that all information (except the name) must not be negative. The number of input trials must not exceed 3, which is strictly 
controlled by the global variable "count". If all the input information are valid, they will be stored in the corresponding 
parameter of the struct. 

The function does not have any checked runtime errors. 

The function does not have a return value.
*/
void input_USB_infomation(USB *usb, int i) {
    char c;
    int capacity = -1;
    int serial_number = -1;
    int number_of_uses = -1;

    printf("Enter information on USB %d: \n", i+1);
    printf("Enter name of USB: ");

    while ((c = getchar()) == '\n');
    ungetc(c, stdin);

    fgets(usb->name, 31, stdin);

    while (count < 3) {
        printf("Enter real capacity: ");
        scanf("%d", &capacity);
        count ++;

        if (capacity >= 0){
            count = 0;
            break;
        }
    };
        
    while (count < 3) {
        printf("Enter serial number: ");
        scanf("%d", &serial_number);
        count ++;

        if (serial_number >= 0){
            count = 0;
            break;
        }
    };

    while (count < 3) {
        printf("Enter number of uses: ");
        scanf("%d", &number_of_uses);
        count ++;
        if (number_of_uses >= 0){
            count = 0;
            break;
        }
    };    

    usb->capacity = capacity;
    usb->number_of_uses = number_of_uses;
    usb->serial_number = serial_number;

}


/*
This function find_index_USB_max_uses takes in two parameters: a pointer to a structure USB named "usbs_list", 
and number_of_USB, an integer that specifies the number of usbs. 

The function returns the index of the USB with the highest number of uses (which is an integer). Before comparing
the "number_of_USB" of a usb with the local variable "max_uses" to find the max uses, it will check if the structure 
exists or not (exist means having the values of the parameters input by the user; do not exist means one of the parameter 
is wrongly input more than 3 times and thus the program won't allow further input actions and won't take into account 
all the remaining structures). If the capacity, serial_number andnumber_of_uses of a usb are all -1 at the same time, 
the function will end halfway and not consider the remaining structures.

The function does not have any checked runtime errors. 
*/
int find_index_USB_max_uses(USB *usbs_list, int number_of_USB) {
    int max_uses = 0;
    int i;
    int index_max_uses = -1;

    for (i = 0; i < number_of_USB; i++) {
        USB *usb;
        usb = &usbs_list[i];
        if ((usb->capacity) == -1 && (usb->serial_number) == -1 && (usb->number_of_uses) == -1) 
            return index_max_uses;
        if ((usb->number_of_uses) > max_uses && (usb->number_of_uses) > 0) {
            max_uses = usb->number_of_uses;
            index_max_uses = i;
        }
    }
    
    return index_max_uses;
}


int main() {
    USB *usbs_stored;
    int n;
    int i;
    int index_max_uses;
    
    printf("Enter number of USB (n): ");
    scanf("%d", &n);

    /*
    allocates memory for an array of 'n' USB structures using the malloc();
    "getchar()" is used to consume any leftover input in the buffer
    */
    usbs_stored = (USB*) malloc(n * sizeof(USB));
    getchar(); 


    /*
    use for loop to iterate over each USB structure to run the input function for user to input the values of
    the parameters in each USB. It will stop allowing input if the global variable "count" is 3.
    */
    for (i = 0; i < n; i++) {
        if (count != 3) {
            input_USB_infomation(&usbs_stored[i], i);
            printf("\n");
        }
    }

    /*
    use for loop to iterate over each USB structure to run the display function for each USB, with the condition that
    all the parameters in the usb structure are validly input by the users (if one of the parameters is wrongly input
    for more than 3 times, which means its value is -1, the loop will break).
    */
    for (i = 0; i < n; i++) {
        USB *usb;
        usb = &usbs_stored[i];
        if ((usb->capacity) == -1 || (usb->number_of_uses) == -1 || (usb->serial_number) == -1) {
            break;        
        }
        else {
            display_USB_infomation(usb, i);
        }
    }

    index_max_uses = find_index_USB_max_uses(usbs_stored, n);
    display_USB_infomation(&usbs_stored[index_max_uses], -1);

    /*
    deallocate the memory
    */
    free(usbs_stored);
    return 0;
}