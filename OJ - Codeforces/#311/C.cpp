//
//  Created by TaoSama on 2015-06-30
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

int n, d[205], l[N], sum[N];
pair<int, int> a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(d, 0, sizeof d);
        memset(l, 0, sizeof l);
        for(int i = 1; i <= n << 1; ++i) {
            if(i <= n) {
                cin >> a[i].first;
                l[a[i].first]++;
            } else {
                cin >> a[i - n].second;
            }
        }
        sort(a + 1, a + 1 + n);

        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i].second;

//      for(int i = 1; i <= n; ++i){
//          pr(a[i].first); pr(a[i].second); prln(sum[n] - sum[i]);
//      }

        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            int t = i + l[a[i].first];
            int cur = sum[n] - sum[t - 1];

            for(int j = 1, k = i - l[a[i].first]; j <= 200 && k > 0; ++j) {
                if(k >= d[j]) cur += j * d[j], k -= d[j];
                else cur += j * k, k = 0;
            }
//            prln(cur);
//            for(int j = 1; j <= 200; ++j){
//              if(d[j]) pr(j), prln(d[j]);
//          }
//          cout << endl;
            ans = min(ans, cur);
            for(int j = i; j < t; ++j) d[a[j].second]++;
            i = t - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
2
1 5
3 2
3
2 4 4
1 1 1
6
2 2 1 1 3 3
4 3 5 5 2 1
*/
