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

const int INF = 1'000'000'000'000'000'000;

signed main() {
    fastio();
    int f; cin >> f;
    while (f != 0) {
        vi C(f);
        int sum = 0, menor = INF;
        for (auto &e: C) {
            cin >> e;
            sum += e;
            menor = min(menor, e);
        }
        int g = 0;
        for (int i = 1; i < f; i++) {
            g = __gcd(g, abs(C[i]-C[0]));
        }

        int ans = 0;
        for (int t = f; t*t <= sum && t < menor && (g == 0 || (g > 0 && t <= g)); t += f) {
            cout << t <<  " ";
            if (g%t != 0) continue;

            int vmenor = menor%t;
            if (vmenor == 0) vmenor += t;

            int vmaior = menor-t;
        
            if (vmenor <= vmaior) ans += (vmaior-vmenor+t)/t;
            cout << vmenor << " " << vmaior << endl;
        }


        cout << ans << endl;
        cin >> f;
    }
  
    return 0;
}