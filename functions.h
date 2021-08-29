//! @mainpage


#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "TXLib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "malloc.h"
#include "sys\stat.h"
#include "stdlib.h"
#include "ctype.h"
#include "locale.h"

//!
typedef struct JOJO {

    size_t len_str;
    char *str;

}JOJO;


typedef struct TEXT {

    size_t number_lines;
    size_t filesize;
    char *buffer;
    JOJO *array_pointers;
} TEXT;


enum ERRORS {

ERROR_FILE_INPUT_INCORRECT  = 1,
ERROR_FILE_OUTPUT_INCORRECT = 2,
ALLOCATION_MEMORY_ERROR     = 3,
ERROR_IN_READING_FROM_FILE  = 4,
ERROR_IN_FILLIN_BUFFER      = 5
};

//! \brief prints '*' symbols to separate sorted text, not sorted text, and reversed sorted text
//! \param[in] out - file, in which we want to separate texts
void ouput_separation (FILE *out);

//! \brief fills in the parameters of the structure TEXT using the given file
//! \param[in] text - pointer on the structure TEXT
//! \param[in] in_binary - pointer on the file, from which we want to fill in the structure
//! \return 0 if input is ok, not zero if error in input
int TEXT_struct_fillin (TEXT* text, FILE *in_binary);

//! \brief quicksort
void qss (JOJO *a, int number_linesm, int (*comparator)(const void*, const void*));

//! \param[in] in - pointer on the file
//! \return filesize of the given file
size_t FILESIZE_FUNC_FSTAT (FILE *in);

//! \brief counts the number of lines in the buffer
//! \param[in] str - pointer on the buffer
//! \return number of lines in the buffer
size_t number_lines_in_buffer (char* str);

//! \brief fills in JOJO struct (struct with pointers on buffer's lines and its length)
//! \param[in] str - pointer on buffer
//! \param[in] array_sort - structure, which we want to fill in
//! \param[in] number_lines - number of lines in the buffer
void pointers_struct_fillin (char* str, JOJO* array_sort, int number_lines);

//! \brief sorts the JOJO structure array using given comparator
//! \param[in] lines - number of elements in the structure array
//! \param[in] (*comparator)(const void*, const void*) pointer on the comparator function
void pointers_struct_BUBBLE (JOJO *str, int lines, int (*comparator)(const void*, const void*));

//! \brief prints out the JOJO structure array in the given file
//! \param[in] str - JOJO structure array
//! \param[in] num_lines - JOJO structure array size
//! \param[in] out - pointer on the file, in which we want to print the array
void output_sorted (JOJO *str, int num_lines, FILE *out);

//! \brief prints out the buffer in the given file
//! \param[in] str - buffer
//! \param[in] num_lines - number of lines in buffer
//! \param[in] out - pointer on the file, in which we want to print the buffer
void output_ne_sorted (char* str, int num_lines, FILE *out);

//! \brief finds the character in the buffer, which is a number or a letter. Goes from the start of the buffer to the end
//! \param[in] kek - pointer on the element of the buffer
//! \return pointer on the wanted character in the buffer
char *find_alnum (char *kek);

//! \brief finds the character in the buffer, which is a number or a letter. Goes from end of the buffer to the start
//! \param[in] kek - pointer on the element of the buffer
//! \return pointer on the wanted character in the buffer
char *find_alnum_reverse (char *kek);

//! \brief
int comp_void (const void *first, const void *second);

int comp_void_reverse (const void *first, const void *second);

void pointers_struct_destructor (JOJO *pointers_struct);

void TEXT_struct_destructor (TEXT *text);

#endif // FUNCTIONS_H_INCLUDED
