#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "malloc.h"
#include "sys\stat.h"

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


int FILESIZE_FUNC (FILE *in) {

    assert (in != NULL);

    int size_of_file = 0;

    fseek (in, 0, SEEK_END);

    size_of_file = ftell (in);

    fseek (in, 0, SEEK_SET);

    return (size_of_file);
}
/*
int FILESIZE_FUNC_FSTAT (FILE *in) {

    assert (in != NULL);

    struct stat buff;

    fstat (fileno (in), &buff);

    return buff.st_size;
}
*/

/*
int number_lines_in_array_VLOB (char* str, int filesize) {

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
*/

int number_lines_in_array_LEHA (char* str) {

    assert (str != NULL);

    int num_of_lines = 0;


    char *starto = str;

    while (strchr (starto, '\n') != NULL) {

        ++num_of_lines;
        starto = strchr (starto, '\n') + 1;
    }

    return num_of_lines + 1;
}


void copy_arrays (char source[][column], char destination[][column] , int lines) {

     assert (source != NULL);
     assert (destination != NULL);

     for (int i = 0; i < lines; ++i)
        strcpy (destination[i], source[i]);

     return;
}


void JOJO_FILLIN (char* str, JOJO* array_sort, int number_lines) {

    assert (str != NULL);
    assert (array_sort != NULL);

        char *starto = str;
        char *endo = NULL;

    for (int i = 0; i < number_lines; ++i) {

        if (i == number_lines - 1) {

        array_sort[i].str = starto;
        array_sort[i].len_str = strlen (array_sort[i].str);
        //printf ("%s %d\n", array_sort[i].str, array_sort[i].len_str);
        return;

        }

        char *endo = strchr (starto, '\n');
        *endo = '\0';

        array_sort[i].str = starto;
        array_sort[i].len_str = endo - starto;

        //printf ("%s %d\n", array_sort[i].str, array_sort[i].len_str);

        starto = endo + 1;
    }
}


void sort_array_BUBBLE (JOJO *str, int lines) {

    assert (str != NULL);

     for (int i = 1; i < lines; ++i) {
            JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

            if (strcmp(str[j].str, str[j+1].str) > 0) {

                    s.str = str[j].str;
                    s.len_str = str[j].len_str;

                    str[j].str = str[j+1].str;
                    str[j].len_str = str[j+1].len_str;

                    str[j+1].str = s.str;
                    str[j+1].len_str = s.len_str;

            }
        }
    }

}


void output_sorted (JOJO *str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str[i].str, out);
        fputs ("\n", out);
    }
    return;

}


void output_ne_sorted (char* str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    char *starto = str;

    for (int i = 0; i < num_lines; ++i) {

        fputs (starto, out);
        fputs ("\n", out);
        starto = strchr (starto, '\0');
        ++starto;
    }
    return;
}


int main (void) {

    FILE *in = fopen ("HAMLET.txt", "r");
    FILE *out = fopen ("HAMLET_SORTED.txt", "w");
    FILE *in_binary = fopen ("HAMLET.txt", "rb");

    if (in == NULL || out == NULL || in_binary == NULL) {

        puts ("FILE_NOT_FOUND");

        return ERROR_FILE_INCORRECT;
    }


    int filesize = FILESIZE_FUNC_VLOB (in);

    //int filesize_LEHA = FILESIZE_FUNC_FSTAT (in_binary);

   // printf ("%d\n%d", filesize, filesize_LEHA);
   // return 0;
   /////




    char *array_strings = (char*)malloc(filesize * sizeof(char) + 1);

    if (array_strings == NULL) {

      puts ("ERROR IN MEMORY ALLOCATION");

      return ALLOCATION_MEMORY_ERROR;
    }

    fseek (in, 0, SEEK_SET);

    if (fread (array_strings, 1, filesize, in) != filesize) {

      puts ("ERROR IN READIN FROM FILE");

      return ERROR_IN_READING_FROM_FILE;
    }

    array_strings[filesize] = '\0';


    //int number_lines = number_lines_in_array_VLOB (array_strings,filesize);
    int number_lines = number_lines_in_array_LEHA (array_strings);

    JOJO array_sort[number_lines] = {};

    JOJO_FILLIN (array_strings, array_sort, number_lines);

    sort_array_BUBBLE (array_sort, number_lines);

    output_sorted (array_sort, number_lines, out);

    output_ne_sorted (array_strings, number_lines, out);


    fclose (in);
    fclose (out);
    fclose (in_binary);

return 0;
}
