#include "functions.h"

int main (void) {

    setlocale (LC_ALL, "ru_RU.cp1251");

    FILE *in_binary = fopen ("HAMLET.txt", "rb");

    if ( in_binary == NULL) {

        printf ("FILE_INPUT_NOT_FOUND\n");

        return ERROR_FILE_INPUT_INCORRECT;
    }


    TEXT text = {};
    int error = TEXT_struct_fillin (&text, in_binary);

    if (error == ERROR_IN_READING_FROM_FILE) {

        printf ("ERROR_IN_READING_FROM_FILE\n");

        return ERROR_IN_READING_FROM_FILE;
    }

    else if (error == ERROR_IN_FILLIN_BUFFER) {

        printf ("ERROR_IN_FILLIN_BUFFER\n");

        return ERROR_IN_FILLIN_BUFFER;
    }

    else if (error == ALLOCATION_MEMORY_ERROR) {
        puts ("ERROR IN MEMORY ALLOCATION");

        return ALLOCATION_MEMORY_ERROR;
    }

    fclose (in_binary);


    //янпрхпнбйю он юктюбхрс
    //ЯБНИ qsort
    //qss (text.array_pointers, text.number_lines, comp_void);

    //ЯБНИ АЮАК
    // pointers_struct_BUBBLE (text.array_pointers, text.number_lines, comp_void);

    //БЯРПНЕММШИ qsort
    qsort (text.array_pointers, text.number_lines, sizeof (JOJO), comp_void);


    FILE *out = fopen ("HAMLET_SORTED.txt", "w");

    if (out == NULL) {

        puts ("FILE_OUTPUT_NOT_FOUND");

        return ERROR_FILE_OUTPUT_INCORRECT;
    }


    //бшбнд нрянпрхпнбюммнцн он юктюбхрс
    output_sorted (text.array_pointers, text.number_lines, out);
    ouput_separation (out);
    output_ne_sorted (text.buffer, text.number_lines, out);
    ouput_separation (out);


    //янпрхпнбйю напюрмюъ
    //qsort (pointers_struct, text.number_lines, sizeof (JOJO), comp_void_reverse);
    pointers_struct_BUBBLE (text.array_pointers, text.number_lines, comp_void_reverse);


    //бшбнд напюрмюъ янпрхпнбйю
    output_sorted (text.array_pointers, text.number_lines, out);

    fclose (out);

    //pointers_struct_destructor (pointers_struct);
    //TEXT_struct_destructor (&text);

    return 0;
}
