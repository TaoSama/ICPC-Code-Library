//
//  Created by TaoSama on 2017-04-01
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char a[N], r[N];
int cnt[3];

bool go(int mod, int need) {
    for(int a = 0; a < 3; ++a) { //1
        if(a > cnt[1]) continue;
        for(int b = 0; b < 3; ++b) { //2
            if(b > cnt[2]) continue;
            for(int c = 0; c < 3; ++c) { //0
                if(c > cnt[0]) continue;
                if((a + 2 * b) % 3 != mod) continue;
                if(a + b + c > need) continue;
                if((need - a - b - c) % 3 != 0) continue;
                int t = (cnt[1] - a) / 3 + (cnt[2] - b) / 3 + (cnt[0] - c) / 3;
                if(3 * t + a + b + c >= need) return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%s", &n, &m, a + 1);
        int sum = 0;
        for(int i = 0; i < 3; ++i) cnt[i] = 0;
        for(int i = 1; i <= n; ++i) {
            a[i] -= '0';
            r[i] = a[i] % 3;
            ++cnt[r[i]];
            sum += r[i];
        }

        bool ok = false;
        if(m == n - 1)
            for(int i = 1; i <= n && !ok; ++i) ok |= a[i] == 0;

        int need = m;
        for(int i = 1; i <= n && !ok; ++i) {
            int x = a[i];
            if(x) {
                --cnt[r[i]];
                ok |= go(sum % 3, need);
            } else --cnt[r[i]];
            sum -= r[i];
            if(--need < 0) break;
        }
        puts(ok ? "yes" : "no");
    }

    return 0;
}
