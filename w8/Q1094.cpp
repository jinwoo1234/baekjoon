#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int x, count = 0;

    cin >> x;

    while(x > 0) {
        count += x % 2;
        x /= 2;
    }

    cout << count;
    return 0;
}