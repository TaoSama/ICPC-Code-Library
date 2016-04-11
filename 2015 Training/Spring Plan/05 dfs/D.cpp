//
//  Created by TaoSama on 2015-06-03
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long n, m, last, ans;
bool vis[10];
vector<char> have;
map<char, int> mp, zero;
string a[15];

void dfs(int k) {
    if(k == last) {  //to check the last digits is legal or not
        long long sum = 0;
        for(int i = 1; i <= n; ++i) {
            char &c = a[i][a[i].size() - 1];
            if(i != n) sum += mp[c];
            else {
                if(sum % 10 != mp[c]) return;
            }
        }
    }
    if(k == m) { //to check the whole equation is legal or not
        long long sum = 0;
        for(int i = 1; i <= n; ++i) {
            long long t = 0;
            for(int j = 0; j < a[i].size(); ++j) {
                char &c = a[i][j];
                t = t * 10 + mp[c];
            }
            if(i != n) sum += t;
            else {
                if(sum == t) ++ans;
            }
        }
        return;
    }

    for(int i = 0; i < 10; ++i) {
        if(vis[i] || i == 0 && zero[have[k]]) continue;
        vis[i] = true;
        mp[have[k]] = i;
        dfs(k + 1);
        vis[i] = false;

    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(vis, false, sizeof vis);
        have.clear(); mp.clear(); zero.clear();

        //save the last digits first
        for(int i = 1; i <= n; ++i)  cin >> a[i];
        for(int i = 1; i <= n; ++i) {
            char &c = a[i][a[i].size() - 1];
            if(!mp.count(c)) {
                mp[c] = have.size();
                have.push_back(c);
            }
        }
        last = have.size();

        //save the other digits then
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < a[i].size() - 1; ++j) {
                char &c = a[i][j];
                if(j == 0) zero[c] = 1;  //save the nonzero character
                if(!mp.count(c)) {
                    mp[c] = have.size();
                    have.push_back(c);
                }
            }
        }
        m = have.size();

        ans = 0;
        if(m <= 10) dfs(0);
        cout << ans << '\n';
    }
    return 0;
}
