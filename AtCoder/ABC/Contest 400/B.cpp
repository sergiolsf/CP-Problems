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

const int MAXIMO = 1'000'000'000;

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    int sum = 0; 
    int pot = 1;
    for (int i = 0; i <= m; i++) {
        sum += pot;
        pot *= n;
        if (sum > MAXIMO) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << sum << endl;
  
    return 0;
}