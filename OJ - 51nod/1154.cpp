//
//  Created by TaoSama on 2016-08-26
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
const int N = 5000 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// 原串 a[i]:         w   a   a   b   w   s   w   f   d
// 新串 s[i]:       # w # a # a # b # w # s # w # f # d #
// 辅助数组 p[i]:   1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1
// p[i]   := 新串以 s[i] 为中心向右延伸的回文距离 + 1 （自己）
// p[i]-1 := 原串以 s[i] 为中心的回文长度

struct Manacher {
    static const int M = N << 1;
    char s[M];
    int n, p[M];

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

    bool ok(int l, int r) {
        l <<= 1; r <<= 1;
        int k = l + r >> 1;
        return k + p[k] - 1 >= r;
    }
} ma;

int f[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%s", s + 1);
    int n = strlen(s + 1);

    ma.init(s);
    ma.gao();

    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < i; ++j)
            if(ma.ok(j + 1, i)) f[i] = min(f[i], f[j] + 1);
    printf("%d\n", f[n]);

    return 0;
}
