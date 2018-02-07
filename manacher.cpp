#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

char str[100000];
vector<string> arr;
vector<int> a;
int main()
{	
	int idx;
	scanf("%s",str);
	int n = strlen(str);
	arr.resize(n * 2 + 1);
	for (idx = 0; idx < n; ++idx){	
		arr[idx * 2 + 1] = str[idx];
		arr[idx*2] = '#';
	}
	arr[idx * 2] = '#';
	
	a.resize(n * 2 + 1);
	int r, p; // r : ���� �ε������� �����Ǿ��ִ� �Ӹ������ ������ �ε���
	r = 0; p = 0; // p : �� r�� �Ӹ������ �߽� 
	for (int i = 0; i < arr.size(); ++i){
		if (r >= i) // i�� �Ӹ���� �ȿ� ���� ���
			a[i] = min(r - i, a[2 * p - i]); // r-i : i���� �ش� �Ӹ���� ���� ����Ǿ��ִ� ����, a[2*p-i] : i'(p�� ��Ī���� i�� ��Ī��)�� ����� ����  
		else // i�� �Ӹ���� �ۿ� ���� ���
			a[i] = 0;
		while (i - a[i] - 1 >= 0 && i + a[i] + 1 < arr.size() && arr[i - a[i] - 1] == arr[i + a[i] + 1]) a[i]++;
		if (r < i + a[i]){ // �Ӹ������ ���� update 
			r = i + a[i];
			p = i;
		}
	}
	int maxr = 0;
	for (int i = 0; i < arr.size(); ++i)
		maxr = max(maxr,a[i]);
	printf("%d\n",maxr);
	
	return 0;
}