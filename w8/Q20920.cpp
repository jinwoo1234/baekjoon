#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> words;
map<string, int> counts;

bool compare(string a, string b) {
    if(counts[a] == counts[b]) {
        if(a.size() == b.size()) {
            return a < b;
        }
        return a.size() > b.size();
    }
    return counts[a] > counts[b];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;

    string input;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> input;

        if(input.size() < m) {
            continue;
        }

        if(counts.find(input) == counts.end()) {
            words.emplace_back(input);
        }

        counts[input]++;
    }

    sort(words.begin(), words.end(), compare);

    for(int i = 0; i < words.size(); i++) {
        cout << words[i] << "\n";
    }

    return 0;
}