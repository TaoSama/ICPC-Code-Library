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

int n;
const double eps = 1e-12;
inline double add(double a, double b = 0) {
    return fabs(a + b) < eps * (fabs(a) + fabs(b)) ? 0 : a + b;
}
inline int dcmp(double d) {
    if(fabs(d) < eps) return 0;
    return d > 0 ? 1 : -1;
}
struct Point;
typedef Point Vector;
struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }

    Vector operator + (const Vector& rhs) const {   return Vector(add(x, rhs.x), add(y, rhs.y)); }
    Vector operator - (const Vector& rhs) const {   return Vector(add(x, -rhs.x), add(y, -rhs.y)); }
    Vector operator * (const double& rhs) const {   return Vector(rhs * x, rhs * y);}


    double dot(const Vector& rhs) const {  return add(x * rhs.x, y * rhs.y);}
    double det(const Vector& rhs) const {  return add(x * rhs.y, -y * rhs.x);}

    bool operator < (const Point& rhs) const {
        if(!dcmp(x - rhs.x)) return dcmp(y - rhs.y) == -1;
        return dcmp(x - rhs.x) == -1;

    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void write() {
        printf(" %.12f %.12f", x, y);
    }
};

bool on_seg(Point s, Point t, Point p) {
    return dcmp((s - p).det(t - p)) == 0 && dcmp((s - p).dot(t - p)) <= 0;
}

Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

vector<Point> convex_hull(Point* Pnt, int n) {
    sort(Pnt, Pnt + n);
    vector<Point> v(n * 2);
    int k = 0;
    for(int i = 0; i < n; ++i) {
        while(k > 1 && dcmp((Pnt[i] - v[k - 1]).det(v[k - 2] - v[k - 1])) <= 0) k--;
        v[k++] = Pnt[i];
    }
    for(int i = n - 1, t = k; i >= 0; --i) {
        while(k > t && dcmp((Pnt[i] - v[k - 1]).det(v[k - 2] - v[k - 1])) <= 0) k--;
        v[k++] = Pnt[i];
    }
    v.resize(k - 1);
    return v;
}

Point A[100];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 4; ++i) A[i].read();


        bool ok = false;

        for(int i = 0; i < 4 && !ok; ++i) {
            for(int j = 0; j < 4 && !ok; ++j) {
                for(int k = 0; k < 4 && !ok; ++k) {
                    if(i == j || j == k || i == k) continue;
                    if(on_seg(A[i], A[j], A[k])) {
                        ok = true;
                        printf("YES");
                        A[i].write();
                        A[j].write();
                        A[6 - i - j - k].write();
                        puts("");
                    }
                }
            }
        }
        if(ok) continue;

        auto ps = convex_hull(A, 4);
        if(ps.size() != 4) {
            puts("NO");
            continue;
        }

        //pp
        Vector AB = ps[0] - ps[(0 + 1) % 4];
        Vector CD = ps[(0 + 2) % 4] - ps[(0 + 3) % 4];
        Vector BC = ps[(0 + 1) % 4] - ps[(0 + 2) % 4];
        Vector AD = ps[0] - ps[(0 + 3) % 4];
        if(dcmp(AB.det(CD)) == 0 && dcmp(BC.det(AD)) == 0) {
            ok = true;
            printf("YES");
            ps[1].write();
            (ps[0] * 2 - ps[1]).write();
            (ps[2] * 2 - ps[1]).write();
            puts("");
        }
        if(ok) continue;

        //2 2
        for(int s = 2; s < 1 << 4 && !ok; ++s) {
            vector<Point> as, bs;
            for(int i = 0; i < 4; ++i) {
                if(s >> i & 1) {
                    as.push_back(ps[i]);
                } else bs.push_back(ps[i]);
            }
            if(as.size() != 2) continue;

            Point o = intersection(as[0], as[1], bs[0], bs[1]);
//            o.write(); puts("");
            vector<Point> v = {o};
            for(int i = 0; i < 2 && !ok; ++i) {
                v.push_back(as[i]);
                for(int j = 0; j < 2 && !ok; ++j) {
                    v.push_back(bs[j]);
//                    v[0].write();
//                        v[1].write();
//                        v[2].write();
//                        puts("");
                    bool valid = true;
                    for(int k = 0; k < 4 && valid; ++k) {
                        valid &= on_seg(v[0], v[1], ps[k]) ||
                                 on_seg(v[1], v[2], ps[k]) ||
                                 on_seg(v[2], v[0], ps[k]);
                    }
                    if(valid) {
                        ok = true;
                        printf("YES");
                        v[0].write();
                        v[1].write();
                        v[2].write();
                        puts("");
                    }

                    v.pop_back();
                }
                v.pop_back();
            }
        }
        assert(ok);
    }

    return 0;
}
