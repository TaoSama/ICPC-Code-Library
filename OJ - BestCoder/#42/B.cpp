//
//  Created by TaoSama on 2015-05-23
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

int n, m;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        multimap<int, int> mp;
        multimap<int, int>:: iterator it;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            mp.insert(make_pair(x, i));
        }
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            it = mp.find(x);
            if(it == mp.end()) printf("-1\n");
            else {
                printf("%d\n", it->second);
                mp.erase(it);
            }
        }
    }
    return 0;
}
