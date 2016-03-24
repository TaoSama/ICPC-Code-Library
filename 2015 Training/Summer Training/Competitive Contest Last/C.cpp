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
        multiset<int>::iterator iter;
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

                iter = s.lower_bound(cur);
                if(iter == s.end()) x = *(--iter);
                else if(iter == s.begin()) x = *iter;
                else {
                    int r = *iter, l = *(--iter);
                    if(cur - l > r - cur) x = r;
                    else if(cur - l < r - cur) x = l;
                    else x = dir ? r : l;
                }

                if(x > cur) dir = 1;
                else if(x < cur) dir = 0;

                ans += abs(x - cur);
                cur = x;
                s.erase(s.find(x));
            }
        }
        printf("Case %d: %I64d\n", ++kase, ans);
    }
    return 0;
}
