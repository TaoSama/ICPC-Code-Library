//
//  Created by TaoSama on 2016-05-05
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
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int s[N], c[N], t[2][N];
int sa[N], rk[N], height[N];
void buildsa(int n , int m) {
    int i , k , p , a1 , a2 , *x = t[0] , *y = t[1];
    memset(c , 0 , m << 2);
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 , p = 0; k < n ; k <<= 1 , p = 0) {
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        memset(c , 0 , m << 2);
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i) {
            a1 = sa[i - 1] + k < n ? y[sa[i - 1] + k] : -1;
            a2 = sa[i] + k < n ? y[sa[i] + k] : -1;
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && a1 == a2) ? p - 1 : p ++;
        }
        if (p >= n) break; m = p;
    }
    for (i = 0 ; i < n ; ++ i) rk[sa[i]] = i;
    for (i = 0 , k = 0; i < n ; ++ i) {
        if (k) -- k; if (!rk[i]) continue;
        int j = sa[rk[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[rk[i]] = k;
    }
}
void see(int n){
//    for(int i = 0; i < n; ++i) printf("%d: %s\n", i, str + sa[i]);
    printf("sa: "); for(int i = 0; i < n; ++i) printf("%d ", sa[i]); puts("");
    printf("rk: "); for(int i = 0; i < n; ++i) printf("%d ", rk[i]); puts("");
    printf("ht: "); for(int i = 0; i < n; ++i) printf("%d ", height[i]); puts("");
}

int n;
bool check(int x) {
    int minv, maxv; minv = maxv = sa[1];
    for(int i = 2; i < n; ++i) {
        if(height[i] >= x) {
            maxv = max(maxv, sa[i]);
            minv = min(minv, sa[i]);
            if(maxv - minv > x) return true;
        } else maxv = minv = sa[i];
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        int last = 0;
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            if(i) s[i - 1] = last - x + 100;
            last = x;
        }
        buildsa(n - 1, 200);
		see(n - 1);

//        int l = 4, r = n / 2;
//        while(l <= r) {
//            int m = l + r >> 1;
//            if(check(m)) l = m + 1;
//            else r = m - 1;
//        }
//        if(l < 5) l = 0;
//        printf("%d\n", l);
    }
    return 0;
}
