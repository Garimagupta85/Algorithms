#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>


int minkey(int *key, int n, bool mstSet[])
{
	int i;
	int min = INT_MAX, min_index;
	for ( i = 0; i < n; ++i)
	{
		if (mstSet[i] == false && *(key+i) < min)
		{
			min = *(key+i), min_index = i;
		}
	}
	return min_index;
}


void print(int *parent, int *graph, int n) 
{ 
    int i;
	
	for (i = 1; i < n; ++i)
	{
		printf("\n EDGES \n");
		printf("%d - %d \t %d\n", *(parent+i), i, *((graph+i*n)+*(parent+i)) );
	}
}	

int primMST(int *graph, int n)
{
	int p[n];
	int k[n];
	bool mstSet[n];
	int count, u, i;

	for (i = 0; i < n; ++i)
	{
		k[i] = INT_MAX, mstSet[i] = false;
	}

	k[0] = 0;
	p[0] = -1;
	int *key = k;
	int *parent = p;
	for (count = 0; count < n-1; ++count)
	{
		u = minkey(key ,n ,mstSet);
		mstSet[u] = true;

		for ( i = 0; i < n; ++i)
		{
			if (*((graph+u*n) + i) && mstSet[i] == false && *((graph+u*n) + i) < *(key+i))
				*(parent+i) = u, *(key+i) = *((graph+u*n) + i);
		}
	}
	print(parent, (int *)graph,n);

}
int main(int argc, char const *argv[])
{
	int n, i, j;
	printf("Enter the Nodes: \n");
	scanf("%d",&n);
	int g[n][n];
	printf("Enter the Graph: \n");
	for (i = 0; i < n; ++i)
	{
		for ( j = 0; j < n; ++j)
		{
			scanf("%d", &g[i][j]);
		}
	}
	int *graph = &g[0][0];
	primMST((int *)graph,n);
	return 0;
}


/*TEST CASE: 
INPUT:
5
0 2 0 6 0 
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

OUTPUT:
 EDGES 
0 - 1 	 2

 EDGES 
1 - 2 	 3

 EDGES 
0 - 3 	 6

 EDGES 
1 - 4 	 5
*/
