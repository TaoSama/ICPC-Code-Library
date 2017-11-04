#include <bits/stdc++.h>
using namespace std;

const string op = "+-*/";

int getPriority(char c) {
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return op.find(c) != string::npos;
}

double calcOnce(stack<double>& stk, char op) {
    assert(stk.size());
    double y = stk.top(); stk.pop();
    assert(stk.size());
    double x = stk.top(); stk.pop();
    //cout << x << ' ' << op << ' ' << y << endl;
    if(op == '+') return x + y;
    else if(op == '-') return x - y;
    else if(op == '*') return x * y;
    return x / y;
}

double calc(string& s) {
    stack<double> opd; stack<char> ops;
    for(char c : s) {
        if(c == '(') ops.push(c);
        else if(c == ')') {
            while(ops.size()) {
                char op = ops.top(); ops.pop();
                if(op == '(') break;
                opd.push(calcOnce(opd, op));
            }
        } else if(isOperator(c)) {
            if(!ops.size()) ops.push(c);
            else {
                int priorityCur = getPriority(c);
                char top = ops.top();
                int priorityNxt = getPriority(top);
                if(priorityCur > priorityNxt) {
                    ops.push(c);
                } else {
                    ops.pop();
                    opd.push(calcOnce(opd, top));
                    ops.push(c);
                }
            }
        } else {
            double x = c - '0';
            opd.push(x);
        }
    }
    while(ops.size()) {
        char top = ops.top(); ops.pop();
        opd.push(calcOnce(opd, top));
    }
    return opd.top();
}

bool check(int dep, bool lftBracketed, string s) {
    if(dep == s.size()) {
        if(!lftBracketed) {
//            cout << s << endl;
            if(abs(calc(s) - 24) < 1e-5) return true;
        }
        return false;
    }
    if(isdigit(s[dep])) {
        if(dep > 0) {
            for(int i = 0; i < 4; ++i) {
                string ns = s;
                ns.insert(dep, 1, op[i]);
                if(check(dep + 2, lftBracketed, ns)) return true;
                if(lftBracketed) {
                    ns.insert(dep + 2, 1, ')');
                    if(check(dep + 3, 0, ns)) return true;
                } else {
                    ns.insert(dep + 1, 1, '(');
                    if(check(dep + 3, 1, ns)) return true;
                }
            }
        } else {
            if(check(dep + 1, 0, s)) return true;
            if(!lftBracketed) {
                string ns = s;
                ns.insert(dep, 1, '(');
//                cout << ns << endl;
                if(check(dep + 2, 1, ns)) return true;
            }
        }
    } else if(check(dep + 1, 0, s)) return true;
    return false;

}

bool twentyFour(int a, int b, int c, int d) {
    auto toChar = [](int x) {return char('0' + x);};
    string v = string("") + toChar(a) + toChar(b) + toChar(c) + toChar(d);
    sort(v.begin(), v.end());

    bool ok = false;
    do {
//      cout << "1" << endl;
//      cout << v << endl;
        ok |= check(0, 0, v);
    } while(!ok && next_permutation(v.begin(), v.end()));
    return ok;
}

int main() {
    string test = "5*5-5/5";
    //cout << calc(test) << endl;
    cout << (calc(test)) << endl;
    cout << twentyFour(5, 5, 5, 5) << endl;
    cout << twentyFour(1, 2, 3, 0) << endl;

    return 0;
}
