#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    string n;
    long long int ans = 0;

    cin >> n;

    for(int i = 0; i < n.size(); i++) {
        for(int j = 0; j < n.size(); j++) {
            ans += (n[i] - 48) * pow(10, j);
        }
    }

    cout << ans;

    return 0;
}