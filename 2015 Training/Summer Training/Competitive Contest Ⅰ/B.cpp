//
//  Created by TaoSama on 2015-08-21
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

string a, b;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    map<string, string> mp;
    mp["A#"] = "Bb"; mp["Bb"] = "A#";
    mp["C#"] = "Db"; mp["Db"] = "C#";
    mp["D#"] = "Eb"; mp["Eb"] = "D#";
    mp["F#"] = "Gb"; mp["Gb"] = "F#";
    mp["G#"] = "Ab"; mp["Ab"] = "G#";

    int kase = 0;
    while(cin >> a >> b) {
        cout << "Case " << ++kase << ": ";
        if(mp.count(a)) cout << mp[a] << ' ' << b << '\n';
        else cout << "UNIQUE\n";
    }
    return 0;
}
