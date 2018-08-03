#include<cstdio>

using namespace std;

int main()
{
	int m, d;
	int m_d[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char day[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	scanf("%d %d", &m, &d);

	int cnt = 0;
	int dd = d;
	for (int i = 0; i < m - 1; ++i) {
		dd += m_d[i];
	}
	for (int j = 1; j <= dd; ++j) {
		cnt++;
		if (cnt == 7)
			cnt %= 7;
	}

	puts(day[cnt]);
}
