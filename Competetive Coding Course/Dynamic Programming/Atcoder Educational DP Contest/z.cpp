// Ivan Carvalho
// Problem Z - Educational Dynamic Programming Contest - AtCoder
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2*1e5 + 10;

struct line{

	ll a,b;

	line(ll _a,ll _b){
		a = _a;
		b = _b;
	}

	ll get(ll x){return a*x + b;}

	ld get(ld x){return a*x + b;}

};

ld inter(line l1,line l2){

	return -(l1.b - l2.b)/ld(l1.a - l2.a);

}

bool useless(line l1,line l2,line l3){
	return inter(l1,l3) < inter(l2,l1);
}

vector<line> CHT;
ll dp[MAXN],h[MAXN],C;
int chtPtr,N;

void add(line l){

	while(CHT.size() >= 2 && useless(CHT[CHT.size()-2],CHT.back(),l) ){
		CHT.pop_back();
	}

	CHT.push_back(l);

}

ll query(ll x){

	if(chtPtr >= CHT.size()) chtPtr = CHT.size() - 1;

	while(chtPtr + 1 < CHT.size() && CHT[chtPtr].get(x) > CHT[chtPtr+1].get(x) ){
		chtPtr++;
	}

	return CHT[chtPtr].get(x);

}

int main(){

	scanf("%d %lld",&N,&C);

	for(int i = 1;i<=N;i++){
		scanf("%lld",&h[i]);
	}

	add(line(-2*h[1], h[1]*h[1] + C ));

	for(int i = 2;i<=N;i++){

		dp[i] = query(h[i]) + h[i]*h[i];
		add(line(-2*h[i], h[i]*h[i] + dp[i] + C ));

	}

	printf("%lld\n",dp[N]);

	return 0;

}