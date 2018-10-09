#include <stdio.h>
#define MAX 1001

int isCheck(int, int);
void find(int);
void solution(int);

int isEmpty();
int isFull(int);
void push(int);
int pop();

typedef struct ELEPHANT {
	int weight;
	int IQ;
} Elephant;

int dp[MAX];
Elephant e[MAX];
int stack[MAX], top;
int prev[MAX];

int main() {
	int i;
	int n;

	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		scanf("%d %d", &e[i].weight, &e[i].IQ);
	} 
	find(n);

	solution(n);

	return 0;
}

int isCheck(int i, int j) {
	if (e[i].weight > e[j].weight && e[i].IQ < e[j].IQ)
		return 1;
	return 0;
}

void find(int n) {
	int i, j;

	for (i = 1; i <= n; ++i) {
		dp[i] = 1;
	}

	for (i = 2; i <= n; ++i) {
		for (j = 1; j < i; ++j) {
			if (isCheck(i, j)) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}
			}
		}
	}
}

void solution(int n) {
	int i;
	int max, pos;

	max = dp[1];
	pos = 1;

	for (i = 2; i <= n; ++i) {
		if (max < dp[i]) {
			max = dp[i];
			pos = i;
		}
	}

	do {
		push(pos);
		pos = prev[pos];
	} while (pos != 0);

	printf("%d\n", max);
	while (!isEmpty()) {
		printf("%d\n", pop());
	}
}

int isEmpty() {
	if (top > 0)
		return 0;
	return 1;
}

int isFull(int n) {
	if (top <= n)
		return 0;
	return 1;
}

void push(int val) {
	stack[++top] = val;
}

int pop() {
	int val;

	val = stack[top--];
	return val;
}