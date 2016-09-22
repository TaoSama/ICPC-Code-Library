//
//
//  Created by TaoSama on 2016-08-26
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
LL n, k;
LL a[N], sg[N];

map<LL, int> mp;

int getSg(int x) {
    if(x == 1) return 0;
    if(mp.count(x)) return mp[x];
    bool mark[200] = {};
    int cnt = 0;
    for(int i = (x + k - 1) / k; i < x; ++i) {
        mark[getSg(i)] = 1;
    }
    for(int i = 0; ; ++i) if(!mark[i]) return mp[x] = i;
    return -1;
}

LL mySg(LL x) {
    if(x == 1) return 0;

    if(x % k == 1) return mySg(x / k);
    return (x + k - 1) / k * (k - 1) - (k - x % k) % k;
}

LL sgToV(LL sg) {
    if(sg == 0) return 1;
    LL t = k - 1;
    return (sg + t - 1) / t * k - (t - sg % t) % t;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    k = 2; mp.clear();
//    for(int i = 1; i <= 200; ++i) {
//        printf("%4d", getSg(i));
//        if(i % 10 == 0) puts("");
//    }
//    puts("");
//
//    {
//        int f[105];
//        for(int i = 1; i <= 200; ++i) {
//            printf("%4d", mySg(i));
//            if(i % 10 == 0) puts("");
//        }
//        puts("");
//    }
//
//    for(int i = 1; i <= 100; ++i) {
//        printf("%4d", sgToV(i));
//        if(i % 10 == 0) puts("");
//    }

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sg[i] = mySg(a[i]);
    }

    LL sum = 0;
    for(int i = 1; i <= n; ++i) sum ^= sg[i];
    if(!sum) {cout << "Bob\n"; return 0;}

    cout << "Alice";
    bool ok = false;
    for(int i = 1; i <= n && !ok; ++i) {
        LL newSg = sum ^ sg[i];
        LL v = sgToV(newSg);
//        pr(newSg); prln(v);
        while(v < a[i] && !ok) {
            if(v >= (a[i] + k - 1) / k) {
                ok = true;
                cout << ' ' << i << ' ' << v << endl;
            }
            if(1.0L * v * k > 2e18) break;
            v = v * k + 1;
        }
    }

    return 0;
}
