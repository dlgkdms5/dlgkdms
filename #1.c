#include <stdio.h>

int main()
{
    int id;
    int stock[100] = { 0 };
    int sold[100] = { 0 };
    int num, total = 0;

    printf("��ǰ ������ ������ �Է��Ͻÿ� (1~100): ");
    scanf("%d", &num);

    if (num < 1 || num > 100) {
        printf("1���� 100������ ���� �Է��Ͻÿ�:");
        return 1;
    }

    printf("��ǰ�� ��� ������ �Է��Ͻÿ�:");
    for (int i = 0; i < num; i++) {
        scanf("%d", &stock[i]);
    }

    printf("��ǰ�� �Ǹ� ������ �Է��Ͻÿ�:");
    for (int j = 0; j < num; j++) {
        scanf("%d", &sold[j]);
        stock[j] -= sold[j];
        if (stock[j] < 0) {
            stock[j] = 0;
        }
    }

    printf("��� Ȯ���� ID�� �Է��Ͻÿ�:");
    scanf("%d", &id);

    if (id < 1 || id > num) {
        printf("�߸��� ID�Դϴ�.");
        return 1;
    }

    printf("%d\n", stock[id - 1]);

    for (int i = 0; i < num; i++) {
        printf("%d", stock[i]);
    }

    return 0;
}