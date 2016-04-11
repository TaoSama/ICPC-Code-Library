//
//  Created by TaoSama on 2016-01-31
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        LL s1 = 0, s2 = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), s1 += a[i];
        for(int i = 1; i <= n; ++i) scanf("%d", b + i), s2 += b[i];

        bool flipped = false;
        if(s1 > s2) swap(a, b), flipped = true;

        vector<pair<int, int> > pos(n);
        for(auto &x : pos) x = { -1, -1};
        pos[0] = {1, 1};

        vector<int> ans1, ans2;
        LL xs = 0, ys = 0;
        for(int i = 1, j = 1; i <= n;) {
            xs += a[i++];
            while(j <= n && ys + b[j] <= xs) ys += b[j++];
            int dif = xs - ys;
            if(~pos[dif].first) {
                for(int k = pos[dif].first; k < i; ++k) ans1.push_back(k);
                for(int k = pos[dif].second; k < j; ++k) ans2.push_back(k);
                break;
            }
            pos[dif] = {i, j};
        }

        if(flipped) swap(ans1, ans2);
        printf("%d\n", ans1.size());
        for(int i = 0; i < ans1.size(); ++i)
            printf("%d%c", ans1[i], " \n"[i == ans1.size() - 1]);
        printf("%d\n", ans2.size());
        for(int i = 0; i < ans2.size(); ++i)
            printf("%d%c", ans2[i], " \n"[i == ans2.size() - 1]);
    }
    return 0;
}
