#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
typedef struct Point {
    double x,y;
}point;
typedef struct Line {
    int p1, p2;
    double dist;
}line;
point p[100];
vector<int> parent;
vector<line> lines;
double total = 0.0;
bool cmp(line l1, line l2){
    return l1.dist < l2.dist;
}
int find(int i) {
    if(parent[i] == i)
        return parent[i];
    return parent[i] = find(parent[i]);
}
bool join(int p1, int p2) {
    p1 = find(p1);
    p2 = find(p2);

    if(p1 == p2)
        return false;

    parent[p2] = p1;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;

    int line_num = n*(n-1)/2;
    lines.resize(static_cast<unsigned long>(line_num));
    parent.resize(static_cast<unsigned long>(line_num));

    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    for(int i = 0; i < n; ++i)
        parent[i] = i;

    int idx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j) {
            lines[idx].dist = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            lines[idx].p1 = i;
            lines[idx].p2 = j;
            idx++;
        }
    }
    sort(lines.begin(), lines.end(), cmp);
    for(int i = 0; i < idx; ++i) {
        if(join(lines[i].p1, lines[i].p2))
            total += lines[i].dist;
    }
    cout << total;
    return 0;
}