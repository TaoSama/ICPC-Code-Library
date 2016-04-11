//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
string a[50], b[50];

bool check(string s) {
    if(s.size() == 1) return s[0] == 'a';
    for(int i = 1; i <= q; ++i) {
        auto p = s.find(a[i]);
        if(p != 0) continue;
        string t = s;
        t[p] = b[i][0];
        t.erase(p + 1, 1);
        if(check(t)) return true;
    }
    return false;
}

void construct(string s, int& ans) {
    if(s.size() == n) {
        if(check(s)) ++ans;
        return;
    }
    for(char c = 'a'; c <= 'f'; ++c)
        construct(s + c, ans);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
        cin >> a[i] >> b[i];

    int ans = 0;
    construct("", ans);
    printf("%d\n", ans);
    return 0;
}
