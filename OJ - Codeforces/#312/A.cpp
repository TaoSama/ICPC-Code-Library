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

int n;
typedef pair<int, int> P;
vector<P> l, r;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        l.clear(); r.clear();
        for(int i = 1; i <= n; ++i) {
            int x, y; cin >> x >> y;
            if(x > 0) r.push_back({x, y});
            else l.push_back({ -x, y});
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        int ans = 0, t = 0, cnt = 1;
        int i = 0, j = 0;
        while(true) {
            if(cnt++ & 1) {
                if(i == l.size()) break;
                t += l[i++].second;
            } else {
                if(j == r.size()) break;
                t += r[j++].second;
            }
//            prln(t);
        }
        ans = max(ans, t);

        i = j = t = 0; cnt = 1;
        while(true) {
            if(cnt++ & 1) {
                if(j == r.size()) break;
                t += r[j++].second;
            } else {
                if(i == l.size()) break;
                t += l[i++].second;
            }
        }
        ans = max(ans, t);

        cout << ans << '\n';
    }
    return 0;
}
