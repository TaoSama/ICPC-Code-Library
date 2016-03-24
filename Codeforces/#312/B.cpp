//
//  Created by TaoSama on 2015-07-14
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

int n, a[N], cnt[N * 10];
pair<int, int> p[N * 10];
bool yes[N * 10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(cnt, 0, sizeof cnt);
        memset(yes, false, sizeof yes);
        int l, r, Max = 0;
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
            Max = max(Max, cnt[a[i]]);
            if(!yes[a[i]]) {
                yes[a[i]] = true;
                p[a[i]].first = p[a[i]].second = i;
            } else p[a[i]].second = i;
        }

//      prln(Max);
        for(int i = 1; i <= 1e6; ++i) {
            if(cnt[i] == Max) v.push_back(i);
        }

        int dif = INF;
        for(int i = 0; i < v.size(); ++i) {
//          prln(v[i]);
            if(p[v[i]].second - p[v[i]].first < dif) {
                l = p[v[i]].first;
                r = p[v[i]].second;
                dif = p[v[i]].second - p[v[i]].first;
            }
        }
        cout << l << ' ' << r << '\n';
    }
    return 0;
}
