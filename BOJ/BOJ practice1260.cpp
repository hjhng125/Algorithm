#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int > adj[1001];
bool visit[1001];

void dfs(int s){
    cout << s << " ";
    visit[s] = true;

    for(int next:adj[s]){
        if(visit[next])
            continue;
        dfs(next);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visit[s] = true;
    cout << s << " ";
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next:adj[cur]){
            if(visit[next])
                continue;
            q.push(next);
            visit[next] = true;
            cout << next << " ";
        }
    }
}
int main() {
    int s;
    cin >> n >> m >> s;

    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    dfs(s);
    fill_n(visit, 1001, false);
    cout << endl;
    bfs(s);
    return 0;
}

