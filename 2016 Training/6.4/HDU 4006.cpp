//
//  Created by TaoSama on 2016-06-04
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Heap {
    int n, dat[N];
    void down(int rt) {
        int ls = rt << 1, rs = ls | 1;
        int idx = rt;
        if(ls <= n && dat[ls] < dat[idx]) idx = ls;
        if(rs <= n && dat[rs] < dat[idx]) idx = rs;
        if(idx != rt) {
            swap(dat[rt], dat[idx]);
            down(idx);
        }
    }
    void up(int rt) {
        int fa = rt >> 1;
        if(fa >= 1 && dat[rt] < dat[fa]) {
            swap(dat[rt], dat[fa]);
            up(fa);
        }
    }
    void build() {n = 0;}
    void build(int* a, int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) dat[i] = a[i];
        for(int i = n >> 1; i; --i) down(i);
    }
    void push(int x) {
        dat[++n] = x;
        up(n);
    }
    void pop() {
        dat[1] = dat[n--];
        down(1);
    }
    int size() { return n; }
    int top() { return dat[1]; }
    int find(int x) {
        return ::find(dat + 1, dat + 1 + n, x) - dat;
    }
} heap;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &k) == 2) {
        heap.build();
        for(int i = 1; i <= n; ++i) {
            char op[2]; int x;
            scanf("%s", op);
            if(*op == 'I') {
                scanf("%d", &x);
                heap.push(x);
                if(heap.size() > k) heap.pop();
            } else printf("%d\n", heap.top());
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

