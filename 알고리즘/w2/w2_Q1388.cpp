#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    int count = 0;
    char arr[51][51] = {0, };

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 0) {
                continue;
            }

            count++;

            if(arr[i][j] == '-') {
                int a = j;
                while(arr[i][a] == '-') {
                    arr[i][a++] = 0;
                }
            }

            if(arr[i][j] == '|') {
                int a = i;
                while(arr[a][j] == '|') {
                    arr[a++][j] = 0;
                }
            }
        }
    }

    cout << count;

    return 0;
}