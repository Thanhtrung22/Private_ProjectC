#include "main.h"


int main()
{
	
    SinhVien list[MAX_SV];
    int quantity = 0;
    char  sel = '\0';
    char answer[6] = "\0";
    FILE *file = NULL;
    file = fopen(INPUT_FILE, "r");
    if(file != NULL)
    {
        read_input_file(list, &quantity, file);
        fclose(file);
        while(strcmp(answer, "no") != 0)
        {
            system("cls");
            menu();
            printf("\nNhap lua chon cua ban: ");
            fflush(stdin);
            sel = getche();
            switch(sel)
            {
                case '1': 
                {
                    printf("\n\t\tBANG DIEM SINH VIEN MON TIN DAI CUONG\n\n");
                    display(list, quantity);
                    break;
                }
                case '2': 
                {
                   file = fopen(OUTPUT_FILE, "w+");
                   if(file != NULL)
                   {
                        write_output(list, quantity, file);
                        fclose(file);

                   }
                   else
                   {
                        printf("\nKhong the mo duoc file");

                   }
                   break;
                }
                case '3': 
                {
                    int count = 0;
                    SinhVien *result = NULL;
                    result = list_point_F(list, quantity, &count);
                    if(count != 0)
                    {
                        printf("\n\t\tDANH SACH SINH VIEN DIEM F\n\n");
                        display(result, count);
                    }
                    else
                    {
                        printf("Khong co sinh vien nao diem F");
                    }
                    break;
                }
                case '4': 
                {
                    SinhVien *result = NULL;
                    char id_search[20] = "\0";
                    bool flag = 0;
                    printf("\nNhap id sinh vien can tim: ");
                    fgets(id_search, sizeof(id_search), stdin);
                    id_search[strlen(id_search) - 1] = '\0';
                    result = search(list, quantity, &flag, id_search);
                    if(flag )
                    {
                        printf("Sinh vien co ma id  %s:\n", id_search);
                        display(result, 1);
                    }
                    else
                    {
                        printf("\nKhong tim thay ma id sinh vien!");
                    }
                    break;
                }
                case '5':
                {
                    add_student(list, &quantity);
                    break;

                }
                case '6':
                {
                    char id_delete[20] = "\0";
                    printf("\nNhap id sinh vien can xoa: ");
                    fgets(id_delete, sizeof(id_delete), stdin);
                    id_delete[strlen(id_delete) - 1] = '\0';
                    delete_student(list, &quantity, id_delete);
                    break;
                }
                case '7':
                {
                    char id_edit[20] = "\0";
                    printf("\nNhap id sinh vien can sua: ");
                    fgets(id_edit, sizeof(id_edit), stdin);
                    id_edit[strlen(id_edit) - 1] = '\0';
                    edit_student(list, quantity, id_edit);
                    break;
                }
                case '8':
                {
                    printf("\nSee you again!");
                    return 0;
                    break;
                }
                default:
                {
                	printf("\nBan da nhap sai lua chon.Vui long nhap lai!");
                	break;
				}

            }
            printf("\nDo you wanna continue?(yes/no)\n");
            fflush(stdin);
            scanf("%s", answer);
        }
        
    }
    else
    {
        printf("Khong mo duoc file");
    }
    
    return 0;
}