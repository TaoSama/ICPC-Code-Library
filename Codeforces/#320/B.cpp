//
//  Created by TaoSama on 2015-09-16
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

int n, ans[805];
struct P {
    int s, i, j;
    bool operator<(const P& rhs) const {
        return s > rhs.s;
    }
} a[800 * 800];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int cnt = 0;
        n <<= 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                scanf("%d", &a[cnt].s);
                a[cnt].i = i;
                a[cnt].j = j;
//                printf("%d %d %d\n", a[cnt].s, a[cnt].i, a[cnt].j);
                ++cnt;
            }
        }
        sort(a, a + cnt);
        memset(ans, 0, sizeof ans);
        for(int i = 0; i < cnt; ++i) {
            P& cur = a[i];
//          printf("%d %d %d\n", cur.s, cur.i, cur.j);
            if(ans[cur.i] || ans[cur.j]) continue;

            ans[cur.i] = cur.j;
            ans[cur.j] = cur.i;
        }
        for(int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
