//
//  Created by TaoSama on 2015-12-26
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

typedef pair<int, int> P;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        vector<P> xs;
        for(int i = 1; i <= n; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            xs.push_back(P(l, -1));
            xs.push_back(P(r, 1));
        }
        sort(xs.begin(), xs.end());

        int cnt = 0, l;
        vector<P> ans;
        for(auto &x : xs) {
            cnt -= x.second;
//            printf("%d %d cnt:%d\n", x.first, x.second, cnt);
            if(cnt == k && x.second == -1)
                l = x.first;
            else if(cnt == k - 1 && x.second == 1)
                ans.push_back(P(l, x.first));
        }

        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first, x.second);
    }
    return 0;
}
