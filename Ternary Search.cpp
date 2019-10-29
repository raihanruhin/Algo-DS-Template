// Ternary Search, O(log n)

mid1=(2*low+high)/3;
mid2=(low+2*high)/3;
dist1=func(mid1);
dist2=func(mid2);
if(dist1>dist2+1e-9)    low=mid1;
else high=mid2;

