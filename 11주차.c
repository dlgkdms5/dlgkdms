#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 5
#define FILE_NAME "items.bin"

typedef struct {
    int id;
    char name[30];
    float price;
    int stock;
    int sales;
    int total_stock; 
} Item;

void addItem(Item* items, int* count);
void sellItem(Item* items, int count);
void displayItemStatus(Item* items, int count);
void displayAllItems(Item* items, int count);
void saveItemsToFile(Item* items, int count);
void loadItemsFromFile(Item* items, int* count);

int main() {
    Item items[MAX_ITEMS] = { 0 };
    int itemCount = 0;
    int choice;

    do {
        printf("���ϴ� �޴��� �����ϼ���.(1.�԰�, 2.�Ǹ�, 3.������Ȳ, 4.��ü��Ȳ, 5.��ǰ��������, 6.��ǰ������������, 7.����) : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (itemCount < MAX_ITEMS)
                addItem(items, &itemCount);
            else
                printf("�� �̻� ��ǰ�� �߰��� �� �����ϴ�.\n");
            break;
        case 2:
            sellItem(items, itemCount);
            break;
        case 3:
            displayItemStatus(items, itemCount);
            break;
        case 4:
            displayAllItems(items, itemCount);
            break;
        case 5:
            saveItemsToFile(items, itemCount);
            break;
        case 6:
            loadItemsFromFile(items, &itemCount);
            break;
        case 7:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    } while (choice != 7);

    return 0;
}

void addItem(Item* items, int* count) {
    printf("��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &items[*count].id);
    printf("��ǰ���� �Է��ϼ���: ");
    scanf("%s", items[*count].name);
    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%f", &items[*count].price);
    printf("�԰� ������ �Է��ϼ���: ");
    scanf("%d", &items[*count].stock);
    items[*count].sales = 0;
    items[*count].total_stock = items[*count].stock;
    (*count)++;
    printf("��ǰ�� ���������� �߰��Ǿ����ϴ�.\n");
}

void sellItem(Item* items, int count) {
    int id, quantity, i;
    printf("�Ǹ��� ��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("�Ǹ� ������ �Է��ϼ���: ");
            scanf("%d", &quantity);
            if (quantity > items[i].stock) {
                printf("��� �����մϴ�.\n");
            }
            else {
                items[i].stock -= quantity;
                items[i].sales += quantity;
                printf("�ǸŰ� �Ϸ�Ǿ����ϴ�.\n");
            }
            return;
        }
    }
    printf("�ش� ��ǰ�� �������� �ʽ��ϴ�.\n");
}

void displayItemStatus(Item* items, int count) {
    int id, i;
    printf("��ȸ�� ��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("��ǰ��: %s\n", items[i].name);
            printf("��ǰ ����: %.2f\n", items[i].price);
            printf("��� ����: %d\n", items[i].stock);
            printf("�� �Ǹŷ�: %d\n", items[i].sales);
            return;
        }
    }
    printf("�ش� ��ǰ�� �������� �ʽ��ϴ�.\n");
}

void displayAllItems(Item* items, int count) {
    printf("��ü ��ǰ ��Ȳ:\n");
    printf("ID | �̸�       | ����   | ��� | �Ǹŷ� | �Ǹ���\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        float sell_rate = (items[i].total_stock > 0) ?
            ((float)items[i].sales / items[i].total_stock) * 100 : 0.0;
        printf("%2d | %-10s | %.f | %4d | %6d | %.2f%%\n",
            items[i].id, items[i].name, items[i].price,
            items[i].stock, items[i].sales, sell_rate);
    }
}

void saveItemsToFile(Item* items, int count) {
    FILE* file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("���� ���忡 �����߽��ϴ�.\n");
        return;
    }
    fwrite(items, sizeof(Item), count, file);
    fclose(file);
    printf("��ǰ ������ ���������� ����Ǿ����ϴ�.\n");
}

void loadItemsFromFile(Item* items, int* count) {
    FILE* file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("����� ������ �����ϴ�.\n");
        return;
    }
    *count = fread(items, sizeof(Item), MAX_ITEMS, file);
    fclose(file);
    printf("��ǰ ������ ���������� �ҷ��������ϴ�.\n");
}
