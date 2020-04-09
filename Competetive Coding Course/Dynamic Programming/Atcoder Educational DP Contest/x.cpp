
// Problem X - Educational Dynamic Programming Contest - AtCoder
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> trinca;
typedef long long ll;

const int MAXW = 2*1e4 + 10;

vector<trinca> guloso;
ll dp[MAXW];
int N;

int main(){

	cin >> N;
	for(int i = 1;i<=N;i++){
		int w,s,v;
		cin >> w >> s >> v;
		guloso.push_back(make_tuple(s+w,w,v));
	}

	sort(guloso.begin(),guloso.end());

	for(trinca davez : guloso){
		int solid = get<0>(davez), w = get<1>(davez);
		ll v = get<2>(davez);
		for(int i = MAXW-1;i>=0;i--){
			if(i + w <= solid){
				dp[i+w] = max(dp[i+w],dp[i] + v);
			}
		}
	}

	ll best = 0;
	for(int i = 0;i<MAXW;i++) best = max(best,dp[i]);
	cout << best << endl;

	return 0;

}