#include<stdio.h>

typedef long long ll;
ll a, b;

int gcd(int* x, int* y,ll a, ll b) {
	int _x, _y;
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int ans = gcd(&_x, &_y, b, a % b);
	*x = _y;
	*y = _x - (a / b) * _y;
	return ans;
}
int main()
{
	int x, y;
	scanf("%d %d", &a, &b);
	
	printf("%d %d %d", x, y, gcd(&x, &y, a, b));
}