#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    long long int ans = 1;

    cin >> n;

    if(n <= 4) {
        ans = n;
    } else {
        while(n > 5) {
            ans *= 3;
            ans %= 10007;
            n -= 3;
        }
        if(n == 5) {
            ans = ans * 2 * 3;
        } else if(n == 4) {
            ans = ans * 2 * 2;
        } else if(n==3) {
            ans *= 3;
        }
    }

    cout << ans % 10007;

    return 0;
}