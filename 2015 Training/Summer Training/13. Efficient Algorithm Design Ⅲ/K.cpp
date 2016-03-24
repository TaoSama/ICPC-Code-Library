//
//  Created by TaoSama on 2015-08-03
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], l[N][N], r[N][N];
//p < q < r < s   Aq > As > Ap > Ar
//枚举s、p
//l[i][j]:= 大于Ap p小于q 最小值的位置 p->i q->j
//r[i][j]:= 小于As s大于r 最大值的位置 s->i r->j

bool judge() {
    for(int i = 1; i <= n; ++i) {
        l[i][0] = 0;
        for(int j = 1; j < i; ++j) {
            if(a[i] >= a[j])
                l[i][j] = l[i][j - 1];
            else if(!l[i][j - 1] || a[j] < a[l[i][j - 1]])
                l[i][j] = j;
            else l[i][j] = l[i][j - 1];
        }
    }
    for(int i = 1; i <= n; ++i) {
        r[i][n + 1] = 0;
        for(int j = n; j > i; --j) {
            if(a[i] <= a[j])
                r[i][j] = r[i][j + 1];
            else if(!r[i][j + 1] || a[j] > a[r[i][j + 1]])
                r[i][j] = j;
            else r[i][j] = r[i][j + 1];
        }
    }

    //i->2 j->3 x->1 y->4  p < q < r < s   Aq > As > Ap > Ar
    //o.O I's dizzy
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(!l[j][i - 1] || !r[i][j + 1] || a[i] <= a[j])
                continue;
            int x = l[j][i - 1], y = r[i][j + 1];
            if(a[x] > a[j] && a[y] > a[x] && a[i] > a[y])
                return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        if(judge()) puts("YES");
        else {
            reverse(a + 1, a + 1 + n);
            puts(judge() ? "YES" : "NO");
        }
    }
    return 0;
}
