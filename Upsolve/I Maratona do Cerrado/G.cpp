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
    int L; cin >> L;
    int i = 0;
    map<string, pii> mp;

    while (L--) {
        string op; cin >> op;
        if (op == "CHEGA") {
            string nome; cin >> nome;
            int F; cin >> F;
            mp[nome] = {F, i};
            i++;
        } else if (op == "FOME") {
            string nome; cin >> nome;
            int X; cin >> X;
            mp[nome].first += X;
        } else if (op == "SAI") {
            string nome; cin >> nome;
            mp.erase(nome);
        } else {
            int ind, maior = 0;
            string nome;
            for (auto e: mp) {
                if (e.second.first > maior) {
                    maior = e.second.first;
                    ind = e.second.second;
                    nome = e.first;
                } else if (e.second.first == maior) {
                    if (ind > e.second.second) {
                        maior = e.second.first;
                        ind = e.second.second;
                        nome = e.first;
                    }
                }
            }
            mp.erase(nome);
            cout << nome << endl;
        }
    }


    return 0;
}