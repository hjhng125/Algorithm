#include<stdio.h>

//Variable
int row, col, min_row_idx;
int table[11][101], cost[11][101];
int pos1, pos2, pos3;
int stack[101]; // using back tracking

/*
Parameter : current col/row index
Operation : compare value using previous info
Return : null
*/
void compare_idx(int col_idx, int row_idx) {
	if (row_idx == 1) {
		pos1 = row_idx;
		pos2 = row_idx + 1;
		pos3 = row;
	}
	else if (row_idx == row) {
		pos1 = 1;
		pos2 = row_idx - 1;
		pos3 = row_idx;
	}
	else {
		pos1 = row_idx - 1;
		pos2 = row_idx;
		pos3 = row_idx + 1;
	}
	if ((cost[pos1][col_idx - 1] <= cost[pos2][col_idx - 1]) && (cost[pos1][col_idx - 1] <= cost[pos3][col_idx - 1]))
		min_row_idx = pos1;
	else if ((cost[pos2][col_idx - 1] <= cost[pos3][col_idx - 1]) && (cost[pos2][col_idx - 1] <= cost[pos1][col_idx - 1]))
		min_row_idx = pos2;
	else if ((cost[pos3][col_idx - 1] <= cost[pos1][col_idx - 1]) && (cost[pos3][col_idx - 1] <= cost[pos2][col_idx - 1]))
		min_row_idx = pos3;
}

/*
Parameter : null
Operation : Back tracking
Return : null
*/
void tracking()
{
	int min = 1e9;
	
	for (int i = 1; i <= row; ++i) {
		if (min > cost[i][col]) {
			min = cost[i][col];
			min_row_idx = i;
		}
	}
	for (int i = col; i > 0; --i) {
		stack[col - i + 1] = table[min_row_idx][i];
		compare_idx(i, min_row_idx);
	}
}

/*
Parameter : null
Operation : Make DP table
Return : null
*/
void make_cost_table() {

	for (int i = 1; i <= row; ++i)
		cost[i][1] = table[i][1];

	for (int i = 2; i <= col; ++i) {
		for (int j = 1; j <= row; ++j) {
			compare_idx(i, j);
			cost[j][i] = cost[min_row_idx][i - 1] + table[j][i];
		}
	}
}
int main()
{

	scanf("%d %d", &row, &col);

	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			scanf("%d", &table[i][j]);
		}
	}
	make_cost_table();
	tracking();

	printf("\n");
	for (int i = col; i > 0; --i) {
		printf("%d ", stack[i]);
	}
	printf("\n%d\n", cost[row][col]);
	return 0;
}