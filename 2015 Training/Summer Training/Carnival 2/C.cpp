//
//  Created by TaoSama on 2015-08-02
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

string s;
int k;
bool del[30];
pair<int, char> a[30];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> k) {
        memset(a, 0, sizeof a);
        memset(del, false, sizeof del);
        for(int i = 0; i < s.size(); ++i) {
            a[s[i] - 'a'].first++;
            a[s[i] - 'a'].second = s[i] - 'a';
        }
        int all = 0;
        for(int i = 0; i < 26; ++i)
            if(a[i].first) ++all;
        sort(a, a + 26);
        for(int i = 0; i < 26; ++i) {
//            cout << k << ' ' << a[i].first << endl;
            if(a[i].first) {
                if(k >= a[i].first) {
                    k -= a[i].first;
                    all--;
                    del[a[i].second] = true;
                } else break;
            }
        }
        cout << all << '\n';
        for(int i = 0; i < s.size(); ++i) {
            if(del[s[i] - 'a']) continue;
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
