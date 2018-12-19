//Binary search-Iterative 
//Time Complexcity- O(logn)
//Input- the key to be searched.
//Output- the inedx of the element if the key is present.
#include<stdio.h>
#include<math.h>

void main(){
	int n,key,flag=0;
  int i;
	printf("\nEnter the size of array\n");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements (sorted)\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int high=n-1,low=0,mid;
	printf("\nEnter the element to search\n");
	scanf("%d",&key);
	while(low<=high){
		mid=(high+low)/2;

		if(arr[mid]==key){
			printf("\nElement found at index %d",mid);
			flag=1;
			break;
		}

		else if(arr[mid]>key)
			high=mid-1;

		else
			low=mid+1;
	}	

	if(flag==0)
	    printf("\nElement not found\n");
}


