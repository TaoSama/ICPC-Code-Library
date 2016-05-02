//
//  Created by TaoSama on 2016-05-03
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 6e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int rt, ls[N], rs[N];
char s[N << 1], t[7010];

void dfs(int rt) {
    s[n++] = (rt & 1) + '0';
    if(ls[rt]) {
        dfs(ls[rt]);
        s[n++] = (rt & 1) + '0';
    }
    if(rs[rt]) {
        dfs(rs[rt]);
        s[n++] = (rt & 1) + '0';
    }
}

int kmp() {
    m = strlen(t);
    vector<int> nxt(m + 1);
    nxt[0] = -1;
    for(int i = 0, j = -1; i < m;) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }

    int ret = 0;
    for(int i = 0, j = 0; i < n;) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == m) {
            ++ret;
            j = nxt[j];
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);

        set<int> st;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(!st.size()) rt = x;
            else {
                auto it = st.lower_bound(x);
                if(it == st.end()) rs[*--it] = x;
                else {
                    if(!ls[*it]) ls[*it] = x;
                    else rs[*--it] = x;
                }
            }
            st.insert(x);
        }
        scanf("%s", t);

        n = 0;
        dfs(rt);
        s[n] = 0;

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, kmp());
    }
    return 0;
}
