#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "malloc.h"
#include "sys\stat.h"
#include "stdlib.h"


const int column = 100;

typedef struct JOJO {
    int len_str;
    char *str;

}JOJO;


enum ERRORS {

ERROR_FILE_INCORRECT       = 1,
ALLOCATION_MEMORY_ERROR    = 2,
ERROR_IN_READING_FROM_FILE = 3

};


int comp (char *str1, char *str2);

int ass_comp (char *uno, char *duo, int len1, int len2);

int FILESIZE_FUNC_VLOB (FILE *in);

int FILESIZE_FUNC (FILE *in);

int number_lines_in_array_LEHA (char* str);

void copy_arrays (char source[][column], char destination[][column] , int lines);

void JOJO_FILLIN (char* str, JOJO* array_sort, int number_lines);

void sort_array_BUBBLE (JOJO *str, int lines);

void output_sorted (JOJO *str, int num_lines, FILE *out);

void output_ne_sorted (char* str, int num_lines, FILE *out);

char *check (char *kek);

char *ass_check (char *kek);

void ass_sort_array_BUBBLE (JOJO *str, int lines);


#endif // FUNCTIONS_H_INCLUDED
