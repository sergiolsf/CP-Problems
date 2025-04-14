#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

signed main() {
    fastio();
    int n, m; cin >> n >> m;
    vi a(n+1);
    vi vMaior, vMenor, vIgual;
    int antes = 0, depois = 0, igual = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < m) {
            antes++;
            vMenor.push_back(i);
        } else if (a[i] > m) {
            depois++;
            vMaior.push_back(i);
        } else {
            igual++;
            vIgual.push_back(i);
        }
    }

    igual--;
    while (igual) {
        if (antes < depois) antes++;
        else depois++;
        igual--;
    }

    vi ans;
    while (true) {
        if (antes == depois) break;
        if (antes+1 == depois) break;
        if (antes < depois) {
            depois--;
            if (!vMaior.empty()) {
                ans.push_back(vMaior.back());
                vMaior.pop_back();
            } else {
                ans.push_back(vIgual.back());
                vIgual.pop_back();
            }
        } else {
            antes--;
            if (!vMenor.empty()) {
                ans.push_back(vMenor.back());
                vMenor.pop_back();
            } else {
                ans.push_back(vIgual.back());
                vIgual.pop_back();
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size()-1 ? "\n" : " ");
    }

    return 0;
}