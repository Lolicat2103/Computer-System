/*
* Student name: Nguyen Ngoc Phuc Tien
* Number of assignment: 1
* Name of file: NguyenNgocPhucTien_Assignment_1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
The function replace_notalpha_characters takes in the input string that user entered earlier 
to scan for all characters that are neither numbers or characters. Then, it will replace all 
of those "non alnum" characters with space. The function returns the original string with 
"non alnum" characters replaced by spaces. The function does not generate any runtime errors.
*/
char * replace_notalpha_characters(char *c_raw_string) {
    for (int i =0; c_raw_string[i] != '\0'; i++ ) {
        if (isalnum(c_raw_string[i]) == 0){
            c_raw_string[i] = ' ';
        }
    }
    return c_raw_string;
}


/*
The function adjust_space takes in the input string that user entered earlier but after all 
"non alnum" characters are replaced by spaces. In the function, c_adjusted_string is a new 
static array to store the characters in the c_replaced_string that are not two successive spaces.
Then, it returns the static array c_adjusted_string. The function does not generate any runtime errors.
*/
char * adjust_space(char *c_replaced_string) {
    int i_length_string;
    static char c_adjusted_string[200];
    int j = 0;
    
    for (int i=0; c_replaced_string[i] != '\0'; i++) {
        if (!(c_replaced_string[i] == ' ' && c_replaced_string[i+1] == ' ')){
            c_adjusted_string[j] = c_replaced_string[i];
            j ++;   
        }            
    }
    i_length_string = sizeof c_adjusted_string;
    c_adjusted_string[i_length_string-1] = '\0';
    return c_adjusted_string;
}


/*
The function lowercase_transform takes in c_adjusted_string after the spaces are adjusted
to transform all the characters into lowercases. It returns a static array c_is_lowercase.
The function does not generate any runtime errors.
*/
char * lowercase_transform(char *c_not_lowercase) {
    static char c_is_lowercase[200];
    for (int i = 0; c_not_lowercase[i] != '\0'; i++) {
        c_is_lowercase[i] = tolower(c_not_lowercase[i]);
    }
    return c_is_lowercase;
}


/*
The fuction convert_string executes all the functions above to the input string by the user.
The function does not generate any runtime errors.
*/
char * convert_string(char* c_string) {
    return  lowercase_transform(adjust_space(replace_notalpha_characters(c_string)));
}

int main() {
    char c_input_string[400];
    printf("Enter your string: ");
    fgets(c_input_string, sizeof(c_input_string), stdin);
    printf("Output: %s", convert_string(c_input_string));
    return 0;
}