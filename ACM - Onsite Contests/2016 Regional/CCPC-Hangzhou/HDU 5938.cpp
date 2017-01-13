//
//  Created by TaoSama on 2016-10-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;
typedef long long LL;
char op[N][N];
int ls[N], rs[N];
int sz;

int build(const char* s, int l, int r) {
    int add = -1, mul = -1, p = 0;

    bool allDigit = true;
    for(int i = l; i <= r; ++i) {
        if(!isdigit(s[i])) allDigit = false;
        if(s[i] == '(') ++p;
        if(s[i] == ')') --p;
        if(s[i] == '+' || s[i] == '-')
            if(!p) add = i;
        if(s[i] == '*' || s[i] == '/')
            if(!p) mul = i;
    }

    if(allDigit) { //leaf node
        int u = ++sz;
        ls[u] = rs[u] = 0;
        for(int i = l; i <= r; ++i)
            op[u][i - l] = s[i];
        return u;
    }

    //can't find +- outside brackets, then use */
    if(add < 0) add = mul;
    //been bracketed
    if(add < 0) return build(s, l + 1, r - 1);

    int u = ++sz;
    ls[u] = build(s, l, add - 1);
    rs[u] = build(s, add + 1, r);
    op[u][0] = s[add];
    return u;
}

LL parse(int u) {
    if(!ls[u]) {
        LL cur = 0;
        for(int i = 0; op[u][i]; ++i)
            cur = cur * 10 + op[u][i] - '0';
        return cur;
    }
    LL x = parse(ls[u]);
    LL y = parse(rs[u]);

    if(op[u][0] == '+') return x + y;
    else if(op[u][0] == '-') return x - y;
    else if(op[u][0] == '*') return x * y;
    else return x / y;
}

LL calc(string& s) {
    sz = 0;
    memset(op, 0, sizeof op);
    int rt = build(s.c_str(), 0, s.size() - 1);
    LL tmp = parse(rt);
    return tmp;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s;

        LL ans = -1e18;
        for(int i = 2; i <= s.size() - 3; ++i) {
            string a = s;
            a.insert(i, "-");
            string b = a;
            a.insert(1, "+");
            b.insert(i - 1, "+");
            a.insert(i + 4, "/");
            b.insert(i + 4, "/");
            a.insert(i + 3, "*");
            b.insert(i + 3, "*");

            ans = max({ans, calc(a), calc(b)});
        }

        static int kase = 0;
        cout << "Case #" << ++kase << ": " << ans << "\n";
    }

    return 0;
}
