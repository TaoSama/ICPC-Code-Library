//
//
//
//  Created by TaoSama on 2015-04-15
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        vector<vector<int> > v(n);
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            v[x].push_back(i);
        }
        bool ok = true;
        int j = 0;
        vector<int> ans;
        for(int i = 1; i <= n; ++i) {
            while(v[j].empty() && j >= 3) j -= 3;
            if(v[j].empty()) {
                ok = false;
                break;
            }
            ans.push_back(v[j].back());
            v[j].pop_back();
            j++;
        }
        if(!ok) cout << "Impossible" << endl;
        else {
            cout << "Possible" << endl;
            for(int i = 0; i < n; ++i)
                cout << ans[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}
