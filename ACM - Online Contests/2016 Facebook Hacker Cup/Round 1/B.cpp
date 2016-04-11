//
//  Created by TaoSama on 2016-01-17
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;
LL l, n, m, d;
struct Node {
    LL t, x;
    Node() {}
    Node(LL t, LL x): t(t), x(x) {}
    bool operator<(const Node& rhs) const {
        return t + x < rhs.t + rhs.x;
    }
};

int main() {
    freopen("laundro_matt.txt", "r", stdin);
    freopen("laundro_matt_out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d%I64d%I64d%I64d", &l, &n, &m, &d);
        multiset<Node> washer, dryer;
        for(int i = 1; i <= n; ++i) {
            LL x; scanf("%I64d", &x);
            washer.insert(Node(0, x));
        }
        m = min(l, m);
        for(int i = 1; i <= m; ++i) dryer.insert(Node(0, d));
        for(int i = 1; i <= l; ++i) {
            Node toWash = *washer.begin();
            washer.erase(washer.begin());
            toWash.t += toWash.x;
            washer.insert(toWash);

            Node toDry = *dryer.begin();
            dryer.erase(dryer.begin());
            toDry.t = max(toDry.t, toWash.t) + toDry.x;
            dryer.insert(toDry);

//          printf("wash: %I64d dry: %I64d\n", toWash.t, toDry.t);
        }
        LL ans = -INF;
        for(auto &p : washer) ans = max(ans, p.t);
        for(auto &p : dryer) ans = max(ans, p.t);

        static int kase = 0;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
