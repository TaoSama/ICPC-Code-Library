//
//  Created by TaoSama on 2015-09-22
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];
int deq[N];

inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

void out(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) out(x / 10);
    putchar(x % 10 + '0');
}

void getMax() {
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++i) {
        while(l < r && a[deq[r - 1]] <= a[i]) --r;
        deq[r++] = i;
        if(i >= k) {
            out(a[deq[l]]);
            putchar(" \n"[i == n]);
            if(deq[l] == i - k + 1) ++l;
        }
    }
}

void getMin() {
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++i) {
        while(l < r && a[deq[r - 1]] >= a[i]) --r;
        deq[r++] = i;
        if(i >= k) {
            out(a[deq[l]]);
            putchar(" \n"[i == n]);
            if(deq[l] == i - k + 1) ++l;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) a[i] = read();
        getMin();
        getMax();
    }
    return 0;
}
