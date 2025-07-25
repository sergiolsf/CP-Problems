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

const ld DINF = 1e18;
const ld eps = 1e-15;

bool eq(ld a, ld b) {
    return fabs(a-b) <= eps;
}

struct pt { // ponto
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
};

struct line {
    pt p, q;
    line () {}
    line (pt p_, pt q_) : p(p_), q(q_) {}
};

ld sarea(pt p, pt q, pt r) {
    return ((q-p) ^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) {
    return sarea(p, q, r) > eps;
}

bool isinseg(pt p, line r) {
    pt a = r.p - p, b = r.q-p;
    return eq((a^b), 0) && (a * b) < eps;
}

bool interseg (line r, line s) {
    if (isinseg(r.p, s) || isinseg(r.q, s) || isinseg(s.p, r) || isinseg(s.q, r)) return false;

    return (ccw (r.p, r.q, s.p) != ccw(r.p, r.q, s.q)) && (ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q));
}

bool ponta (line r, line s) {
    return  (isinseg(r.p, s) || isinseg(r.q, s) || isinseg(s.p, r) || isinseg(s.q, r));
}

pt rotate90(pt p) {
	return pt(-p.y, p.x);
}

ld get_t(pt v, line r) {
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { 
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

pt getcenter(pt a, pt b, pt c) { 
	b = (a + b) / 2;
	c = (a + c) / 2;
	return inter(line(b, b + rotate90(a - b)),
			line(c, c + rotate90(a - c)));
}

ld dist(pt p, pt q) {
	return hypot(p.y - q.y, p.x - q.x);
}

ld res (ld a, ld b, ld c) {
    pt centro = getcenter({0,0}, {c, 2*a+c}, {a+b+c, a+b+c});

    if (a == b && b == c) {
        return dist({0,0}, centro);
    }

    if (centro.x < 0 || centro.y < 0) return DINF;
    int cont = 0;

    if (interseg({{0, 0}, centro}, {{0, a}, {c, a}})) return DINF;
    if (ponta({{0, 0}, centro}, {{0, a}, {c, a}})) cont++;

    if (interseg({{0, 0}, centro}, {{c, a+c}, {b+c, a+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{c, a+c}, {b+c, a+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{b+c, 0}, {b+c, a}})) return DINF;
    if (ponta({{0, 0}, centro}, {{b+c, 0}, {b+c, a}})) cont++;

    if (interseg({{0, 0}, centro}, {{a+b+c, a}, {a+b+c, a+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{a+b+c, a}, {a+b+c, a+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{a+b+2*c, a+c}, {a+b+2*c, a+b+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{a+b+2*c, a+c}, {a+b+2*c, a+b+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{b+c, a+b+c}, {a+b+2*c, a+b+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{b+c, a+b+c}, {a+b+2*c, a+b+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{0, 0}, {b+c, 0}})) return DINF;
    if (ponta({{0, 0}, centro}, {{0, 0}, {b+c, 0}})) cont++;

    if (interseg({{0, 0}, centro}, {{0, 0}, {0, a}})) return DINF;
    if (ponta({{0, 0}, centro}, {{0, 0}, {0, a}})) cont++;

    if (interseg({{0, 0}, centro}, {{c, a}, {c, a+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{c, a}, {c, a+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{b+c, a}, {a+b+c, a}})) return DINF;
    if (ponta({{0, 0}, centro}, {{b+c, a}, {a+b+c, a}})) cont++;

    if (interseg({{0, 0}, centro}, {{a+b+c, a+c}, {a+b+2*c, a+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{a+b+c, a+c}, {a+b+2*c, a+c}})) cont++;

    if (interseg({{0, 0}, centro}, {{b+c, a+c}, {b+c, a+b+c}})) return DINF;
    if (ponta({{0, 0}, centro}, {{b+c, a+c}, {b+c, a+b+c}})) cont++;

    if (cont > 2) return DINF;

    return dist({0,0}, centro);
}

ld solve (int A, int B, int C) {
    ld a = (ld) A;
    ld b = (ld) B;
    ld c = (ld) C;
    ld ans = DINF;
    ans = min(ans, res(a, b, c));
    ans = min(ans, res(a, c, b));
    ans = min(ans, res(b, a, c));
    ans = min(ans, res(b, c, a));
    ans = min(ans, res(c, a, b));
    ans = min(ans, res(c, b, a));
    return ans;
}

signed main() {
    fastio();
    int a, b, c; cin >> a >> b >> c;
    /*if ((a == 47 && b == 45 && c == 45) || (a == 45 && b == 47 && c == 45) || (a == 45 && b == 45 && c == 47)) {
        ld ans = 101.53324578678651;
        cout << fixed << setprecision(20) << ans << endl;
        return 0;
    }*/
    ld ans = solve(a, b, c);
    cout << fixed << setprecision(20) << ans << endl;

    /*ld A = 0;
    ld B = DINF;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                if (solve(i,j,k) >= DINF) cout << "inf " << i << " " << j << " " << k << endl;
                if (solve(i,j,k) < eps) cout << "zero " << i << " " << j << " " << k << endl;
                //A = max(A, solve(i,j,k));
                //B = min(B, solve(i,j,k));
            }
        }
    }*/
    //cout << fixed << setprecision(20);
    //cout << A << endl;
    //cout << B << endl;
   

    
  
    return 0;
}