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
    int id_del, i, j;
    int found = 0;

    printf("Nhap id sinh vien can xoa: ");
    scanf("%d", &id_del);

    for (i = 0; i < current; i++) {
        if (sv[i].id == id_del) {
            found = 1;

            for (j = i; j < current - 1; j++) {
                sv[j] = sv[j + 1];
            }

            current--; 
            printf("\nXoa thanh cong sinh vien co id = %d\n", id_del);
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien co id = %d\n", id_del);
    }

    
    printf("\n===== DANH SACH SINH VIEN SAU KHI XOA =====\n");
    for (i = 0; i < current; i++) {
        printf("\nID: %d\n", sv[i].id);
        printf("Ten: %s", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("SDT: %s\n", sv[i].phoneNumber);
    }

    return 0;
}

