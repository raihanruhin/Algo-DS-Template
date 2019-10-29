//stringstream

//int to string
string tostring(int a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}

//string to long long
long long tolong(string a)
{
    long long res;
    istringstream os(a);
    os>>res;
    return res;
}

//parse a string into a int vector
vector<int> parse(string str)
{
    vector<int>res;
    int s;
    istringstream os(str);
    while(os>>s)
        res.push_back(s);
    return res;
}

//parse a string into a string vector
vector<string> parse(string str)
{
    vector<string>res;
    string s;
    stringstream os(str);
    while(os>>s)
        res.push_back(s);
    return res;
}


