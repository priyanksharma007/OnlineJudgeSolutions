#include<bits/stdc++.h>
// #include "bits/stdc++.h"
using namespace std;
#define ull       unsigned long long
#define SPEEDHACK ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff        first
#define ss        second
#define sz(v)     (ll)(v).size()
#define file      freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define mod             1000000007
// #define mod             998244353 
#define inv 499122177
#define pb push_back
#define all(a) a.begin(), a.end()
const double eps = 1e-2;
#define ll       long long
#define rep(i, c) for(int i = 0; i < (int)c; i++)
#define ri(i) for (auto &i : a) cin >> i
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template<class T> using P = pair<T, T>;
using vi = vector<int>;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
// int dx[] = { 1,0,-1,0,1,1,-1,-1 };
// int dy[] = { 0,1,0,-1,1,-1,1,-1 };
// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[] = {0,1,0,-1,0};

string stepDir = "URDL";


void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int getValue(string card) {
    char value = card[0];
    if (value >= '2' and value <= '9') return value - '0';
    else return 10;
}

void solve() {
    int n;
    cin >> n;
    string line;

    // getline(cin, line);
    getline(cin, line);
    // getline(cin, line);

    for (int i =0 ;i < n; i++) {
        string john, jane;
        cin >> jane >> john;
        // cout << jane << "---" << john << endl;


        reverse(all(jane));
        reverse(all(john));

        string janePile;
        string johnPile;


        bool won = false;


        for (int j = 0; j < 1000 and !won; j++) {
            if (jane.empty() and janePile.empty()) {
                cout << "John wins.\n";
                if (i < n - 1) cout << endl;
                won = true;
                break;
            }

            if (john.empty() and johnPile.empty()) {
                cout << "Jane wins.\n";
                if (i < n - 1) cout << endl;
                won = true;
                break;
            }


            if (jane.empty()) {
                jane = janePile;
                janePile = "";
                reverse(all(jane));
            }

            if (john.empty()) {
                john = johnPile;
                johnPile = "";
                reverse(all(john));
            }

            char janeCard = jane.back();
            jane.pop_back();

            char johnCard = john.back();
            john.pop_back();

            janePile.push_back(janeCard);
            johnPile.push_back(johnCard);

            // cout << "card -> " << janeCard << " " << johnCard << endl;

            if (janeCard == johnCard) {
                if (random()/141%2 == 0) {
                    janePile += johnPile;
                    johnPile = "";
                    string cards(janePile.rbegin(), janePile.rend());
                    cout << "Snap! for Jane: " << cards << endl;;
                } else {
                    johnPile += janePile;
                    janePile = "";
                    string cards(johnPile.rbegin(), johnPile.rend());
                    cout << "Snap! for John: " << cards << endl;;
                }
            }

        }


        if (!won) {
            cout << "Keeps going and going ...\n";
            cout << endl;
        }
        if (i < n - 1) {
            getline(cin, line);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    // int c = 1;

    while (t--) {
        solve();
    }
}













