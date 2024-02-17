#include <iostream>

using namespace std;

struct Tree {
    char value;
    char left;
    char right;
} tree[27];

void preorder(int index) {
    cout << tree[index].value;
    if(tree[index].left != '.') {
        preorder(tree[index].left - 'A');
    }
    if(tree[index].right != '.') {
        preorder(tree[index].right - 'A');
    }
}

void inorder(int index) {
    if(tree[index].left != '.') {
        inorder(tree[index].left - 'A');
    }
    cout << tree[index].value;
    if(tree[index].right != '.') {
        inorder(tree[index].right - 'A');
    }
}

void postorder(int index) {
    if(tree[index].left != '.') {
        postorder(tree[index].left - 'A');
    }
    if(tree[index].right != '.') {
        postorder(tree[index].right - 'A');
    }
    cout << tree[index].value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    char name, left, right;
    for(int i = 0; i < n; i++) {
        cin >> name >> left >> right;
        tree[name-'A'].value = name;
        tree[name-'A'].left = left;
        tree[name-'A'].right = right;
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}