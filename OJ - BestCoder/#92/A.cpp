//
//  Created by TaoSama on 2017-02-26
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
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        map<string, pair<int, int> > mp;
        for(int i = 1; i <= n; ++i) {
            char s[50]; int v; scanf("%s%d", s, &v);
            if(!mp.count(s)) mp[s].first = v, mp[s].second = 0;
            else {
                mp[s].second = max(mp[s].second, v);
                if(mp[s].first < mp[s].second) swap(mp[s].first, mp[s].second);
            }
        }
        int ans = 0;
        for(auto& p : mp) ans += p.second.first + p.second.second;
        printf("%d\n", ans);
    }

    return 0;
}
