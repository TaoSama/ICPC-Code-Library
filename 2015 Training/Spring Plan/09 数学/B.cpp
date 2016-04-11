//
//  Created by TaoSama on 2015-09-24
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int euler(int n) {
    int ret = n, t = n;
    for(int i = 2; i * i <= n; i++) {
        if(t % i == 0) {
            ret = ret / i * (i - 1);
            while(t % i == 0) t /= i;
        }
    }
    if(t > 1) ret = ret / t * (t - 1);
    return ret;
}

int exgcd(int a, int b, int &x, int& y) {
    int d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

int inv(int a, int m) {
    int x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int op;
    while(scanf("%d", &op) == 1) {
        int ans;
        if(op == 1) {
            int n; scanf("%d", &n);
            for(int i = 1; i <= n; ++i) {
                int x; scanf("%d", &x);
                if(i == 1) ans = x;
                else ans = __gcd(ans, x);
            }
        } else if(op == 2) {
            int x, m; scanf("%d%d", &x, &m);
            ans = inv(x, m);
        } else {
            int x; scanf("%d", &x);
            ans = euler(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
