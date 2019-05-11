#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int A[n1],B[n2];
	for(int i=0;i<n1;i++)
		cin>>A[i];
	for(int i=0;i<n2;i++)
		cin>>B[i];
	int C;
	cin>>C;

	int l = 0,r=n2-1;
    int min = INT_MAX;
    int ai=INT_MAX,aj=INT_MAX;
    vector<pair<int,int> > pos;
    while(l<n1 && r>=0)
    {
        int sum = (A[l]+B[r]-C);
        cout<<sum<<"\n";
        if(abs(sum)<=min)
        {
            min = abs(sum);
            pos.push_back({A[l],B[r]});
            if(l<=ai && r<=aj)
            {
            	 ai = l;
            	aj = r;
            }
           
            cout<<":"<<A[l]<<" "<<B[r]<<endl;
            
        }
        if(sum>=0)
        {
            r--;
        }
        else l++;
    }
    
    vector<int> v;
    v.push_back(A[ai]);
    v.push_back(B[aj]);
    // return v;
    cout<<v[0]<<"  "<<v[1]<<endl;

}