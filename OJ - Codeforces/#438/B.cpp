
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
    
    int h, m, s, t1, t2;
    while(cin >> h >> m >> s >> t1 >> t2) {
        double ss = 360.0 / 60;
        double sm = 360.0 / 60 / 60;
        double sh = 360.0 / 12 / 60 / 60;
        // cout << ss << ' ' << sm << ' ' << sh << endl;
        double t = h * 3600 + m * 60 + s;
        double ds = fmod(ss * t, 360.0);
        double dm = fmod(sm * t, 360.0);
        double dh = fmod(sh * t, 360.0);
        double dt1 = fmod(360.0 / 12 * t1, 360.0); 
        double dt2 = fmod(360.0 / 12 * t2, 360.0); 
        if(dt1 > dt2) swap(dt1, dt2);
        vector<double> v = {ds, dm, dh};
        sort(v.begin(), v.end());
        v.emplace_back(360 + *v.begin());

        // cout << ds << ' ' << dm << ' ' << dh << endl;
        // cout << dt1 << ' ' << dt2 << endl;

        bool ok = false;
        for(size_t i = 0; i + 1 < v.size(); ++i) {
            ok |= v[i] <= dt1 && dt2 <= v[i + 1]; 
            ok |= v[i] <= dt1 + 360 && dt2 + 360 <= v[i + 1]; 
            ok |= v[i] <= dt2 && dt1 + 360 <= v[i + 1];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
