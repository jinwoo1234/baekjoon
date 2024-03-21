#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    string x;

    cin >> x;

    int ans = 0;

    if(x.at(0) == '0') {
        if(x.at(1) == 'x') {
            for(int i = x.size() - 1; i >= 2; i--) {
                if(x.at(i) > 95) {
                    ans += (int)(x.at(i) - 'a' + 10) * pow(16, x.size() - 1 - i);

                } else {
                    ans += (int)(x.at(i) - 48) * pow(16, x.size() - 1 - i);
                }
            }
        } else {
            for(int i = x.size() - 1; i >= 1; i--) {
                ans += (int)(x.at(i) - 48) * pow(8, x.size() - 1 - i);
            }
        }

        cout << ans;
    } else {
        cout << x;
    }

    return 0;
}