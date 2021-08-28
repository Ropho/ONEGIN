#include "functions.h"

void ouput_separation (FILE *out) {

    assert (out != nullptr);

    fputs ("\n****************************************************************************************************************************************\n"
           "****************************************************************************************************************************************\n\n", out);
}

char *rabota (TEXT* text, FILE *in_binary) {

    assert (text != nullptr);
    assert (in_binary != nullptr);


    text->filesize = FILESIZE_FUNC_FSTAT (in_binary);


    char *buffer = (char*)malloc(text->filesize * sizeof(char) + 1);

    assert (buffer != nullptr);



    if (fread (buffer, sizeof(char), text->filesize, in_binary) != text->filesize) {

      puts ("ERROR IN READIN FROM FILE");

      assert (0);
    }


    text->number_lines = number_lines_in_buffer (buffer);

    buffer[text->filesize] = '\0';

    return buffer;
}


void qss (JOJO *a, int first, int last) {

    if (first < last)
    {
        int left = first, right = last;

        char middle[100] = {};

        strcpy (middle, a[(left + right) / 2].str);

        do
        {
            while (strcmp (a[left].str , middle) < 0) left++;
            while (strcmp (a[right].str, middle) > 0) right--;

            if (left <= right)
            {
                char tmp[10] = {};
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



int FILESIZE_FUNC_FSTAT (FILE *in) {

    assert (in != nullptr);

    struct stat buff = {};

    fstat (fileno (in), &buff);

    return buff.st_size;
}


int number_lines_in_buffer (char* str) {

    assert (str != nullptr);

    int num_of_lines = 0;

    while (strchr (str, '\n') != nullptr) {

        ++num_of_lines;
        str = strchr (str, '\n') + 1;
    }

    return num_of_lines + 1;
}


void array_sort_fillin (char* str, JOJO* array_sort, int number_lines) {

    assert (str != nullptr);
    assert (array_sort != nullptr);

        char *start = str;
        char *finish = NULL;

    for (int i = 0; i < number_lines; ++i) {

        if (i == number_lines - 1) {

        array_sort[i].str = start;
        array_sort[i].len_str = strlen (array_sort[i].str);

        return;

        }

        char *finish = strchr (start, '\n');

        //пофиксить
       // if (*(finish - 1) == '\r')
       //     *(finish - 1) =  '\0';
        *finish = '\0';

        array_sort[i].str = start;
        array_sort[i].len_str = finish - start;

        start = finish + 1;
    }
}


void sort_array_BUBBLE (JOJO *str, int lines) {

    assert (str != nullptr);

     for (int i = 1; i < lines; ++i) {

            JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

              if (comp_void (&str[j], &str[j+1]) == 1) {

                    s = str[j];
                    str[j] = str[j+1];
                    str[j+1] = s;
            }
        }
    }
}


void output_sorted (JOJO *str, int num_lines, FILE *out) {

    assert (str != nullptr);
    assert (out != nullptr);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str[i].str, out);
        fputc ('\n', out);
    }
    return;
}


void output_ne_sorted (char* str, int num_lines, FILE *out) {

    assert (str != nullptr);
    assert (out != nullptr);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str, out);
        fputc ('\n', out);
        str = strchr (str, '\0') + 1;
    }
    return;
}

char *find_alnum (char *kek) {

    assert (kek != nullptr);

        while (1) {

            if (isalnum (*kek))
                    return kek;

            else
                kek = kek + 1;
        }
}


int comp_void (const void *first, const void *second) {

    assert (first != nullptr);
    assert (second != nullptr);

    char *str1 = ((JOJO *)first) -> str;

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

    assert (first != nullptr);
    assert (second != nullptr);

    char *uno = ((JOJO *)first) -> str;

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



char *find_alnum_reverse (char *kek) {

    assert (kek != nullptr);

        while (1) {

            if (isalnum (*kek))
                    return kek;

            else
                kek = kek - 1;
        }
}


void sort_array_BUBBLE_reverse (JOJO *str, int lines) {

    assert (str != nullptr);

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
