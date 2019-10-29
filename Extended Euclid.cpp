//Input a ,b.
//Returns X,Y,D in vector such that aX+bY=D, where D is the greatest common divisor of a and b
//|X|+|Y| is the minimal (primarily) and X<=Y (secondarily).


vector<int> Extended_Euclid(int a, int b)
{
    int last_x=1,last_y=0,x=0,y=1,tmp,quotient,reminder;
    while(b)
    {
        quotient=a/b;
        reminder=a%b;
        a=b;
        b=reminder;

        tmp=x;
        x=last_x-quotient*x;
        last_x=tmp;

        tmp=y;
        y=last_y-quotient*y;
        last_y=tmp;
    }
    vector<int>res;
    res.push_back(last_x);
    res.push_back(last_y);
    res.push_back(a);
return res;
}
