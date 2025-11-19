#include <stdio.h>

#define MAX 5

struct Student {
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student sv[MAX];
    int i;

    for (i = 0; i < MAX; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);

        getchar();  
        printf("Nhap ten: ");
        fgets(sv[i].name, sizeof(sv[i].name), stdin);

        printf("Nhap tuoi: ");
        scanf("%d", &sv[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%s", sv[i].phoneNumber);
    }

    printf("\n===== DANH SACH SINH VIEN VUA NHAP =====\n");
    for (i = 0; i < MAX; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ten: %s", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("SDT: %s\n", sv[i].phoneNumber);
    }

    return 0;
}

