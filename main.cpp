#include "functions.h"

int main (void) {

    FILE *in_binary = fopen ("HAMLET.txt", "rb");

    if ( in_binary == NULL) {

        puts ("FILE_INPUT_NOT_FOUND");

        return ERROR_FILE_INPUT_INCORRECT;
    }

    TEXT text = {};

    char *buffer = rabota (&text, in_binary);

    fclose (in_binary);



    JOJO *array_sort = (JOJO*)malloc(sizeof (JOJO) * text.number_lines);

    if (array_sort == NULL) {

      puts ("ERROR IN MEMORY ALLOCATION");

      return ALLOCATION_MEMORY_ERROR;
    }

    array_sort_fillin (buffer, array_sort, text.number_lines);


    //qss(array_sort, 0, number_lines - 1);

    sort_array_BUBBLE (array_sort, text.number_lines, comp_void);

    // qsort (array_sort, text.number_lines, sizeof (JOJO), comp_void);


    FILE *out = fopen ("HAMLET_SORTED.txt", "w");
    if (out == NULL) {

        puts ("FILE_INPUT_NOT_FOUND");

        return ERROR_FILE_OUTPUT_INCORRECT;
    }

    output_sorted (array_sort, text.number_lines, out);
    ouput_separation (out);
    output_ne_sorted (buffer, text.number_lines, out);
    ouput_separation (out);

    qsort (array_sort, text.number_lines, sizeof (JOJO), comp_void_reverse);
    //sort_array_BUBBLE_reverse (array_sort, text.number_lines);
    output_sorted (array_sort, text.number_lines, out);

    free (buffer);
    free (array_sort);
    fclose (out);

return 0;
}
