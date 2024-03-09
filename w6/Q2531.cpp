#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, d, k, c;
    int arr[30001];
    int ans = 0;

    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int count = 0;
        int chk[3001] = {0, };

        for(int j = 0; j < k; j++) {
            if(!chk[arr[(i + j) % n]]) {
                ++count;
                chk[arr[(i + j) % n]] = 1;
            }
        }

        if(!chk[c]) {
            ++count;
        }

        ans = max(ans, count);
    }

    cout << ans;

    return 0;
}