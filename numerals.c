#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct MyHashMap {
    char key[2];
    int value;
} hashmap;


int searchHashMap(hashmap* my_hashmap, int size, char key) {
    for (int i = 0; i < size;  i++) {
        printf("Checking Key: %s\n", my_hashmap[i].key);
        if (key == my_hashmap[i].key[0]) {
            printf("Match: %d\n", my_hashmap[i].value);
            return my_hashmap[i].value;
        }
    }
    printf("No Match :(\n");
    return 0;
}


int main(void) {
    hashmap my_hashmap[] = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };

    int i;
    int total = 0;
    int arr_length = sizeof(my_hashmap) / sizeof(my_hashmap[0]);
    char numeral[10];
    int numeral_length = strlen(numeral);
    int *decimal_array = (int *)malloc((numeral_length) * sizeof(int));
    printf("Enter Roman Numeral:");
    scanf("%s", numeral);

    for (i = 0; i < numeral_length; i++) {
        int decimal = searchHashMap(my_hashmap, arr_length, numeral[i]);
        decimal_array[i] = decimal;
    }

    printf("----------------------\n");
    
    for (i = 0; i < numeral_length - 1; i++) {
        printf("Number: %d \n",decimal_array[i]);
        if (decimal_array[i] < decimal_array[i + 1]) {
            total -= decimal_array[i];
        }
        else {
            total += decimal_array[i];
        }
    }
    printf("Number: %d\n", decimal_array[numeral_length - 1]);
    total += decimal_array[numeral_length - 1];
    free(decimal_array);
    printf("Total: %d", total);
    return 0;
}