//
//  Created by TaoSama on 2016-03-31
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        set<int> s;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            s.insert(x);
        }

        vector<int> ans;
        for(int i = 1; ; ++i) {
            if(s.count(i)) continue;
            if(m >= i) {
                m -= i;
                ans.push_back(i);
            } else break;
        }
        printf("%d\n", ans.size());
        for(int x : ans) printf("%d ", x); puts("");
    }
    return 0;
}
