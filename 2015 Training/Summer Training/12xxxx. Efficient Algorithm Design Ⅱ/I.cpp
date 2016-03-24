//
//  Created by TaoSama on 2015-08-01
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
int mark;

int count1(string& s) {
    int ret = 0;
    for(char &c : s)
        if(c == '1') ++ret;
        else if(c == '?') mark++;
    return ret;
}

void fillc(char c) {

}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    int kase = 0;
    while(T--) {
        cin >> s >> t;
        mark = 0;
        int s1 = count1(s);
        int t1 = count1(t);
        cout << "Case " << ++kase << ": ";
        if(s1 > t1) {
            cout << "-1\n";
            continue;
        }
        int ans = 0, need = t1 - s1;
        //change right ? to 1
        for(int i = 0; i < s.size() && need > 0; ++i) {
            if(t[i] == '1' && s[i] == '?') {
                s[i] = '1';
                need--;
            }
        }
        //change right 0 to 1
        for(int i = 0; i < s.size() && need; ++i) {
            if(s[i] == '0' && t[i] == '1') {
                s[i] = '1';
                ++ans; --need;
            }
        }
        //left ? to need
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '?') {
                if(need) s[i] = '1', --need;
                else s[i] = '0';
            }
        }
        int dif = 0; //exchange
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != t[i]) ++dif;
        }

        ans += mark + dif / 2;
        cout << ans << '\n';
    }
    return 0;
}
