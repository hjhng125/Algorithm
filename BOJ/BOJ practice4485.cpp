#include <cstdio>
#include <queue>
#define INF 1e9

using namespace std;

int n;
int arr[125][125], dist[125][125];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int idx = 1;
    while (1) {
        scanf("%d", &n);

        if (n == 0)
            return 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
                dist[i][j] = INF;
            }
        }
        priority_queue <pair<int, int>> pq;
        pq.push({0, 0});
        dist[0][0] = arr[0][0];
        while (!pq.empty()) {
            int curRow = pq.top().first;
            int curCol = pq.top().second;
            pq.pop();

            for (int i = 0; i < 4; ++i) {
                int nextRow = curRow + dy[i];
                int nextCol = curCol + dx[i];

                if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= n) continue;
                if (dist[nextCol][nextRow] > dist[curCol][curRow] + arr[nextCol][nextRow]) {
                    pq.push({nextRow, nextCol});
                    dist[nextCol][nextRow] = dist[curCol][curRow] + arr[nextCol][nextRow];
                }

            }
        }
        printf("Problem %d: %d\n", idx, dist[n - 1][n - 1]);
        idx++;
    }
}