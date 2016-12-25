//
//  Created by TaoSama on 2016-12-20
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
#include <list>
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
string s;

int p[N];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> s) {
        set<int> T, D, R;
        for(int i = 0; i < n; ++i) p[i] = i;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'D') D.insert(i);
            else R.insert(i);
            T.insert(i);
        }

        int idx = 0;
        while(D.size() && R.size()) {
            auto iter = T.lower_bound(idx);
            if(iter == T.end()) idx = *T.begin();
            else idx = *iter;
            if(D.find(idx) != D.end()) {
                auto to = R.lower_bound(idx);
                if(to != R.end()) {
                    T.erase(*to);
                    R.erase(to);
                } else {
                    if(R.size()) {
                        T.erase(*R.begin());
                        R.erase(R.begin());
                    }
                }
            } else if(R.find(idx) != R.end()) {
                auto to = D.lower_bound(idx);
                if(to != D.end()) {
                    T.erase(*to);
                    D.erase(to);
                } else {
                    if(D.size()) {
                        T.erase(*D.begin());
                        D.erase(D.begin());
                    }
                }
            }
            ++idx;
        }
        cout << (D.size() ? "D" : "R") << endl;
    }

    return 0;
}
