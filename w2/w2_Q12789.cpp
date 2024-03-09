#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, now, i;
    int order[1001];
    stack<int> stack;

    cin >> n;

    for(i = 1; i <= n; i++) {
        cin >> order[i];
    }

    i = 1;
    int j = 1;

     do {
        if(j <= n) {
            if(stack.empty() || stack.top() > order[j]) {
                stack.push(order[j++]);
            }
        }

        if(stack.top() == i) {
            i++;
            stack.pop();
        } else if(stack.top() > i && order[j] > i && stack.top() < order[j]) {
            break;
        }
    } while(i <= n);

    if(i > n) {
        cout << "Nice";
    } else {
        cout << "Sad";
    }

    return 0;
}