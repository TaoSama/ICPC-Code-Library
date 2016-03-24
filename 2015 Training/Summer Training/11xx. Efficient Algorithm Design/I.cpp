//
//  Created by TaoSama on 2015-07-31
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
#include <ctime>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long n, k, a[505];
bool vis[505];

bool check(long long x) {
    int cnt = 1;
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(sum + a[i] <= x) sum += a[i];
        else {
            cnt ++ ;
            sum = a[i];
        }
    }
    return cnt <= k;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        long long sum = 0, maxv = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            maxv = max(maxv, a[i]);
        }

        long long l = maxv, r = sum + 1;
        while(l < r) {
            long long m = l + r >> 1;
            if(check(m)) r = m;
            else l = m + 1;
        }

        sum = 0;
        memset(vis, false, sizeof vis);
        int left = k;
        for(int i = n; i; --i) {
            if(sum + a[i] > l || i < left) {
//              cout << i << ' ' << left << endl;
                vis[i] = true;
                --left;
                sum = a[i];
            } else sum += a[i];
        }
        for(int i = 1; i <= n; ++i) {
            cout << a[i] << (i == n ? '\n' : ' ');
            if(i != n && vis[i]) cout << "/ ";
        }
    }
    return 0;
}
