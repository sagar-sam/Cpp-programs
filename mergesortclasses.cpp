#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class sort
{
	vector<int> vec;
	public:
		int n;
		sort();
		void print();
		void mergesort(int left,int right);
		void merge(int l, int m,int r);
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

void sort::mergesort(int left,int right)
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = left+(right-left)/2;
 
        // Sort first and second halves
        mergesort(left, m);
        mergesort(m+1, right);
 
        merge(left, m, right);
    }
}

void sort::merge(int l,int m,int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vec[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
	sort so;
	so.mergesort(0,so.n-1);
	so.print();
}
