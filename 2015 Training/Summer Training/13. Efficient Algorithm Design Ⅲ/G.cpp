//
//  Created by TaoSama on 2015-08-03
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
const int N = 8e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
struct P {
    int t, r;
    bool operator< (const P& rhs) const {
        return r < rhs.r;
    }
} a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i].t >> a[i].r;
        sort(a + 1, a + 1 + n);

        int sum = 0, ans = 0;
        priority_queue<int> q;
        for(int i = 1; i <= n; ++i) {
            sum += a[i].t;
            q.push(a[i].t);
            ans++;
            if(sum > a[i].r) {
                sum -= q.top(); q.pop();
                ans--;
            }
        }
        cout << ans << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
