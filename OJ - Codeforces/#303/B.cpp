//
//  Created by TaoSama on 2015-05-20
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

string s, t;
char ans[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> t) {
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != t[i]) {
                ++cnt;
                ans[i] = (cnt & 1) ? s[i] : t[i];
            } else ans[i] = s[i];
        }
        if(cnt & 1) cout << "impossible\n";
        else {
            ans[s.size()] = 0;
            puts(ans);
        }
    }
    return 0;
}
