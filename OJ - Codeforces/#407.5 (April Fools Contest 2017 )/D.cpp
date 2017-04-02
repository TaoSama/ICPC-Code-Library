//
//  Created by TaoSama on 2017-04-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    map<char, char> mp;
    mp['3'] = mp['3'] = 'A';
    mp['4'] = mp['6'] = 'B';
    mp['5'] = mp['9'] = 'C';
    mp['7'] = mp['7'] = 'D';
    mp['8'] = mp['0'] = 'E';

    string s;
    while(cin >> s) {
        bool ok = true;
        for(int i = 0; ok && i < (s.size() + 1) / 2; ++i) {
            char a = s[i], b = s[s.size() - i - 1];
//            pr(a); prln(b);
            if(a == b && (a == '3' || a == '7')) {}
            else if(a != b && mp.count(a) && mp.count(b) && mp[a] == mp[b]) {}
            else ok = false;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}
