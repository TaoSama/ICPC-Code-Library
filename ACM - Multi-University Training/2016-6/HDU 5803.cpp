//
//  Created by TaoSama on 2016-08-08
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[4];
int f[61][1 << 4][5][5]; //[-2, 2]

inline void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

//a+c-b-d>0 a+d-b-c>=0
const int O = 2; //offset
int dfs(int x, int msk, int f1, int f2) {
    if(x == -1) return f1 > 0 && f2 >= 0;
    int& ret = f[x][msk][f1 + O][f2 + O];
    if(~ret) return ret;

    ret = 0;
    int to[4];
    for(int i = 0; i < 4; ++i) to[i] = (msk >> i & 1) ? 1 : a[i] >> x & 1;
    for(int a = 0; a <= to[0]; ++a) {
        for(int b = 0; b <= to[1]; ++b) {
            for(int c = 0; c <= to[2]; ++c) {
                for(int d = 0; d <= to[3]; ++d) {
                    int newF1 = f1 * 2 + a + c - b - d;
                    int newF2 = f2 * 2 + a + d - b - c;
                    if(newF1 < -2 || newF2 < -2) continue;
                    newF1 = min(newF1, 2);
                    newF2 = min(newF2, 2);

                    int newMsk = msk;
                    if(a != to[0]) newMsk |= 1 << 0;
                    if(b != to[1]) newMsk |= 1 << 1;
                    if(c != to[2]) newMsk |= 1 << 2;
                    if(d != to[3]) newMsk |= 1 << 3;

                    add(ret, dfs(x - 1, newMsk, newF1, newF2));
                }
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 4; ++i) scanf("%I64d", a + i);
        memset(f, -1, sizeof f);
        printf("%d\n", dfs(60, 0, 0, 0));
    }

    return 0;
}
