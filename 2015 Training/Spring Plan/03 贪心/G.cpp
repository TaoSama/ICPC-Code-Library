//
//
//
//  Created by TaoSama on 2015-04-22
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
const double EPS = 1e-5;

int p, l, w, n;
double price[32005]; // $/L -> $/m
struct ACM {
    int pos;
    double cost;
} a[505];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> p >> l >> w >> n) {
        for(int i = 1; i <= n; ++i)
            cin >> a[i].cost >> a[i].pos;

        for(int i = 1; i <= l; ++i) price[i] = INF;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= p * w; ++j)
                price[a[i].pos + j] = min(price[a[i].pos + j], a[i].cost);

        double ans = 0, far;
        bool ok = true;
        for(int i = 1; i <= l; ++i) {
            if(price[i] == INF) {
                far = i - 1;
                ok = false;
                break;
            } else ans += price[i];
        }

        if(ok) cout << "YES\n" << fixed << setprecision(2) << ans / w << '\n';
        else cout << "NO\n" << fixed << setprecision(2) << far << '\n';
    }
    return 0;
}

/*
double p, l, w;
int n;
typedef pair <double, double> sta;
struct pnt{
    double price;
    double x;
    bool operator < (const pnt &ths) const{
        return price > ths.price;
    }
}a[505];
bool cmp(pnt x, pnt y){
    return x.x < y.x;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    while(scanf("%lf%lf%lf%d", &p, &l, &w, &n) != EOF){
        priority_queue <pnt> pq;
        for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].price, &a[i].x);
        a[0].x = l;
        sort(a, a + 1 + n, cmp);
        int flag = 1;
        //for(int i = 0; i <= n; i++)
            //printf("%f  %f\n", a[i].x, a[i].price);
        double res = 0, ans = 0, now = 0;
        for(int i = 0; i <= n; i++){
            while(!pq.empty() && now < a[i].x){
                pnt th = pq.top(); pq.pop();
                double c = th.x + p * w;
                if(c >= now){
                    ans += th.price * (min(a[i].x, c) - now) / w;
                    now = min(a[i].x, c);
                }
                if(now < c) pq.push(th);
            }
            if(now < a[i].x){
                flag = 0;
                ans = now;
                break;
            }
            else{
                pq.push(a[i]);
            }
        }
        if(flag) printf("YES\n%.2f\n", ans);
        else printf("NO\n%.2f\n", ans);
    }

    return 0;
}
*/
