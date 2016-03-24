//
//  Created by TaoSama on 2015-08-06
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, A, m, a[N];
bool vis[N];

bool check(int x) {
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= x; i++) vis[a[i]] = 1;
    int sum = 0, ok = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1) {
            ok = 0;
        } else {
            ok ++;
            if(ok >= A) {
                ok -= A;
                sum++;
                i++;
            }
        }
    }
    return sum >= k;

}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &k, &A, &m) == 4) {
        for(int i = 1; i <= m; ++i) scanf("%d", a + i);

        int l = 1, r = m + 1;
        while(l < r) {
            int mid = l + r >> 1;
//          pr(mid);
            if(check(mid)) {
//              cout << "true\n";
                l = mid + 1;
            } else {
//              cout << "false\n";
                r = mid;
            }
        }
        cout << (l == m + 1 ? -1 : l) << '\n';
    }
    return 0;
}
