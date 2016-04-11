//
//  Created by TaoSama on 2016-01-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c[26];
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        memset(c, 0, sizeof c);
        n = strlen(s);
        for(int i = 0; i < n; ++i) ++c[s[i] - 'a'];
        vector<int> have;
        for(int i = 0; i < 26; ++i)
            if(c[i] & 1) have.push_back(i);
        int odd = -1;
        if(n & 1) {
            odd = have[have.size() / 2];
            have.erase(have.begin() + have.size() / 2);
        }
        for(int i = 0; i < have.size() / 2; ++i) {
//          cout << have[i] << ' ' << have[have.size() - i - 1] << endl;
            ++c[have[i]], --c[have[have.size() - i - 1]];
        }
        string ans;
        for(int i = 0; i < 26; ++i)
            if(c[i]) ans += string(c[i] >> 1, char('a' + i));
        cout << ans;
        if(~odd) cout << char('a' + odd);
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}
