Merge sort, O(nlongn)

long long cntSwap;
vector<int> merge( vector<int>& left, vector<int>& right)
{
    vector<int> result;
    int ll=left.size(), rl=right.size();
    int i = 0, j = 0, lmt=ll+rl;
    left.push_back(1e9);
    right.push_back(1e9);

    for(int k=0;k<lmt;k++)
    {
        if(left[i] <=right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
            cntSwap+=(ll-i);
        }
    }
    return result;
}

vector<int> merge_sort(vector<int>& vec)
{
    if(vec.size() == 1) return vec;
    vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}
