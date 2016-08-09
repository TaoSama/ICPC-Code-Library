//
//  Created by TaoSama on 2016-08-03
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

// 原串 a[i]:         w   a   a   b   w   s   w   f   d
// 新串 s[i]:       # w # a # a # b # w # s # w # f # d #
// 辅助数组 p[i]:   1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1
// p[i]   := 新串以 s[i] 为中心向右延伸的回文距离 + 1 （自己）
// p[i]-1 := 原串以 s[i] 为中心的回文长度

int n;
char s[N];

struct Manacher {
    static const int M = N << 1;
    char s[M];
    int n, p[M];
    int delta[2][M], sum[2][M];

    void init(char* a) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for(int i = 1; a[i]; ++i)
            s[n++] = a[i], s[n++] = '#';
        s[n] = 0;
    }

    int gao() {
        int mx = 0, id, ret = 0;
        for(int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) ++p[i];
            if(mx < i + p[i]) mx = i + p[i], id = i;
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }

    inline void add(int& x, int y) {
        if(y < 0) y += MOD;
        if((x += y) >= MOD) x -= MOD;
    }
    //0->start 1->end
    void process() {
        memset(delta, 0, sizeof delta);
        memset(sum, 0, sizeof sum);
        for(int i = 1; i < n; ++i) {
            int r = i + p[i] - 1, l = i - (p[i] - 1);
            add(sum[0][l], r);
            add(sum[0][i + 1], -r - (i - l) * (-1)); //+ r ~ i
            add(delta[0][l + 1], -1);
            add(delta[0][i + 1], 1); //d + -1

            add(sum[1][i], i);
            add(sum[1][r + 1], -i - (r - i) * (-1)); //+ i ~ l
            add(delta[1][i + 1], -1);
            add(delta[1][r + 1], 1); //d + -1
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 2; ++j) {
                add(delta[j][i], delta[j][i - 1]);
                add(sum[j][i], sum[j][i - 1]);
                add(sum[j][i], delta[j][i]);
            }
        }
    }

    bool ok(int l, int r) {
        l <<= 1; r <<= 1;
        int k = l + r >> 1;
        return k + p[k] - 1 >= r;
    }
} ma;

int quick(int x, int n) {
    int ret = 1;
    for(; n ; n >>= 1) {
        if(n & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
    }
    return ret;
}

const int invTwo = 500000004;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        ma.init(s);
        ma.gao();
        ma.process();
        n = strlen(s + 1);

        int* preSum = ma.sum[0], *sufSum = ma.sum[1];

        int ans = 0;
        for(int i = 1; i < n; ++i) {
            sufSum[i << 1] = 1LL * sufSum[i << 1] * invTwo % MOD;
            preSum[i + 1 << 1] = 1LL * preSum[i + 1 << 1] * invTwo % MOD;
            ans += 1LL * sufSum[i << 1] * preSum[i + 1 << 1] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}
