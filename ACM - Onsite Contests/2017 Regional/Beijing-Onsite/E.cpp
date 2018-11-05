
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Cat {
    int id;
    int fish;
    int notFish;
    int lftMins;
    int totMins;
};

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int m, n, x; 
    while(cin >> m >> n >> x) {
        vector<Cat> cats;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            cats.push_back(Cat{i, 0, 0, x, x});
        }
        sort(cats.begin(), cats.end(), [](const Cat& x, const Cat& y) {
            return make_tuple(-x.notFish, x.lftMins, x.id) < make_tuple(-y.notFish, y.lftMins, y.id);
        });
        for(int i = 0; i < n; ++i) {
            Cat& c = cats[i];
            if(m) {
                c.notFish = 1;
                --m;
            }
        }
        for(int i = 1; i <= x; ++i) {
            sort(cats.begin(), cats.end(), [](const Cat& x, const Cat& y) {
                return make_tuple(-x.notFish, x.lftMins, x.id) < make_tuple(-y.notFish, y.lftMins, y.id);
            });
            for(int j = 0; j < n; ++j) {
                Cat& c = cats[j];
                if(c.notFish) {
                    if(--c.lftMins == 0) {
                        ++c.fish;
                        c.lftMins = c.totMins;
                        if(m) {
                            --m;
                        }
                        else {
                            c.notFish = 0;
                        }
                    }
                }
            }
        }
        int p = m, q = 0;
        for(int i = 0; i < n; ++i) {
            Cat& c = cats[i];
            p += c.notFish && c.lftMins == c.totMins;
            q += c.notFish && c.lftMins != c.totMins;
        }
        cout << p << ' ' << q << endl;
    }
    return 0;
}
