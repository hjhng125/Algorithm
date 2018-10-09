#include<stdio.h>
#include<stdbool.h>

typedef struct jewel_box {
	int d;
	int c;
	float comp;
	int cnt;
}jbox;
jbox jb[2];
int n;
int h, l;
bool flag;
int comp_jewel_box() {
	if (jb[0].comp < jb[1].comp) {
		h = 1;
		l = 0;
	}
	else {
		h = 0;
		l = 1;
	}
}
int main()
{
	
	while (true) {
		flag = false;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < 2; ++i) {
			scanf("%d %d", &jb[i].d, &jb[i].c);
			jb[i].comp = (float)jb[i].c / jb[i].d;
		}
		comp_jewel_box();
		while (n >= jb[h].c) {
			if (!(n % jb[h].c)) {
				flag = true;
				jb[0].cnt = n / jb[h].c;
				printf("%d %d\n", jb[0].cnt, jb[1].cnt);
				break;
			}
			else {
				n -= jb[l].c;
				jb[l].cnt++;
			}
		}
		if(!flag)
			printf("failed\n");
	}	
}

/*
43
1 3
2 4
40
5 9
5 12 
0*/