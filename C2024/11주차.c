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
        printf("원하는 메뉴를 선택하세요.(1.입고, 2.판매, 3.개별현황, 4.전체현황, 5.상품정보저장, 6.상품정보가져오기, 7.종료) : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (itemCount < MAX_ITEMS)
                addItem(items, &itemCount);
            else
                printf("더 이상 상품을 추가할 수 없습니다.\n");
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
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    } while (choice != 7);

    return 0;
}

void addItem(Item* items, int* count) {
    printf("상품 ID를 입력하세요: ");
    scanf("%d", &items[*count].id);
    printf("상품명을 입력하세요: ");
    scanf("%s", items[*count].name);
    printf("상품 가격을 입력하세요: ");
    scanf("%f", &items[*count].price);
    printf("입고 수량을 입력하세요: ");
    scanf("%d", &items[*count].stock);
    items[*count].sales = 0;
    items[*count].total_stock = items[*count].stock;
    (*count)++;
    printf("상품이 성공적으로 추가되었습니다.\n");
}

void sellItem(Item* items, int count) {
    int id, quantity, i;
    printf("판매할 상품 ID를 입력하세요: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("판매 수량을 입력하세요: ");
            scanf("%d", &quantity);
            if (quantity > items[i].stock) {
                printf("재고가 부족합니다.\n");
            }
            else {
                items[i].stock -= quantity;
                items[i].sales += quantity;
                printf("판매가 완료되었습니다.\n");
            }
            return;
        }
    }
    printf("해당 상품이 존재하지 않습니다.\n");
}

void displayItemStatus(Item* items, int count) {
    int id, i;
    printf("조회할 상품 ID를 입력하세요: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("상품명: %s\n", items[i].name);
            printf("상품 가격: %.2f\n", items[i].price);
            printf("재고 수량: %d\n", items[i].stock);
            printf("총 판매량: %d\n", items[i].sales);
            return;
        }
    }
    printf("해당 상품이 존재하지 않습니다.\n");
}

void displayAllItems(Item* items, int count) {
    printf("전체 상품 현황:\n");
    printf("ID | 이름       | 가격   | 재고 | 판매량 | 판매율\n");
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
        printf("파일 저장에 실패했습니다.\n");
        return;
    }
    fwrite(items, sizeof(Item), count, file);
    fclose(file);
    printf("상품 정보가 성공적으로 저장되었습니다.\n");
}

void loadItemsFromFile(Item* items, int* count) {
    FILE* file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("저장된 파일이 없습니다.\n");
        return;
    }
    *count = fread(items, sizeof(Item), MAX_ITEMS, file);
    fclose(file);
    printf("상품 정보가 성공적으로 불러와졌습니다.\n");
}
