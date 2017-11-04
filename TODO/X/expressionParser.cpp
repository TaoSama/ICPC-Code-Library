#include <bits/stdc++.h>

using namespace std;

void RE(bool fuck) {
    if(!fuck) printf("%d\n", 1 / 0);
}

double calc(stack<double>& opd, char op) {
    double y = opd.top(); RE(!opd.empty()); opd.pop();
    double x = opd.top(); RE(!opd.empty()); opd.pop();
    if(op == '+') return x + y;
    else if(op == '-') return x - y;
    else if(op == '*') return x * y;
    return x / y;
}

int getPriority(char c) {
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    return 0;
}

double getResult(char* expr, int length) {
    stack<double> opd;
    stack<char> opr;
    for(int i = 0; i < length; ++i) {
        char c = expr[i];
        if(c == '(') opr.push(c);
        else if(c == ')') {
            while(true) {
                char top = opr.top(); opr.pop();
                if(top == '(') break;
                opd.push(calc(opd, top));
            }
        } else if(isdigit(c)) {
            int j = i;
            double oct = 0, dec = 0, x = 1;
            for(; j < length && (isdigit(expr[j]) || expr[j] == '.'); ++j) {
                if(expr[j] == '.') {++j; break;}
                oct = oct * 10 + expr[j] - '0';
            }
            for(; j < length && isdigit(expr[j]); ++j) {
                x *= 0.1;
                dec += x * (expr[j] - '0');
            }
            opd.push(oct + dec);
            i = j - 1;
        } else {
            if(!opr.size()) opr.push(c);
            else {
                char top = opr.top();
                int pT = getPriority(top);
                int pN = getPriority(c);
                if(pN > pT) opr.push(c);
                else {
                    opr.pop();
                    opr.push(c);
                    opd.push(calc(opd, top));
                }
            }
        }
    }
    while(opr.size()) {
        char top = opr.top(); opr.pop();
        opd.push(calc(opd, top));
    }
    return opd.top();
}

int main() {

//    int a[] = {8, 4, 1, 6, 7, 4, 9, 6, 4};
    char* expr1 = "2/5";
    char* expr2 = "(10.5*((1+4/2)-5+(9+1)))/2.0";
    printf("%.2f\n", getResult(expr1, strlen(expr1)));
//    printf("%.2f\n", getResult(expr2, strlen(expr2)));

    return 0;
}
