#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	cout<<"If you want to perform bubble sort on random numbers enter 1 and if you want to input a number enter 2"<<"\n";
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"Enter the number of numbers you want to perform bubble sort on"<<"\n";
		int k,l=0,j=0,s=0;
		cin>>k;
		int arr[10000],b[10000];
		srand(time(0));
		for(int h=0;h<k;h++)
		{
			arr[h]=rand();
			b[h]=arr[h];
		}
		for(int d=0;d<k;d++)
		{
			cout<<arr[d]<<"\n";
		}


		for(int m=1;m<k;m++)
		{
			for(int n=0;n<k-m;n++)
			{
				l++;
				if(arr[n]>arr[n+1])
				{

					int temp=arr[n];
					arr[n]=arr[n+1];
					arr[n+1]=temp;

				}
			}
		}
		cout<<"No. of comparisions in bubble sort are="<<l<<"\n";
		cout<<"Sorted array is:"<<"\n";
		for(int i=0;i<k;i++)
		{
			cout<<arr[i]<<"\n";
		}
		for(int m=1;m<k;m++)
		{
		    s=0;
			for(int n=0;n<k-m;n++)
			{
				//s=0;
				j++;

				if(b[n]>b[n+1])
				{
				int temp=b[n];
					b[n]=b[n+1];
					b[n+1]=temp;
					s++;


				}
			}
			if(s==0)
			break;
		}
		cout<<"No. of comparisions in modified bubble sort are="<<j<<"\n";
		cout<<"Sorted array is:"<<"\n";
		for(int i=0;i<k;i++)
		{
			cout<<b[i]<<"\n";
		}
	}
	else if(n==2)
	{
		cout<<"Enter number of elements of array";
		int p,x[100],y[100],l1=0,j1=0,s1=0;
		cin>>p;
		for(int c=0;c<p;c++)
		{
			cin>>x[c];
			y[c]=x[c];
		}
	/*	for(int d1=0;d1<p;d1++)
		{
			cout<<x[d1]<<"\n";
		}*/
			for(int m1=1;m1<p;m1++)
		{
			for(int n1=0;n1<p-m1;n1++)
			{
				l1++;
				if(x[n1]>x[n1+1])
				{

					int temp1=x[n1];
					x[n1]=x[n1+1];
					x[n1+1]=temp1;

				}
			}
		}
		cout<<"No. of comparisions in bubble sort are="<<l1<<"\n";
		cout<<"Sorted array is:"<<"\n";
		for(int i1=0;i1<p;i1++)
		{
			cout<<x[i1]<<"\n";
		}
		for(int m1=1;m1<p;m1++)
		{
			for(int n1=0;n1<p-m1;n1++)
			{
				j1++;
				 s1=0;
				if(y[n1]>y[n1+1])
				{

				int temp1=y[n1];
					y[n1]=y[n1+1];
					y[n1+1]=temp1;

					s1++;
				}
			}
			if(s1==0)
			break;
		}
		cout<<"No. of comparisions in modified bubble sort are="<<j1<<"\n";
		cout<<"Sorted array is:"<<"\n";
		for(int i1=0;i1<p;i1++)
		{
			cout<<y[i1]<<"\n";
		}
	}

}

