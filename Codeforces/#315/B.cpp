//
//  Created by TaoSama on 2015-08-10
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

int n, a[N];
bool vis[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        set<int> s;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) s.insert(i);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            if(s.count(a[i])) {
                vis[a[i]] = true;
                s.erase(a[i]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(vis[a[i]]) {
                cout << a[i] << ' ';
                vis[a[i]] = false;
            } else {
                cout << *s.begin() << ' ';
                s.erase(s.begin());
            }
        }
        cout << '\n';
    }
    return 0;
}
