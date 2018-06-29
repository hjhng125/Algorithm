#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

vector<int> dwarf;
int total = 0;
void sum() {
	for (int i = 0; i < 9; ++i) {
		total += dwarf[i];
	}
}
void solution() {
	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (total - dwarf[i] - dwarf[j] == 100) {
				dwarf[i] = 0;
				dwarf[j] = 0;
				return;
			}
		}
	}
}
int main()
{
	dwarf.resize(9);
	for (int i = 0; i < 9; ++i)
		scanf("%d", &dwarf[i]);
	sort(dwarf.begin(),dwarf.end());
	sum();
	solution();

	for (int i = 0; i < 9; ++i) {
		if (dwarf[i] != 0)
			printf("%d\n", dwarf[i]);
	}
	return 0;
}



