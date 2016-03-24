//
//  Created by TaoSama on 2016-03-21
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

int n;
typedef long long LL;
const int S = 1594323; //3^13
LL f[2][S][2];
// S: 0->偶数个1(不全是) 1->奇数个1(不全是) 2->全是1
// 0/1: 选取了偶/奇数个数

int sta[13];
inline void decode(int s, int n) {
    for(int i = 0; i < n; ++i) {
        sta[i] = s % 3;
        s /= 3;
    }
}

inline int encode(int n) {
    int code = 0;
    for(int i = n - 1; ~i; --i) code = code * 3 + sta[i];
    return code;
}

const int HS = 2187; //3^7
int trans[HS][1 << 7][2];
int sHigh[S], sLow[S];
int th[13] = {1};

void gao() {
    for(int i = 1; i < 13; ++i) th[i] = th[i - 1] * 3;
    for(int j = 0; j < S; ++j) sHigh[j] = j / HS, sLow[j] = j % HS;

    for(int i = 0; i < HS; ++i) {
        for(int j = 0; j < 1 << 7; ++j) {
            for(int p = 0; p < 2; ++p) {
                int newS = i;
                for(int k = 0; k < 7; ++k) {
                    int b = i / th[k] % 3;
                    if(j >> k & 1) { //1
                        if(b != 2) {
                            //sta[k] ^= 1; //奇偶互换
                            newS += (b ? -1 : 1) * th[k];
                        }
                    } else { //0
                        if(b == 2) {
                            //sta[k] = p; //不全是1了
                            newS += (p - 2) * th[k];
                        }
                    }
                }
                //trans[i][j][p] = encode(7);
                trans[i][j][p] = newS;
            }
        }
    }
}

inline bool check(int s, int p) {
    decode(s, 13);
    //偶数个1(不全是) 同为0, 奇数个1(全是) 同为1
    //非法的同理
    for(int i = 0; i < 13; ++i)
        if(sta[i] == 1 || !p && sta[i] == 2) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    scanf("%d", &n);

    int p = 0;
    f[p][S - 1][0] = 1;
    for(int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        int xHigh = x / (1 << 7), xLow = x % (1 << 7);
        memset(f[!p], 0, sizeof f[!p]);
        for(int j = 0; j < S; ++j) {
            for(int k = 0; k < 2; ++k) {
                if(!f[p][j][k]) continue;
                int newHigh = trans[sHigh[j]][xHigh][k];
                int newLow = trans[sLow[j]][xLow][k];
                int newS = newHigh * HS + newLow;
                f[!p][newS][k ^ 1] += f[p][j][k]; //选

//                pr(i); pr(j); pr(k); prln(x);
//                pr(sLow); pr(xLow); pr(sHigh); prln(xHigh);
//                pr(newHigh); pr(newLow); prln(newS);
//                decode(j, 13);
//                for(int k = 0; k < 13; ++k) printf("%d ", sta[k]); puts("");
//                decode(newS, 13);
//                for(int k = 0; k < 13; ++k) printf("%d ", sta[k]); puts("");
//                if(i == n) printf("f[%d][%d]=%I64d\n", newS, k ^ 1, f[i][newS][k ^ 1]);

                f[!p][j][k] += f[p][j][k]; //不选
            }
        }
        p = !p;
    }

    LL ans = 0;
    for(int i = 0; i < S; ++i)
        for(int j = 0; j < 2; ++j)
            if(f[p][i][j] && check(i, j)) ans += f[p][i][j];
    printf("%lld\n", ans);
    return 0;
}
