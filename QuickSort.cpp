#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class sort
{
	vector<int> vec;
	int n;
	public:
		sort();
		void print();
		void quicksort(int left,int right);
		int partition(int left,int right,int pivot);
		void quicksort()
		{
			quicksort(0,n-1);
		}
};

void sort::print()
{
	for(int i=0;i<n;i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

sort::sort()
{
	int q;
	cout<<"1) Manual data\n2) Random data"<<endl;
	cin>>q;
	if(q==1)
	{
		int count=0;
		char ch='y';
		do{
			count++;
			int a;
			cout<<"Enter data"<<endl;
			cin>>a;
			vec.push_back(a);
			cout<<"Do you want to enter more data"<<endl;
			cin>>ch;
		}while(ch!='n');
		n=count;
	}
	else if(q==2)
	{
		cout<<"enter the number of elements yuo want to enter"<<endl;
		cin>>n;
		srand(time(NULL));
		for(int i=0;i<n;i++)
		{
			int a=rand()%1000;
			cout<<a<<" ";
			vec.push_back(a);
		}
		cout<<endl;
	}
}

void sort::quicksort(int left,int right)
{
	if(left>=right)
		return;
	else
	{
		int pivot=vec[left];
		//print();
		int par=partition(left,right,pivot);
		print();
		//for(int j=0;j<par-1;j++)
		//	cout<<vec[j]<<" ";
		//cout<<endl;
		//for(int j=par+1;j<n;j++)
		//	cout<<vec[j]<<" ";
		//cout<<endl;
		quicksort(left,par-1);
		quicksort(par+1,right);
		//print();
	}
}

int sort::partition(int left,int right,int pivot)
{
	int leftptr=left,rightptr=right+1;
	while(true)
	{
		do{
			continue;
		}while(vec[++leftptr]<pivot);
		do{
			continue;
		}while(vec[--rightptr]>pivot);
		if(leftptr>=rightptr)
			break;
		else
		{
			int t=vec[leftptr];
			vec[leftptr]=vec[rightptr];
			vec[rightptr]=t;
		}
		print();
	}
	int t=vec[left];
	vec[left]=vec[rightptr];
	vec[rightptr]=t;
	return rightptr;
}

int main()
{
	sort so;
	so.quicksort();
}
