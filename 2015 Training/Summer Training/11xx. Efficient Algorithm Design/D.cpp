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
struct P {
    int l, r, id;
    bool operator< (const P& rhs) const {
        return r < rhs.r;
    }
};

P x[5005], y[5005];

int ansx[5005], ansy[5005];
bool vis[5005];

bool choose(P *x, int *ansx) {
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; ++i) {
        bool ok = false;
        for(int j = x[i].l; j <= x[i].r; ++j) {
            if(!vis[j]) {
                ansx[x[i].id] = j;
                ok = vis[j] = true;
                break;
            }
        }
        if(ok) continue;
        return false;
    }
    return true;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> x[i].l >> y[i].l >> x[i].r >> y[i].r;
            x[i].id = y[i].id = i;
        }
        sort(x + 1, x + 1 + n);
        sort(y + 1, y + 1 + n);

        bool o = true;
        o &= choose(x, ansx);
//      cout << o <<endl;
        o &= choose(y, ansy);

        if(!o) {cout << "IMPOSSIBLE\n"; continue;}
        for(int i = 1; i <= n; ++i)
            cout << ansx[i] << ' ' << ansy[i] << '\n';

//        cout << endl;
    }
    return 0;
}
