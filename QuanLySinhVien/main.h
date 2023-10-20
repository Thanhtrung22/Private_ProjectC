#ifndef _MAIN_HEADER_
#define _MAIN_HEADER_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define MAX_SV 50
typedef struct
{
    char name[50];
    char id[20];
    float diemQT;
    float diemCK;
    char diemChu[3];
}SinhVien;
void read_input_file(SinhVien *list,  int *quality, FILE *file);
void convert_point(SinhVien *per);
void display(SinhVien *list, int quality);
void write_output(SinhVien *list, int quality, FILE *file);
void sort_name(SinhVien *list, int quality);
SinhVien* search(SinhVien *list, int quality, bool *flag, char *id_search);
SinhVien* list_point_F(SinhVien *list, int quantity, int *count);
void add_student(SinhVien *list, int *quality);
void delete_student(SinhVien *list, int *quality, char *id_student);
void edit_student(SinhVien *list, int quality, char *id_student);
void menu();


#endif