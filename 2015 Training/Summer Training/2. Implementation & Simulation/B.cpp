//
//  Created by TaoSama on 2015-07-19
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

int kase;
string s, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> kase && ~kase) {
        cin >> s >> t;
        map<char, bool> mp, guessed;
        for(int i = 0; i < s.size(); ++i) {
            mp[s[i]] = true;
        }

        int cnt = 0;
        cout << "Round " << kase << '\n';
        for(int i = 0; i < t.size(); ++i) {
            if(!guessed.count(t[i])) {
                guessed[t[i]] = true;
                if(mp.count(t[i])) {
                    mp.erase(t[i]);
                    if(mp.size() == 0) {
                        cout << "You win.\n";
                        break;
                    }
                } else {
                    if(++cnt == 7) {
                        cout << "You lose.\n";
                        break;
                    }
                }
            }
        }
        if(mp.size() && cnt < 7) cout << "You chickened out.\n";
    }
    return 0;
}
