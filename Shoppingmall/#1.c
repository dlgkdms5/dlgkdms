#include <stdio.h>

int main()
{
    int id;
    int stock[100] = { 0 };
    int sold[100] = { 0 };
    int num, total = 0;

    printf("상품 종류의 갯수를 입력하시오 (1~100): ");
    scanf("%d", &num);

    if (num < 1 || num > 100) {
        printf("1부터 100까지의 수를 입력하시오:");
        return 1;
    }

    printf("상품별 재고 수량을 입력하시오:");
    for (int i = 0; i < num; i++) {
        scanf("%d", &stock[i]);
    }

    printf("상품별 판매 수량을 입력하시오:");
    for (int j = 0; j < num; j++) {
        scanf("%d", &sold[j]);
        stock[j] -= sold[j];
        if (stock[j] < 0) {
            stock[j] = 0;
        }
    }

    printf("재고를 확인할 ID를 입력하시오:");
    scanf("%d", &id);

    if (id < 1 || id > num) {
        printf("잘못된 ID입니다.");
        return 1;
    }

    printf("%d\n", stock[id - 1]);

    for (int i = 0; i < num; i++) {
        printf("%d", stock[i]);
    }

    return 0;
}