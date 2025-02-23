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

const double PI = 4*atan(1);

signed main() {
    fastio();

    int teta, n;
    cin >> teta >> n;
    vector<pii> person(n);
    for (int i = 0; i < n; i++) {
        int x, h;
        cin >> x >> h;
        person[i] = {x,h};
    }  


    sort(all(person));
    double ang = ((double) teta*PI)/180.0;
    double t = 1.0/(tan(ang));
    double ini = 0, alc = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int x = person[i].first;
        int h = person[i].second;
        if ((double) x > alc) {
            ans += alc-ini;
            ini = (double) x;
        }
        alc = max(alc, (double) x + (double) h * t);
    }
    ans += alc-ini;


    cout << fixed << setprecision(20) << ans << endl;
    
    return 0;
}