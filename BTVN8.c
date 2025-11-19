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
        {2, "Tran Thi B\n",   21, "0987654321"},
        {3, "Le Van C\n",     19, "0345678912"},
        {4, "Pham Thi D\n",   22, "0567891234"},
        {5, "Hoang Van E\n",  20, "0789123456"}
    };

    int current = 5; 
    int pos, i;

    printf("Nhap vi tri can chen (0 - %d): ", current);
    scanf("%d", &pos);

    if (pos < 0 || pos > current || current >= MAX) {
        printf("\nVi tri khong hop le hoac mang da day!\n");
        return 0;
    }

    for (i = current; i > pos; i--) {
        sv[i] = sv[i - 1];
    }

    getchar(); 

    printf("\nNhap ten sinh vien moi: ");
    fgets(sv[pos].name, sizeof(sv[pos].name), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &sv[pos].age);

    printf("Nhap so dien thoai: ");
    scanf("%s", sv[pos].phoneNumber);

    current++;

    for (i = 0; i < current; i++) {
        sv[i].id = i + 1;
    }

    printf("\n===== DANH SACH SINH VIEN SAU KHI CHEN =====\n");
    for (i = 0; i < current; i++) {
        printf("\nID: %d\n", sv[i].id);
        printf("Ten: %s", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("SDT: %s\n", sv[i].phoneNumber);
    }

    return 0;
}

