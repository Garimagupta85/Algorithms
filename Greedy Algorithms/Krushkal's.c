#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

int find(int i, int n, int *parent)
{
	
	while(*(parent+i) != i)
		i = *(parent+i);
	return i;
}
void union1(int i, int j, int n, int *parent)
{
	
	int a,b;
	a = find(i,n,parent);
	b = find(j,n,parent);
	*(parent+a) = b;
}
void krushkal(int *cost, int n)
{
	int mincost = 0;
	int p[n],i,j;
	int *parent = p;

	for (i = 0; i < n; ++i)
	{
		*(parent+i) = i;
	}
	int edge_count = 0;
	while(edge_count < n-1)
	{
		int min = INT_MAX, a = -1, b = -1;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if (find(i,n,parent) != find(j,n,parent) && *((cost+i*n)+j) < min)
				{
					min = *((cost+i*n)+j);
					a = i;
					b = j;
				}
			}
		}

		union1(a, b, n, parent);
		printf("Edge %d:(%d, %d) cost: %d \n", edge_count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost );
}

int main(int argc, char const *argv[])
{
	int n, i, j;
	printf("Enter the no. of edges: \n");
	scanf("%d" , &n);
	int c[n][n];
	printf("Enter the Cost: \n");
	for (i = 0; i < n; ++i)
	{
		for ( j = 0; j < n; ++j)
		{
			scanf("%d", &c[i][j]);
			if(c[i][j]==0)
			{
				c[i][j] = INT_MAX;
			}
		}
	}
	int *cost = &c[0][0];
	krushkal((int *)cost, n);

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
Edge 0:(0, 1) cost: 2 
Edge 1:(1, 2) cost: 3 
Edge 2:(1, 4) cost: 5 
Edge 3:(0, 3) cost: 6 

 Minimum cost= 16 

