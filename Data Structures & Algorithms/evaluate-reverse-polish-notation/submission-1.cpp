class Solution {
    char isOperand(string t) {
        if (t == "+") return '+';
        else if (t == "-") return '-';
        else if (t == "*") return '*';
        else if (t == "/") return '/';
        return 'a';
    }

    int executeOperand(int i, int j, char op) {
        switch(op) {
            case '+': return i + j;
                break;
            case '-': return i - j;
                break;
            case '*': return i * j;
                break;
            case '/': return i / j;
                break;
            default: return 0;
                break;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string tok: tokens) {
            char op = isOperand(tok);
            if (op != 'a') {
                int j = s.top();
                s.pop();
                int i = s.top();
                s.pop();
                int k = executeOperand(i, j, op);
                s.push(k);
            } else {
                s.push(stoi(tok));
            }
        }
        return s.empty() ? 0 : s.top();
    }
};
