#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		vector<int> x(m-1), y(n-1);
		for(int i=0; i<m-1; i++) cin>>x[i];
		for(int i=0; i<n-1; i++) cin>>y[i];
		
		int sumX = 0, sumY = 0;
		
		for(int i=0; i<m-1; i++) sumX += x[i];
		for(int i=0; i<n-1; i++) sumY += y[i];
		
		int ans1 = sumX + (m-1)*sumY;
		int ans2 = sumY + (n-1)*sumX;
		
		cout << min(ans1, ans2) << endl;
	}
	return 0;
}