#include<bits/stdc++.h>
using namespace std;
int main(){
	bool flag=1;
	int i=0,j;
	string A,B;
	cin>>A>>B;
	for(int i=0;i<A.length()&&flag;i++){
		string C;
		for(int j=i,count=0;count<B.length();j++){
			C+=A[j];
			count++;
		}
		string temp=B;
		sort(temp.begin(),temp.end());
		do{
			if(temp==C)flag=0;
		}while(next_permutation(temp.begin(),temp.end()));
	}
	if(flag)cout<<"False\n";
	else cout<<"True\n";
}
