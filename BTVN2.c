#include <stdio.h>

struct Student {
    char name[50];
    int age;
    char phoneNumber[20];
};

int main() {
    struct Student sv;

    printf("Nhap ten sinh vien: ");
    fgets(sv.name, sizeof(sv.name), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);

    printf("Nhap so dien thoai: ");
    scanf("%s", sv.phoneNumber);

    printf("\n--- Thong tin sinh vien ---\n");
    printf("Ten: %s", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("SDT: %s\n", sv.phoneNumber);

    return 0;
}

