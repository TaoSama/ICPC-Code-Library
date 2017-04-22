//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    stack<double> stk;
    string cur;
    vector<string> vs;
    while(cin >> cur) vs.push_back(cur);
    reverse(vs.begin(), vs.end());

    bool ok = true;
    for(const auto& cur : vs) {
        if(!ok) break;
        if(cur.size() == 1 && !isdigit(cur.front())) {
            double x = stk.top(); stk.pop();
            double y = stk.top(); stk.pop();

            if(cur[0] == '+') {
                stk.push(x + y);
            } else if(cur[0] == '-') {
                stk.push(x - y);
            } else if(cur[0] == '*') {
                stk.push(x * y);
            } else if(cur[0] == '/') {
                if(abs(y) < 1e-5) ok = false;
                else stk.push(x / y);
            } else ok = false;

        } else stk.push(stod(cur));
//        prln(stk.top());
    }
    ok &= stk.size() == 1;
    if(ok) cout << fixed << setprecision(1) << stk.top() << endl;
    else cout << "ERROR" << endl;


    return 0;
}
