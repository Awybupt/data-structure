#include <iostream>
using namespace std;


int MaxSum(int n,int *a,int& besti,int& bestj)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int thissum = 0;
            for(int k=i; k<=j; k++)
            {
                thissum += a[k];
            }
            if(thissum>sum)
            {
                sum = thissum;
                besti = i;
                bestj = j;
            }
        }
    }
    return sum;
}
