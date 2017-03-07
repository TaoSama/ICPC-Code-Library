//
//  Created by TaoSama on 2017-01-25
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

int a, b, c;
int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> a >> b >> c;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 1; i <= n; ++i) {
        int val; char s[10]; cin >> val >> s;
        v[i - 1] = {val, *s == 'U'};
    }
    sort(v.begin(), v.end());

    int num = 0;
    long long sum = 0;
    for(auto& p : v) {
        if(p.second == 1) {
            if(a) {
                --a;
                ++num;
                sum += p.first;
            } else if(c) {
                --c;
                ++num;
                sum += p.first;
            }
        } else {
            if(b) {
                --b;
                ++num;
                sum += p.first;
            } else if(c) {
                --c;
                ++num;
                sum += p.first;
            }
        }
    }
    cout << num << ' ' << sum << endl;

    return 0;
}
