//
//  Created by TaoSama on 2015-07-20
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
#include <stack>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, cnt;
typedef set<int> S;
vector<S> v;
map<S, int> mp;

int get(S x) {
    if(mp.count(x)) return mp[x];
    else {
        v.push_back(x);
        return mp[x] = v.size() - 1;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        stack<int> s;
        mp.clear(); v.clear();
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            char op[20]; cin >> op;
            if(op[0] == 'P') s.push(get(S()));
            else if(op[0] == 'D') s.push(s.top());
            else {
                S a = v[s.top()]; s.pop();
                S b = v[s.top()]; s.pop();
                S c;
                if(op[0] == 'A') {
                    b.insert(get(a));
                    s.push(get(b));
                } else if(op[0] == 'U') {
                    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
                    s.push(get(c));
                } else {
                    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c,
                                     c.begin()));
                    s.push(get(c));
                }
            }
            cout << v[s.top()].size() << '\n';
        }
        cout << "***\n";
    }
    return 0;
}
