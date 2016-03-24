//
//  Created by TaoSama on 2015-08-09
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

string s, t;
int nxt[1005];
int l[1005], r[1005];
//l[i]:= record the position of the original string of the i's length
//r[i]:= similar to l[i]

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < t.size()) {
        if(j == -1 || t[i] == t[j])
            nxt[++i] = ++j;
        else j = nxt[j];
    }
}

void match(int *l) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j]) {
            ++i, ++j;
            l[j] = min(l[j], i);
        } else j = nxt[j];
        if(j == t.size()) j = nxt[j];
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int k; cin >> k;

        int ans = 0;
        while(k--) {
            cin >> t;
            if(t.size() == 1) continue;

            memset(l, 0x3f, sizeof l);
            memset(r, 0x3f, sizeof r);
            l[0] = r[0] = 0;
            getNxt(); match(l);
            reverse(s.begin(), s.end());
            reverse(t.begin(), t.end());
            getNxt(); match(r);

//            for(int i = 1; i <= t.size(); ++i)cout << l[i] << ' '; cout << endl;
//            for(int i = 1; i <= t.size(); ++i)cout << r[i] << ' '; cout << endl;

            for(int i = 1; i <= t.size(); ++i) {
                if(l[i] + r[t.size() - i] <= s.size()) {
                    ++ans;
                    break;
                }
            }
            reverse(s.begin(), s.end());
        }
        cout << ans << '\n';
    }
    return 0;
}
