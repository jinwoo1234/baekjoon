#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    long long int arr[1001] = {0, };

    cin >> n;

    arr[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            arr[i] += arr[j] % 10007;
        }

        if(i % 2 == 0) {
            arr[i] += 2;
        } else {
            arr[i]++;
        }
    }

    cout << arr[n] % 10007;

    return 0;
}