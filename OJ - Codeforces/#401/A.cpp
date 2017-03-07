//
//
//  Created by TaoSama on 2017-02-26
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
char p[N], s[N], t[N];
int a[N];

int tim, vis[N];
bool check(int x) {
    ++tim;
    for(int i = 0; i < x; ++i) vis[a[i] - 1] = tim;
    n = 0;
    for(int i = 0; i < k; ++i) if(vis[i] != tim) s[n++] = p[i];
    s[n] = 0;

    for(int i = 0, j = 0; i < n; ++i) {
        if(s[i] == t[j]) {
            if(++j == m) return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> p >> t) {
        m = strlen(t);
        k = strlen(p);
        for(int i = 0; i < k; ++i) cin >> a[i];
        int l = 0, r = k, ans = -1;
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m)) ans = m, l = m + 1;
            else r = m - 1;
        }
        cout << ans << endl;
    }

    return 0;
}
