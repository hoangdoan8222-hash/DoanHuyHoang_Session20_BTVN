#include <stdio.h>
#include <string.h>

#define MAX 100

struct Dish {
    int id;
    char name[50];
    float price;
};

void printMenu(struct Dish menu[], int current) {
    int i;
    for (i = 0; i < current; i++) {
        printf("%d. id: %d - name: %s - price: %.2f\n",
               i, menu[i].id, menu[i].name, menu[i].price);
    }
}

void insertAt(struct Dish menu[], int *current) {
    int pos, i;

    if (*current >= MAX) {
        printf("Menu day, khong the chen!\n");
        return;
    }

    printf("Nhap vi tri can chen (0 - %d): ", *current);
    scanf("%d", &pos);

    if (pos < 0 || pos > *current) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (i = *current; i > pos; i--) {
        menu[i] = menu[i - 1];
    }

    menu[pos].id = pos + 1;
    getchar();
    printf("Nhap ten mon: ");
    fgets(menu[pos].name, sizeof(menu[pos].name), stdin);
    menu[pos].name[strcspn(menu[pos].name, "\n")] = 0;

    printf("Nhap gia: ");
    scanf("%f", &menu[pos].price);

    (*current)++;

    for (i = 0; i < *current; i++)
        menu[i].id = i + 1;
}

void editAt(struct Dish menu[], int current) {
    int pos;
    printf("Nhap vi tri can sua: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= current) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    getchar();
    printf("Nhap ten moi: ");
    fgets(menu[pos].name, sizeof(menu[pos].name), stdin);
    menu[pos].name[strcspn(menu[pos].name, "\n")] = 0;

    printf("Nhap gia moi: ");
    scanf("%f", &menu[pos].price);

    printf("Sua thanh cong!\n");
}

void deleteAt(struct Dish menu[], int *current) {
    int pos, i;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= *current) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (i = pos; i < *current - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*current)--;

    for (i = 0; i < *current; i++)
        menu[i].id = i + 1;

    printf("Xoa thanh cong!\n");
}

void sortByPrice(struct Dish menu[], int current, int asc) {
    int i, j;
    struct Dish tmp;
    for (i = 0; i < current - 1; i++) {
        for (j = i + 1; j < current; j++) {
            if ((asc && menu[i].price > menu[j].price) ||
                (!asc && menu[i].price < menu[j].price)) {
                tmp = menu[i];
                menu[i] = menu[j];
                menu[j] = tmp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchLinear(struct Dish menu[], int current) {
    char key[50];
    int i, found = 0;
    getchar();
    printf("Nhap ten mon can tim: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    for (i = 0; i < current; i++) {
        if (strcmp(menu[i].name, key) == 0) {
            printf("Tim thay: id=%d, name=%s, price=%.2f\n",
                   menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }

    if (!found)
        printf("Khong tim thay!\n");
}

void searchBinary(struct Dish menu[], int current) {
    char key[50];
    int left = 0, right = current - 1, mid;
    int found = 0;

    getchar();
    printf("Nhap ten mon can tim: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        int cmp = strcmp(menu[mid].name, key);
        if (cmp == 0) {
            printf("Tim thay: id=%d, name=%s, price=%.2f\n",
                    menu[mid].id, menu[mid].name, menu[mid].price);
            found = 1;
            break;
        } else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }

    if (!found)
        printf("Khong tim thay (can sap xep theo name truoc)!\n");
}

int main() {
    struct Dish menu[MAX] = {
        {1, "Com Tam", 25000},
        {2, "Pho Bo", 35000},
        {3, "Banh Mi", 20000},
        {4, "Bun Bo", 30000},
        {5, "Mi Quang", 40000}
    };

    int choice, sub, current = 5;

    do {
        printf("\n===== MENU QUAN LY MON AN =====\n");
        printf("1. In danh sach\n");
        printf("2. Chen theo vi tri\n");
        printf("3. Sua theo vi tri\n");
        printf("4. Xoa theo vi tri\n");
        printf("5. Sap xep theo price\n");
        printf("6. Tim kiem theo name\n");
        printf("7. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printMenu(menu, current);
            break;
        case 2:
            insertAt(menu, &current);
            break;
        case 3:
            editAt(menu, current);
            break;
        case 4:
            deleteAt(menu, &current);
            break;
        case 5:
            printf("a. Giam dan (0)\n");
            printf("b. Tang dan (1)\n");
            printf("Chon: ");
            scanf("%d", &sub);
            sortByPrice(menu, current, sub);
            break;
        case 6:
            printf("a. Tuyen tinh (1)\n");
            printf("b. Nhi phan (2)\n");
            printf("Chon: ");
            scanf("%d", &sub);
            if (sub == 1) searchLinear(menu, current);
            else searchBinary(menu, current);
            break;
        case 7:
            printf("Thoat...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
}

