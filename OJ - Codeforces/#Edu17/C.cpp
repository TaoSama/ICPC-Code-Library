//
//  Created by TaoSama on 2017-01-25
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
        pair<int, int> del = {t.size(), 0};

        vector<int> f(t.size(), +INF), g(t.size(), -INF);
        for(int i = 0, j = 0; i < s.size(); ++i) {
            if(j < t.size() && t[j] == s[i]) {
                f[j] = i;
                del = min(del, {t.size() - j, j + 1});
                ++j;
            }
        }
        for(int i = s.size() - 1, j = t.size() - 1; i >= 0; --i) {
            if(j >= 0 && t[j] == s[i]) {
                g[j] = i;
                del = min(del, {j, 0});
                --j;
            }
        }
//      for(int i = 0; i < t.size(); ++i){
//          cout << i << ' ' << f[i] << ' ' << g[i] << endl;
//      }
//        cout << endl;
//        pr(del.first); prln(del.second);

        for(int l = 0, r = 0; l < t.size(); ++l) {
            if(f[l] == INF) break;
            while(r < t.size() && (l >= r || f[l] >= g[r])) ++r;
            del = min(del, {r - l - 1, l + 1});
        }

        t.erase(del.second, del.first);
        if(!t.size()) t = "-";
        cout << t << endl;
    }

    return 0;
}
