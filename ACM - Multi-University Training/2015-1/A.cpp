//
//  Created by TaoSama on 2016-04-12
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int pre[N];

vector<int> divisors[N];
void gao() {
    for(int i = 1; i <= 1e4; ++i)
        for(int j = i; j <= 1e4; j += i)
            divisors[j].push_back(i);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        map<int, int> last;
        for(int i = 1; i <= n; ++i) {
            pre[i] = 0;
            for(int d : divisors[a[i]]) pre[i] = max(pre[i], last[d]);
            last[a[i]] = i;
        }

        last.clear();
        int ans = 0;
        for(int i = n; i; --i) {
            int nxt = n + 1;
            for(int d : divisors[a[i]]) if(last[d]) nxt = min(nxt, last[d]);
            ans += 1LL * (i - pre[i]) * (nxt - i) % MOD;
            if(ans >= MOD) ans -= MOD;
            last[a[i]] = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
