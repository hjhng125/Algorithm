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
		//스택이 비어있지 않고 현재 스택의 top값이 들어올 값보다 크다면
		while (!s.empty() && hist[s.top()] > hist[i]) { 
			height = hist[s.top()]; //현재 stack top 인덱스를 pop하며 높이로 지정
			s.pop();
			width = i - 1;
			if(!s.empty())
				width = i - s.top() - 1; //stack top의 arr 인덱스를 빼주어 너비 지정
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