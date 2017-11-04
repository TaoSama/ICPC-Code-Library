//
//  Created by TaoSama on 2017-01-18
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        vector<pair<int, int> > v;
        int last = 0, first = 0, second = 0;
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if(!first) first = i;
            if(x != 0) {
                second = i;
                v.push_back({first, second});
                first = second = 0;
            }
        }

        if(v.size()) {
            auto& bk = v.back();
            if(bk.second != n) bk.second = n;
            cout << "YES" << endl;
            cout << v.size() << endl;
            for(auto& p : v) cout << p.first << ' ' << p.second << endl;
        } else cout << "NO" << endl;
    }

    return 0;
}
