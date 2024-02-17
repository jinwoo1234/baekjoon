#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    long long int n, m, c;
    long long int input;
    long long int sum = 0, max = 0;

    cin >> n >> m;

    vector<int>v;

    for(int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    long long int start = 0;
    long long int end = v[n-1];

    while(start <= end) {
        sum = 0;
        c = (start + end) / 2;

        for(int i = 0; i < n; i++) {
            if(c < v[i]) {
                sum += v[i] - c;
            }
        }

        if(sum < m){
            end = c - 1;
        } else {
            start = c + 1;
            max = c;
        }
    }

    cout << max;

    return 0;
}