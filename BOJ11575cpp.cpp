/**
	@file		BOJ11575.cpp
	@brief		Encrypt Sting
	@author		Hong JinHyung
	@return		none
	@remark		none
	@version	none
	@code
	for (int j = 0; j < length; ++j){
	x = str[j] - 65;
	str[j] = (a*x + b) % 26 + 65;
	}
	@endcode
*/
#include<cstdio>
#include<cstring>
#define MAX 1000000
using namespace std;
/**
	\brief		Main function.
	\details	Encrypt String
	\author		Hong JinHyung
	\version	0.0
	\date		2018/04/06
	\pre		First initialize the system
	\bug		N/A
	\warning    N/A
*/
int main()
{
	int t, a, b, x;
	char str[MAX] = "";

	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		scanf("%d %d", &a, &b);
		scanf("%s",&str);
		
		int length = strlen(str);
		for (int j = 0; j < length; ++j){	
			x = str[j] - 65;
			str[j] = (a*x + b) % 26 + 65;
		}
		printf("%s\n", str);
	}
	return 0;
}