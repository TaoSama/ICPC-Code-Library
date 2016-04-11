//
//  Created by TaoSama on 2016-03-18
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int L, n, k;
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &L, &n, &k);
        vector<LL> l(1, 0), r(1, 0); //l[0] = r[0] = 0
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            while(y--) {
                if(x << 1 < L) l.push_back(x);
                else r.push_back(L - x);
            }
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        for(int i = k; i < l.size(); ++i) l[i] += l[i - k];
        for(int i = k; i < r.size(); ++i) r[i] += r[i - k];

        LL ans = l.back() + r.back() << 1;
        for(int i = 0; i <= k; ++i) {
            int a = max(0, (int)l.size() - 1 - i);
            int b = max(0, (int)r.size() - 1 - (k - i));
            ans = min(ans, L + (l[a] + r[b] << 1));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
