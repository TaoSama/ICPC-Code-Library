//
//  Created by TaoSama on 2017-04-08
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int main() {
#ifdef LOCAL
    freopen("C-small-2-attempt0.in", "r", stdin);
    freopen("C-small-2-attempt0.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d%d", &n, &k);

        set<pair<int, int>> s; s.insert({ -n, 1});
        int ls, rs;
        for(int i = 1; i <= k; ++i) {
            int len, l; tie(len, l) = *s.begin(); len *= -1;
            s.erase(s.begin());
            int choice = l + (len - 1) / 2;
            ls = choice - l;
            rs = l + len - 1 - choice;
            s.insert({ -ls, l});
            s.insert({ -rs, choice + 1});
        }

        static int kase = 0;
        printf("Case #%d: %d %d\n", ++kase, max(ls, rs), min(ls, rs));
    }

    return 0;
}
