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

/*#pragma warning(disable:4996)
#include <stdio.h>

typedef struct system {
    int in;
    int out;
};

void scan(struct system* s, int* size, int* id) {
    scanf("%d", size);
    for (int i = 0; i < *size; i++) scanf("%d", &s[i].in);
    for (int i = 0; i < *size; i++) scanf("%d", &s[i].out);
    scanf("%d", id);
}

void print(struct system* s, int* size, int* id) {
    printf("%d\n", s[*id - 1].in - s[*id - 1].out);
    for (int i = 0; i < *size; i++) printf("%d ", s[i].in - s[i].out);
}

int main() {
    int n, id;
    struct system s[101] = { 0 };
    scan(s, &n, &id);
    print(s, &n, &id);
}*/ //���� �ڵ�