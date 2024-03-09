#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    int n;
    int arr[1001], dp[1001];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}