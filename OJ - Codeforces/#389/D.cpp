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

int n, k, val[N];
string s[N];

bool isPal(string& s) {
    for(int i = 0; i < s.size() / 2; ++i)
        if(s[i] != s[s.size() - i - 1])  return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        map<string, vector<pair<int, int>>> mp;
        map<string, int> isP, del;
        for(int i = 1; i <= n; ++i) {
            cin >> s[i] >> val[i];
            isP[s[i]] = isPal(s[i]);
            mp[s[i]].push_back({val[i], i});
        }
        for(auto& p : mp) {
            auto& vec = p.second;
            sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        }

        int ans1 = 0, ans2 = 0;
        vector<int> used(n + 1, 0);
        for(auto& p : mp) {
            auto& lft = p.first;
            auto& v1 = p.second;
//            prln(lft);
            string rht = lft; reverse(rht.begin(), rht.end());
            if(!mp.count(rht)) continue;
            if(!isP[lft]) {
                auto& v2 = mp[rht];
                for(int i = 0; i < min(v1.size(), v2.size()); ++i) {
                    int a = v1[i].first, b = v2[i].first;
                    if(a + b < 0) break;
                    used[v1[i].second] = true;
                    used[v2[i].second] = true;
                    ans1 += a + b;
                }
            } else {
                int e = -1;
                for(int i = 0; i + 1 < v1.size(); i += 2) {
                    int a = v1[i].first, b = v1[i + 1].first;
                    if(a + b < 0) break;
                    used[v1[i].second] = true;
                    used[v1[i + 1].second] = true;
                    ans2 += a + b;
                    e = i + 1;
                }
                //abandon last one of the pairs
                if(~e) del[lft] = v1[e].first;
                //add the next one
                if(e + 1 < v1.size()) del[lft] = min(del[lft], -v1[e + 1].first);
            }
        }

        int tot = ans1 / 2 + ans2;
        int ans = tot;
        for(int i = 1; i <= n; ++i) {
            if(val[i] < 0 || !isP[s[i]]) continue;
            int cur = tot + (used[i] ? -del[s[i]] : val[i]);
//            pr(i);prln((used[i] ? -val[i] - del[s[i]] : val[i]));
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
