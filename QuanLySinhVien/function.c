#include "main.h"


void menu()
{
    printf("\n\t\t\tPOINT MANAGEMENT SYSTEM\n\n");
    printf("----------------------------------------------------------------\n\n");
    printf("1.Display list of students\n");
    printf("2.Print list into output file\n");
    printf("3.Display list of students fail\n");
    printf("4.Search for students\n");
    printf("5.Add new students\n");
    printf("6.Delete students\n");
    printf("7.Edit students\n");
    printf("8.Exit program\n");

}
void convert_point(SinhVien *per)
{
    float result = 0.0f;
    result = 0.3 * per->diemQT + 0.7 * per->diemCK;
    if(result < 4.0 || per->diemQT < 3.0 || per->diemCK < 3.0)
    {
        strcpy(per->diemChu, "F");
    }
    else if(result < 5.0)
    {
        strcpy(per->diemChu, "D");
    }
    else if(result < 5.5)
    {
        strcpy(per->diemChu, "D+");
    }
    else if(result < 6.5)
    {
        strcpy(per->diemChu, "C");
    }
    else if(result < 7.0)
    {
        strcpy(per->diemChu, "C+");
    }
    else if(result < 8.0)
    {
        strcpy(per->diemChu, "B");
    }
    else if(result < 8.5)
    {
        strcpy(per->diemChu, "B+");
    }
    else if(result < 9.4)
    {
        strcpy(per->diemChu, "A");
    }
    else
    {
        strcpy(per->diemChu, "A+");
    }
}
void read_input_file(SinhVien *list,  int *quality, FILE *file)
{
    char buffer[256];
    int count = 0, index = 0;
    char* token = NULL;
    while((!feof(file)) && count <= MAX_SV)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strlen(buffer) - 1] = '\0';
        printf("\nNhap thong tin sinh vien thu %d: ", ++index); 
        token = strtok(buffer, ",");
        strcpy(list[count].id, token);
        token = strtok(NULL, ",");
        strcpy(list[count].name, token);
        printf("\nNhap diem qua trinh: ");
        scanf("%f", &list[count].diemQT);
        printf("Nhap diem cuoi ki: ");
        scanf("%f", &list[count].diemCK);
        convert_point(&list[count]);
        count++;
    }
    *quality = count;
    token = NULL;
    printf("\nRead file successfully");
}
void display(SinhVien *list, int quality)
{
    sort_name(list, quality);
    printf("%-5s %-20s %-10s %-8s %-8s %-5s\n", "STT", "Ho Ten", "Ma so", "Diem QT", "Diem CK", "Diem Chu");
    printf("------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < quality; i++)
    {
        printf("%-5d %-20s %-10s %-8.2f %-8.2f %-5s\n", i + 1, list[i].name, list[i].id, list[i].diemQT, list[i].diemCK,list[i].diemChu);
    }
}
void sort_name(SinhVien *list, int quality)
{
    char *name_i = NULL;
    char *name_j = NULL;
    SinhVien temp;
    for(int i = 0; i < quality - 1; i++)
    {
        for(int j = i + 1; j < quality; j++)
        {
            name_i = strrchr(list[i].name, ' ');
            name_j = strrchr(list[j].name, ' ');
            if(strcmp(name_i, name_j) > 0)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
void write_output(SinhVien *list, int quality, FILE *file)
{
    sort_name(list, quality);
    fprintf(file, "\t\t\tBANG DIEM SINH VIEN MON TIN DAI CUONG\n");
    fprintf(file, "___________________________________________________________________________________________\n\n");
    fprintf(file, "%-5s %-20s %-10s %-8s %-8s %-5s\n", "STT", "Ho Ten", "Ma so", "Diem QT", "Diem CK", "Diem Chu");
    fprintf(file,"------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < quality; i++)
    {
        fprintf(file, "%-5d %-20s %-10s %-8.2f %-8.2f %-5s\n", i + 1, list[i].name, list[i].id, list[i].diemQT, list[i].diemCK,list[i].diemChu);
    }
    printf("\nWrite output successfully");
}

SinhVien* search(SinhVien *list, int quality, bool *flag, char *id_search)
{
    SinhVien *result = NULL;
    *flag = 0;
    for(int i = 0; i < quality; i++)
    {
        if(strcmp(id_search, list[i].id) == 0)
        {
            *flag = 1;
            result = &list[i];
            break;

        }
    }
    return result;
}

SinhVien* list_point_F(SinhVien *list, int quantity, int *count)
{
    SinhVien *result = NULL;
    *count = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(strcmp(list[i].diemChu, "F") == 0)
        {
            (*count)++;
        }
    }
    result = (SinhVien*)malloc((*count) * sizeof(SinhVien));
    int j = 0;
    for(int i = 0; i < quantity; i++)
    {
        if(strcmp(list[i].diemChu, "F") == 0)
        {
            result[j] = list[i];
            j++;
        }
    }
    return result;
}

void add_student(SinhVien *list, int *quality)
{
    if(*quality == MAX_SV)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        SinhVien value;
        bool flag = 0;
        printf("\nNhap ten sinh vien: ");
        fflush(stdin);
        fgets(value.name, sizeof(value.name), stdin);
        value.name[strlen(value.name)-1] = '\0';
        printf("Nhap ma so sinh vien: ");
        fflush(stdin);
        fgets(value.id, sizeof(value.id), stdin);
        value.id[strlen(value.id)-1] = '\0';
        search(list, *quality, &flag, value.id);
        while(flag)
        {
            printf("Ban da nhap sai id. Vui long nhap lai!");
            fgets(value.id, sizeof(value.id), stdin);
            value.id[strlen(value.id)-1] = '\0';
            search(list, *quality, &flag, value.id);

        }
        printf("Nhap diem qua trinh: ");
        scanf("%f", &value.diemQT);
        printf("Nhap diem cuoi ki: ");
        scanf("%f", &value.diemCK);
        convert_point(&value);
        list[*quality] = value;
        (*quality)++;
        printf("Add student successfully!");
    }
}

void delete_student(SinhVien *list, int *quality, char *id_student)
{
    if(*quality == 0)
    {
        printf("\nList is empty!");
    }
    else
    {
        int count = 0;
        bool flag = 0;
        for(int i = 0; i < *quality; i++)
        {
            if(strcmp(list[i].id, id_student) != 0)
            {
                list[count] = list[i];
                count++;
            }
            else
            {
                flag = 1;
            }
        }
        *quality = count;
        if(flag)
        {
            printf("\nDelete student successfully!");

        }
        else
        {
            printf("\nKhong ti thay id sinh vien!");
        }
    }
}

void edit_student(SinhVien *list, int quality, char *id_student)
{
    if(quality == 0)
    {
        printf("\nList is empty!");
    }
    else
    {
        int index = -1;
        for(int i = 0; i < quality; i++)
        {
            if(strcmp(list[i].id, id_student) == 0)
            {
                index = i;
                break;
            }
        }
        if(index != -1)
        {
            char answer = '\0';
            char sel = 0;
            while(answer != 'k')
            {
                printf("\n\tEDIT MENU");
                printf("\n1.Edit name");
                printf("\n2.Edit diemQT");
                printf("\n3.Edit diemCk");
                printf("\nNhap lua chon cua ban: ");
                sel = getche();
                switch(sel)
                {
                    case '1':
                    {
                        printf("\nNhap ten moi: ");
                        fflush(stdin);
                        fgets(list[index].name, sizeof(list[index].name), stdin);
                        list[index].name[strlen(list[index].name) - 1] = '\0';
                        break;
                    }
                    case '2':
                    {
                        printf("\nNhap diem qua trinh moi: ");
                        scanf("%f", &list[index].diemQT);
                        break;

                    }
                    case '3':
                    {
                        printf("\nNhap diem cuoi ki moi: ");
                        scanf("%f", &list[index].diemCK);
                        break;
                    }
                    default: printf("Ban da nhap sai lua chon"); break;

                }
               printf("Ban co muon tiep tuc sua?(c/k)");
               fflush(stdin);
               answer = getchar();
            }
             convert_point(&list[index]);
            printf("\nEdit student successfully!");
        }
        else
        {
            printf("\nKhong tim thay id sinh vien");
        }
    }
}