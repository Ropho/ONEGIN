#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "malloc.h"

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

int FILESIZE_FUNC_VLOB (FILE *in) {

    assert (in != NULL);

	int file_size = 0;
	fseek (in, 0, SEEK_SET);


    while (getc(in) != EOF)
        file_size++;

	return file_size;
}

/*
int FILESIZE_FUNC (FILE *fp) {

    assert (fp != NULL);

    int save_pos = 0, size_of_file = 0;

    save_pos = ftell (fp);
    fseek (fp, 0L, SEEK_END);
    size_of_file = ftell (fp);
    fseek (fp, save_pos, SEEK_SET);

    return (size_of_file);
}


void input_from_file (FILE *in, char array_strings[][column], int lines) {

    assert (in != NULL);
    assert (array_strings != NULL);

    for (int i = 0; i < lines; ++i)
        fgets (array_strings[i], column , in);
}


void output_in_file (FILE *out, char array_strings[][column], int lines) {

    assert (out != NULL);
    assert (array_strings != NULL);

    for (int i = 0; i < lines; ++i)
        fputs (array_strings[i], out);

}

*/
int number_lines_in_array (char* str, int filesize) {

    assert (str != NULL);

    int num_of_lines = 0, i = 0;

    while (i < filesize) {

        if (*(str + i) == '\n')
            num_of_lines++;

        ++i;
    }

    num_of_lines++;

    return num_of_lines;
}


void copy_arrays (char source[][column], char destination[][column] , int lines) {

     assert (source != NULL);
     assert (destination != NULL);

     for (int i = 0; i < lines; ++i)
        strcpy (destination[i], source[i]);

     return;
}


void bubble_sort (char array_sort[][column], int lines) {

     for (int i = 1; i < lines; ++i) {                 //BUBBLE SORT
            char str[column] = "";

        for (int j = 0; j < lines - i; ++j) {

            if (strcmp(array_sort[j], array_sort[j+1]) > 0){

                    strcpy(str, array_sort[j]);
                    strcpy(array_sort[j], array_sort[j+1]);
                    strcpy(array_sort[j+1], str);

            }
        }
    }
}


void JOJO_FIILIN (char* str, JOJO ) {

                    //юзать strchr
                    //заменять в кнце строки \n на \0
}

int main (void) {

    FILE *in = fopen ("HAMLET.txt", "r");

    if (in == NULL) {
        puts ("FILE_NOT_FOUND");

        return ERROR_FILE_INCORRECT;
    }


    int filesize = FILESIZE_FUNC_VLOB (in);

    char *array_strings = (char*)malloc(filesize * sizeof(char));

    if (array_strings == NULL) {
      puts ("ERROR IN MEMORY ALLOCATION");

      return ALLOCATION_MEMORY_ERROR;
    }

    fseek (in, 0, SEEK_SET);

    if (fread (array_strings, 1, filesize, in) != filesize) {
      puts ("ERROR IN READIN FROM FILE");

      return ERROR_IN_READING_FROM_FILE;
  }
    fclose (in);

    int number_lines = number_lines_in_array (array_strings,filesize);


    JOJO array_sort[number_lines];      //sozdal massiv

    JOJO_FILLIN;

    for (int i = 0; i < number_lines; ++i) {

        array_sort[i].str = array_strings[i];

        array_sort[i].len_str = strlen (array_sort[i].str);

    }                                    //zapolnyayu ego

/*

    copy_arrays (array_nesort, array_sort, lines);

    bubble_sort (array_sort, lines);


    FILE *out = fopen ("HAMLET_SORTED.txt", "w");

        if (out == NULL)
            return ERROR_FILE_INCORRECT;

    output_in_file (out, array_sort,   lines);
    output_in_file (out, array_nesort, lines);
    fclose (out);
*/
return 0;
}
