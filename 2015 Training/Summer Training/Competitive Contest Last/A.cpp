//
//  Created by TaoSama on 2015-09-13
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

int nxt[N];

void getNxt(string &s) {
    int i = 0, j = -1;
    nxt[0] = -1;
    while(i < s.size()) {
        if(j == -1 || s[i] == s[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

int kmp(string &s, string &t) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j])
            ++i, ++j;
        else j = nxt[j];
    }
    return j; //s串后缀与t串前缀最多有多少个重合
}

char mp[26];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        string con, s, t;
        cin >> con >> t;
        cout << t;
        for(int i = 0; i < 26; ++i)
            mp[con[i] - 'a'] = 'a' + i; //to 明文

        s = t.substr(t.size() + 1 >> 1);
        for(int i = 0; i < t.size(); ++i)
            t[i] = mp[t[i] - 'a'];
        getNxt(t);
        int k = kmp(s, t); //明文重叠的部分
//      cout << s << '\n' << t << '\n' << k << "\n\n";
        for(int i = k; i < t.size() - k; ++i) cout << t[i];
        cout << '\n';
    }
    return 0;
}
