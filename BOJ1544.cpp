#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> buffer;

void check(string compStr){
	if (buffer.empty()){
		buffer.push_back(compStr);
		return;
	}
	
	for (int i = 0; i < buffer.size(); ++i){
		string temp = buffer[i];
		for (int k = 0; k < compStr.size(); ++k){
			if (compStr == temp)
				return;
			char ch = compStr.at(0);
			compStr = compStr.erase(0, 1) + ch;
		}
	}
	buffer.push_back(compStr);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		char input[51];
		scanf("%s", &input);
		check(input);
	}
	printf("%d", buffer.size());
	
	buffer.clear();
	return 0;
}