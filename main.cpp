#include "functions.h"



int main (void) {

    FILE *in = fopen ("HAMLET.txt", "r");
    FILE *out = fopen ("HAMLET_SORTED.txt", "w");
    FILE *in_binary = fopen ("HAMLET.txt", "rb");
    FILE *ass_out = fopen ("HAMLET_ASS.txt", "w");

    if (in == NULL || out == NULL || in_binary == NULL || ass_out == NULL) {

        puts ("FILE_NOT_FOUND");

        return ERROR_FILE_INCORRECT;
    }


    int filesize = FILESIZE_FUNC_VLOB (in);

    //int filesize_LEHA = FILESIZE_FUNC_FSTAT (in_binary);

    //int filesize_NEVLOB = FILESIZE_FUNC (in_binary);

    //printf ("%d\n%d\n%d", filesize, filesize_LEHA, filesize_NEVLOB);
    //return 0;
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

    JOJO array_sort[number_lines];

    JOJO_FILLIN (array_strings, array_sort, number_lines);


    //qss(array_sort, 0, number_lines - 1);

    //sort_array_BUBBLE (array_sort, number_lines);

    qsort (array_sort, number_lines, sizeof (JOJO), comp_void);

    output_sorted (array_sort, number_lines, out);
    output_ne_sorted (array_strings, number_lines, out);


    qsort (array_sort, number_lines, sizeof (JOJO), comp_void_ass);
    ass_sort_array_BUBBLE (array_sort, number_lines);
    output_sorted (array_sort, number_lines, ass_out);


    fclose (in);
    fclose (out);
    fclose (in_binary);
    fclose (ass_out);

return 0;
}
