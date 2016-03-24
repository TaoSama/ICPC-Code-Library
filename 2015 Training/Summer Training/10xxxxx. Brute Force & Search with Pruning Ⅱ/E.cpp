//
//  Created by TaoSama on 2015-07-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <ctime>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;
const char* op = "*+-";

vector<string> ex;

bool isLegal(string &s) {
    int cnt = 0;
    for(int i = 1; i < s.size() - 1; ++i) {
        if(!isdigit(s[i])) ++cnt;
        if(!isdigit(s[i - 1]) && s[i] == '0' && isdigit(s[i + 1]))
            return false;
    }
    return cnt > 0;
}

void dfs(string s, int p) {
    if(p == s.size()) {
        ex.push_back(s);
        return;
    }
    for(int i = 0; i < 3; ++i) {
        string ns = s;
        ns.insert(p, 1, op[i]);
        dfs(ns, p + 2);
    }
    dfs(s, p + 1);
}

int parse(string &s) {
    int ret = 0, i = 0, mul = 0;
    char op = '+';
    while(i < s.size() && isdigit(s[i]))
        mul = mul * 10 + s[i++] - '0';
    while(i < s.size()) {
        if(s[i] == '*') {
            int tmp = 0; ++i;
            while(i < s.size() && isdigit(s[i]))
                tmp = tmp * 10 + s[i++] - '0';
            mul *= tmp;
        } else {
            if(op == '+') ret += mul;
            else ret -= mul;
            op = s[i];
            mul = 0; ++i;
            while(i < s.size() && isdigit(s[i]))
                mul = mul * 10 + s[i++] - '0';
        }
    }
    if(op == '+') ret += mul;
    else ret -= mul;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> s && s != "=") {
        s.pop_back();
        ex.clear();
        dfs(s, 1);
        cout << "Problem " << ++kase << '\n';
        bool ok = false;
        for(auto &i : ex) {
            if(isLegal(i) && parse(i) == 2000) {
                ok = true;
                cout << "  " << i << "=\n";
            }
        }
        if(!ok) cout << "  IMPOSSIBLE\n";
    }
    return 0;
}
