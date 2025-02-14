#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Ax, Bx, Cx;
int Ay, By, Cy;
int Az, Bz, Cz;

int f(int x, int a, int b, int c) {
    return a*x*x + b*x + c;
}

signed main() {
    fastio();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        Ax += w; Bx -= 2*x*w; Cx += x*x*w;
        Ay += w; By -= 2*y*w; Cy += y*y*w;
        Az += w; Bz -= 2*z*w; Cz += z*z*w;
    }

    int Xv = -Bx/(2*Ax);
    int Yv = -By/(2*Ay);
    int Zv = -Bz/(2*Az);

    if (f(Xv, Ax, Bx, Cx) <= f(Xv+1, Ax, Bx, Cx)) {
        cout << max(Xv, 1LL) << " ";
    } else cout << Xv+1 << " ";

    if (f(Yv, Ay, By, Cy) <= f(Yv+1, Ay, By, Cy)) {
        cout << max(Yv, 1LL) << " ";
    } else cout << Yv+1 << " ";

    if (f(Zv, Az, Bz, Cz) <= f(Zv+1, Az, Bz, Cz)) {
        cout << max(Zv, 1LL) << " ";
    } else cout << Zv+1 << endl;
  
    return 0;
}