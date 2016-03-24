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

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        multimap<pair<int, int>, bool> mp;
        for(int i = 1; i <= n; ++i) {
            int x, y; cin >> x >> y;
            auto iter = mp.find({y, x});
            if(iter != mp.end()) mp.erase(iter);
            else mp.insert({{x, y}, true});
        }
        cout << (mp.size() ? "NO" : "YES") << '\n';
    }
    return 0;
}
