/**
	@file	BOJ1135.cpp
	@brief	1135 problem of BOJ
	@author Hong Jin Hyung
	@return none
	@remark none
	@version none
	@code
	for (int i = 0; i < u.size(); ++i){
		int next = u[i].second;
		u[i].first = 1 + checkDFS(next);
	}
	sort(u.begin(), u.end(), comp);
	for (int i = 0; i < u.size(); ++i){
		u[i].first += i;
		ret = max(ret, u[i].first);
	}
	@endcode
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

typedef pair<int, int> pii;
int n, val;
vector<vector<pii> > adj;

/**
*	\brief		compare pair variable
*	\details	copare
*	\author		Hong jin Hyung
*	\date		2018.4.7
*	\bug		N/A
*	\warning	N/A	
*/
bool comp(pii a, pii b){
	return a.first > b.first;
}
/**
*	\brief		check node
*	\details	checking depth level
*	\author		Hong jin Hyung
*	\date		2018.4.7
*	\bug		N/A
*	\warning	N/A	
*/
int checkDFS(int root){
	int ret = 0;
	vector<pii> u;
	u = adj[root];
	if (!u.size())
		return 0;
	for (int i = 0; i < u.size(); ++i){
		int next = u[i].second;
		u[i].first = 1 + checkDFS(next);
	}
	sort(u.begin(), u.end(), comp);
	for (int i = 0; i < u.size(); ++i){
		u[i].first += i;
		ret = max(ret, u[i].first);
	}

	return ret;
}
/**
*	\brief		Main function
*	\details	print lowest search
*	\author		Hong jin Hyung
*	\date		2018.4.7
*	\bug		N/A
*	\warning	N/A
*/
int main()
{
	scanf("%d", &n);
	adj.resize(n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &val);
		if (val != -1)
			adj[val].push_back(make_pair(0, i));
	}
	printf("%d", checkDFS(0));

	return 0;
}
