#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=23,j,path=-1,count;
    //cin>>n;
    int a[]={4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21};
    //int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    /*
	for(int i=0;i<n;i++)
        cin>>a[i];
    */
	for(int i=0;i<n;i++){   
		j=i;
		for(int k=0;k<n;k++)
			cout<<a[k]<<":";
		cout<<endl;
        count=0;
        while(true)
        {   
            cout<<j<<"::"<<a[j]<<":::"<<endl;
			count++;
            if(a[j]==-1)
                break;
            else if(i==a[j]){
                if(count>path)
                	path=count;
                break;
            }
            else{   
				int temp=j;
                j=a[j];
                a[temp]=-1;                 
            }
        }
        cout<<endl<<i<<"-"<<count<<endl;
 	}
    cout<<"my path: "<<path<<endl;
}
/*
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
{4,4,1,4,13,8,8,8,0,8,14,9,15,11,-1,10,15,22,22,22,22,22,21}
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}
*/
