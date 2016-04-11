//
//  Created by TaoSama on 2015-04-27
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

int n, m, day[N], h[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= m; ++i) cin >> day[i] >> h[i];
        int ans = -INF;
        if(day[1] == 1) ans = h[1];
        if(day[1] > 1) ans = max(ans, h[1] + day[1] - 1);
        if(day[m] < n) ans = max(ans, h[m] + n - day[m]);

        bool ok = true;
        for(int i = 1; i < m; ++i) {
            if(abs(day[i + 1] - day[i]) < abs(h[i + 1] - h[i])) {
                ok = false;
                break;
            } else if(abs(day[i + 1] - day[i]) == abs(h[i + 1] - h[i]))
                ans = max(ans, max(h[i + 1], h[i]));
            else {
                int diff = abs(day[i + 1] - day[i]) - abs(h[i + 1] - h[i]), Max = max(h[i + 1], h[i]);
                //cout<<diff<<' '<<Max<<endl;
                ans = max(ans, Max + diff / 2);
            }
        }
        if(ok) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
