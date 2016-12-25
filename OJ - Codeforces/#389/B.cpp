//
//  Created by TaoSama on 2016-12-25
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

string s, t;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> t) {
        vector<pair<char, char> > mp;
        bool ok = true;
        for(int i = 0; ok && i < s.size(); ++i) {
            bool have = false;
            for(auto p : mp) {
                if(p.first == s[i] && p.second != t[i]) ok = false;
                if(p.first == t[i] && p.second != s[i]) ok = false;
                if(p.first == s[i] && p.second == t[i]) have = true;
            }
            if(have) continue;
            mp.push_back({s[i], t[i]});
            mp.push_back({t[i], s[i]});
        }
        if(ok) {
            int same = 0;
            for(int i = 0; i < mp.size(); i += 2)
                if(mp[i].first == mp[i].second) ++same;
            cout << mp.size() / 2 - same << endl;
            for(int i = 0; i < mp.size(); i += 2)
                if(mp[i].first != mp[i].second)
                    cout << mp[i].first << ' ' << mp[i].second << endl;
        } else cout << -1 << endl;
    }

    return 0;
}
