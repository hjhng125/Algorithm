#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct POINT {
	float x, y;
}Point;

Point p[5] = { { 0.0,2.0 },{ 6.0,67.0 },{ 39.0,107.0 },{ 43.0,71.0 },{ 189.0,140.0 } };
Point strip[5];
int n = 5;
bool compareX(Point p1, Point p2) {
	return p1.x < p2.x;
}

double dist(Point p1, Point p2) {
	double d = sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
	return d;
}

double calMin(float p1, float p2) {
	if (p1 > p2)
		return p2;
	return p1;
}
double bruteforce(int p1, int p2) {
	double minD = 98765432.0;
	for (int i = p1; i < p2; ++i) {
		for (int j = i + 1; j < p2; ++j) {
			minD = calMin(minD, dist(p[i], p[j]));
		}
	}
	return minD;
}

double stripDist(int size, float minD) {
	double minDist = minD;

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size && strip[j].y - strip[i].y < minD; ++j)
			minDist = calMin(minDist, dist(strip[i], strip[j]));
	}
	return minDist;
}
double c_pair(int q1, int q2) {
	if (q2 - q1 <= 3)
		return bruteforce(q1, q2);
	int mid = (q1 + q2) / 2;

	double dl = c_pair(q1, mid);
	double dr = c_pair(mid, q2);

	double minD = calMin(dl, dr);

	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(p[mid].x - p[i].x) < minD) {
			strip[j] = p[i];
			j++;
		}
	}

	return calMin(minD, stripDist(j, minD));
}
int main()
{

	qsort(p, n, sizeof(Point), compareX);
	printf("%lf", c_pair(0, n - 1));
}