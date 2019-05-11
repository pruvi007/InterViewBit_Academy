#include<bits/stdc++.h>
using namespace std;
vector<int> code;

void gray(int n,int &num)
{
	if(n==0)
	{
		code.push_back(num);
		return ;
	}

	gray(n-1,num);

	num = num ^ (1<<(n-1));
	gray(n-1,num);
}
int main()
{
	int n;
	cin>>n;
	int num = 0;
	gray(n,num);
	for(int i=0;i<code.size();i++)
		cout<<code[i]<<endl;
}