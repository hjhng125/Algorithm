#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, column = 1;
int node[10001];
int left_end[10001];
int right_end[10001];
vector<int> tree[10001];

void dfs(int n_idx, int row){
    if(tree[n_idx][0] > 0)
        dfs(tree[n_idx][0], row+1);

    left_end[row] = min(left_end[row], column);
    right_end[row] = max(right_end[row], column++);

    if(tree[n_idx][1] > 0)
        dfs(tree[n_idx][1], row+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for(int i = 1; i <= n; ++i){
        int node_num, left_child, right_child;
        cin >> node_num >> left_child >> right_child;
        node[node_num]++;
        if(left_child > 0)
            node[left_child]++;
        if(right_child > 0)
            node[right_child]++;
        tree[node_num].push_back(left_child);
        tree[node_num].push_back(right_child);
    }
    int root = 0;
    for(int i = 1; i <= n; ++i) {
        if (node[i] == 1) {
            root = i;
            break;
        }
    }
    fill(left_end, left_end + 10001, INF);
    dfs(root, 1);

    int ans = 0;
    int ans_row = 0;
    for(int i = 1; i <= n; ++i){
        if(left_end[i] == INF)
            break;
        if(ans < right_end[i] - left_end[i] + 1) {
            ans_row = i;
            ans = right_end[i] - left_end[i] + 1;
        }
    }
    cout << ans_row << " " << ans;

    return 0;
}

