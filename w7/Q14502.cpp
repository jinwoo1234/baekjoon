#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[8][8];
int copy_map[8][8];
vector<pair<int, int>> blank;
vector<pair<int, int>> virus;

int ans = 0;

void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}

void bfs() {
    queue<pair<int, int>> q;
    for(pair<int, int> pos : virus) {
        q.push(pos);
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        copy_map[x][y] = 2;

        // 4방향 추가
        if(x-1 >= 0 && copy_map[x-1][y] == 0)
            q.emplace(x-1, y);
        if(x+1 < n && copy_map[x+1][y] == 0)
            q.emplace(x+1, y);
        if(y-1 >= 0 && copy_map[x][y-1] == 0)
            q.emplace(x, y-1);
        if(y+1 < m && copy_map[x][y+1] == 0)
            q.emplace(x, y+1);
    }
}

void make_wall() {
    for(int i = 0; i < blank.size(); i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                copy();

                copy_map[blank[i].first][blank[i].second] = 1;
                copy_map[blank[j].first][blank[j].second] = 1;
                copy_map[blank[k].first][blank[k].second] = 1;

                int ans_cnt = 0;

                bfs();

                for(int ii = 0; ii < n; ii++) {
                    for(int jj = 0; jj < m; jj++) {
                        if(copy_map[ii][jj] == 0)
                            ans_cnt++;
                    }
                }

                ans = max(ans, ans_cnt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                virus.emplace_back(i, j);
            } else if(map[i][j] == 0) {
                blank.emplace_back(i, j);
            }
        }
    }

    make_wall();

    cout << ans;

    return 0;
}