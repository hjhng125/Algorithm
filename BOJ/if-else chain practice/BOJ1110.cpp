#include<cstdio>
#include<algorithm>

using namespace std;

int cnt;
int n;
void len(int new_num) {
	if (new_num == n && cnt) {
		printf("%d", cnt);
		return;
	}
	int ten = new_num / 10;
	int one = new_num % 10;
	int sum = ten + one;
	cnt++;
	len(one * 10 + sum % 10);
}
int main() {

	scanf("%d", &n);
	len(n);
}