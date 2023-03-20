/*
* Student name: Nguyen Ngoc Phuc Tien
* Number of assignment: 2
* Name of file: NguyenNgocPhucTien_Assignment_2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
The function uppercase_transform takes in the input string entered by the user. Then, it
transforms all the characters into uppercases. After that, it stores the new characters 
after making uppercase to a new static array c_is_uppercase. It returns the static array 
c_is_lowercase. The function does not generate any runtime errors.
*/
char * uppercase_transform(char *c_not_uppercase) {
    static char c_is_uppercase[200];
    for (int i = 0; c_not_uppercase[i] != '\0'; i++) {
        c_is_uppercase[i] = toupper(c_not_uppercase[i]);
    }
    return c_is_uppercase;
}

int main() {
    char c_input_string[400]; // Declare input string
    printf("Enter your string: ");
    fgets(c_input_string, sizeof(c_input_string), stdin); //input string with size of 400
    printf("Output: %s", uppercase_transform(c_input_string)); 
    return 0;
}