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

const int MAX_N = 10;

int n; 
vector<pii> airplane(MAX_N);
vi ordem;

bool possible (double x) {
    double ant = (double) airplane[ordem[0]].first;
    for (int i = 1; i < n; i++) {
        if (ant + x > (double) airplane[ordem[i]].second) return false;
        ant = max(ant+x, (double) airplane[ordem[i]].first);
    }
    return true;
}

void solve() {
    ordem.clear();
    for (int i = 1; i <= n; i++) {
        ordem.push_back(i);
        cin >> airplane[i].first >> airplane[i].second;
    }

    double ans = 0.0;

    do {
        double lo = 0.0, hi = 1441.0; // lo >= e hi >
        for (int i = 1; i < 50; i++) {
            double m = (hi+lo)/2.0;
            if (possible(m)) lo = m;
            else hi = m;
        }

        ans = max(ans, lo);
    } while (next_permutation(all(ordem)));

    // transforma ans para minutos: segundos
    int minutos = (int) ans;
    double seg = ans*60.0 - (double) minutos*60.0;
    int segundos = (int) seg;

    if ((double) (segundos+1) - seg < seg - (double) segundos) segundos++;
    if (segundos == 60) {
        segundos = 0;
        minutos++;
    }

    cout << minutos << ":";
    if (segundos < 10) cout << "0" << segundos;
    else cout << segundos;
    cout << endl;
    
}

signed main() {
    fastio();
    int caso = 0;
    cin >> n;
    while (n) {
        ++caso;
        cout << "Case " << caso << ": ";
        solve();
        cin >> n;
    }
  
    return 0;
}