/*
1. 平行向量叉积为0的性质 可以用来判断点是否在直线上
2. 点积的符号 可以用来判断点与线段的位置关系  角度等等
3. 叉积的大小可以用于计算距离等等


Attetion: 以下属于各种问题的特殊情况
1. 多条直线/线段交于同一个点
2. 重合
3. 凸包退化成点或者线段
4. 输出-0.00 
*/



#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cctype>
#include <cmath>
#include <vector>
#include <sstream>
#include <bitset>
#include <deque>
#include <iomanip>
using namespace std;
#define pr(x) cout << #x << " = " << x << endl;
#define bug cout << "bugbug" << endl;
#define ppr(x, y) printf("(%d, %d)\n", x, y);
#define pdr(x, y) printf("(%.3f, %.3f)\n", x, y);
#define pfun(a, b) printf("x = %d   f(x) = %d\n", a, b);

typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 4;
const int maxm = 1e4 + 4;
inline double add(double a, double b = 0){
	return fabs(a + b) < eps * (fabs(a) + fabs(b)) ? 0 : a + b;
}
inline int dcmp(double d){
	if (fabs(d) < eps) return 0;
	return d > 0 ? 1 : -1;
}
struct Point;
typedef Point Vector;
typedef vector<Point> Polygon;
struct Point{
	double x, y;
	Point(double _x = 0, double _y = 0):x(_x), y(_y){
	}

	//Point相减显然可以得到Vector
	Vector operator + (const Vector &rhs) const {	return Vector(add(x, rhs.x), add(y, rhs.y)); }
	Vector operator - (const Vector &rhs) const {	return Vector(add(x, -rhs.x), add(y, -rhs.y)); }
	Vector operator * (const double &rhs) const {	return Vector(rhs * x, rhs * y);}


	void operator += (const Vector &rhs) {	*this = *this + rhs; }
	void operator -= (const Vector &rhs) {	*this = *this - rhs; }
	void operator *= (const double &rhs) {	*this = *this * rhs; }


	double dot (const Vector &rhs) const {	return add(x * rhs.x, y * rhs.y);}
	double det (const Vector &rhs) const {	return add(x * rhs.y, -y * rhs.x);}

	bool operator < (const Point& rhs) const{
		if (!dcmp(x-rhs.x)) return dcmp(y-rhs.y) == -1;
		return dcmp(x-rhs.x) == -1;

	}

	bool operator == (const Point& rhs) const{	return dcmp(x-rhs.x) == 0 && dcmp(y-rhs.y) == 0; }


	double length() {	return sqrt(dot(*this));}

	//逆时针旋转
	Vector rotate(double rad) {	return Vector(add(x * cos(rad), -y * sin(rad)), add(x * sin(rad), y * cos(rad))); }
	void print() {	pdr(x, y); }
	void read(){
		scanf("%lf%lf", &x, &y);
	}
};
const Point O = Point{0, 0};

Vector MakeVector(double angle, double len){
	// MakeVector(angle, len) 的反向向量是  MakeVector(angle+pi, len) 或者 MakeVector(angle, -len) 
	return Point{add(cos(angle) * len), add(sin(angle) * len)};
}
bool on_seg(Point s, Point t, Point p){
	return dcmp((s-p).det(t-p)) == 0 && dcmp((s-p).dot(t-p)) <= 0;
	//此处有没有等于 就是含不含端点
}

//求直线的交点
Point intersection(Point p1, Point p2, Point q1, Point q2){//p1p2 与  q1q2不能是平行的
	return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

struct Triangle{
	Point p[3];
	Vector d;
	void read(){
		for (int i = 0; i < 3; ++i) 
			p[i].read();
		d.read();
	}
}A, B; 
bool judge(Point s, Point d, Point p, Point q){
	if (d == O){
		return on_seg(p, q, s);
	}
	Point t = s+d;
	if (dcmp((t-s).det(p-q)) == 0) return false;
	Point inter = intersection(s, t, p, q);
	if (on_seg(p, q, inter) && dcmp((t-s).dot(inter-s)) >= 0){
//		s.print();
//		d.print();
//		p.print();
//		q.print();
		return true;
	} 
	return false;
}
int in_polygon(Point P, Polygon& poly){
	/*
		判断点是否在多边形内 (可以是凹多边形， 可以自交的多边形)
		返回值为-1表示点在多边形的边上， 1表示在多边形内部， 0表示在多边形的外部
		poly内的点可以是逆时针排序的
		如果多边形是凸多边形的话， 可以简化为判断点是不是在所有边的左边(要求逆时针) 
	*/ 
	int wn = 0; // winding number
	int n = poly.size();
	for (int i = 0; i < n; ++i){
		if (on_seg(poly[i], poly[(i+1) % n], P)) return -1;
		int k = dcmp((poly[(i+1) % n] - poly[i]).det(P - poly[i]));
		int d1 = dcmp(poly[i].y - P.y);
		int d2 = dcmp(poly[(i+1)%n].y - P.y);
		if (k > 0 && d1 <= 0 && d2 > 0) wn++;//注意此处的 = 取不取的到 
		if (k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	if (wn) return 1;
	return 0;
}
vector<Point> convex_hull(vector<Point>& Pnt, int n){
	sort(Pnt.begin(), Pnt.begin()+n);
	vector<Point> v(n*2);
	int k = 0;
	for (int i = 0; i < n; ++i){
		while(k > 1 && dcmp((Pnt[i] - v[k-1]).det(v[k-2] - v[k-1])) <= 0) k--;
		v[k++] = Pnt[i];
	}
	for (int i = n - 1, t = k; i >= 0; --i){
		while(k > t && dcmp((Pnt[i] - v[k-1]).det(v[k-2] - v[k-1])) <= 0) k--;
		v[k++] = Pnt[i];
	}
	v.resize(k - 1);
	return v;
}


double sA, sB;
double judge(Triangle A, Triangle B){
    vector<Point> vs, pA, pB;
    for(int i = 0; i < 3; ++i) pA.push_back(A.p[i]);
    for(int i = 0; i < 3; ++i) pB.push_back(B.p[i]);
    for(int i = 0; i < 3; ++i) if(in_polygon(pA[i], pB)) vs.push_back(pA[i]);
    for(int i = 0; i < 3; ++i) if(in_polygon(pB[i], pA)) vs.push_back(pB[i]);
    puts("...");
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (dcmp((A.p[i] - A.p[(i+1)%3]).det(B.p[j] - B.p[(j+1)%3]))){
				Point tmp = intersection(A.p[i], A.p[(i+1)%3], B.p[j], B.p[(j+1)%3]);
				if (on_seg(A.p[i], A.p[(i+1)%3], tmp) && on_seg(B.p[j], B.p[(j+1)%3], tmp))
                    vs.push_back(tmp);
			}
		}
	}
    auto ch = convex_hull(vs, vs.size()); 
    if(ch.size() < 3) return 0;

    double sum = sA + sB;
    for(size_t i = 1; i < ch.size() - 1; ++i) {
        sum -= (ch[i] - ch[0]).det(ch[i + 1] - ch[0]); 
    }
	return sum;
}

double calc(double x) {
    Triangle AA = A, BB = B;
    for(int i = 0; i < 3; ++i) {
        AA.p[i] += AA.d * x;
        BB.p[i] += BB.d * x;
    }
    return judge(AA, BB);
}

int main(){
//必须编译过才能交
//	ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif

    int t; scanf("%d", &t);
    while(t--) {
        A.read();
        B.read();

        sA = sB = 0;
        sA += (A.p[1] - A.p[0]).det(A.p[2] - A.p[0]);
        sB += (B.p[1] - B.p[0]).det(B.p[2] - B.p[0]);
        printf("calc = %f\n", calc(0));
        printf("sA = %.f sB = %f\n", sA, sB);
        
        double l = 0, r = 1e18;
        for(int i = 0; i < 100; ++i) {
            double ll = (2 * l + r) / 3;
            double rr = (l + 2 * r) / 3;
            if(calc(ll) > calc(rr)) l = ll;
            else r = rr;
        }
        static int kase = 0;
        printf("l = %.f zrea = %.f\n", l, calc(l));
        bool ok = dcmp(calc(l));
		printf("Case #%d: %s\n", ++kase, ok ? "YES" : "NO");
	}
	return 0;
}
/*
3
1 1 2 1 1 2   0 2 
3 0 3 -1 2 -1    0 3


0 0 5 0 5 5     0 0
1 -1 1 4 6 4     0 0


*/
