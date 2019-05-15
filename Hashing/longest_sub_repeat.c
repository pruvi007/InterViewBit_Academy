// longest substring without repeat in C
// solution by @pruvi007

#include<stdio.h>
#include<string.h>

int main()
{
	char A[1000];
	scanf("%s",A);
	

	int f[256];
    int i,j;
    for(i=0;i<256;i++)
        f[i] = 0;
    int n = strlen(A);
    
    int l=0,r=0;
    f[A[0]%256]++;
    int max = 0;
    
    while(l<=r && r<n)
    {
        int flag=0;
        for(i=0;i<256;i++)
        {
            if(f[i]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            int x = (r-l+1);
            if(x>max)
                max = x;
            r++;
            f[A[r]%256]++;
            
        }
        else
        {
            
            
            f[A[l]%256]--;
            l++;
            
        }
        
    }
    printf("%d\n",max);
}