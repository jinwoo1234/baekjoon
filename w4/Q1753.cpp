#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int, int>> arr[20001];
int INF = 4000000;

int distTable[20001];
int V, E, K;
int u, v, w;


void dijkstra() {
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> PQ;
    PQ.emplace(0, K);
    distTable[K] = 0;

    while(!PQ.empty()) {
        int dist = PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        if(distTable[cur] < dist) {
            continue;
        }

        for(int i = 0; i < arr[cur].size(); i++) {
            int cost = dist + arr[cur][i].second;

            if(cost < distTable[arr[cur][i].first]) {
                distTable[arr[cur][i].first] = cost;
                PQ.emplace(cost,arr[cur][i].first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    cin >> K;

    fill_n(distTable, V + 1, INF);

    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        arr[u].emplace_back(v, w);
    }

    dijkstra();

    for (int i = 1; i <= V; i++)
    {
        if (distTable[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << distTable[i] << '\n';
        }
    }

    return 0;
}