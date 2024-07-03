#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct product
{
    int pno;
    char name[50];
    float price;
    int dis;
};

int x,j;

void show_product(struct product pr)
{
    printf("\nThe Product No. of The Product : %d", pr.pno);
    printf("\nThe Name of The Product : %s", pr.name);
    printf("\nThe Price of The Product : %.2f", pr.price);
    printf("\nDiscount : %d %%", pr.dis);
}

int retpno(struct product pr)
{
    int n = pr.pno;
    return n;
}

float retprice(struct product pr)
{
    float p = pr.price;
    return p;
}

int retdis(struct product pr)
{
    int d = pr.dis;
    return d;
}

void add_product()
{
    FILE *fp;
    struct product pr;
    fp = fopen("Shop.dat", "ab");
    printf("\nPlease Enter The Product No. of The Product :");
    scanf("%d", &pr.pno);
    printf("\n\nPlease Enter The Name of The Product :");
    getchar();
    gets(pr.name);
    printf("\nPlease Enter The Price of The Product : ");
    scanf("%f", &pr.price);
    printf("\nPlease Enter The Discount (%%) : ");
    scanf("%d", &pr.dis);
    fwrite(&pr, sizeof(struct product), 1, fp);
    fclose(fp);
    printf("\n\nThe Product Has Been Added.. \n");
    getch();
}

void display_all()
{
    FILE *fp;
    struct product pr;
    if (fp == NULL)
    {
        printf("File is Empty!");
    }

    fp = fopen("Shop.dat", "rb");
    while (fread(&pr, sizeof(struct product), 1, fp))
    {
        printf("\n\n====================================\n");
        show_product(pr);
    }
    fclose(fp);
    getch();
}

void display_sp(int n)
{
    FILE *fp;
    struct product pr;
    int flag = 0;
    fp = fopen("Shop.dat", "rb");
    while (fread(&pr, sizeof(struct product), 1, fp))
    {
        if (retpno(pr) == n)
        {
            printf("\n\n");
            show_product(pr);
            flag = 1;
        }
    }
    fclose(fp);
    if (flag == 0)
        printf("\n\nrecord not exist");
    getch();
}

void modify_product()
{
    FILE *fp;
    struct product pr;
    int no, found = 0;
    printf("\n\n\tPlease Enter The Product No. To Modify : ");
    scanf("%d", &no);
    fp = fopen("Shop.dat", "rb+");
    while (fread(&pr, sizeof(struct product), 1, fp) && found == 0)
    {
        if (retpno(pr) == no)
        {
            show_product(pr);
            printf("\nEnter New Details of the Product:\n");
            printf("\nPlease Enter The Product No. of The Product :");
            scanf("%d", &pr.pno);
            printf("\n\nPlease Enter The Name of The Product :");
            getchar();
            gets(pr.name);
            printf("\nPlease Enter The Price of The Product : ");
            scanf("%f", &pr.price);
            printf("\nPlease Enter The Discount (%%) : ");
            scanf("%d", &pr.dis);
            int pos = -1 * sizeof(pr);
            fseek(fp, pos, SEEK_CUR);
            fwrite(&pr, sizeof(struct product), 1, fp);
            printf("\n\n------>>Record Updated<<------");
            found = 1;
        }
    }
    fclose(fp);
    if (found == 0)
        printf("\n\n Record Not Found ");
    getch();
}

void delete_product()
{
    FILE *fp, *fp2;
    struct product pr;
    int no;
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The product no. of The Product You Want To Delete : ");
    scanf("%d", &no);
    fp = fopen("Shop.dat", "rb+");
    fp2 = fopen("Temp.dat", "wb");
    rewind(fp);
    while (fread(&pr, sizeof(struct product), 1, fp))
    {
        if (retpno(pr) != no)
        {
            fwrite(&pr, sizeof(struct product), 1, fp2);
        }
    }
    fclose(fp2);
    fclose(fp);
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    printf("\n\n\t--------->>Record Deleted<<---------");
    getch();
}

void menu()
{
    FILE *fp;
    struct product pr;
    fp = fopen("Shop.dat", "rb");
    if (!fp)
    {
        printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File");
        getch();
    }
    printf("\n\n\t\t----->>PRODUCT MENU<<-----\n\n");
    printf("\t============================================\n");
    printf("\t    P.NO.\tNAME\t\tPRICE       \n");
    printf("\t============================================\n");
    while (fread(&pr, sizeof(struct product), 1, fp))
    {
        printf("\t     %d\t\t%s", retpno(pr), pr.name);
        for ( j = 0; j < (15 - strlen(pr.name)); j++)
        {
            printf(" ");
        }
        printf("Rs. %.2f\n", retprice(pr));
    }
    printf("\t============================================\n");
    fclose(fp);
}

void place_order()
{
    FILE *fp;
    struct product pr;
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    int ch;
    menu();
    printf("\n\n\t\t================================");
    printf("\n\t\t|   -->>PLACE YOUR ORDER<<--   |");
    printf("\n\t\t================================\n");
    do
    {
        printf("\n\nEnter The Product No. Of The Product : ");
        scanf("%d", &order_arr[c]);
        printf("\nQuantity in number : ");
        scanf("%d", &quan[c]);
        c++;
        printf("\nEnter 1 to place another order or 0 to skip.\n");
        scanf("%d", &ch);
    } while (ch != 0);
    system("cls");
    printf("\n\n---------------------Thank You For Placing The Order----------------------\n");
    printf("\n*********************************INVOICE**********************************\n");
    printf("\nPr No.\tPr Name\t    Quantity    Price         Amount       Net Amount\n");
    for ( x = 0; x < c; x++)
    {
        fp = fopen("Shop.dat", "rb");
        while (fread(&pr, sizeof(struct product), 1, fp))
        {
            if (retpno(pr) == order_arr[x])
            {
                amt = retprice(pr) * quan[x];
                damt = amt - (amt * retdis(pr) / 100);
                printf("\n  %d\t%s", order_arr[x], pr.name);
                for ( j = 0; j < (15 - strlen(pr.name)); j++)
                {
                    printf(" ");
                }
                printf("%d\tRs. %.2f    Rs. %.2f     Rs. %.2f", quan[x], retprice(pr), amt, damt);
                total += damt;
            }
        }
        fclose(fp);
    }
    printf("\n**************************************************************************\n");
    printf("\n\n\t\t\t----------------------------");
    printf("\n\t\t\t     TOTAL = Rs. %.2f   ", total);
    printf("\n\t\t\t----------------------------\n");
    getch();
}

void admin_menu()
{
    int ch2;
    while (ch2 != 7)
    {
        printf("\n\n\t1:ADD PRODUCT");
        printf("\n\n\t2:DISPLAY ALL PRODUCT");
        printf("\n\n\t3:DISPLAY SPECIFIC PRODUCT");
        printf("\n\n\t4:MODIFY PRODUCT");
        printf("\n\n\t5:DELETE PRODUCT");
        printf("\n\n\t6:VIEW PRODUCT MENU");
        printf("\n\n\t7:BACK TO MAIN MENU");
        printf("\n\n\tPlease Enter Your Choice (1-7) : ");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
            system("cls");
            add_product();
            break;
        case 2:
            system("cls");
            display_all();
            break;
        case 3:
            system("cls");
            int num;
            printf("\n\n\tPlease Enter The Product No. : ");
            scanf("%d", &num);
            display_sp(num);
            break;
        case 4:
            system("cls");
            modify_product();
            break;
        case 5:
            system("cls");
            delete_product();
            break;
        case 6:
            system("cls");
            menu();
        case 7:
            break;
        default:
            printf("\nEnter a valid choice!");
            break;
        }
    }
}

int main()
{
    int ch;
    do
    {
        system("cls");
        printf("\n\t-->> Welcome to Super Market Billing System <<--\n");
        printf("\t************************************************\n\n");
        printf("\n\n\n\tMAIN MENU\n");
        printf("\t_____________");
        printf("\n\n\t01: CUSTOMER");
        printf("\n\n\t02: ADMINISTRATOR");
        printf("\n\n\t03: EXIT");
        printf("\n\n\tPlease Select Your Option : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            place_order();
            break;
        case 2:
            system("cls");
            admin_menu();
            break;
        case 3:
            printf("Exiting the System..");
            exit(0);
        default:
            printf("\nEnter a valid choice!");
        }
    } while (ch != 3);
    return 0;
}
