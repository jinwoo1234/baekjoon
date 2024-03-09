#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int arr[500001];
    long long int ans = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    for(int i = 1; i <= n; i++) {
        ans += abs(arr[i] - i);
    }

    cout << ans;

    return 0;
}