#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int *men, *women;
    int ans = 1000000000;

    cin >> n >> m;

    men = new int[n];
    women = new int[m];
    int dp[n][m];

    for(int i = 0; i < n; i++) {
        cin >> men[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> women[i];
    }

    sort(men, men + n);
    sort(women, women + m);

    dp[0][0] = abs(men[0] - women[0]);

    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0], abs(men[i] - women[0]));
    }

    for(int j = 1; j < m; j++) {
        dp[0][j] = min(dp[0][j-1], abs(men[0] - women[j]));
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if (i < j) {
                dp[i][j] =  min(dp[i][j-1], dp[i-1][j-1] + abs(men[i] - women[j]));
            } else if(i == j) {
                dp[i][j] = dp[i-1][j-1] + abs(men[i] - women[j]);
            } else if(i > j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(men[i] - women[j]));
            }
        }
    }

    cout << dp[n-1][m-1];

    delete[] men;
    delete[] women;

    return 0;
}
