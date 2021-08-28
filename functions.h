#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//#include "TXLib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "malloc.h"
#include "sys\stat.h"
#include "stdlib.h"
#include "ctype.h"


typedef struct TEXT {

    size_t number_lines;
    size_t filesize;


} TEXT;


typedef struct JOJO {

    // size_t
    int len_str;
    char *str;

}JOJO;


enum ERRORS {

ERROR_FILE_INPUT_INCORRECT  = 1,
ERROR_FILE_OUTPUT_INCORRECT = 2,
ALLOCATION_MEMORY_ERROR     = 3,
ERROR_IN_READING_FROM_FILE  = 4

};
void ouput_separation (FILE *out);

char *rabota (TEXT* text, FILE *in_binary);

void qss (JOJO *a, int first, int last);

int FILESIZE_FUNC_FSTAT (FILE *in);

int number_lines_in_buffer (char* str);

void array_sort_fillin (char* str, JOJO* array_sort, int number_lines);

void sort_array_BUBBLE (JOJO *str, int lines);

void output_sorted (JOJO *str, int num_lines, FILE *out);

void output_ne_sorted (char* str, int num_lines, FILE *out);

char *find_alnum (char *kek);

char *find_alnum_reverse (char *kek);

void sort_array_BUBBLE_reverse (JOJO *str, int lines);

int comp_void (const void *first, const void *second);

int comp_void_reverse (const void *first, const void *second);

#endif // FUNCTIONS_H_INCLUDED
