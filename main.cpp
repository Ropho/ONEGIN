#include "stdio.h"
#include "string.h"

const int column = 10;
const int line   = 3;

int main (void) {

    char array_strings [line][column] ={};

    for (int i = 0; i < line; ++i) {          //vvod ((((

        gets (array_strings[i]);
        //puts (array_strings[i]);
    }
/*
 for (int i = 0; i < line; ++i) {        // ne robit

        puts (array_strings[i]);
    }
*/
    for(int i = 1; i < line; ++i) {                 //пузырек
            char str[column] = "";

        for(int j = 0; j < line - i; ++j) {

            if (strcmp(array_strings[j], array_strings[j+1]) > 0){
                    strcpy(str, array_strings[j]);
                    strcpy(array_strings[j], array_strings[j+1]);
                    strcpy(array_strings[j+1], str);
                    //puts (str);
            }
            //puts (str);
    }
}
//return 0;
 for (int i = 0; i < line; ++i) {        // ne robit

        puts (array_strings[i]);
    }
}
