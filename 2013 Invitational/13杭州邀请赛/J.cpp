//
//  Created by TaoSama on 2015-05-14
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
typedef pair<int, int> P;
set<P>::iterator iter, iter2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        set<P> s;
        s.insert(P(1e9, 1));
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);

            iter = s.lower_bound(P(y, 0));
            int ans;
            if(iter != s.begin()) {
                iter2 = iter--;
                if(abs(y - iter2->first) < abs(y - iter->first)) {
                    ans = iter2->second;
                } else ans = iter->second;
            } else ans = iter->second;
            s.insert(P(y, x));
            printf("%d %d\n", x, ans);
        }
    }
    return 0;
}
