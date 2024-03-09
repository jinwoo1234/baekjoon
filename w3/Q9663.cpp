#include <iostream>

using namespace std;

int n;
int arr[16];
int count = 0;

bool check(int i) {
    for(int j = 0; j < i; j++) {
        if(arr[i] == arr[j] || abs(j - i) == abs(arr[j] - arr[i])) {
            return false;
        }
    }
    return true;
}

void q(int i) {
    if(i == n) {
        ++count;
        return;
    }

    for(int j = 0; j < n; j++) {
        arr[i] = j;
        if(check(i)) {
            q(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    q(0);

    cout << count;

    return 0;
}