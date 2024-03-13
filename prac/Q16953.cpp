#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    long long int A, B;
    int ans = 1;

    cin >> A >> B;

    while(B > A) {
        if(B % 2 == 0) {
            B /= 2;
        } else if(B % 10 == 1) {
            B /= 10;
        } else {
            ans = -1;
            break;
        }
        ans++;
    }

    if(A != B) {
        ans = -1;
    }

    cout << ans;

    return 0;
}