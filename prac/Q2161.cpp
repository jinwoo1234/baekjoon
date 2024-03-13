#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    int count = n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int index = 0;
    bool sw = true;

    while(count) {
        if(sw) {
            if(arr[index % n] != -1) {
                cout << arr[index % n] << " ";
                arr[index % n] = -1;
                count--;
                sw = !sw;
            }
        } else {
            if(arr[index % n] != -1) {
                sw = !sw;
            }
        }
        index++;
    }

    return 0;
}