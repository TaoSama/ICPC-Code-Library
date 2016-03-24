//
//  Created by TaoSama on 2015-06-27
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

int n, k;
vector<int> a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        long long Max = 1, idx, ans = 0;
        for(int i = 1; i <= k; ++i) {
            int m; cin >> m;
            a[i].clear();
            for(int j = 1; j <= m; ++j) {
                int x; cin >> x;
                a[i].push_back(x);
            }
        }
        for(int i = 1; i <= k; ++i) {
            int cnt = 1;
            if(a[i][0] == 1) {
                idx = i;
                for(int j = 1; j < a[i].size(); ++j) {
                    if(a[i][j] - a[i][j - 1] == 1) ++Max;
                    else break;
                }
            }
            ans += a[i].size() - 1;
        }
        long long sum = n - Max + 1;
        ans = ans - (a[idx].size() - 1) + (a[idx].size() - Max) + sum - 1;
        cout << ans << endl;
    }
    return 0;
}
