//
//  Created by TaoSama on 2015-06-28
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
pair<pair<LL, LL>, int> a[N];
set<pair<LL, int> > s;
int n, m, ans[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        LL _l, _r, l, r;
        cin >> _l >> _r;
        for(int i = 1; i < n; ++i) {

            cin >> l >> r;
            a[i] = {{_r - l, _l - r}, i};
            _l = l, _r = r;
        }
        s.clear();
        for(int i = 1; i <= m; ++i) {
            LL x; cin >> x;
            s.insert({x, i});
        }
        sort(a + 1, a + n);

        bool ok = true;
        for(int i = 1; i < n; ++i) {
            LL l = -a[i].first.first, r = -a[i].first.second;
            auto k = s.lower_bound({r, INF});
            if(k == s.begin()) {
                ok = false;
                break;
            }
            k--;
            if(k->first < l) {
                ok = false;
                break;
            }
            ans[a[i].second] = k->second;
            s.erase(k);
        }
        if(ok) {
            cout << "Yes\n";
            for(int i = 1; i < n; ++i)
                cout << ans[i] << ' ';
            cout << '\n';
        } else cout << "No\n";
    }
    return 0;
}
