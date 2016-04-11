//
//
//
//  Created by TaoSama on 2015-04-22
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

int n, b[5], a[1005];
multiset<int>::iterator iter;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= 4; ++i) cin >> b[i];
        int sum = 0;
        multiset<int> s;
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            s.insert(x); sum += x;
        }
        bool yes = true;
        for(int i = 1; i <= 4; ++i) {
            while(b[i]) {
                if(s.size() == 0) {
                    yes = false;
                    break;
                }
                iter = s.lower_bound(b[i]);
                if(iter == s.end()) {
                    --iter;
                    b[i] -= (*iter);
                } else b[i] = 0;
                sum -= (*iter);
                s.erase(iter);
            }
            if(!yes) break;
        }
        if(yes) cout << "YES " << sum << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
