#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const ld eps = 1e-9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { 
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld dist(pt p, pt q) { 
	return hypot(p.y - q.y, p.x - q.x);
}

pt rotate90(pt p) { 
	return pt(-p.y, p.x);
}

int n;
vector<pair<pt, ld>> circ;

vector<pair<pt, int>> circ_inter(pt a, pt b, ld r, ld R) {
    vector<pair<pt, int>> ret;
    ld d = dist(a, b);
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    ld x = (d*d-R*R+r*r)/(2*d);
    ld y = sqrt(r*r-x*x);
    pt v = (b-a)/d;
    ret.push_back({a+v*x + rotate90(v)*y, +1});
    if (y > 0) ret.push_back({a+v*x - rotate90(v)*y, -1});
    else ret.push_back({a+v*x + rotate90(v)*y, -1});
    return ret;
}

pt center;
bool cmp(pair<pt, int> a, pair<pt, int> b) {
    if (a.first == b.first) return a.second > b.second;
    
    pt vecA = a.first - center; 
    pt vecB = b.first - center; 

    auto quadrant = [](const pt& v) {
        if (v.y < 0) return 1;
        if (v.y == 0 && v.x < 0) return 1;
        return 0; 
    };

    int qA = quadrant(vecA);
    int qB = quadrant(vecB);
    
    if (qA != qB) return qA < qB;
    
    double cross = vecA.x * vecB.y - vecA.y * vecB.x;
    if (cross > 0) return true;  
    if (cross < 0) return false; 
    return a.second > b.second; 
}

// Existe uma interseção em comum quando 
// todos os circulos tem raio r+t?
bool inter (double t) {
    vector<pair<pt, int>> ret;
    pt a = center = circ[0].first;
    ld r = circ[0].second;
    for (int i = 1; i < n; i++) {
        pt b = circ[i].first;
        ld R = circ[i].second;
        vector<pair<pt, int>> ret2 = circ_inter(a, b, r+t, R+t);
        if (ret2.size() == 0) return false;
        ret.push_back(ret2[0]);
        ret.push_back(ret2[1]);
    }

    sort(ret.begin(), ret.end(), cmp);
    int cont = 0;
    for (auto [a, b]: ret) {
        cont += b;
        if (cont == n-1 || cont == -(n-1)) return true;
    }
    return false;
}

signed main() {
    fastio();
    cin >> n;
    for (int i = 0; i < n; i++) {
        pt p; cin >> p.x >> p.y;
        ld r; cin >> r;
        circ.push_back({p, r});
    }

    double lo = 0.0, hi = 10000.0;
    for (int i = 0; i < 100; i++) {
        double m = (lo+hi)/2.0;
        if (inter(m)) hi = m;
        else lo = m;
    }

    cout << fixed << setprecision(20) << hi << endl;
  
    return 0;
}