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

typedef long long LL;

LL to_dec(string s, LL base) {
    LL re = 0;
    for(int a = 0; a < s.size(); ++a)
        if('0' <= s[a] && s[a] <= '9') re = re * base + (LL)(s[a] - '0');
        else if('A' <= s[a] && s[a] <= 'Z') re = re * base + (LL)(s[a] - 'A' + 10);
    return re;
}

string to_to(LL num, LL base) {
    string re;
    while(num > 0) {
        LL rem = num % base;
        if(rem <= 9) re = string(1, '0' + rem) + re;
        else re = string(1, 'A' + rem - 10) + re;
        num /= base;
    }
    if(re == "") re = "0";
    return re;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    string s, t;
    while(cin >> s) {
        int maxv = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ':') continue;
            if(isupper(s[i])) maxv = max(maxv, s[i] - 'A' + 10);
            else maxv = max(maxv, s[i] - '0');
        }
        maxv = max(2, maxv + 1);

        int p = s.find(':');
        t = s.substr(p + 1);
        s = s.erase(p);

		int h = to_dec(s, maxv);
        int m = to_dec(t, maxv);

//		cout << h << ' ' << m << endl;

        //erase the leading zeros
        if(h) while(s[0] == '0') s.erase(0, 1);
        else s = "0";
        if(m) while(t[0] == '0') t.erase(0, 1);
        else t = "0";


        //infinite
        if(s.size() == 1 && h < 24 && t.size() == 1 && m < 60) {
            cout << "-1\n";
            continue;
        }
//      cout << h << ' ' << m << endl;

        //illegal
        if(h > 23 || m > 59) {
            cout << "0\n";
            continue;
        }

        cout << maxv;
        for(int i = maxv + 1; ; ++i) {
            h = to_dec(s, i);
            m = to_dec(t, i);
            if(h > 23 || m > 59) break;
            cout << ' ' << i;
        }
        cout << '\n';
    }
    return 0;
}
