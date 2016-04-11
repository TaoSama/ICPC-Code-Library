//
//
//
//  Created by TaoSama on 2015-03-27
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

int n;
string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> s) {
        map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if((i + 1) & 1) {
                mp[toupper(s[i])]++;
            } else {
                if(mp[s[i]] == 0) ++ans;
                else --mp[s[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
