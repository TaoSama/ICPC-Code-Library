//
//  Created by TaoSama on 2017-06-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    map<int, int> mp;
    set<pair<int, int>> s;
    queue<int> v;
    for(int i = 1; i <= n; ++i) {
        int op; scanf("%d", &op);
        if(op == 1) {
            int x; scanf("%d", &x);
            v.push(x);
            if(mp.count(x)) s.erase({mp[x], -x});
            ++mp[x];
            s.insert({mp[x], -x});
            if(v.size() > k) {
                s.erase({mp[v.front()], -v.front()});
                if(--mp[v.front()]) {
                    s.insert({mp[v.front()], -v.front()});
                } else mp.erase(v.front());
                v.pop();
            }
        } else {
            printf("%d\n", -s.rbegin()->second);
        }
    }

    return 0;
}
