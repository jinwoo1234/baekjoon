#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> graph[1001];
bool dfs_visited[1001] = {false, };
bool bfs_visited[1001] = {false, };

void dfs() {
    stack<int> stack;

    int node = v;
    stack.push(node);

    while(!stack.empty()) {
        node = stack.top();
        stack.pop();
        if(!dfs_visited[node])
            cout << node << " ";
        dfs_visited[node] = true;

        for(int i = graph[node].size() - 1; i >= 0; i--) {
            if(!dfs_visited[graph[node][i]]) {
                stack.push(graph[node][i]);
            }
        }

    }
}

void bfs() {
    queue<int> queue;

    int node = v;
    queue.push(node);

    while(!queue.empty()) {
        node = queue.front();
        queue.pop();
        cout << node << " ";
        bfs_visited[node] = true;

        for(int i = 0; i < graph[node].size(); i++) {
            if(!bfs_visited[graph[node][i]]) {
                queue.push(graph[node][i]);
                bfs_visited[graph[node][i]] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> v;

    int node1, node2;

    for(int i = 1; i <= m; i++) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for(int i = 0; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs();
    cout << "\n";
    bfs();

    return 0;
}