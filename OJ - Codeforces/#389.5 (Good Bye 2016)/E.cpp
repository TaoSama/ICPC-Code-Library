//
//  Created by TaoSama on 2016-12-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
char s[N];
struct Node {
    int m[5][5];
    void see() {
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 5; ++j) {
                printf("%d%c", m[i][j], " \n"[j + 1 == 5]);
            }
        }
    }
} dat[N << 1];

inline int id(int l, int r) {return l + r | l != r;}

Node operator+(const Node& A, const Node& B) {
    Node ret;
    memset(ret.m, 0x3f, sizeof ret.m);
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            for(int k = 0; k < 5; ++k)
                ret.m[i][j] = min(ret.m[i][j], A.m[i][k] + B.m[k][j]);
    return ret;
}

void build(int l, int r) {
    if(l == r) {
        int rt = id(l, r);
        memset(dat[rt].m, 0x3f, sizeof dat[rt].m);
        auto& m = dat[rt].m;
        for(int i = 0; i < 5; ++i) m[i][i] = 0;
        if(s[l] == '2') m[0][1] = 0, m[0][0] = 1;
        if(s[l] == '0') m[1][2] = 0, m[1][1] = 1;
        if(s[l] == '1') m[2][3] = 0, m[2][2] = 1;
        if(s[l] == '6') m[3][3] = 1, m[4][4] = 1;
        if(s[l] == '7') m[3][4] = 0, m[3][3] = 1;
        return;
    }
    int m = l + r >> 1;
    build(l, m);
    build(m + 1, r);
    dat[id(l, r)] = dat[id(l, m)] + dat[id(m + 1, r)];
}

Node query(int L, int R, int l, int r) {
    if(L <= l && r <= R) return dat[id(l, r)];
    int m = l + r >> 1;
    if(R <= m) return query(L, R, l, m);
    else if(L > m) return query(L, R, m + 1, r);
    else return query(L, R, l, m) + query(L, R, m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s", &n, &q, s + 1) == 3) {
        build(1, n);
//        dat[id(1, 1)].see();
//        dat[id(2, 2)].see();
//        dat[id(1, 2)].see();
//        dat[id(3, 4)].see();
//        prln((dat[id(1, 2)] + dat[id(3, 4)]).m[0][3]);
//        prln((dat[id(1, 2)] + dat[id(3, 4)]).m[0][4]);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            int ans = query(l, r, 1, n).m[0][4];
            if(ans == INF) ans = -1;
            printf("%d\n", ans);
        }
    }

    return 0;
}
