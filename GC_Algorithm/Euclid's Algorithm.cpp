#include<stdio.h>

typedef long long ll;
ll a, b;

int gcd(ll a, ll b) {
	if (b == 0) 
		return a;

	return gcd(b, a % b);
}
int main()
{
	int x, y;
	scanf("%d %d", &a, &b);

	printf("%d", gcd(a, b));
}