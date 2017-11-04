//
//  Created by TaoSama on 2017-03-21
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int cnt[14] = {};
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }

        int ans = 0;
        for(int s = 1; s < 1 << 14; ++s) {
            int num = 1, sum = 0;
            for(int i = 0; i < 14; ++i) {
                if(s >> i & 1) {
                    num *= (1 << cnt[i]) - 1;
                    sum += i;
                }
            }
            ans += num * sum;
        }
        printf("%d\n", ans);
    }

    return 0;
}