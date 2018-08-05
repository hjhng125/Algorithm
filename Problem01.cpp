#include<cstdio>
#include<vector>

using namespace std;

int t;
int first[6] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
int second[5] = { 5120000, 2560000, 1280000, 640000, 320000 };
int sumA(int a) {
	int suma;

	if (a == 1) suma = first[0];
	else if (a >= 2 && a <= 3) suma = first[1];
	else if (a >= 4 && a <= 6) suma = first[2];
	else if (a >= 7 && a <= 10)suma = first[3];
	else if (a >= 11 && a <= 15)suma = first[4];
	else if (a >= 16 && a <= 21) suma = first[5];
	else  suma = 0;

	return suma;
}
int sumB(int b) {
	int sumb;

	if (b == 1) sumb = second[0];
	else if (b >= 2 && b <= 3) sumb = second[1];
	else if (b >= 4 && b <= 7) sumb = second[2];
	else if (b >= 8 && b <= 15)sumb = second[3];
	else if (b >= 16 && b <= 31)sumb = second[4];
	else  sumb = 0;

	return sumb;
}
int main()
{
	scanf("%d", &t);

	while (t--) {
		int a, b;
		int suma, sumb;
		scanf("%d %d", &a, &b);
		printf("%d\n", sumA(a)+ sumB(b));
	}
}