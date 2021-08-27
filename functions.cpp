#include "functions.h"

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


int FILESIZE_FUNC_VLOB (FILE *in) {

    assert (in != NULL);

	int file_size = 0;
	fseek (in, 0, SEEK_SET);


    while (getc(in) != EOF)
        file_size++;

	return file_size;
}


int FILESIZE_FUNC (FILE *in) {

    assert (in != NULL);

    int size_of_file = 0;

    fseek (in, 0, SEEK_END);

    size_of_file = ftell (in);

    fseek (in, 0, SEEK_SET);

    return (size_of_file);
}

/*
int FILESIZE_FUNC_FSTAT (FILE *in) {

    assert (in != NULL);

    struct stat buff;

    fstat (fileno (in), &buff);

    return buff.st_size;
}
*/

/*
int number_lines_in_array_VLOB (char* str, int filesize) {

    assert (str != NULL);

    int num_of_lines = 0, i = 0;

    while (i < filesize) {

        if (*(str + i) == '\n')
            num_of_lines++;

        ++i;
    }

    num_of_lines++;

    return num_of_lines;
}
*/

int number_lines_in_array_LEHA (char* str) {

    assert (str != NULL);

    int num_of_lines = 0;
    char *starto = str;

    while (strchr (starto, '\n') != NULL) {

        ++num_of_lines;
        starto = strchr (starto, '\n') + 1;
    }

    return num_of_lines + 1;
}


void copy_arrays (char source[][column], char destination[][column] , int lines) {

     assert (source != NULL);
     assert (destination != NULL);

     for (int i = 0; i < lines; ++i)
        strcpy (destination[i], source[i]);

     return;
}


void JOJO_FILLIN (char* str, JOJO* array_sort, int number_lines) {

    assert (str != NULL);
    assert (array_sort != NULL);

        char *starto = str;
        char *endo = NULL;

    for (int i = 0; i < number_lines; ++i) {

        if (i == number_lines - 1) {

        array_sort[i].str = starto;
        array_sort[i].len_str = strlen (array_sort[i].str);
        //printf ("%s %d\n", array_sort[i].str, array_sort[i].len_str);
        return;

        }

        char *endo = strchr (starto, '\n');
        *endo = '\0';

        array_sort[i].str = starto;
        array_sort[i].len_str = endo - starto;

        //printf ("%s %d\n", array_sort[i].str, array_sort[i].len_str);

        starto = endo + 1;
    }
}


void sort_array_BUBBLE (JOJO *str, int lines) {

    assert (str != NULL);

     for (int i = 1; i < lines; ++i) {

            JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

          //  if (strcmp(str[j].str, str[j+1].str) > 0) {
              if (comp (str[j].str, str[j+1].str) == 1) {

                    s.str = str[j].str;
                    s.len_str = str[j].len_str;

                    str[j].str = str[j+1].str;
                    str[j].len_str = str[j+1].len_str;

                    str[j+1].str = s.str;
                    str[j+1].len_str = s.len_str;

            }
        }
    }
}


void output_sorted (JOJO *str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    for (int i = 0; i < num_lines; ++i) {

        fputs (str[i].str, out);
        fputs ("\n", out);
    }
    return;
}


void output_ne_sorted (char* str, int num_lines, FILE *out) {

    assert (str != NULL);
    assert (out != NULL);

    char *starto = str;

    for (int i = 0; i < num_lines; ++i) {

        fputs (starto, out);
        fputs ("\n", out);
        starto = strchr (starto, '\0');
        ++starto;
    }
    return;
}

char *check (char *kek) {

    assert (kek != NULL);

    char *str = kek;

        while (1) {

            if ((*(str) >= '0') && (*(str) <= '9')  || (*(str) >= 'A') && (*(str) <= 'Z') || (*(str) >= 'a') && (*(str) <= 'z'))
                    return str;

            else
                str = str + 1;
        }
}



int comp (char *uno, char *duo) {

    assert (uno != NULL);
    assert (duo != NULL);

    char *str1 = uno;
    char *str2 = duo;


    while (*str1 != '\0' && *str2 != '\0') {

            str1 = check (str1);
            str2 = check (str2);

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

char *ass_check (char *kek) {

    assert (kek != NULL);

    char *str = kek;

        while (1) {

            if ((*(str) >= '0') && (*(str) <= '9')  || (*(str) >= 'A') && (*(str) <= 'Z') || (*(str) >= 'a') && (*(str) <= 'z'))
                    return str;

            else
                str = str - 1;
        }
}

int ass_comp (char *uno, char *duo, int len1, int len2) {

    assert (uno != NULL);
    assert (duo != NULL);

    char *str1 = uno + len1 - 1;
    char *str2 = duo + len2 - 1;


    while (str1 != uno && str2 != duo) {

            str1 = ass_check (str1);
            str2 = ass_check (str2);

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


void ass_sort_array_BUBBLE (JOJO *str, int lines) {

    assert (str != NULL);

     for (int i = 1; i < lines; ++i) {

            JOJO s = {};

        for (int j = 0; j < lines - i; ++j) {

          //  if (strcmp(str[j].str, str[j+1].str) > 0) {
              if (ass_comp (str[j].str, str[j+1].str, str[j].len_str, str[j+1].len_str) == 1) {

                    s.str = str[j].str;
                    s.len_str = str[j].len_str;

                    str[j].str = str[j+1].str;
                    str[j].len_str = str[j+1].len_str;

                    str[j+1].str = s.str;
                    str[j+1].len_str = s.len_str;

            }
        }
    }
}


/*
int cmp (const void *a, const void *b) {
     return comp ((*JOJO))
     return *(int*)a - *(int*)b;
 }
*/
