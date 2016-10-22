//
//  Created by TaoSama on 2015-09-30
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

typedef pair<int, int> P;

int n, m;
P our[N], enemy[N];
//our: atk first   enemy: def first

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d%d", &our[i].first, &our[i].second);
        for(int i = 1; i <= m; ++i) scanf("%d%d", &enemy[i].second, &enemy[i].first);
        printf("Case #%d: ", ++kase);
        if(n < m) {puts("-1"); continue;}

        multiset<int> s; //maintain our defense
        sort(our + 1, our + 1 + n, greater<P>());
        sort(enemy + 1, enemy + 1 + m, greater<P>());
        int ans = n;
        for(int i = 1, j = 1; i <= m; ++i) {
            int def = enemy[i].first, atk = enemy[i].second;
            while(j <= n && our[j].first >= def) s.insert(our[j++].second);
            if(s.size() == 0) {
                ans = -1;
                break;
            }
            auto iter = s.upper_bound(atk);
            if(iter == s.end()) {
                iter = s.begin(); //find a scapegoat
                --ans;
            }
            s.erase(iter);
        }
        printf("%d\n", ans);
    }
    return 0;
}
