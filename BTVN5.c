#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student sv[MAX] = {
        {1, "Nguyen Van A\n", 20, "0123456789"},
        {2, "Tran Thi B\n", 21, "0987654321"},
        {3, "Le Van C\n", 19, "0345678912"},
        {4, "Pham Thi D\n", 22, "0567891234"},
        {5, "Hoang Van E\n", 20, "0789123456"}
    };

    int id_search, i, found = 0;

    printf("Nhap id sinh vien can sua: ");
    scanf("%d", &id_search);

    for (i = 0; i < 5; i++) {
        if (sv[i].id == id_search) {
            found = 1;
            getchar(); 

            printf("\nNhap ten moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);

            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);

            printf("\nSua thong tin thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien co id = %d\n", id_search);
    }

    printf("\n===== DANH SACH SINH VIEN =====\n");
    for (i = 0; i < 5; i++) {
        printf("\nID: %d\n", sv[i].id);
        printf("Ten: %s", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("SDT: %s\n", sv[i].phoneNumber);
    }

    return 0;
}

