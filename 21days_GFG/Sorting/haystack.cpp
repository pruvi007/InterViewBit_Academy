bool isShuffledSubstring(string needle, string haystack) 
{
    int n = needle.length();
    int m = haystack.length();
    int f1[256]={0};
    int f2[256]={0};
    for(int i=0;i<n;i++)
    {
        f1[ needle[i] ]++;
        f2[  haystack[i] ]++;
    }
    for(int i=n;i<=m;i++)
    {
        // check
        bool valid = true;
        for(int j=0;j<256;j++)
        {
            if( f1[j]!=f2[j] )
            {
                valid = false;
                break;
            }
        }
        if(valid)
            return true;
        f2[ haystack[i-n] ]--;
        f2[ haystack[i] ]++;
    }
    
    return false;
}