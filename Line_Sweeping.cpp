#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1e9

int sweep();

vector<pair<int, int> > vt;
int c;

int main()
{
	int s, e;

	scanf("%d",&c);
	for (int i = 0; i < c; ++i){
		scanf("%d %d", &s, &e);
		vt.push_back(make_pair(s, e));
	}
	sort(vt.begin(),vt.end()); // ��Ȱ�� sweeping�� ���� ����

	printf("%d",sweep());
	return 0;
}
int sweep()
{
	int l, r, result = 0;

	l = -INF;
	r = -INF;
	for (int i = 0; i < c; i++){
		if (r < vt[i].first){ // ������ ��ġ�� ���� ���ο� �����϶�
			result += r - l; // ���ο� ������ �Է� �� ���� ������
			l = vt[i].first;
			r = vt[i].second;
		}
		else r = max(r, vt[i].second); //������ ��ĥ �� ���� �ֽ�ȭ
	}
	result += r - l; // �������� �߰��� ������ ���� �־���
	return result;
}
