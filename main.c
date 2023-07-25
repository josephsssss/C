#include <stdio.h>
#include "algorithm.h"
#include "memory.h"
#include "vector.h"
#define LENGTH (5)

#define ROWS 3
#define COLS 5


void print_pointer_size(){
    char ch = 'c';
    int number = 12334;
    float pi = 3.1415f;

    char* char_ptr = &ch;
    int* int_ptr = &number;
    float* float_ptr = &pi;

    printf("char size: %lu, char* size: %lu\n", sizeof(*char_ptr), sizeof(char_ptr));
    printf("int size: %d, int* size: %d\n", sizeof(*int_ptr), sizeof(int_ptr));
    printf("float size: %d, float* size: %d\n", sizeof(*float_ptr), sizeof(float_ptr));
}

size_t get_string_length(const char* str){
    size_t count = 0;
    const char* p = str;
    while (*p++ != '\0'){
           ++count;
    }
    return count;
}


int main(void)
{
    const int nums[LENGTH] = {2, 10, 9, 5, 6};
    int min;
    int max;

    get_min_max(nums, LENGTH, &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);
    print_pointer_size();

    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {4, 5, 6, 7, 8};
    char* array3 = (char*)(array1 + 1);
    size_t length1 = ARRAY_LENGTH(array1);
    size_t length2 = ARRAY_LENGTH(array2);


    size_t length3 = (length1 - 1) * sizeof(int);

    int overlap1 = is_overlap((int*)array3, length3/sizeof(int), array2, length2);
    int overlap2 = is_overlap(array1, length1, (int*)array3, length3/sizeof(int));

    if (overlap1 || overlap2)
        printf("The arrays overlap.\n");
    else
        printf("The arrays do not overlap.\n");

    int result = sum(array1, array1 + 5);
    printf("array sum: %d\n", result);

    const int v1[VECTOR_LENGTH] = {1, 3 , 6};
    const int v2[VECTOR_LENGTH] = {3 , 5, 9};
    int v3[VECTOR_LENGTH];

    add_vector3(v1, v2, v3);

    printf("v3: %d, %d, %d\n", v3[0], v3[1], v3[2]);


    int arr[ROWS][COLS];
    int* row_ptrs[ROWS];

    for (int i = 0; i < ROWS; ++i) {
        row_ptrs[i] = &arr[i][0];
    }

    for (int i = ROWS - 1; i >= 0; --i) {
        printf("Start address of row %d: %p\n", i, row_ptrs[i]);
    }

    for (int i = ROWS - 2; i >= 0; --i) {
        printf("Offset of row %d from row %d: %td\n", i, i+1, row_ptrs[i+1] - row_ptrs[i]);
    }


    char* str = "abc";
    printf("string length: %d", get_string_length(str));

    print_ascii_table();

    return 0;
}
