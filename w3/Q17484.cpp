#include <iostream>

using namespace std;

int n, m;
int arr[10][10], table[10][10][4];

int search(int i, int j, int dir) {
    if(i == n) {
        return 0;
    }

    if(table[i][j][dir] != 1000000) {
        return table[i][j][dir];
    }

    if(j-1 >= 0 &&dir != 0) { // 전에 온 방향이 왼쪽 아닐경우
        table[i][j][dir] = min(table[i][j][dir], arr[i][j] + search(i + 1, j - 1, 0));
    }
    if(dir != 1) { // 방향이 직선 아닐경우
        table[i][j][dir] = min(table[i][j][dir], arr[i][j] + search(i + 1, j, 1));
    }
    if(j+1 <= m &&  dir != 2){ // 방향이 오른쪽 아닐경우
        table[i][j][dir] = min(table[i][j][dir], arr[i][j] + search(i + 1, j + 1, 2));
    }

    return table[i][j][dir];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int minValue = 1000000;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m + 2; j++) {
            arr[i][j] = 1000000;
            table[i][j][0] = 1000000;
            table[i][j][1] = 1000000;
            table[i][j][2] = 1000000;
            table[i][j][3] = 1000000;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        minValue = min(minValue, search(0, i, 3));
    }

    cout << minValue;

    return 0;
}