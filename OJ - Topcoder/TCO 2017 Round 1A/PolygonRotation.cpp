#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class PolygonRotation {
#define double long double
    public:
        vector<double> px, py;
        const double EPS = 1e-12;
        int sgn(double x) {return x < -EPS ? -1 : x > EPS;}

        struct Point {
            double x, y;
            Point() {}
            Point(double x, double y) : x(x), y(y) {}
            void see() {
                pr(x); prln(y);
            }
        };

        friend Point operator+(Point A, Point B) {return Point(A.x + B.x, A.y + B.y);}
        friend Point operator-(Point A, Point B) {return Point(A.x - B.x, A.y - B.y);}
        friend Point operator*(Point A, double x) {return Point(A.x * x, A.y * x);}
        double dot(Point A, Point B) {return A.x * B.x + A.y * B.y;}
        double cross(Point A, Point B) {return A.x * B.y - A.y * B.x;}

        Point getLineIntersection(Point P, Point v, Point Q, Point w) {
            Point u = P - Q;
            double t = cross(w, u) / cross(v, w);
            return P + v * t;
        }
        bool onSegment(Point p, Point a1, Point a2) {
            return sgn(cross(a1 - p, a2 - p)) == 0 && sgn(dot(a1 - p, a2 - p)) <= 0;
        }

        double f(double x) {
            Point P = Point(0, x), v = Point(1, 0);
            double mx = 0;
            for(int i = 0; i + 1 < px.size(); ++i) {
                Point Q = Point(px[i], py[i]), Q2 = Point(px[i + 1], py[i + 1]);
                Point w = Q2 - Q;
                if(sgn(cross(v, w)) == 0) continue;
                Point o = getLineIntersection(P, v, Q, w);
                if(onSegment(o, Q, Q2)) {
                    mx = max(mx, o.x * o.x);
                }
            }
            return mx;
        }

        inline double simpson(double l, double r) {
            return (f(l) + 4 * f((l + r) / 2) + f(r)) * (r - l) / 6;
        }

        double asr(double l, double r, double eps, double A) {
            double m = (l + r) / 2;
            double fL = simpson(l, m), fR = simpson(m, r);
            if(abs(fL + fR - A) <= 15 * eps) return fL + fR + (fL + fR - A) / 15;
            return asr(l, m, eps / 2, fL) + asr(m, r, eps / 2, fR);
        }

        double calc(double l, double r) {
            return asr(l, r, EPS, simpson(l, r));
        }

        double getVolume(vector<int> x, vector<int> y) {
            int l = INF, r = -INF;
            for(int i = 0; i < x.size(); ++i) {
                px.push_back(x[i]);
                py.push_back(y[i]);
                l = min(l, y[i]);
                r = max(r, y[i]);
            }
            px.push_back(px[0]);
            py.push_back(py[0]);
            double ans = 0;
            for(int i = l; i < r; ++i) ans += calc(i, i + 1);
            return ans * acos(-1);
        }
#undef double
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x) { return x < 0;}
template<class I, class O> vector<pair<I, O>> getTestCases() {
    return {
        { { {0, 1, 1, 0}, {1, 1, 0, 0} }, {3.141592653589793} },
        { { {0, 1, 0, -1}, {2, 1, 0, 1} }, {2.0943951023931953} },
        { { {0, 3, 0, -2, -2}, {2, 0, -3, -1, 1} }, {49.91641660703782} },
        { { {0, 3, 3, 0, -1, -1}, {2, 2, -2, -2, -1, 1} }, {113.09733552923255} },
        // Your custom test goes here:
        //{ { {}, {}}, {} },
    };
}

//------------------------------------------------------------------------------
// Tester code:
#define DISABLE_COLORS

#include "tester.cpp"
struct input {
    vector<int> p0; vector<int> p1;

    double run(PolygonRotation* x) {
        return x->getVolume(p0, p1);
    }
    void print() {
        //Tester::printArgs(p0,p1);
    }
};

int main() {
    return Tester::runTests<PolygonRotation>(
               getTestCases<input, Tester::output<double>>(), disabledTest,
               1000, 1491065492, CASE_TIME_OUT, Tester::COMPACT_REPORT
           );
}
// CUT end
