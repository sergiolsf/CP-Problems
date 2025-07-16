#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end();
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
const int MOD = 1e9+7;
const int INF = 1e18;
const double EPS = 1e-6;

struct point {
    int x, y;
    point() {x = y = 0;}
};

struct vec {
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {
    return vec(b.x-a.x, b.y-a.y);
}

int cross (vec a, vec b) {
    return a.x*b.y - a.y*b.x;
}

bool collinear (pair<int,int> p1, pair<int,int> p2, pair<int,int> p3) {
    point p,q,r;
    p.x = p1.F; p.y = p1.S;
    q.x = p2.F; q.y = p2.S;
    r.x = p3.F; r.y = p3.S;
    return abs(cross(toVec(p,q), toVec(p,r))) == 0;
}

bool insideCircle (pair<int,int> p, pair<double, double> c, double r) {
    double dx = (double) p.F - c.F, dy = (double) p.S - c.S;
    double Euc = dx*dx + dy*dy, rSq = r*r;
    if (fabs(Euc-rSq) < EPS) return true;
    return false;
}

double dist(pair<int,int> P1, pair<int,int> P2) {
    return sqrt((double) ((P1.F-P2.F)*(P1.F-P2.F) + (P1.S-P2.S)*(P1.S-P2.S)));
}

bool circle2PtsRad(pair<int,int> p1, pair<int,int> p2, double r, pair<double, double> &c) {
    double d2 = (double) ((p1.F-p2.F)*(p1.F-p2.F) + (p1.S-p2.S) * (p1.S-p2.S));
    double det = r*r/d2 - 0.25;
    if (det < EPS) return false;
    double h = sqrt(det);
    c.F = ((double) (p1.F+p2.F))*(0.5) + ((double) (p1.S-p2.S))*(h);
    c.S = ((double) (p1.S+p2.S))*(0.5) + ((double) (p2.F-p1.F))*(h);
    return true;
}

signed main() {
    fastio();
    int N;

    cin >> N;
    while (N != 0) {
        vector<pair<int,int>> pontos(N+1);
        for (int i = 0; i < N; i++) {
            cin >> pontos[i].F >> pontos[i].S;
        }

        int ans = N >= 2 ? 2 : 1;
        for (int i = 0; i < N-2; i++) {
            for (int j = i + 1; j < N-1; j++) {
                for (int k = j +  1; k < N; k++) {
                    if(collinear(pontos[i],pontos[j],pontos[k])) continue;


                    int x1 = pontos[j].F - pontos[i].F, y1 = pontos[j].S - pontos[i].S;
                    int x2 = pontos[k].F - pontos[i].F, y2 = pontos[k].S - pontos[i].S;
                    /// ache o centro do circulo (c)
                    double r;
                    pair<double,double> c;
                    double L1 = dist(pontos[i], pontos[j]);
                    double L2 = dist(pontos[i], pontos[k]);
                    double L3 = dist(pontos[j], pontos[k]);
                    int A = abs(x1*y2 - x2*y1);
                    r = (L1*L2*L3)/(2*(double)A);

                    vector<pair<double, double>> C1;
                    pair<double,double> c1;
                    if (circle2PtsRad(pontos[i], pontos[j], r, c1)) C1.push_back(c1);
                    if (circle2PtsRad(pontos[j], pontos[i], r, c1)) C1.push_back(c1);

                    vector<pair<double, double>> C2;
                    pair<double,double> c2;
                    if (circle2PtsRad(pontos[j], pontos[k], r, c2)) C2.push_back(c2);
                    if (circle2PtsRad(pontos[k], pontos[j], r, c2)) C2.push_back(c2);

                    bool flag = false;
                    for (auto & f : C1) {
                        for (auto & g : C2) {
                            if(fabs(f.F - g.F) < EPS && fabs(f.S - g.S) < EPS){
                                flag = true;
                                c = f;
                            }
                        }
                    }

                    if(!flag) continue;
                    int cont = 3;

                    for (int a = 0; a < N; a++) {
                        if (a == i || a == j || a == k) continue;
                        if ( insideCircle(pontos[a], c, r) ) cont++;
                    }

                    ans = max(ans, cont);
                }
            }
        }

        cout << ans << endl;
        cin >> N;
    }

    return 0;
}