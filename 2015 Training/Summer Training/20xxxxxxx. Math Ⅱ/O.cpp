//
//  Created by TaoSama on 2015-08-15
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

vector<long long> prime, otz;
void gao() {
    bool vis[N] = {};
    for(int i = 2; i < N; ++i) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j = i + i; j < N; j += i) vis[j] = 1;
    }

    for(auto &p : prime) {
        for(long long j = p * p; j <= 1e12; j *= p)
            otz.push_back(j);
    }
    sort(otz.begin(), otz.end());
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
//  cout << prime.size() << endl;
    while(t--) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        l = lower_bound(otz.begin(), otz.end(), l) - otz.begin();
        r = upper_bound(otz.begin(), otz.end(), r) - otz.begin();
//        cout << otz[l] << ' ' << otz[r] << endl;
        printf("%lld\n", r - l);
    }
    return 0;
}
