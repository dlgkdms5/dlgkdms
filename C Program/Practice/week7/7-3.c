#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
typedef struct point {
	int x;
	int y;
}POINT;
void input_random_point(POINT* p, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		(p + i)->x = rand() % 101;
		(p + i)->y = rand() % 101;
	}
}
void swap_point(POINT* p1, POINT* p2) {
	POINT temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void print_point_array(POINT p[], int size) {
	for (int i = 0; i < size; i++)
		printf("p[%3d] : (%3d, %3d)\n", i, p[i].x, p[i].y);
}
void selection_sort_point(POINT* point, int size) {
	int least;
	for (int i = 0; i < SIZE - 1; i++) {
		least = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (point[least].x > point[j].x) least = j;
			else if ((point + least)->x == point[j].x && point[least].y > point[j].y) least = j;
		}
		swap_point(&point[i], point + least);
	}
}
int main() {
	POINT point[SIZE] = { 0 };
	POINT temp = { 0,0 };

	input_random_point(point, SIZE);
	print_point_array(point, SIZE);
	selection_sort_point(point, SIZE);
	printf("after sorting>>>>>>>>>>>>>>>>\n");
	for (int i = 0; i < SIZE; i++)
		printf("point[%3d] : (%3d, %3d)\n", i, point[i].x, point[i].y);
	return 0;
}
