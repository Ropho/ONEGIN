#include "TXLib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"


const int column = 100;


enum ERRORS {

ERROR_FILE_INCORRECT = 1

};


void input_from_file (FILE *in, char array_strings[][column], int lines) {

    assert (in != NULL);
    assert (array_strings != NULL);

    for (int i = 0; i < lines; ++i)
        fgets (array_strings[i], column, in);
}


void output_in_file (FILE *out, char array_strings[][column], int lines) {

    assert (out != NULL);
    assert (array_strings != NULL);

    for (int i = 0; i < lines; ++i)
        fputs (array_strings[i], out);

}


int number_lines_in_file (FILE *in) {

    assert (in != NULL);

    char str[column] = {};
    int  i = 0;

    while (fgets (str, column, in) != NULL) {

        ++i;

    }
    return i;
}

void copy_arrays (char source[][column], char destination[][column] ,int lines) {

     assert (source != NULL);
     assert (destination != NULL);

     for (int i = 0;i < lines; ++i) {
        strcpy (destination[i], source[i]);
     }

     return;
}

int main (void) {

    FILE *num_lines = fopen ("HAMLET.txt", "r");
    if (num_lines == NULL)
        return ERROR_FILE_INCORRECT;
    int lines = number_lines_in_file (num_lines);
    fclose (num_lines);
                                                            //как перевести каретку заново на начало файла?
                                                            //приходиться переоткрывать файл

    FILE *in = fopen ("HAMLET.txt", "r");
    if (in == NULL)
        return ERROR_FILE_INCORRECT;

    char array_nesort [lines][column] = {};
    char array_sort [lines][column] = {};

    input_from_file (in, array_nesort, lines);

    fclose (in);

    copy_arrays (array_nesort, array_sort, lines);


    for (int i = 1; i < lines; ++i) {                 //BUBBLE SORT
            char str[column] = "";

        for(int j = 0; j < lines - i; ++j) {

            if (strcmp(array_sort[j], array_sort[j+1]) > 0){

                    strcpy(str, array_sort[j]);
                    strcpy(array_sort[j], array_sort[j+1]);
                    strcpy(array_sort[j+1], str);

            }
        }
    }


    FILE *out = fopen ("HAMLET_SORTED.txt", "w");      //vivod sort
        if (out == NULL)
            return ERROR_FILE_INCORRECT;

    output_in_file (out, array_sort,   lines);
    output_in_file (out, array_nesort, lines);
    fclose (out);

return 0;
}
