/*
Lab 01
Author : Hong Jin Hyung
Date   : 2018-10-04

This problem is Longest Common Subsequence.

*Sample Input
abcb
bdca

abcbdab
bdcaba

abcdeefg
abgacef

*/
/*

LCS(char* s, char* t)
	dp[][] <- 0

	for i <- 1 to n
		for j <- 1 to m
			if s[i - 1] = t[j - 1]
				then dp[i][j] <- dp[i - 1][j - 1] + 1
			else 
				dp[i][j] <- max(dp[i - 1][j] or dp[i][j - 1])
	
	return dp[n][m]

*/

#include<stdio.h>
#include<string.h>

char s[256], t[256];
int dp[256][256];

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
int main()
{
	int n, m;

	printf("S = ");
	scanf("%s", s);
	getchar();
	printf("T = ");
	scanf("%s", t);
	
	n = strlen(s);
	m = strlen(t);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("Longest common subsequence is of length %d", dp[n][m]);

	return 0;
}