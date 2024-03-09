#include <iostream>

using namespace std;

struct node{
    int num;
    node* next;
};

class Stack {
private:
    int size = 0;
    node* topNode = NULL;
public:
    void push(int num);
    int pop();
    int getSize();
    int empty();
    int top();
};

void Stack::push(int num) {
    node* newNode = new node;

    newNode->num = num;
    if(size <= 0) {
        newNode->next = NULL;
    } else {
        newNode->next = topNode;
    }

    topNode = newNode;

    size++;
}

int Stack::pop() {
    if(size <= 0) {
        return -1;
    }

    int num = topNode->num;
    node* node = topNode->next;

    free(topNode);

    topNode = node;

    size--;
    return num;
}

int Stack::getSize() {
    return size;
}

int Stack::empty() {
    if(size <= 0) {
        return 1;
    } else {
        return 0;
    }
}

int Stack::top() {
    if(size <= 0 ) {
        return -1;
    }

    return topNode->num;
}

int main() {
    Stack stack;
    int n;
    string input;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> input;

        if(input == "push") {
            int num;
            cin >> num;
            stack.push(num);
        } else if(input =="pop") {
            cout << stack.pop() << endl;
        } else if(input == "size") {
            cout << stack.getSize() << endl;
        } else if(input == "empty") {
            cout << stack.empty() << endl;
        } else if(input =="top") {
            cout << stack.top() << endl;
        }
    }

    return 0;
}