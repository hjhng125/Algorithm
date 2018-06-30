#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int n;
vector<int> hist;
stack<int> s;
int main()
{
	scanf("%d", &n);
	hist.resize(n + 1);
	
	int maxR = 0;
	int height, width;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &hist[i]);
	}

	for (int i = 1; i <= n; ++i) {
		//������ ������� �ʰ� ���� ������ top���� ���� ������ ũ�ٸ�
		while (!s.empty() && hist[s.top()] > hist[i]) { 
			height = hist[s.top()]; //���� stack top �ε����� pop�ϸ� ���̷� ����
			s.pop();
			width = i - 1;
			if(!s.empty())
				width = i - s.top() - 1; //stack top�� arr �ε����� ���־� �ʺ� ����
			maxR = max(maxR, height * width);
		}
		s.push(i);
	}
	while (!s.empty()) {
		height = hist[s.top()];
		s.pop();
		width = n;
		if(!s.empty())
			width = n - s.top();
		maxR = max(maxR, height * width);
	}
	
	printf("%d", maxR);

	return 0;
}