#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int small = i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]<arr[small])
    {
        small = l;
    }
    
    if(r<n && arr[r]<arr[small])
    {
        small = r;
    }
    
    if(small != i)
    {
        swap(&arr[i], &arr[small]);

        heapify(arr, n, small);
    }
}

void buildHeap(int arr[], int n)
{
    int si = n/2 - 1;
    
    for(int i=si; i>=0; i--)
        heapify(arr,n,i);
    
}

void printHeap(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
        
     printf("\n");
}

int main() 
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n, k;
	    scanf("%d",&n);
	 
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    buildHeap(arr,n);
	    
	    printHeap(arr,n);
	    
	}
	return 0;
}
