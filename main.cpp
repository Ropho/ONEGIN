#include "functions.h"

int main (void) {

    setlocale (LC_ALL, "ru_RU.cp1251");

    FILE *in_binary = fopen ("E_HAMLET.txt", "rb");

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

    ////////////////////////////////
    // СОРТИРОВОЧКА ПО АЛФАВИТИКУ //
    //      (на отличненько)      //
    ////////////////////////////////

    //свой qsort
    qss (text.array_pointers, text.number_lines, comp_void);

    //свой бабл
    // pointers_struct_BUBBLE (text.array_pointers, text.number_lines, comp_void);

    //встроенный qsort
    //qsort (text.array_pointers, text.number_lines, sizeof (JOJO), comp_void);

    FILE *out = fopen ("HAMLET_SORTED.txt", "w");

    if (out == NULL) {

        puts ("FILE_OUTPUT_NOT_FOUND");

        return ERROR_FILE_OUTPUT_INCORRECT;
    }

    //ВЫВОД ОТСОРТИРОВАННОГО ПО АЛФАВИТУ
    output_sorted (text.array_pointers, text.number_lines, out);
    output_separation (out);
    output_ne_sorted (text.buffer, text.number_lines, out);
    output_separation (out);


    //СОРТИРОВКА ОБРАТНАЯ
    //встроенная qsort
    //qsort (text.array_pointers, text.number_lines, sizeof (JOJO), comp_void_reverse);
    //бабл сорт
    pointers_struct_BUBBLE (text.array_pointers, text.number_lines, comp_void_reverse);
    //свой qsort
    //qss (text.array_pointers, text.number_lines, comp_void_reverse);

    //ВЫВОД ОБРАТНАЯ СОРТИРОВКА
    output_sorted (text.array_pointers, text.number_lines, out);

    fclose (out);

    TEXT_struct_destructor (&text);

    return 0;
}

