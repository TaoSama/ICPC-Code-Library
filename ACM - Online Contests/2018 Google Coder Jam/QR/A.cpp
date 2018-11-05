
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int d; string s; cin >> d >> s;
        int cur = 0, b = 1, sNum = 0;
        for(char c : s) {
            if(c == 'C') {
                b <<= 1;
            }
            else {
                ++sNum;
                cur += b;
            }
        }
        // cout << "sNum=" << sNum << endl;
        // cout << "cur=" << cur << endl;
        static int kase = 0;
        if(sNum > d) {
            cout << "Case #" << ++kase << ": IMPOSSIBLE\n";
        }
        else if(cur <= d) {
            cout << "Case #" << ++kase << ": 0\n";
        }
        else {
            int to = cur - d;
            int ans = 0;
            // cout << "to=" << to << endl;
            while(to > 0) {
                vector<pair<int,pair<int,int>>> need(31, {INF, {-1, -1}});
                int cNum = 0, cPos = -1;
                for(int i = 0; i < s.size(); ++i) {
                    char c = s[i];
                    if(c == 'C') {
                        ++cNum;
                        cPos = i;
                    }
                    else {
                        if(cNum > 0) {
                            pair<int, pair<int, int>> o = {i - cPos, {cPos, i}};
                            need[cNum] = min(need[cNum], o);
                        }
                    }
                }
                for(int i = 29; i >= 0; --i) need[i] = min(need[i], need[i + 1]);
                // for(int i = 0; i < 5; ++i) cout << i << "=" << need[i].first << ' ' << need[i].second.first << ' ' << need[i].second.second << endl;
                int p = 0;
                for(int i = 30; i >= 0; --i) {
                    if((1 << (i - 1)) > to) continue;
                    if(need[i].first != INF) {
                        p = i;
                        break; 
                    }
                }
                // cout << "p=" << p << endl;
                int delta = need[p].first;
                assert(delta != INF);
                int u, v; tie(u, v) = need[p].second;
                ans += delta;
                to -= 1 << (p - 1);
                for(int i = v; i - 1 >= u; --i) swap(s[i], s[i - 1]);
            }
            cout << "Case #" << ++kase << ": " << ans << "\n";
        }

    }
    return 0;
}
