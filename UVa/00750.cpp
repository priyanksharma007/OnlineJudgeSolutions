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

class DSU {
public:
	vector<int> root;
	vector<int> size;
	int cc;


	DSU(int n) {
		root = vector<int>(n);
		size = vector<int>(n, 1);
		iota(all(root), 0);
		cc = n;
	}

	int get(int x) { return root[x] == x ? x : x = get(root[x]);};

	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) { return;}

		if (size[x] > size[y]) swap(x, y);
		size[y] += size[x];
		root[x] = y;
		cc--;
	}

	bool sameSet(int x, int y) {
		return get(x) == get(y);
	}
};

unsigned LSOne(int mask) {
	return mask & (-mask);
}


int row[8], a, b, lineCounter;

bool canPlace(int r, int c) {
	for (int prevCol = 0; prevCol < c; prevCol++) {
		int prevRow = row[prevCol];
		if (prevRow == r || abs(prevRow - r) == abs(prevCol - c)) {
			return false;
		}
	}

	return true;
}

void backtrack(int col) {
	// base case
	if ((col == 8) and (row[b] == a)) {
		printf("%2d      %d", lineCounter++, row[0] + 1);
		for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
		printf("\n");
		return;
	}

	for (int r = 0; r < 8; r++) {
		if (col == b and r != a) continue;

		if (canPlace(r, col)) {
			row[col] = r;
			backtrack(col+1);
		}
	}
}

void solve() {
	int tc; scanf("%d", &tc);

	while (tc--) {
		scanf("%d %d", &a, &b); --a; --b; // 0-indexing
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		
		memset(row, 0, sizeof row); lineCounter = 1;
		backtrack(0);
		if (tc) printf("\n");


	}
}

int main() {
	setIO(); 
	// setIO("circlecross"); 
	int t = 1;
	// cin >> t;
	// int k = t;
	while (t--) {
		// cout << "Case #" <<  k - t <<  ":" << endl;;
		solve();
	}

}		