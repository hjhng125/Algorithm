#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<stdbool.h>

typedef struct NODE {
	int x, y;
}Node;
Node* node;
int n;
float distance = 0;
bool compareX(Node a, Node b) {
	return a.x < b.x;
}
bool compareY(Node a, Node b) {
	return a.y < b.y;
}
float minNum(float a, float b) {
	return (a < b) ? a : b;
}
float dist(Node a, Node b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
float bruteForce(int size) {
	float min = FLT_MAX;
	for (int i = 1; i <= size; ++i)
		for (int j = i + 1; j <= size; ++j)
			if (dist(node[i], node[j]) < min)
				min = dist(node[i], node[j]);
	return min;
}
float stripClosest(Node strip[], int size, float d) {
	float min = d;

	for (int i = 1; i < size; ++i) {
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++) {
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
		}
	}
	return min;
}
float closest_pair(Node nx[], Node ny[], int size) {
	if (size <= 3) return bruteForce(size);
	int mid = (size + 1) / 2;
	Node midnode = nx[mid];

	Node* nyl;
	Node* nyr;
	nyl = (Node*)malloc(sizeof(Node) * (mid + 1));
	nyr = (Node*)malloc(sizeof(Node) * (size - mid + 1));
	int li = 1, ri = 1;
	for (int i = 1; i <= size; ++i) {
		if (ny[i].x <= midnode.x)
			nyl[li++] = ny[i];
		else
			nyr[ri++] = ny[i];
	}
	float dl = closest_pair(nx, nyl, mid);
	float dr = closest_pair(nx + mid, nyr, size - mid);

	float minD = minNum(dl, dr);

	Node* strip;

	strip = (Node*)malloc(sizeof(Node) * (size + 1));
	int j = 1;
	for (int i = 1; i <= size; ++i) {
		if (abs(nx[i].x - midnode.x) < minD)
			strip[j] = nx[i], j++;
	}
	return minNum(minD, stripClosest(strip, j, minD));
}

float closest() {
	Node* nx, *ny;
	nx = (Node*)malloc(sizeof(Node) * (n + 1));
	ny = (Node*)malloc(sizeof(Node) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		nx[i] = node[i];
		ny[i] = node[i];
	}
	qsort(nx, n + 1, sizeof(Node), compareX);
	qsort(ny, n + 1, sizeof(Node), compareY);

	return closest_pair(nx, ny, n);
}
int main()
{
	scanf("%d", &n);
	if (n == 0) {
		printf("You have to input more than Zero.");
		exit(1);
	}
	node = (Node*)malloc(sizeof(Node) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &node[i].x, &node[i].y);
	}
	float ans = closest();
	if (ans < 10000)
		printf("%.2f\n", ans);
	else printf("Infinity\n");
}