#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
   int  temp=*a;
    *a=*b;
    *b=temp;
}


void deleteParticularNode(int arr[], int* n , int k)
{
    int i=0;
    for(i=0; i < *n; i++)
    {
        if(arr[i]==k)
            break;
    }
    
    if(i == *n)
        printf("%d Not found\n",k);
    else
    {
        for(; i<(*n)-1; i++)
        {
            arr[i]=arr[i+1];
        }
        
        (*n)--;
        
        buildHeap(arr,*n);
        printf("Deleted\n");
    }
}

void heapify(int arr[],int n,int i)
{
    int large = i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(l<n && arr[l]>arr[large])
    {
        large = l;
    }
    
    if(r<n && arr[r]>arr[large])
    {
        large = r;
    }
    
    if(large != i)
    {
        swap(&arr[i], &arr[large]);
        
        heapify(arr, n, large);
    }
}

void printHeap(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
        
    printf("\n");
}

void buildHeap(int arr[], int n)
{
    int si = n/2 - 1;
    
    for(int i=si; i>=0; i--)
        heapify(arr, n, i);
}

void addArray(int arr[], int data, int n)
{
    arr[n-1] = data;
    
    buildHeap(arr, n);
    printf("Inserted\n");
}

int main() 
{
	int arr[100], c=0, data;
	char val;
	
	while(scanf("%c", &val) == 1)
	{
    	switch(val)
    	{
    	    case 'a' : {
    	                scanf("%d", &data);
    	                c++; 
    	                addArray(arr, data, c);
    	                break;
    	               }
    	               
    	    case 'b' :{
    	                scanf("%d", &data); 
    	                deleteParticularNode(arr, &c, data);
    	                break;
    	              }
    	              
    	    case 'c' :printHeap(arr, c);
    	              break;
    	    
    	    case 'd' :break;
    	}
	}
	
	return 0;
}
