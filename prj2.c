#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct product {
    int pno;
    char name[50];
    float price;
    int dis;
};
void create_product(struct product *pr) {
    printf("\nPlease Enter The Product No. of The Product :");
    scanf("%d", &pr->pno);
    printf("\n\nPlease Enter The Name of The Product :");
    getchar();
    gets(pr->name);
    printf("\nPlease Enter The Price of The Product : ");
    scanf("%f", &pr->price);
    printf("\nPlease Enter The Discount (%%) : ");
    scanf("%d", &pr->dis);
}
void show_product(struct product pr) {
    printf("\nThe Product No. of The Product : %d", pr.pno);
    printf("\nThe Name of The Product : %s", pr.name);
    printf("\nThe Price of The Product : %.2f", pr.price);
    printf("\nDiscount : %d", pr.dis);
}
int retpno(struct product pr) {
    return pr.pno;
}
float retprice(struct product pr) {
    return pr.price;
}
int retdis(struct product pr) {
    return pr.dis;
}
void write_product() {
    FILE *fp;
    struct product pr;
    fp = fopen("Shop.dat", "ab");
    create_product(&pr);
    fwrite(&pr, sizeof(struct product), 1, fp);
    fclose(fp);
    printf("\n\nThe Product Has Been Created ");
    getchar();
}
void display_all() {
    FILE *fp;
    struct product pr;
    fp = fopen("Shop.dat", "rb");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    while (fread(&pr, sizeof(struct product), 1, fp)) {
        show_product(pr);
        printf("\n\n====================================\n");
        getchar();
    }
    fclose(fp);
    getchar();
}
void display_sp(int n) {
    FILE *fp;
    struct product pr;
    int flag = 0;
    fp = fopen("Shop.dat", "rb");
    while (fread(&pr, sizeof(struct product), 1, fp)) {
        if (retpno(pr) == n) {
            printf("\n\n");
            show_product(pr);
            flag = 1;
        }
    }
    fclose(fp);
    if (flag == 0)
        printf("\n\nrecord not exist");
    getchar();
}
void modify_product() {
    FILE *fp;
    struct product pr;
    int no, found = 0;
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The Product No. of The Product");
    scanf("%d", &no);
    fp = fopen("Shop.dat", "rb+");
    while (fread(&pr, sizeof(struct product), 1, fp) && found == 0) {
        if (retpno(pr) == no) {
            show_product(pr);
            printf("\nPlease Enter The New Details of Product:\n");
            create_product(&pr);
            int pos = 1 * sizeof(pr);
            fseek(fp, pos, SEEK_CUR);
            fwrite(&pr, sizeof(struct product), 1, fp);
            printf("\n\n\t Record Updated");
            found = 1;
        }
    }
    fclose(fp);
    if (found == 0)
        printf("\n\n Record Not Found ");
    getchar();
}
void delete_product() {
    FILE *fp, *fp2;
    struct product pr;
    int no;
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The product no. of The Product You Want To Delete");
    scanf("%d", &no);
    fp = fopen("Shop.dat", "rb+");
    fp2 = fopen("Temp.dat", "wb");
    rewind(fp);
    while (fread(&pr, sizeof(struct product), 1, fp)) {
        if (retpno(pr) != no) {
            fwrite(&pr, sizeof(struct product), 1, fp2);
        }
    }
    fclose(fp2);
    fclose(fp);
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    printf("\n\n\tRecord Deleted ..");
    getchar();
}
void menu() {
    FILE *fp;
    struct product pr;
    fp = fopen("Shop.dat", "rb");
    if (!fp) {
        printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File");
        printf("\n\n\n Program is closing ….");
        getchar();
        exit(0);
    }
    printf("\n\n\t\tPRODUCT MENU\n\n");
    printf("====================================================\n");
    printf("P.NO.\t\tNAME\t\tPRICE\n");
    printf("====================================================\n");
    while (fread(&pr, sizeof(struct product), 1, fp)) {
        printf("%d\t\t%s\t\t%.2f\n", retpno(pr), retname(pr), retprice(pr));
    }
    fclose(fp);
}
void place_order() {
    FILE *fp;
    struct product pr;
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    printf("\n\n\n\n\n          ===============================");
    printf("\n              -->>PLACE YOUR ORDER<<--");
    printf("\n          ===============================\n");
    do {
        printf("\n\nEnter The Product No. Of The Product : ");
        scanf("%d", &order_arr[c]);
        printf("\nQuantity in number : ");
        scanf("%d", &quan[c]);
        c++;
        printf("\nDo You Want To Order Another Product ? (y/n)");
        getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    printf("\n\nThank You For Placing The Order");
    getchar();
    getchar();
    printf("\n******************************INVOICE*****************************\n");
    printf("\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n");
    int x;
    for ( x = 0; x < c; x++) {
        fp = fopen("Shop.dat", "rb");
        while (fread(&pr, sizeof(struct product), 1, fp)) {
            if (retpno(pr) == order_arr[x]) {
                amt = retprice(pr) * quan[x];
                damt = amt - (amt * retdis(pr) / 100);
                printf("\n%d\t%s\t%d\t\t%.2f\t%.2f\t\t%.2f", order_arr[x], retname(pr), quan[x], retprice(pr), amt, damt);
                total += damt;
            }
        }
        fclose(fp);
    }
    printf("\n\n\t\t\t\t\tTOTAL = %.2f", total);
    getchar();
    getchar();
}
void intro() {
    printf("----->> SUPER MARKET <<-----");
    printf("\n\n   ---->> BILLING <<----");
    printf("\n\n    --->> PROJECT <<---");
    printf("\n\n\n\n\n\n\nMADE BY : Tribhuwan Kumar");
    printf("\n\nSCHOOL : Oxford Public School");
    getchar();
}
void admin_menu() {
    char ch2;
    printf("\n\n\t4:MODIFY PRODUCT");
    printf("\n\n\t5:DELETE PRODUCT");
    printf("\n\n\t6:VIEW PRODUCT MENU");
    printf("\n\n\t7:BACK TO MAIN MENU");
    printf("\n\n\tPlease Enter Your Choice (1-7) ");
    getchar();
    scanf("%c", &ch2);
    switch (ch2) {
    	int num;
        case '1':
           
            write_product();
            break;
        case '2':
            display_all();
            break;
        case '3':
            printf("\n\n\tPlease Enter The Product No. ");
            scanf("%d", &num);
            display_sp(num);
            break;
        case '4':
            modify_product();
            break;
        case '5':
            delete_product();
            break;
        case '6':
            menu();
            getchar();
        case '7':
            break;
        default:
            printf("\a");
            admin_menu();
    }
}
int main() {
    char ch;
    intro();
    do {
        clrscr();
        printf("\n-->> Welcome to Super Market Billing System Application <<--      \n");
        printf("\t************************************************************\n\n");
        printf("\n\n\n\tMAIN MENU\n");
        printf("\t_____________");
        printf("\n\n\t01: CUSTOMER");
        printf("\n\n\t02: ADMINISTRATOR");
        printf("\n\n\t03: EXIT");
        printf("\n\n\tPlease Select Your Option ");
        getchar();
        scanf("%c", &ch);
        switch (ch) {
            case '1':
                
                place_order();
                getchar();
                break;
            case '2':
                admin_menu();
                break;
            case '3':
                exit(0);
            default:
                printf("\a");
        }
    } while (ch != '3');
    return 0;
}
