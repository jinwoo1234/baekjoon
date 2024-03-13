#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    string input[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for(int i = 0; i < n; i++) {
        int count = 0;
        int ans = 0;
        for(char j : input[i]) {
            if(j == 'O') {
                ans += ++count;
            } else {
                count = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}