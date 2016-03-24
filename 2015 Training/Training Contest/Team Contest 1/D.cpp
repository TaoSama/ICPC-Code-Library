//
//
//
//  Created by TaoSama on 2015-03-26
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string s, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> t) {
        int l = -INF, r = -INF;
        for(int i = 0, j = 0; j < t.size(); ++j) {
            if(s[i] == t[j]) ++i;
            if(i == s.size()) {
                l = j;
                break;
            }
        }
        for(int i = s.size() - 1, j = t.size() - 1; j >= 0; --j) {
            if(s[i] == t[j]) --i;
            if(i == -1) {
                r = j;
                break;
            }
        }
        //cout << l << ' ' << r << endl;
        if(l != -INF && r != -INF && r - l > 0)
            cout << r - l << endl;
        else cout << 0 << endl;
    }
    return 0;
}
