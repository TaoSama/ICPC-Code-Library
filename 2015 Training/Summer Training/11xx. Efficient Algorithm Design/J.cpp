//
//  Created by TaoSama on 2015-07-31
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

int n;
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        priority_queue<LL, vector<LL>, greater<LL> > pq;
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            pq.push(x);
        }

        LL ans = 0;
        while(pq.size() > 1) {
            LL u = pq.top(); pq.pop();
            LL v = pq.top(); pq.pop();
            ans += u + v;
            pq.push(u + v);
        }
        cout << ans << '\n';
    }
    return 0;
}
