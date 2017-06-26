//
//  Created by TaoSama on 2017-06-04
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int get(string src, string des) {
    vector<int> a(26), b(26);
    for(int i = 0; i < src.size(); ++i) ++a[src[i] - 'a'], ++b[des[i] - 'a'];
    if(a != b) return -1;
    for(int i = 0; i < src.size(); ++i) {
        if(src == des) return i;
        char c = src.back();
        src.pop_back();
        src.insert(0, 1, c);
    }
    return -2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TsaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s, t;
    while(cin >> s >> t) {
        int ans = 0, ok = 0;
        if(get(s, t) == -1) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0, j; i < s.size(); i = j + 1) {
            string src, des;
            ok = 0;
            for(j = i; j < s.size(); ++j) {
                src += s[j];
                des += t[j];
                int ret = get(src, des);
                if(ret >= 0) {
                    ans += ret;
                    ok = 1;
                    break;
                }
            }
            if(!ok) break;
        }
        if(!ok) ans = -1;
        cout << ans << endl;
    }

    return 0;
}
