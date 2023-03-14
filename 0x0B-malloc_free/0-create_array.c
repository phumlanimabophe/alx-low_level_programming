/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the addition of positive numbers,
 *        followed by \n.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 * Return: If one of the numbers contains symbols that are non-digits - 1.
 *         Otherwise - 0.
 */

char *create_array(unsigned int size, char c){
    if (size==0){
        return NULL;
    }
    int* array = (int*) malloc(size * sizeof(int));
    return array;
}

