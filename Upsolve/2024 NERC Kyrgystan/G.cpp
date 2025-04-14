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

signed main() {
    fastio();
    int Sp, Sm; cin >> Sp >> Sm;
    int Dp, Dm; cin >> Dp >> Dm;
    int Tp, Tm; cin >> Tp >> Tm;
    int E; cin >> E;

    int d1 = (E-Sp)%(Dp) > 0 ? 1 : 0;
    int d2 = (E-Sm)%(Dm) > 0 ? 1 : 0;
    int Kp = max(0LL, (E-Sp)/(Dp) + d1);
    int Km = max(0LL, (E-Sm)/(Dm) + d2);

    int dias = max(Kp, Km);

    cout << dias << endl;

    int minutos = 0;
    if (Kp == dias) {
        minutos += dias*4*Tp;
        int d = (2*E-2*Sm-Dm*dias)%(Dm) > 0 ? 1 : 0;
        int y = max(0LL, (2*E-2*Sm-Dm*dias)/(Dm) + d);
        if (Sm + Dm*((dias-y)/2) + Dm*y < E) y++;
        minutos += y*4*Tm + (dias-y)*Tm;
    } else {
        minutos += dias*4*Tm;
        int d = (2*E-2*Sp-Dp*dias)%(Dp) > 0 ? 1 : 0;
        int y = max(0LL, (2*E-2*Sp-Dp*dias)/(Dp) + d);
        if (Sp + Dp*((dias-y)/2) + Dp*y < E) y++;
        minutos += y*4*Tp + (dias-y)*Tp;
    }

    cout << minutos << endl;
  
    return 0;
}