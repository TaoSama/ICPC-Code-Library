//
//  Created by TaoSama on 2015-12-12
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N], b[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);
        memset(c, 0, sizeof c);
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            ++c[x];
        }
        multiset<int> x, y;
        multiset<int>::iterator iter;
        int delta = 0;
        for(int i = 1; i <= n; ++i) {
            b[i] -= delta;
            if(a[i]) {
                iter = y.upper_bound(b[i]);
                y.erase(y.begin(), iter);
                x.insert(b[i]);
            } else {
                iter = x.upper_bound(b[i]);
                x.erase(x.begin(), iter);
                y.insert(b[i]);
            }
            delta += c[i];
        }
        printf("%d\n", x.size() + y.size());
    }
    return 0;
}
