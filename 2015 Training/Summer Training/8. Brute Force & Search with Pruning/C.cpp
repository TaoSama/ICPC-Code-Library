//
//  Created by TaoSama on 2015-07-26
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

int k;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> k) {
        vector<pair<int, int> > v;
        for(int i = k + 1; i <= k << 1; ++i) {
            if(i * k % (i - k) == 0) {
                v.push_back({i * k / (i - k), i});
            }
        }
        cout << v.size() << '\n';
        for(auto &i : v) {
            cout << "1/" << k << " = 1/" << i.first << " + 1/" << i.second << '\n';
        }
    }
    return 0;
}
