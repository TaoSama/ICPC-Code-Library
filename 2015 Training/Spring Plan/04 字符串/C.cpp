//
//  Created by TaoSama on 2015-05-04
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int sz = s.size(), ans = -1;

        int l, r;
        bool ok = true;
        for(int i = 0, j = sz - 1; i <= j; ++i, --j) {
            if(s[i] != s[j]) {
                ok = false;
                l = i, r = j;
                break;
            }
        }

        if(!ok) {
            ok = true;
            for(int i = l + 1, j = r; i <= j; ++i, --j) {
                if(s[i] != s[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans = l;
            else {
                ok = true;
                for(int i = l, j = r - 1; i <= j; ++i, --j) {
                    if(s[i] != s[j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) ans = r;
                else ans = -1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
