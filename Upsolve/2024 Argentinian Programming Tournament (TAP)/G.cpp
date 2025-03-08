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
    string s; cin >> s;

    int T = 0, P = 0, A = 0, U = 0;
    for (auto c : s) {
        if (c == 'T') T++;
        else if (c == 'P') P++;
        else if (c == 'A') A++;
        else if (c == 'U') U++;
    }

    cout << min({T, P, A+U}) << endl;
  
    return 0;
}