//
//  Created by TaoSama on 2015-07-21
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

int n, m, cnt[10];
typedef pair<int, int> P;

bool canPrint(int x) {
    for(int i = x + 1; i < 10; ++i)
        if(cnt[i]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        queue<P> q;
        P target;
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; ++i) {
            int x; cin >> x; ++cnt[x];
            if(m == i) target = {x, i};
            q.push({x, i});
        }

        int ans = 0;
        while(q.size()) {
            P cur = q.front(); q.pop();
            if(canPrint(cur.first)) {
                --cnt[cur.first]; ++ans;
                if(cur == target) break;
            } else q.push(cur);
        }
        cout << ans << '\n';
    }
    return 0;
}
