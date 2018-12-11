#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int q[6], n = 5;
bool promising(int row) {
	if (row < 1) return true;
	for (int i = 0; i < row; ++i) {
		if (q[row] == q[i] || row - i == abs(q[row] - q[i])) // 세로배제, 대각배제
			return false;
	}
	return true;
}

int nQueen(int row) {
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		q[row] = i; // int 변수는 row, q array는 column
		if (promising(row)) {
			if (row == n - 1) {
				return 1;
			}
			else {
				sum += nQueen(row + 1);
			}
		}
	}
	return sum;
}
int main()
{
	printf("%d", nQueen( 0));
}


