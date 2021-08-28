#include "functions.h"

int main (void) {

    FILE *in_binary = fopen ("HAMLET.txt", "rb");

    if ( in_binary == NULL) {

        puts ("FILE_INPUT_NOT_FOUND");

        return ERROR_FILE_INPUT_INCORRECT;
    }

    TEXT text = {};

    TEXT_struct_fillin (&text, in_binary);

    fclose (in_binary);



    JOJO *pointers_struct = (JOJO*)calloc(text.number_lines, sizeof (JOJO));

    if (pointers_struct == NULL) {

      puts ("ERROR IN MEMORY ALLOCATION");

      return ALLOCATION_MEMORY_ERROR;
    }

    pointers_struct_fillin (text.buffer, pointers_struct, text.number_lines);


    //qss (pointers_struct, 0, text.number_lines);

    //pointers_struct_BUBBLE (pointers_struct, text.number_lines, comp_void);

    qsort (pointers_struct, text.number_lines, sizeof (JOJO), comp_void);


    FILE *out = fopen ("HAMLET_SORTED.txt", "w");
    if (out == NULL) {

        puts ("FILE_INPUT_NOT_FOUND");

        return ERROR_FILE_OUTPUT_INCORRECT;
    }

    output_sorted (pointers_struct, text.number_lines, out);
    ouput_separation (out);
    output_ne_sorted (text.buffer, text.number_lines, out);
    ouput_separation (out);

    //qsort (pointers_struct, text.number_lines, sizeof (JOJO), comp_void_reverse);
    pointers_struct_BUBBLE_reverse (pointers_struct, text.number_lines);
    output_sorted (pointers_struct, text.number_lines, out);

    fclose (out);

    pointers_struct_destructor (pointers_struct);
    TEXT_struct_destructor (&text);

return 0;
}
