#include<stdio.h>

int I[3][3]={{1,0,0},{0,1,0},{0,0,1}};

//
void initializeA( int rSize , int cSize , int A[rSize][cSize] )
{
	int i,j;

	for( i=0 ; i<rSize ; i++ )
	{
		for( j=0 ; j<cSize ; j++ )
		{
			printf("Enter elem of A[%d][%d] : ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
}

int traceA( int rSize , int cSize , int A[rSize][cSize] )
{
	int i,j;
	int tr=0;

	for( i=0 ; i<rSize ; i++ )
	{
		tr+=A[i][i];
	}

	return(tr);
}

int instantiationA( int rSize , int cSize , int A[rSize][cSize] )
{
	int ins;

	ins=A[0][0]*A[1][1]+A[1][1]*A[2][2]+A[2][2]*A[0][0]-A[0][1]*A[1][0]-A[1][2]*A[2][1]-A[2][0]*A[0][2];

	return(ins);
}

//Sarrus' scheme
int determinantA( int rSize , int cSize , int A[rSize][cSize] )
{
	int det;

	det= A[0][0]*A[1][1]*A[2][2];
	det+=A[0][1]*A[1][2]*A[2][0];
	det+=A[0][2]*A[1][0]*A[2][1];
	det-=A[2][0]*A[1][1]*A[0][2];
	det-=A[1][0]*A[0][1]*A[2][2];
	det-=A[0][0]*A[1][2]*A[2][1];

	return(det);
}

void mulMat( int rSize , int cSize , int arr1[rSize][cSize] , int arr2[rSize][cSize] , int arrS[rSize][cSize])
{
	int i,j,k;
	int ans=0;

	for( i=0 ; i<rSize ; i++ )
	{
		for( j=0 ; j<cSize ; j++ )
		{
			for( k=0 ; k<rSize ; k++ )
			{
				ans+=arr1[i][k]*arr2[k][j];
			}
			arrS[i][j]=ans;
			ans=0;
		}
	}
}

void cmMat( int cons , int rSize , int cSize , int arrL[rSize][cSize] , int arrS[rSize][cSize] )
{
	int i,j;

	for( i=0 ; i<rSize ; i++ )
	{
		for( j=0 ; j<cSize ; j++ )
		{
			arrS[i][j]=cons*arrL[i][j];
		}
	}
}

void addMat( int rSize , int cSize , int arr1[rSize][cSize] , int arr2[rSize][cSize] , int arrS[rSize][cSize] )
{
	int i,j;

	for( i=0 ; i<rSize ; i++ )
	{
		for( j=0 ; j<cSize ; j++ )
		{
			arrS[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
}

void printArr( char *str , int rSize , int cSize , int arr[rSize][cSize] )
{
	int i,j;

	printf("%s",str);
	for( i=0 ; i<rSize ; i++ )
	{
		printf("[");
		for( j=0 ; j<cSize ; j++ )
		{
			printf("     %5d",arr[i][j]);
		}
		printf("]\n");
	}
}

int main(void)
{
	int A[3][3],A_2[3][3];
	int a,b,c;
	int term1[3][3],term2[3][3],term3[3][3],term4[3][3];
	int t1Andt2[3][3],t3Andt4[3][3],ans[3][3];
	int i,j;

	initializeA(3,3,A);
	a=traceA(3,3,A);
	b=instantiationA(3,3,A);
	c=determinantA(3,3,A);

	mulMat(3,3,A,A,A_2);
	mulMat(3,3,A_2,A,term1);
	cmMat(a,3,3,A_2,term2);
	cmMat(-1,3,3,term2,term2);
	cmMat(b,3,3,A,term3);
	cmMat(-c,3,3,I,term4);

	addMat(3,3,term1,term2,t1Andt2);
	addMat(3,3,term3,term4,t3Andt4);
	addMat(3,3,t1Andt2,t3Andt4,ans);

	printArr("Result of calcuration...\n",3,3,ans);

	return(0);
}
