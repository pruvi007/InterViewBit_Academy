/*
	Given 3 strings s1,s2,s3
	tell whether s3 is formed by interleaving s1 and s2
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int e1[100001]={0},e2[100001]={0};
string s1,s2,s3;
bool IL[1001][1001]={NULL};
bool isInterleaf(int i,int j)
{
	if(i==-1 && j==-1)
	{
		return true;
	}
	if(i==-1)
	{
		if(e2[j]==1)
		{
			IL[i][j] = true;
			return IL[i][j];
		}
		IL[i][j]= false;
	}
	if(j==-1)
	{
		if(e1[i]==1)
		{
			IL[i][j] = true;
			return IL[i][j];
		}
		IL[i][j]= false;
	}
	if(s3[i+j+1] != s1[i] && s3[i+j+1] != s2[j])
	{
		IL[i][j]= false;
		return IL[i][j];
	}
	if(s3[i+j+1] == s1[i] && s3[i+j+1] == s2[j])
	{
		if(IL[i][j])
			return IL[i][j];
		IL[i][j] = isInterleaf(i-1,j) || isInterleaf(i,j-1) ;
		return IL[i][j];
	}
	if(s3[i+j+1] == s1[i])
	{
		if(IL[i][j])
			return IL[i][j];
		IL[i][j] = isInterleaf(i-1,j);
		return IL[i][j];
	}
	if(s3[i+j+1] == s2[j])
	{
		if(IL[i][j])
			return IL[i][j];
		IL[i][j] = isInterleaf(i,j-1);
		return IL[i][j];
	}
}
int main()
{
	
	cin >> s1 >> s2 >> s3;

	int n1 = s1.length();
	int n2 = s2.length();
	for(int i=0;i<n1;i++)
	{
		if(s1[i]==s3[i])
			e1[i]=1;
		else break;
	}
	for(int i=0;i<n2;i++)
	{
		if(s2[i]==s3[i])
			e2[i] = 1;
		else break;
	}
	bool ans = isInterleaf(n1-1,n2-1);
	cout << ans << endl;
}