#include "functions.h"

void pointers_struct_destructor (JOJO *pointers_struct) {

    free (pointers_struct);

}

void TEXT_struct_destructor (TEXT *text) {

    free (text);
}

void ouput_separation (FILE *out) {

    assert (out != NULL);

    fputs ("\n*********************************************************************************"
           "*******************************************************\n"
           "***********************************************************************************"
           "*****************************************************\n\n", out);
}

void TEXT_struct_fillin (TEXT* text, FILE *in_binary) {

    assert (text != NULL);
    assert (in_binary != NULL);


    text->filesize = FILESIZE_FUNC_FSTAT (in_binary);


    text->buffer = (char*)calloc(text->filesize + 1, sizeof(char));

    assert (text->buffer != NULL);



    if (fread (text->buffer, sizeof(char), text->filesize, in_binary) != text->filesize) {

      puts ("ERROR IN READIN FROM FILE");

      assert (0);
    }


    text->number_lines = number_lines_in_buffer (text->buffer);

    text->buffer[text->filesize] = '\0';

    return;
}


void qss (JOJO *a, int first, int last) {

    if (first < last)
    {
        int left = first, right = last;

        char middle[100] = {};

        strcpy (middle, a[(left + right) / 2].str);

        do
        {
            while (comp_void (&a[left].str , &middle) < 0) left++;
            while (comp_void (&a[right].str, &middle) > 0) right--;

            if (left <= right)
            {
                char tmp[100] = {};
                strcpy (tmp, a[left].str);
                strcpy(a[left].str, a[right].str);
                strcpy (a[right].str ,tmp);
                left++;
                right--;
            }
        } while (left <= right);

        qss (a, first, right);

        qss (a, left, last);
    }
}



size_t FILESIZE_FUNC_FSTAT (FILE *in) {

    assert (in != NULL);

    struct stat buff = {};

    fstat (fileno (in), &buff);

    return buff.st_size;
}


size_t number_lines_in_buffer (char* str) {

    assert (str != NULL);

    int num_of_lines = 0;

    while (strchr (str, '\n') != NULL) {

        ++num_of_lines;
        str = strchr (str, '\n') + 1;
    }

    return num_of_lines + 1;
}


void pointers_struct_fillin (char* str, JOJO* array_sort, int number_lines) {

    assert (str != NULL);
    assert (array_sort != NULL);

        char *start = str;
        char *finish = NULL;

    for (int i = 0; i < number_lines; ++i) {

        if (i == number_lines - 1) {

        array_sort[i].str = start;
        array_sort[i].len_str = strlen (array_sort[i].str);

        return;

        }

        char *finish = strchr (start, '\n');

        *finish = '\0';

        array_sort[i].str = start;
        array_sort[i].len_str = finish - start;

        start = finish + 1;
    }
}


void pointers_struct_BUBBLE (JOJO *str, int lines, int (*comparator)(const void*, const void*)) {

    assert (str != NULL);

     for (int i = 1; i < lines; ++i) {

        JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

              if (comparator (&str[j], &str[j + 1]) == 1) {

                    s = str[j];
                    str[j] = str[j + 1];
                    str[j + 1] = s;
            }
        }
    }
}


void output_sorted (JOJO *str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str[i].str, out);
        //fputc ('\n', out);
    }
    return;
}


void output_ne_sorted (char* str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str, out);
        //fputc ('\n', out);
        str = strchr (str, '\0') + 1;
    }
    fputc ('\n', out);

    return;
}


char *find_alnum (char *ch) {

    assert (ch != NULL);

        while (1) {

            if (isalnum (*ch))
                    return ch;

            else
                ++ch;
        }
}


int comp_void (const void *first, const void *second) {

    assert (first  != NULL);
    assert (second != NULL);

    char *str1 = ((JOJO *)first)  -> str;
    char *str2 = ((JOJO *)second) -> str;


    while (*str1 != '\0' && *str2 != '\0') {

            str1 = find_alnum (str1);
            str2 = find_alnum (str2);

            if (*str1 > *str2) {

                return 1;
            }

            else if (*str1 < *str2) {

                return -1;
            }
            else {
                ++str1;
                ++str2;
            }

    }

    if (*str1 == '\0') {

         return -1;
    }
    else return 1;
}


int comp_void_reverse (const void *first, const void *second) {

    assert (first  != NULL);
    assert (second != NULL);

    char *uno = ((JOJO *)first)  -> str;
    char *duo = ((JOJO *)second) -> str;

    char *str1 = uno + strlen (uno) - 1;
    char *str2 = duo + strlen (duo) - 1;


    while (str1 != uno && str2 != duo) {

            str1 = find_alnum_reverse (str1);
            str2 = find_alnum_reverse (str2);

            if (*str1 > *str2) {

                return 1;
            }

            else if (*str1 < *str2) {

                return -1;
            }
            else {
                --str1;
                --str2;
            }

    }


    if (*str1 > *str2) {

         return 1;
    }
    else return -1;
}



char *find_alnum_reverse (char *ch) {

    assert (ch != NULL);

        while (1) {

            if (isalnum (*ch))
                    return ch;

            else
                --ch;
        }
}


void pointers_struct_BUBBLE_reverse (JOJO *str, int lines) {

    assert (str != NULL);

     for (int i = 1; i < lines; ++i) {

            JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

              if (comp_void_reverse (&str[j], &str[j+1]) == 1) {

                    s = str[j];

                    str[j] = str[j+1];

                    str[j+1] = s;

            }
        }
    }
}
