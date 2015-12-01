#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

struct exp {
    char val;
    exp* left;
    exp* right;

    exp(char c) : val(c), left(nullptr), right(nullptr) {}
};

void q_postfix(exp* root) {
    std::queue<exp*> q;
    std::stack<char> s;
    q.push(root);

    while (!q.empty()) {
        exp* front = q.front();
        q.pop();
        s.push(front->val);
        if (front->left != nullptr)
            q.push(front->left);
        if (front->right != nullptr)
            q.push(front->right);
    }

    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    unsigned n;

    std::cin >> n;

    while (n--) {
        std::string s;
        std::cin >> s;

        std::stack<exp*> stk;

        for (char c : s) {
            if (std::islower(c)) {
                exp* tmp = new exp(c);
                stk.push(tmp);
            } else {
                exp* a = stk.top();
                stk.pop();
                exp* b = stk.top();
                stk.pop();

                exp* op = new exp(c);
                op->left = b;
                op->right = a;

                stk.push(op);
            }
        }

        q_postfix(stk.top());
    }

    return 0;
}
