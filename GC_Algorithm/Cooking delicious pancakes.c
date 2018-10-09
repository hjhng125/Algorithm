#include<stdio.h>

int ans[100];
int ans_idx = 0;
int cake[30], n;
void flip(int i) {
	int temp, start = 0, idx = i;
	while (start < i) {
		temp = cake[start];
		cake[start] = cake[i];
		cake[i] = temp;
		start++;
		i--;
	}
	if (idx != 0) {
		ans[ans_idx] = n - idx;
		ans_idx++;
	}
}

void solution(int n) {
	for (int i = n; i >  1; i--) {
		int max = 0;
		int max_idx;
		for (int j = 0; j < i; ++j){
			if (max < cake[j]) {
				max = cake[j];
				max_idx = j;
			}
		}
		if (max_idx != i - 1) {
			flip(max_idx);
			flip(i - 1);
		}
	}
}

int main() {
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cake[i]);
	}
	solution(n);
	for (int i = 0; i < n; i++) {
		printf("%d ", cake[i]);
	}
	printf("\n");
	ans[ans_idx] = 0;
	for (int i = 0; i <= ans_idx; i++) {
		printf("%d ", ans[i]);
	}
}
