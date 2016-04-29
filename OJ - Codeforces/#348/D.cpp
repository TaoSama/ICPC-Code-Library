//
//  Created by TaoSama on 2016-04-25
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        int a = 0, b = 1;
        while(q--) {
            int op, x; scanf("%d", &op);
            if(op == 1) {
                scanf("%d", &x);
                a = (a + x) % n;
                b = (b + x) % n;
            } else {
                if(~a & 1) a = (a + 1) % n; //ÆæÊý
                else a = (a - 1) % n;
                if(~b & 1) b = (b + 1) % n;
                else b = (b - 1) % n;
            }
        }
        a = ((a - 0) % n + n) % n;
        b = ((b - 1) % n + n) % n;

        vector<int> ans(n);
        for(int i = 0; i < n; ++i)
            if(~i & 1) ans[(i + a) % n] = i;
            else ans[(i + b) % n] = i;
        for(int x : ans) printf("%d ", x + 1); puts("");
    }
    return 0;
}