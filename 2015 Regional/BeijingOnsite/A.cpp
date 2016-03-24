//
//  Created by TaoSama on 2015-11-15
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int r, n;
long long sum[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &r, &n);
        memset(sum, 0, sizeof sum);
        for(int i = 1; i <= n; ++i) {
            int x, y, w, h; scanf("%d%d%d%d", &x, &y, &w, &h);
            sum[x + 1] += h;
            sum[x + w + 1] -= h;
        }
        for(int i = 1; i <= r; ++i)
            sum[i] += sum[i - 1];
        for(int i = 1; i <= r; ++i)
            sum[i] += sum[i - 1];

        int p = -1;
        long long dif = 1e18;
        for(int i = 0; i <= r; ++i) {
            if(sum[i] >= sum[r] - sum[i]) {
                long long tmp = 2 * sum[i] - sum[r];
                if(tmp < dif || tmp == dif && i > p) {
                    p = i;
                    dif = tmp;
                }
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
