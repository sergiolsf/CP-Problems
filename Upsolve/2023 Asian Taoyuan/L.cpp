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

const int MOD = 1'000'000'007;
int maxK = 0;

bool hasSubsetSum9(const vi& groups) {
    bitset<10> possible; // Somas até 9
    possible[0] = 1;
    for (int g : groups) {
        if (g == 9) return true;
        bitset<10> temp = possible;
        for (int s = 0; s <= 9; s++) {
            if (possible[s] && s + g <= 9) temp[s + g] = 1;
        }
        possible = temp;
    }
    return possible[9];
}

// Gera partições e testa validade
void backtrack(int N, vi& groups, int start) {
    if (N == 0) {
        if (!hasSubsetSum9(groups)) {
            maxK = max(maxK, (int)groups.size());
        }
        return;
    }
    for (int i = start; i <= N; i++) {
        if (i == 9) continue; // Ignora grupos de tamanho 9
        groups.push_back(i);
        backtrack(N - i, groups, i); // Garante ordem não-decrescente
        groups.pop_back();
    }
}

signed main() {
    fastio();
    int n; cin >> n;
    if (n < 9) cout << n << endl;
    else if (n%2 == 0) cout << (n/2)%MOD << endl;
    else if (n > 29) {
        int maior = (n/2)-4;
        maior = (maior%MOD + MOD)%MOD;
        cout << maior << endl;
    } else {
        vi groups;
        backtrack(n, groups, 1); 
        cout << maxK << endl; // Inicia com grupos >= 1
    }
  
    return 0;
}