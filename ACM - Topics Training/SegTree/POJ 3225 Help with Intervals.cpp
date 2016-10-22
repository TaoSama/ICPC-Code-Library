//
//  Created by TaoSama on 2015-09-18
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
const int N = 65535 * 2 + 5, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int cov[N << 2], Xor[N << 2];

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void fxor(int rt) {
    if(~cov[rt]) cov[rt] ^= 1;
    else Xor[rt] ^= 1;
}

void push_down(int rt) {
    if(~cov[rt]) {
        Xor[rt << 1] = Xor[rt << 1 | 1] = 0;
        cov[rt << 1] = cov[rt << 1 | 1] = cov[rt];
        cov[rt] = -1;
    }
    if(Xor[rt]) {
        fxor(rt << 1);
        fxor(rt << 1 | 1);
        Xor[rt] = 0;
    }
}

//T-> [l, r]  all about segments
//U: S¡ÈT => [l,r]->1
//I: S¡ÉT => (-¡Þ,l)¡È(r,+¡Þ)->0
//S: S¨’T => [l,r] 1/0 reverse
//D: S-T => [l,r]->0
//C: T-S => (-¡Þ,l)¡È(r,+¡Þ)->0, [l,r] 1/0 reverse

void update(int L, int R, char op, int l, int r, int rt) {
    if(L <= l && r <= R) {
        if(op == 'U') {
            cov[rt] = 1;
            Xor[rt] = 0;
        }
        if(op == 'D') {
            cov[rt] = 0;
            Xor[rt] = 0;
        }
        if(op == 'S' || op == 'C') fxor(rt);
        return;
    }
    int m = l + r >> 1;
    push_down(rt);
    if(L <= m) update(L, R, op, lson);
    else if(op == 'I' || op == 'C') cov[rt << 1] = Xor[rt << 1] = 0;
    if(R > m) update(L, R, op, rson);
    else if(op == 'I' || op == 'C') cov[rt << 1 | 1] = Xor[rt << 1 | 1] = 0;
}

bool vis[N];
void query(int l, int r, int rt) {
    if(cov[rt] == 1) {
        fill(vis + l, vis + r + 1, 1);
        return;
    }
    if(cov[rt] == 0 || l == r) return;
    int m = l + r >> 1;
    push_down(rt);
    query(lson);
    query(rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cov[1] = Xor[1] = 0;
    char op, a, b; int l, r;
    while(~scanf("%c %c%d,%d%c ", &op, &a, &l, &r, &b)) {
        l <<= 1; r <<= 1;
        if(a == '(') ++l;
        if(b == ')') --r;
        if(l > r) {
            if(op == 'C' || op == 'I')
                cov[1] = Xor[1] = 0;
            continue;
        }
        update(l, r, op, 0, N, 1);
    }

    memset(vis, false, sizeof vis);
    query(0, N, 1);
    bool ok = false;
    int s = -1, e;
    for(int i = 0; i < N; ++i) {
        if(vis[i]) {
            if(s == -1) s = i;
            e = i;
        } else {
            if(s == -1) continue;
            if(ok) putchar(' ');
            ok = true;
            printf("%c%d,%d%c", "[("[s & 1], s >> 1, e + 1 >> 1, "])"[e & 1]);
            s = -1;
        }
    }
    if(!ok) printf("empty set");
    puts("");
    return 0;
}
