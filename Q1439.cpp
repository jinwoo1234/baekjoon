#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    int ans = 0;

    cin >> s;

    char before_str = s[0];
    char match_str = s[0];
    for(int i = 0; i < s.size(); i++) {
        if(match_str != s[i]) {
            if(before_str != s[i]) {
                ans++;
            }
        }
        before_str = s[i];
    }

    cout << ans;

    return 0;
}