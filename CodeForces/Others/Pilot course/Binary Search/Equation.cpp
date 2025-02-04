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

double c;

bool f(double x) {
    return x*x + sqrt(x) >= c;
}

signed main() {
    fastio();
    
    cin >> c;

    double l = 0;
    double r = 1e10;

    for (int i = 0; i < 100; i++) {
        double m = (l+r)/2;
        if (f(m)) r = m;
        else l = m;
    }  

    cout << setprecision(20) << r << endl;

    return 0;
}