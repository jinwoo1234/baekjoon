#include <iostream>
#include <algorithm>

using namespace std;

int arr[9] = {0, }, print_arr[9] = {0, }, check[9] = {0, };
int n, m;

void printNum(int index) {
    if(index == m + 1) {
        for(int i = 1; i <= m; i++) {
            cout << print_arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(check[i] == 0) {
            if(print_arr[index - 1] < arr[i]) {
                check[i] = 1;
                print_arr[index] = arr[i];
                printNum(index + 1);
                check[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    printNum(1);

    return 0;
}