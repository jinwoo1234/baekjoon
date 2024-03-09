#include <iostream>

using namespace std;

int arr[8], check[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int n, m;

void printNum(int count, int index) {
    check[index] = count;
    if (m - 1 == count) {
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[j] == i) {
                    cout << arr[j] << " ";
                }
            }
        }
        cout << "\n";
        check[index] = -1;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(check[i] == -1) {
            printNum(count + 1, i);
        }
    }

    check[index] = -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        fill_n(check, -1, sizeof(check));
        printNum(0, i);
    }

    return 0;
}