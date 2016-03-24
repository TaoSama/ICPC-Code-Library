//
//
//
//  Created by TaoSama on 2015-03-26
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
typedef long long LL;

int n, k;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        priority_queue<LL, vector<LL>, greater<LL> > pq;
        for(int i = 1; i <= k; ++i) pq.push(0);
        for(int i = 1; i <= n; ++i) {
            LL s, cost; cin >> s >> cost;
            LL ans = pq.top(); pq.pop();
            ans = max(ans, s) + cost;
            cout << ans << endl;
            pq.push(ans);
        }
    }
    return 0;
}
