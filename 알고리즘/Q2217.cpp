#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int maxWeight = 0;
    int* rope = new int[100001];

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> rope[i];
    }

    sort(rope + 1, rope + n + 1);

    for(int i = 1; i <= n; i++) {
        if(maxWeight < rope[i] * (n - (i - 1))) {
            maxWeight = rope[i] * (n - (i - 1));
        }
    }

    cout << maxWeight;

    return 0;
}
