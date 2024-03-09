#include <iostream>

using namespace std;

int n, m, h;
int arr[11][11];
int ans = 0;
int start[2];
pair<int, int> mint[11];
int m_index;

int distance(int i, int j, int k, int l) {
    return abs(i - k) + abs(j - l);
}

void search(int count, int hp, int i, int j) {
    if(hp - distance(i, j, start[0], start[1]) >= 0) {
        ans = max(ans, count);
    }

    for(int index = 0; index < m_index; index++) {
        if(mint[index].first != -1) {
            if(hp - distance(i, j, mint[index].first, mint[index].second) >= 0) {
                pair<int, int> temp = mint[index];
                mint[index] = make_pair(-1, -1);

                search(count + 1, hp - distance(i, j, temp.first, temp.second) + h, temp.first, temp.second);

                mint[index] = temp;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                start[0] = i;
                start[1] = j;
            } else if(arr[i][j] == 2) {
                mint[m_index++] = make_pair(i, j);
            }
        }
    }

    search(0, m, start[0], start[1]);

    cout << ans;

    return 0;
}