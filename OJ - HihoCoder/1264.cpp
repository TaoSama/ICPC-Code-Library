//
//  Created by TaoSama on 2016-02-14
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int cc1[26], cc2[26];
string s, t;

int calc(string s, string t) {
    if(s.size() != t.size()) return INF;
    int ret = 0;
    for(int i = 0; i < t.size(); ++i) {
        char c = t[i];
        string::size_type idx = s.find(c, i);
        if(idx == string::npos) return INF;
        for(int j = idx; j > i; --j) {
            ++ret;
            swap(s[j], s[j - 1]);
        }
    }
    assert(s == t);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> s >> t;

    int ans = INF;
    //add
    for(int i = 0; i <= t.size(); ++i) {
        for(char c = 'a'; c <= 'z'; ++c) {
            string tmp = t;
            tmp.insert(i, 1, c);
            ans = min(ans, calc(s, tmp));
        }
    }
    //del
    for(int i = 0; i < t.size(); ++i) {
        string tmp = t;
        tmp.erase(i, 1);
        ans = min(ans, calc(s, tmp));
    }
    //replace
    for(int i = 0; i < t.size(); ++i) {
        for(char c = 'a'; c <= 'z'; ++c) {
            string tmp = t;
            tmp[i] = c;
            ans = min(ans, calc(s, tmp));
        }
    }
    cout << ans << '\n';

    return 0;
}
