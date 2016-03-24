//
//  Created by TaoSama on 2015-09-12
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

int n, q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &q);
        multiset<int> s;
        multiset<int>::iterator lef, rig;
        int cur = 0, dir = 1;
        long long ans = 0;
        while(q--) {
//          printf("q: %d\n", q);
            int op, x; scanf("%d", &op);
            if(op == 0) {
                scanf("%d", &x);
                s.insert(x);
            } else {
                if(s.size() == 0) continue;
                rig = s.lower_bound(cur);
                lef = rig;
                int pre = -INF, nxt = INF;
                if(rig != s.end()) nxt = *rig;
                if(lef != s.begin()) pre = *(--lef);
                int dif1 = cur - pre, dif2 = nxt - cur;

//              printf("%d %d %d dir: %d\n", pre, cur, nxt, dir);
                ans += min(dif1, dif2);

                if(dif1 < dif2) {
                    if(cur != pre) {
                        dir = 0;
                        cur = pre;
                    }
                    s.erase(lef);
                } else if(dif1 > dif2) {
                    if(cur != nxt) {
                        dir = 1;
                        cur = nxt;
                    }
                    s.erase(rig);
                } else {
                    if(dir) cur = nxt, s.erase(rig);
                    else cur = pre, s.erase(lef);
                }
            }
        }
        printf("Case %d: %I64d\n", ++kase, ans);
    }
    return 0;
}
