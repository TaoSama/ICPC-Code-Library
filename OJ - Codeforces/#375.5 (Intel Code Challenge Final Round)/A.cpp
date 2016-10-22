//
//  Created by TaoSama on 2016-10-08
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string days[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int mons[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string a, b;
    while(cin >> a >> b) {
        int x = find(days, days + 12, a) - days;
        int y = find(days, days + 12, b) - days;
        int ok = false;
        for(int i = 0; i + 1 < 12; ++i) {
            if((x + mons[i] - y) % 7 == 0) {
//              prln(i);
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
