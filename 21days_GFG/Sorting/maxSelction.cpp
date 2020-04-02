bool compare(pair<int,int>& a,pair<int,int>& b)
{
    return a.second < b.second;
}
int max_non_overlapping( vector< pair<int,int> >& ranges )
{
    sort(ranges.begin(),ranges.end(),compare);
    int c = 1;
    int m = 1;
    pair<int,int> cur = ranges[0];
    for(int i=1;i<ranges.size();i++)
    {
        if( ranges[i].first>=cur.second )
        {
            cur = ranges[i];
            c++;
        }
            
    }
   
    return c;
}