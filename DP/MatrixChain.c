#include<stdio.h>
#include<limits.h>

int MatrixChainOrder(int p[], int n)
{
	int m[n][n];

	int i, j, l, k, q;
	for (i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}

	for (l=2;l<n;l++)
	{
		for (i = 0; i < n-l+1; ++i)
		{
			j = i+l-1;
			m[i][j] = INT_MAX;
			for (k = i; k<=j-1; k++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
				}
			}
		}
	}
	return m[1][n-1];
}

int main(int argc, char const *argv[])
{
	int n,i;
	printf("Enter The No. Of Matrix: \n");
	scanf("%d" ,&n);
	int p[n];
	printf("Enter The Size Each Matrix: \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
	}
	
	printf("The number of Multiplications: %d\n", MatrixChainOrder(p,n));
	return 0;
}

/*TEST CASE:
INPUT:
5
1 2 3 4 3

OUTPUT:
The number of Multiplications: 30
*/
