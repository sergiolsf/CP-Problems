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

vector<pii> poles;
set<int> vertical;
set<pair<pii, pii>> retas; // {aN, aD}, {bN, bD}

signed main() {
    fastio();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        poles.push_back({x, y});
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            auto [x1, y1] = poles[i];
            auto [x2, y2] = poles[j];
            if (x1 == x2) {
                vertical.insert(x1);
                continue;
            }
            int aN = y1-y2, aD = x1-x2; 
            int bN = y2*x1-y1*x2, bD = x1-x2; 

            int g1 = __gcd(aN, aD);
            aN = aN/g1;
            aD = aD/g1;

            int g2 = __gcd(bN, bD);
            bN = bN/g2;
            bD = bD/g2;

            retas.insert({{aN, aD}, {bN, bD}});
        }
    }

    int ans = 0;
    ans += (int) retas.size()* (int) vertical.size();

    vector<pii> retasA;
    for (auto [p1, p2]: retas) {
        retasA.push_back(p1);
    }

    for (int i = 0; i < retasA.size()-1; i++) {
        for (int j = i+1; j < retasA.size(); j++) {
            auto [aN1, aD1] = retasA[i];
            auto [aN2, aD2] = retasA[j];

            if (aN1*aD2 != aN2*aD1) ans++;
        }
    }
    
    cout << ans << endl;
  
    return 0;
}