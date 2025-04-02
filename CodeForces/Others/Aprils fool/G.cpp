#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const double PI = acos(-1);

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n, k;
    cin >> n >> k;
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    if(k == 1){
        cout << fixed << setprecision(20) << 0.0 << endl;
        return 0;
    }
    
    ld dx = (ld) (x[1] - x[0]);
    ld dy = (ld) (y[1] - y[0]);
    
    ld  l = sqrtl(dx*dx + dy*dy);
    
    vector<ld> p(n);
    ld x0 = (ld) x[0], y0 = (ld) y[0];
    for(int i = 0; i < n; i++){
        ld rx = (ld) x[i] - x0;
        ld ry = (ld) y[i] - y0;
        ld d = rx*dx + ry*dy; 
        p[i] = d / l;
    }
    
    sort(all(p));
    
    ld diametro = numeric_limits<ld>::infinity();
    for (int i = 0; i + k - 1 < n; i++) {
        ld d = p[i + k - 1] - p[i];
        if (d < diametro) diametro = d;
    }
    
    ld r = diametro / 2.0;
    ld area = PI * r * r;
    
    cout << fixed << setprecision(20) << (long double)area << "\n";
    return 0;
}