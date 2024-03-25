#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, arr[300];
    int dp[300][2];
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i][0] = arr[i];
        dp[i][1] = arr[i];
    }

    dp[1][0] += dp[0][0];

    for(int i = 2; i < n; i++) {
        dp[i][0] += dp[i-1][1];
        dp[i][1] += max(dp[i-2][0], dp[i-2][1]);
    }

    ans = max(dp[n-1][0], dp[n-1][1]);

    cout << ans;

    return 0;
}