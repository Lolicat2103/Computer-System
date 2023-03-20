/*
* Student name: Nguyen Ngoc Phuc Tien
* Number of assignment: 3
* Name of file: NguyenNgocPhucTien_Assignment_3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
Swaps the values of the two integer pointers provided as arguments.
parameter i_number1: A pointer to an integer representing the first number to be swapped.
parameter i_number2: A pointer to an integer representing the second number to be swapped.
The function returns: void - The function does not return a value.
The function reads: Nothing from standard input or any other stream.
The function writes: Nothing to standard output, standard error, or any other stream.
The function uses: No global variables are used or affected by this function.
runtime_error: None - The function does not generate any runtime errors.
*/

void swap_numbers(int *i_number1, int *i_number2) {   
    int i_temp;

    i_temp = *i_number1;
    *i_number1 = *i_number2;
    *i_number2 = i_temp;

}

/*
Sorts an integer array in ascending order using the bubble sort algorithm.
parameter c_input_array: A pointer to an integer array to be sorted.
parameter i_number_elements: An integer representing the number of elements in the input array.
The function returns: void - The function does not return a value.
The function reads: Nothing from standard input or any other stream.
The function writes: Nothing to standard output, standard error, or any other stream.
The function uses: This function uses the swap_numbers() function to swap the elements in the array.
runtime_error: None - The function does not generate any runtime errors.
*/

void bubble_sort(int *c_input_array, int i_number_elements) {
    
    for (int i = 0; i < i_number_elements -1; i++) {       
        for (int j = 0; j < i_number_elements -i-1; j++) {
            if (c_input_array[j] > c_input_array[j+1]) {
                swap_numbers(&c_input_array[j], &c_input_array[j+1]);
            }
        }
    }
}


int main() {
    int i_number_elements;
    
    printf("Input number of elements: ");
    scanf("%d", &i_number_elements);
    
    int i_input_array[i_number_elements];
    printf("Input array: ");

    for (int i = 0; i < i_number_elements; i++) {
        scanf("%d", &i_input_array[i]);
    }

    bubble_sort(i_input_array, i_number_elements);

    printf("Output: ");

    for (int i = 0; i < i_number_elements; i++) {
        printf("%d ", i_input_array[i]);
    }
    
    return 0;
}
