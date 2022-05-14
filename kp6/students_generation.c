#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "students.h"

#define STR_SIZE 32
#define STUDENTS_NUMBER 8

char surname[8][STR_SIZE] = {"Ozerensky", "Simonov", "Kuznetsov", "Tupoleva", "Lyashenko", "Gasanov", "Zhmyshenko", "Zubenko"};
char initials[8][STR_SIZE] = {"YK", "SV", "SR", "MP", "YY", "GG", "VA", "MP"};
char sex[2][STR_SIZE] = {"M", "F"};
int class_number[CNQ] = {9, 10, 11};
char class_letter[CLQ][STR_SIZE] = {"A", "B", "C", "D"};
char higher_education[5][STR_SIZE] = {"-", "MAI, faculty 8", "Tomsk Military Academy", "Synergy", "BMSTU"};
char job[5][STR_SIZE] = {"-", "Designer", "Programmer", "Engineer", "Salesman"};
char military_service[3][STR_SIZE] = {"-", "Division 882", "Batallion 737"};

int main()
{
    FILE *f = fopen("students_test.bin", "wb");
    if (f == NULL) {
        fprintf(stderr, "I/O Error: can't open file\n");
        exit(1);
    }

    srand(time(0));

    for(int i = 0; i < 8; i++) {
        fwrite(surname[rand()%8], sizeof(char), STR_SIZE, f);
        fwrite(initials[rand()%8], sizeof(char), STR_SIZE, f);
        fwrite(sex[rand()%2], sizeof(char), STR_SIZE, f);
        fwrite(&class_number[rand()%3], sizeof(int), 1, f);
        fwrite(class_letter[rand()%4], sizeof(char), STR_SIZE, f);
        int dice_roll = rand()%6;
        if (dice_roll > 3) {
            fwrite(higher_education[rand()%5], sizeof(char), STR_SIZE, f);
            fwrite(job[rand()%5], sizeof(char), STR_SIZE, f);
            fwrite(military_service[0], sizeof(char), STR_SIZE, f);
        } else {
            fwrite(higher_education[0], sizeof(char), STR_SIZE, f);
            fwrite(job[0], sizeof(char), STR_SIZE, f);
            fwrite(military_service[rand()%2+1], sizeof(char), STR_SIZE, f);
        }
    }

    fclose(f);
    return 0;
}