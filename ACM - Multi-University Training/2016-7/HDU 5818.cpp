//
//  Created by TaoSama on 2016-08-09
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
#include <stack>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &q) == 1 && q) {
        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        vector<pair<int, int> > s[3];
        for(int i = 1; i <= q; ++i) {
            char op[10], wh[2]; scanf("%s%s", op, wh);
            int p1 = *wh - 'A';
            if(op[1] == 'u') {
                int x; scanf("%d", &x);
                s[p1].push_back({i, x});
            } else if(op[1] == 'o') {
                int p = s[p1].size() ? p1 : 2;
                auto e = s[p].back();
                s[p].pop_back();
                printf("%d\n", e.second);
            } else {
                scanf("%s", wh);
                int tmpSz = s[2].size();
                s[2].resize(s[2].size() + s[0].size() + s[1].size());
                merge(s[0].begin(), s[0].end(), s[1].begin(), s[1].end(),
                      s[2].begin() + tmpSz);
                for(int k = 0; k < 2; ++k) s[k].clear();
            }
        }
    }

    return 0;
}
