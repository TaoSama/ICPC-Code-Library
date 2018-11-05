
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
pair<int, int> a[N], b[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
        for(int i = 1; i <= m; ++i) cin >> b[i].first >> b[i].second;

        bool meOk = false;
        set<int> aOk, bOk;
        auto checkPair = [](pair<int, int> x, pair<int, int> y) {
            if (x.first > x.second) swap(x.first, x.second);
            if (y.first > y.second) swap(y.first, y.second);
            if (x.first == y.first && x.second == y.second) return -2;
            if (x.first == y.first || x.first == y.second) return x.first;
            if (x.second == y.first || x.second == y.second) return x.second;
            return -1;
        };

        bool aC = false;
        for(int i = 1; i <= n; ++i) {
            int tryThis = -1;
            for(int j = 1; j <= m; ++j) {
                int ret = checkPair(a[i], b[j]);
                if (ret > 0) {
                    if (tryThis != -1) {
                        if (tryThis != ret) {
                            aC = true;
                            tryThis = -1;
                            break;
                        }
                    }
                    tryThis = ret;
                }
                else if(ret == -2) {
                    // tryThis = -1;
                    // break;
                }
            }
            if (tryThis > 0) aOk.insert(tryThis);
        }
        bool bC = false; 
        for(int i = 1; i <= m; ++i) {
            int tryThis = -1;
            for(int j = 1; j <= n; ++j) {
                int ret = checkPair(b[i], a[j]);
                if (ret > 0) {
                    if (tryThis != -1) {
                        if (tryThis != ret) {
                            bC = true;
                            tryThis = -1;
                            break;
                        }
                    }
                    tryThis = ret;
                }
                else if(ret == -2) {
                    // tryThis = -1;
                    // break;
                }
            }
            if (tryThis > 0) bOk.insert(tryThis);
        }
        // for(int a : aOk) cout << a << ' ';cout << endl;;
        // for(int a : bOk) cout << a << ' ';cout << endl;;
        
        int contain = false;
        for(int a : aOk) contain += bOk.count(a);
        if (!aC && !bC) {
            if (contain == 1) {
                cout << *aOk.begin() << endl;
            }
            else if(contain > 1) {
                cout << 0 << endl;
            }
            else cout << -1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
