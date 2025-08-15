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
    double ans = 0.0;
    string s; cin >> s;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] != 't') continue;
        for (int j = i+1; j < s.size(); j++) {
            if (s[j] != 't') continue;
            int cont = 0;
            for (int k = i+1; k < j; k++) {
                if (s[k] == 't') cont++;
            }
            double rate = (double) cont/ (double) (j-i-1);
            ans = max(ans, rate);
        }
    }

    cout << fixed << setprecision(20) << ans << endl;
  
    return 0;
}