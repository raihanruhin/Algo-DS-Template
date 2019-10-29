Stable Marriage Problem, O(n^2)

bool is_man_paired[MX], is_woman_paired[MX], is_woman_proposed[MX][MX];
int men_pref[MX][MX], women_pref[MX][MX];
int man_partner[MX], num_women_proposed[MX], woman_partner[MX];

void stableMarriage(int n)
{
    int i,j,m,mm,m_preferred,w;
    CLR(is_man_paired), CLR(is_woman_paired);
    CLR(is_woman_proposed), CLR(num_women_proposed);
    while(1)
    {
        for(m=0; m<n; m++)   if((!is_man_paired[m]) && (num_women_proposed[m]!=n))     break;
        if(m==n)     break;
        for(i=0; i<n; i++)   if(!is_woman_proposed[m][i])      break;
        w=men_pref[m][i];
        if(!is_woman_paired[w])
        {
            man_partner[m]=w,   woman_partner[w]=m;
            is_man_paired[m]=1, is_woman_paired[w]=1;
        }
        else
        {
            mm=woman_partner[w], m_preferred=0;
            for(j=0; j<n; j++)
                if(women_pref[w][j]==m)
                {
                    m_preferred=1;
                    break;
                }
                else if(women_pref[w][j]==mm)     break;

            if(m_preferred)
            {
                man_partner[m]=w, woman_partner[w]=m;
                is_man_paired[m]=1, is_man_paired[mm]=0;
            }
        }
        num_women_proposed[m]++;
        is_woman_proposed[m][i]=1;
    }
    return;
}
