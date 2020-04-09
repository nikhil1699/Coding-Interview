
// Problem Y - Educational Dynamic Programming Contest - AtCoder
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2*1e5 + 10;
const int MAXK = 3010;
const int MOD = 1e9 + 7;

vector<ii> pontos;
ll fatorial[MAXN],invfatorial[MAXN],qnts[MAXK];
int H,W,N;

ll fast_expo(ll x,int y){
	if(y == 0) return 1;
	if(y & 1) return (x*fast_expo(x,y-1)) % MOD;
	ll temp = fast_expo(x,y/2);
	return (temp*temp) % MOD;
}

ll binomial(ll n,ll k){
	return ((fatorial[n]*invfatorial[k] % MOD)*invfatorial[n - k]) % MOD;
}

int main(){

	fatorial[0] = invfatorial[0] = 1;
	for(int i = 1;i<MAXN;i++){
		fatorial[i] = (fatorial[i-1]*i) % MOD;
		invfatorial[i] = fast_expo(fatorial[i],MOD - 2);
	}

	cin >> H >> W >> N;
	pontos.push_back(ii(H,W));

	for(int i = 0;i<N;i++){
		int x,y;
		cin >> x >> y;
		pontos.push_back(ii(x,y));
	}

	sort(pontos.begin(),pontos.end());

	for(int i = 0;i<=N;i++){
		qnts[i] = binomial(pontos[i].first + pontos[i].second - 2, pontos[i].first - 1 );
	}

	for(int i = 0;i<N;i++){
		for(int j = i+1;j<=N;j++){
			int deltax = pontos[j].first - pontos[i].first;
			int deltay = pontos[j].second - pontos[i].second;
			if(deltax < 0 || deltay < 0) continue;
			qnts[j] -= binomial(deltax+deltay,deltay)*qnts[i];
			qnts[j] %= MOD;
		}
	}

	if(qnts[N] < 0) qnts[N] += MOD;
	cout << qnts[N] << endl;

	return 0;

}