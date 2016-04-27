//
//  Created by TaoSama on 2016-04-27
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

typedef long long LL;

LL n, r;
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
                     41, 43, 47, 53, 59, 61
                    };

void dfs(int p, int e, int cnt, LL n, LL& sum) {
    if(e > 62) return; //4^31 -> 2^62
    if(p == prime.size()) {
        if(e == 1) return;
        LL cur = pow((long double)(n + 0.5), 1.0 / e) - 1;
        if(cnt & 1) sum += cur;
        else sum -= cur;
        return;
    }
    dfs(p + 1, e, cnt, n, sum);
    if(prime[p] <= r) dfs(p + 1, e * prime[p], cnt + 1, n, sum);
}

LL calc(LL n) {
    LL sum = 0;
    dfs(0, 1, 0, n, sum);
    return n - sum - 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d%I64d", &n, &r);
        LL ans = n, cnt = calc(n);
        while(cnt < n) {
            ans += n - cnt;
            cnt = calc(ans);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
