#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
};

class Node {
public:
    void insert(int item) {
        node* newNode = new node;
        newNode->value = item;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        size++;
    }

    int getFirstElement() const {
        if (head != nullptr)
            return head->value;
        return -1;
    }

    int getNthElement(int n) const {
        if (n == 0)
            return getFirstElement();
        if (n < -1 || head == nullptr)
            return -1;
        node* temp = head;
        int i = 1;
        while (i < n) {
            temp = temp->next;
            i++;
        }
        return temp->value;
    }

    int getLastElement() const {
        if (head == nullptr)
            return -1;
        node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        return temp->value;
    }

    int length() const {
        return size;
    }

    void print() const {
        node* temp = head;
        std::cout << "{";
        if (temp == nullptr)
            goto end;
        while (temp != NULL) {
            std::cout << temp->value;
            temp = temp->next;
            if (temp != NULL)
                std::cout << ", ";
        }
        end:
        std::cout << "}" << std::endl;
    }

private:
    node* head;
    int size;
};

int main() {
    List l{};
    cout << "Length: " << l.length() << endl;
    l.insert(10);
    l.insertFirst(5);
    l.insert(20);
    l.insertAt(0, 3);
    l.print();
    cout << "Length: " << l.length() << endl;
    l.replace(5, 7);
    l.replaceFirst(1);
    l.replaceLast(15);
    l.replaceAt(l.length() - 1, 30);
    l.print();
    cout << "Length: " << l.length() << endl;
    l.removeFirst();
    l.removeLast();
    l.removeAt(l.length() - 1);
    l.remove(7);
    cout << "Length: " << l.length() << endl;
    l.print();
    l.insert(10);
    l.insertFirst(5);
    l.insert(20);
    l.insertAt(0, 3);
    int i = 0;
    while (i < l.length())
        cout << l.get(i++) << endl;
    return 0;
}

//int precedence(char c) {
//    if (c == '^')
//        return 3;
//    else if (c == '*' || c == '/')
//        return 2;
//    else if (c == '+' || c == '-')
//        return 1;
//    return -1;
//}
//
//bool isOperator(char ch) {
//    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
//}
//
//bool isOpening(char ch) {
//    return ch == '(';
//}
//
//bool isClosing(char ch) {
//    return ch == ')';
//}
//
//bool isVar(char ch) {
//    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
//}
//
//string infixToPostfix(stack<char> st, string infix) {
//    string postfix_exp;
//    for(int i = 0; i < infix.length(); i++) {
//        char ch = infix[i];
//        if (isVar(ch))
//            postfix_exp += ch;
//        else if(isOpening(ch))
//            st.push('(');
//        else if(isClosing(ch)) {
//            while(st.top() != '(') {
//                postfix_exp += st.top();
//                st.pop();
//            }
//            st.pop();
//        } else {
//            while (!st.empty() && precedence(ch) < precedence(st.top())) {
//                postfix_exp += st.top();
//                st.pop();
//            }
//            st.push(ch);
//        }
//    }
//    while (!st.empty()) {
//        postfix_exp += st.top();
//        st.pop();
//    }
//    return postfix_exp;
//}
//
//string infixToPrefix(stack<char> st, string infix)
//{
//    string prefix_exp;
//    reverse(infix.begin(), infix.end());
//    for (int i = 0; i < infix.size(); i++) {
//        if (infix[i] == '(')
//            infix[i] = ')';
//        else if (infix[i] == ')')
//            infix[i] = '(';
//    }
//    prefix_exp = infixToPostfix(st, infix);
//    reverse(prefix_exp.begin(), prefix_exp.end());
//    return prefix_exp;
//}