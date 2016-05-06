//
//  Created by TaoSama on 2016-05-06
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, p, sum[N];
char s[N], op[N];
int l[N], r[N];

void link(int x, int y) {
    r[x] = y;
    l[y] = x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &p) == 3) {
        scanf("%s", s + 1);
        set<pair<int, int> > L, R;
        for(int i = 1; i <= n; ++i)
            if(s[i] == '(') {
                sum[i] = sum[i - 1] + 1;
                L.insert({sum[i], i});
            } else {
                sum[i] = sum[i - 1] - 1;
                R.insert({sum[i], i});
            }
        for(int i = 0; i <= n + 1; ++i) {
            l[i] = i - 1, r[i] = i + 1;
//            printf("l[%d] = %d, r[%d] = %d\n", i, l[i], i, r[i]);
        }
        scanf("%s", op + 1);
        for(int i = 1; i <= m; ++i) {
            if(op[i] == 'L') p = l[p];
            else if(op[i] == 'R') p = r[p];
            else {
                set<pair<int, int> >::iterator iter;
                if(s[p] == '(') {
                    iter = R.lower_bound({sum[p] - 1, p});
//                    pr(p); prln(sum[p] - 1);
                    assert(iter != R.end());

                    int x = l[p], y = r[iter->second];
//                    printf("s[%d] = %c x = %d, y = %d\n", p, s[p], x, y);
                    link(x, y);
                    p = y;
                    if(p == n + 1) p = l[p];
                } else {
                    iter = L.lower_bound({sum[p] + 1, p});
//                    pr(p); prln(sum[p] + 1);
//                    return 0;
                    assert(iter != L.begin());
                    int x = l[(--iter)->second], y = r[p];
//                    printf("s[%d] = %c x = %d, y = %d\n", p, s[p], x, y);
                    link(x, y);
                    p = y;
                    if(p == n + 1) p = l[p];
                }

            }
        }
        p = r[0];
        while(p != n + 1) {
            putchar(s[p]);
            p = r[p];
        }
        puts("");
    }
    return 0;
}
