//
//  Created by TaoSama on 2015-07-27
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
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int l, r;
vector<string> all;

bool cmp(string s, string t) {
    if(s.size() != t.size()) return s.size() < t.size();
    return s < t;
}

void dfs(string u) {
    if(u.size() > 9) return;
    if(u.size()) all.push_back(u);
    dfs(u + "4");
    dfs(u + "7");
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    dfs("");
    all.push_back("4444444444");
    sort(all.begin(), all.end(), cmp);
    vector<long long> v;
    for(int i = 0; i < all.size(); ++i) {
        v.push_back(atoll(all[i].c_str()));
    }

    long long l, r; cin >> l >> r;
    long long ans = 0;
    for(long long i = l; i <= r; ++i) {
        for(int j = 0; j < v.size(); ++j) {
            if(v[j] >= i) {
//                cout << i << ' ' << v[j] << endl;
                ans += v[j] * min(r - i + 1, (v[j] - i + 1));
                i = v[j];
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
