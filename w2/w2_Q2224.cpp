#include <iostream>

using namespace std;

int arr[52][52] = {0, };
int count = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, front, back;
    string input;

    cin >> n;

    for(int i = 0; i <= n; i++) {
        getline(cin, input);

        if(input.front() == input.back()) {
            continue;
        }

        if(input.front() >= 97) {
            front = input.front() - 71;
        } else {
            front = input.front() - 65;
        }

        if(input.back() >= 97) {
            back = input.back() - 71;
        } else {
            back = input.back() - 65;
        }

        if(!arr[front][back]) {
            count++;
        }

        arr[front][back] = 1;
    }

    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            for(int k = 0; k < 52; k++) {

                if(j == k || arr[j][k]) {
                    continue;
                }

                arr[j][k] = arr[j][i] && arr[i][k];

                if(arr[j][k]) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            if(arr[i][j]) {
                if(i < 26) {
                    front = i + 65;
                } else {
                    front = i + 71;
                }

                if(j < 26) {
                    back = j + 65;
                } else {
                    back = j + 71;
                }

                cout << (char)front << " => " << (char)back << endl;
            }
        }
    }

    return 0;
}