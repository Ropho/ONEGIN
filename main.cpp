#include "stdio.h"
#include "string.h"

const int column = 10;
const int line   = 3;

int main (void) {

    char array_strings [line][column];

    for (int i = 0; i < line; ++i) {          //vvod ((((

        gets (array_strings[i]);
        //puts (array_strings[i]);
    }

 /*for (int i = 0; i < column; ++i) {        // ne robit

        puts (array_strings[i]);
    }
*/
    for(int i = 1; i < line; i++) {
            char str[100] = "";

        for(int j = 0; j < column - i; j++)
            if(strcmp(array_strings[j], array_strings[j+1]) > 0){
                strcpy(str, array_strings[j]);
                strcpy(array_strings[j], array_strings[j+1]);
                strcpy(array_strings[j+1], str);
            }
    }

    for (int i = 0; i < line; ++i) {          //vivod posimvolno
        for (int j = 0; j < column; ++j)
            putchar (array_strings[i][j]);
        printf("\n");
    }
}
