#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

typedef struct POINT {
	float x, y;
}Point;

Point p[5] = { {0,2},{6,67},{39,107},{43,71},{189,140} }, strip[5], nx[5];
int n = 5;
bool compareX(Point p1, Point p2) {
	return p1.x < p2.x;
}

float dist(Point p1, Point p2) {
	return sqrt(pow(p1.x - p2.x) - pow(p1.y - p2.y));
}

float bruteforce(Point p[]) {
	float minD = FLT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			minD = min(minD, dist(p[i], p[j]));
		}
	}
	return minD;
}

float stripDist(Point strip[], int size, float minD) { 
	float minDist = minD;

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size, strip[j] - strip[i] < minD; ++j)
			minDist = min(minDist, dist(strip[i], strip[j]));
	}
	return minDist;
}
float c_pair(Point p[], int q1, int q2) {
	if (q2 - q1 <= 3)
		return bruteforce(p, q1, q2);
	int mid = (q1 + q2) / 2;

	float dl = c_pair(p, q1, mid);
	float dr = c_pair(p, mid, q2);

	float minD = min(dl, dr);

	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(p[mid] - p[i]) < minD) {
			strip[j] = p[i];
			j++;
		}
	}
	return min(minD, stripDist(strip, j, minD));
}
int main()
{

	for (int i = 0; i < n; ++i) {
		scanf("%f %f", &p[i].x, &p[i].y);
	}

	qsort(p, n, compareX);
	printf("%f", c_pair(p, 0, n - 1);
}