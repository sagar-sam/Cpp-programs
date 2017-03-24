#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
    int *a;
    int n,m=1;
    cout<<"Please select a choice:-\n1)Manual insertion of numbers.\n2)Random Number.\n3)exit\n";
    cin>>m;
    while(m!=3)
    {
        cout<<"How many numbers you want to enter?"<<endl;
        cin>>n;
        a=new int[n];
        switch(m)
        {
        case 1:
            cout<<"enter numbers:"<<endl;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            break;
        case 2:
            srand(time(NULL));
            for(int i=0;i<n;i++)
            {
                a[i]=rand();
                cout<<a[i]<<" ";
            }
            cout<<endl;
            break;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        int l=0,r=n-1,mid;
        cout<<"Enter the number you want to search:";
        int q;
        cin>>q;
        int result=-1,comp=0;
        while(l<=r)
        {
            comp++;
            mid=(l+r)/2;
            if(a[mid]==q)
            {
                result=mid;
                r=mid-1;
            }
            else if(a[mid]<q)
                l=mid+1;
            else if(a[mid]>q)
                r=mid-1;
        }
        if(result==-1)
            cout<<"number not found"<<endl;
        else
        {
            cout<<"search successfull"<<endl<<"number found at position:"<<result<<endl<<"number of passes are:"<<comp<<endl;
        }
    cout<<"Please select a choice:-\n1)Manual insertion of numbers.\n2)Random Number.\n3)exit\n";
    cin>>m;
    }
    return 0;
}
