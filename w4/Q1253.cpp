#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    int n;
    long long int arr[2001];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        long long int sum;
        int start = 0;
        int end = n - 1;

        while(start < end) {
            sum = arr[start] + arr[end];
            if(start == i) {
                ++start;
                continue;
            }
            if(end == i) {
                --end;
                continue;
            }

            if(sum == arr[i]) {
                ans++;
                break;
            } else if(sum < arr[i]) {
                ++start;
            } else if(sum > arr[i]){
                --end;
            }
        }
    }

    cout << ans;

    return 0;
}