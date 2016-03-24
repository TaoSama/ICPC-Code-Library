//
//  Created by TaoSama on 2015-08-14
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cnt, k;
char s[8][8], t[8][8], ans[8];
set<char> col[10];

bool dfs(int d) {
    if(d == 7) {
        if(++cnt == k) {
            puts(ans + 1);
            return true;
        }
        return false;
    }
    for(auto &c : col[d]) {
        ans[d] = c;
        if(dfs(d + 1)) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &k);
        for(int i = 1; i <= 6; ++i) scanf("%s", s[i] + 1);
        for(int i = 1; i <= 6; ++i) scanf("%s", t[i] + 1);

        for(int j = 1; j <= 6; ++j) {
            set<char > v;
            col[j].clear();
            for(int i = 1; i <= 6; ++i) v.insert(s[i][j]);
            for(int i = 1; i <= 6; ++i) {
                if(v.count(t[i][j])) col[j].insert(t[i][j]);
            }
        }

        cnt = 0;
        if(!dfs(1)) puts("NO");
    }
    return 0;
}
