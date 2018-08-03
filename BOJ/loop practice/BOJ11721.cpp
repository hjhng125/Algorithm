#include<cstdio>

using namespace std;

int main()
{
	char str[256];
	gets_s(str);

	putchar(str[0]);
	for (int i = 1; str[i] != '\0'; ++i) {
		if (!(i % 10))
			printf("\n");
		putchar(str[i]);
	}
}
