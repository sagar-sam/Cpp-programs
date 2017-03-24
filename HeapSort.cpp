#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;
 
class heap{
    int *arr;
    int n;
    int height;
public:
    heap();
    static int findHeight(int n)
    {
    	int m=n,x=0;
    	while(m>0)
    	{
    		m=m/2;
    		x++;
    	}
    	return x;
    }
    static int exp(int m){
    	if(m==0)
    		return 1;
    	else 
    		return 2*exp(m-1);
    }
    void printArray();
    void heapify(int m,int i);
    void heapSort();
    void print();
};

void heap::print()
{
	getchar();
	system("clear");
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<exp(height-i);j++)
			cout<<" ";
		for(int k=exp(i)-1;k<=exp(i+1)-2;k++)
		{
			if(k<n)
			cout<<arr[k];
			else cout<<" ";
			for(int l=0;l<exp(height-i+1);l++)
				cout<<" ";
		}
		cout<<endl;
	}
	printf("press enter to continue\n");

}

heap::heap()
{
    int q;
    cout<<"1) Manual\n2) Random"<<endl;
    cin>>q;
    cout<<"Enter the number of elements you want to enter"<<endl;
    cin>>n;
    height=findHeight(n);
    arr=new int[n];
    switch(q)
    {
        case 1:
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }        srand(time(NULL));

        break;
        case 2:
        srand(time(NULL));
        for(int i=0;i<n;i++)
        {
            arr[i]=rand()%10;
            cout<<"arr[i] ";
        }
    }
    cout<<endl<<"initial tree"<<endl;
    print();
}

void heap::heapify(int m,int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < m && arr[l] > arr[largest])
        largest = l;
    if (r < m && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        print();
        heapify(m,largest);
    }
}
 
void heap::heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
    	heapify(n,i);
    }
    //print();
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        print();
        heapify(i,0);
    }
}
 
void heap::printArray()
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    heap hp;
    hp.heapSort();
    cout<<endl<<"sorted array is: "<<endl;
    hp.print(); 
    cout << "Sorted array is \n";
    hp.printArray();
}
