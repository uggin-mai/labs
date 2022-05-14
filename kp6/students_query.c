#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "table.h"

#define STR_SIZE 32

int main(int argc, char const *argv[])
{
    FILE * f;
        students s;
        f = fopen("students_test.bin", "rb");

        int *classes = (int *)malloc(1 * sizeof(int));
        int *letters = (int *)malloc(1* sizeof(int));
        int letter = 0;
        int number = 0;
        int class_data[3][4];

        for(int i = 0; i < CNQ; i++) {
            for(int k = 0; k < CLQ; k++) {
                class_data[i][k] = 0;
            }
        }

    char parameter[STR_SIZE] = "";
    bool p_switch = false;
    for (int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-f") == 0) {
            fprintf(stdout,     "+----------+--------+---+-----+------------------+------------+-------------------+\n");
            fprintf(stdout,     "| Surname  |Initials|Sex|Class| Higher Education |    Job     | Military Service  | \n");
            while (get_student(&s, f) == 0) {
                fprintf(stdout,     "+----------+--------+---+-----+------------------+------------+-------------------+\n");
                fprintf(stdout, "|%-10s|   %c.%c  | %s | %-2d%s | %-16s | %-10s | %-16s |\n", s.surname, s.initials[0], s.initials[1], s.sex, s.class_number, s.class_letter, s.higher_education, s.job, s.military_service);
            }
            fprintf(stdout,     "+----------+--------+---+-----+------------------+------------+-------------------+\n");
            fclose(f);
        }
        if(strcmp(argv[i], "-p") == 0) {
            strcpy(parameter, argv[i+1]);
            i++;
        }
    }

    printf("%s\n", parameter);
    if (parameter[0] == 'h') {
    

        
        //-65 offset 4 letters
        while (get_student(&s, f) == 0) {
            letter = s.class_letter[0];
            number = s.class_number;
            if (s.higher_education[0] != 45 && class_data[number - 9][letter - 65] == 0) {
                class_data[number - 9][letter - 65] = 1;
            }
            if (s.higher_education[0] == 45 && class_data[number - 9][letter - 65] == 1) {
                class_data[number - 9][letter - 65] = -1;
            }
        }
        
        fclose(f);

        printf("Query classes\n");
        for(int i = 0; i < CNQ; i++) {
            for(int k = 0; k < CLQ; k++) {
                if (class_data[i][k] == 1){
                    printf("%d %c, ", i + 9, k + 65);
                }
            }
        }

    } else if (parameter[0] == 'm') {
        
        
        while (get_student(&s, f) == 0) {
            letter = s.class_letter[0];
            number = s.class_number;
            if (s.military_service[0] != 45 && class_data[number - 9][letter - 65] == 0) {
                class_data[number - 9][letter - 65] = 1;
            }
            if (s.military_service[0] == 45 && class_data[number - 9][letter - 65] == 1) {
                class_data[number - 9][letter - 65] = -1;
            }
        }
        
        fclose(f);

    }

    return 0;
}