//
//  Created by TaoSama on 2016-07-24
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int k, n, m, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    map<string, int> mp[105];
    map<string, vector<pair<string, int> > > composite;

    cin >> k >> n >> m >> q;
    cin.get();
    for(int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
    }
    for(int j = 1; j <= m; ++j) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string a; ss >> a; a.pop_back(); //:
        string b, c;
        while(ss >> b >> c) {
            if(c.back() == ',') c.pop_back();
            composite[a].push_back({b, stoi(c)});
        }
    }

    for(int i = 1; i <= q; ++i) {
        int p; string s; cin >> p >> s;
        ++mp[p][s];
        for(auto& p1 : composite) {
            auto& newOne = p1.first;
            auto& big = p1.second;
            bool ok = true;
            for(auto& p2 : big) {
                string name; int cnt;
                tie(name, cnt) = p2;
                ok &= mp[p].count(name) && mp[p][name] >= cnt;
                if(!ok) break;
            }
            if(ok) {
                ++mp[p][newOne];
                for(auto& p2 : big) {
                    string name; int cnt;
                    tie(name, cnt) = p2;
                    mp[p][name] -= cnt;
                    if(!mp[p][name]) mp[p].erase(name);
                }
            }
        }
    }

    for(int i = 1; i <= k; ++i) {
        cout << mp[i].size() << '\n';
        for(auto& cur : mp[i]) cout << cur.first << ' ' << cur.second << '\n';
    }

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
