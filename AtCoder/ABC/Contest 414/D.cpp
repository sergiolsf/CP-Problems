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
    int n; cin >> n;
    while (n--) {
        int maior = -1, menor = 1'000'000'000'000'000'000;
        int r; cin >> r;
        while (r--) {
            int a;  cin >> a;
            maior = max(maior, a);
            menor = min(menor, a);
        }
        cout << maior-menor << endl;
    }
  
    return 0;
}