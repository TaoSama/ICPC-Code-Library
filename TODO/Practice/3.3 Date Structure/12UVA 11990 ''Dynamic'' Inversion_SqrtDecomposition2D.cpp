//
//  Created by TaoSama on 2015-07-11
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
const int B = 500;

int n, q, X[N], Y[N];
int cnt[B][B], sum[B][B]; //cnt:=2D块内点数 sum:=X的前缀点数和

void update_sum(int bx, int by) {
    int t = bx ? sum[bx - 1][by] : 0;
    for(int i = bx; i <= n / B; ++i) {
        t += cnt[i][by];
        sum[i][by] = t;
    }
}

void add(int x, int y) {
    X[y] = x; Y[x] = y;
    int bx = x / B, by = y / B;
    ++cnt[bx][by];
    update_sum(bx, by);
}

void del(int x, int y) {
    X[y] = Y[x] = -1;
    int bx = x / B, by = y / B;
    --cnt[bx][by];
    update_sum(bx, by);
}

//获得(0, 0)到(x, y)矩形区域的点数
int getRectSum(int x, int y) {
    int ret = 0, bx = x / B, by = y / B;
    if(bx) for(int i = 0; i < by; ++i) ret += sum[bx - 1][i];
    //这里要仔细注意边界问题 只能算一次
    for(int i = bx * B; i <= x; ++i)
        if(~Y[i] && Y[i] < by * B) ret++;
    for(int i = by * B; i <= y; ++i)
        if(~X[i] && X[i] <= x) ret++;
//  pr(x); pr(y); prln(ret);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
////    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        memset(X, -1, sizeof X);
        memset(Y, -1, sizeof Y);
        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);

        long long ans = 0;
        //原来的点被算进去也无所谓 最后会被减去
        for(int i = 1; i <= n; ++i) {
            int y; scanf("%d", &y);
            add(i, y);
            ans += getRectSum(i, n) - getRectSum(i, y);
        }
        while(q--) {
            int y; scanf("%d", &y);
            printf("%lld\n", ans);
            if(ans && q)
                ans -= getRectSum(n, y) + getRectSum(X[y], n) - 2 * getRectSum(X[y], y);
            del(X[y], y);
        }
    }
    return 0;
}
