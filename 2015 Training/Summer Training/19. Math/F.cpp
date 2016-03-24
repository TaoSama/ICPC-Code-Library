//
//  Created by TaoSama on 2015-08-14
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

int n, m;
bool no[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        n--;
        memset(no, false, sizeof no);

        vector<int> factor;
        int t = m;
        for(int i = 2; i * i <= m; ++i) {
            if(t % i == 0) {
                factor.push_back(i);
                while(t % i == 0) t /= i;
            }
        }
        if(t > 1) factor.push_back(t);

        for(auto &p : factor) {
            int x = m, e = 0, cur = 0;
            while(x % p == 0) ++e, x /= p;

            for(int k = 1; k < n; ++k) {
                x = n - k + 1;
                while(x % p == 0) ++cur, x /= p;
                x = k;
                while(x % p == 0) --cur, x /= p;
                if(cur < e) no[k] = true;
            }
        }

        vector<int> ans;
        for(int i = 1; i < n; ++i)
            if(!no[i]) ans.push_back(i + 1);
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) {
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
