string Solution::countAndSay(int A) {
    string s[100005];
    int cs = 0;
    s[1] = "1";
    s[2] = "11";
    for(int i=3;i<=A;i++)
    {
        int l = s[i-1].length();
        int c = 1;
        char t = s[i-1][0];
        string tmp="";
        for(int j=1;j<l;j++)
        {
            if(s[i-1][j] == t)
                c++;
            else
            {
                tmp = tmp+to_string(c)+t;
                t = s[i-1][j];
                c=1;
            }
        }
        tmp = tmp+to_string(c)+t;
        s[i] = tmp;
    }
    return s[A];
}
