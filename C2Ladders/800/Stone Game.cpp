#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() 
{
    int n;
    cin >> n;
    int maior, menor, indMaior, indMenor;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == 1) {
            maior = x;
            menor = x;
            indMaior = i;
            indMenor = i;
            continue;
        }
        if (maior < x) {
            maior = x;
            indMaior = i;
        }
        if (menor > x) {
            menor = x;
            indMenor = i;
        }
    }

    int ans = max(indMaior, indMenor);

    ans = min(ans, n-min(indMaior, indMenor)+1);
    ans = min(ans, min(indMaior, indMenor) + n-max(indMaior, indMenor)+1);
    cout << ans << endl;
}

signed main() 
{
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}