#include<stdio.h>

void counting_sort(int);
int vt[10001] = { 0, };

int main()
{
	int num,input;

	scanf("%d",&num);

	for (int i = 1; i < num + 1; i++){
		scanf("%d", &input);
		vt[input]++;
	}
	counting_sort(num);

	return 0;
}
void counting_sort(int num)
{
	for (int i = 1; i <= 10000; i++){
		while (vt[i] --) {
			printf("%d\n", i);
		}
	}
}