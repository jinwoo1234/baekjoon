#include <iostream>

using namespace std;

int n;
long long int arr[100001][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < 3; i++) {
        arr[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        arr[i][0] = (arr[i-1][0] + arr[i-1][1] + arr[i-1][2]) % 9901;
        arr[i][1] = (arr[i-1][0] + arr[i-1][2]) % 9901;
        arr[i][2] = (arr[i-1][0] + arr[i-1][1]) % 9901;
    }

    cout << (arr[n][0] + arr[n][1] + arr[n][2]) % 9901;

    return 0;
}