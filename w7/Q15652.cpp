#include <iostream>

using namespace std;

int arr[9] = {0, }, check[9] = {0, };
int n, m;

void printNum(int index) {
    if(index == m + 1) {
        for(int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(i >= arr[index-1]) {
            arr[index] = i;
            printNum(index + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    printNum(1);

    return 0;
}