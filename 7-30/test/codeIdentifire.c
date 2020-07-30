#include<stdio.h>

int E[3][3]={{1,0,0},{0,1,0},{0,0,1}};

//
void shokika( int s1 , int s2 , int a[s1][s2] )
{
	int i,j;

	for( i=0 ; i<s1 ; i++ )
	{
		for( j=0 ; j<s2 ; j++ )
		{
			printf("A[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}

int t( int s1 , int s2 , int a[s1][s2] )
{
	int i,j;
	int tp=0;

	for( i=0 ; i<s1 ; i++ )
	{
		tp+=a[i][i];
	}

	return(tp);
}

int dainyuu( int s1 , int s2 , int a[s1][s2] )
{
	int var;

	var=a[0][0]*a[1][1]+a[1][1]*a[2][2]+a[2][2]*a[0][0]-a[0][1]*a[1][0]-a[1][2]*a[2][1]-a[2][0]*a[0][2];

	return(var);
}

//Sarrus' scheme
int gyouretusiki( int s1 , int s2 , int a[s1][s2] )
{
	int var;

	var= a[0][0]*a[1][1]*a[2][2];
	var+=a[0][1]*a[1][2]*a[2][0];
	var+=a[0][2]*a[1][0]*a[2][1];
	var-=a[2][0]*a[1][1]*a[0][2];
	var-=a[1][0]*a[0][1]*a[2][2];
	var-=a[0][0]*a[1][2]*a[2][1];

	return(var);
}

void kakezan( int s1 , int s2 , int gyouretu1[s1][s2] , int gyouretu2[s1][s2] , int gyouretuS[s1][s2])
{
	int i,j,k;
	int var=0;

	for( i=0 ; i<s1 ; i++ )
	{
		for( j=0 ; j<s2 ; j++ )
		{
			for( k=0 ; k<s1 ; k++ )
			{
				var+=gyouretu1[i][k]*gyouretu2[k][j];
			}
			gyouretuS[i][j]=var;
			var=0;
		}
	}
}

void teisuubai( int cons , int s1 , int s2 , int gyouretuL[s1][s2] , int gyouretuS[s1][s2] )
{
	int i,j;

	for( i=0 ; i<s1 ; i++ )
	{
		for( j=0 ; j<s2 ; j++ )
		{
			gyouretuS[i][j]=cons*gyouretuL[i][j];
		}
	}
}

void tashizan( int s1 , int s2 , int gyouretu1[s1][s2] , int gyouretu2[s1][s2] , int gyouretuS[s1][s2] )
{
	int i,j;

	for( i=0 ; i<s1 ; i++ )
	{
		for( j=0 ; j<s2 ; j++ )
		{
			gyouretuS[i][j]=gyouretu1[i][j]+gyouretu2[i][j];
		}
	}
}

void hyouji( char *str , int s1 , int s2 , int arr[s1][s2] )
{
	int i,j;

	printf("%s",str);
	for( i=0 ; i<s1 ; i++ )
	{
		printf("[");
		for( j=0 ; j<s2 ; j++ )
		{
			printf("     %5d",arr[i][j]);
		}
		printf("]\n");
	}
}

int main(void)
{
	int aa[3][3],aa2[3][3];
	int a,b,c;
	int term1[3][3],term2[3][3],term3[3][3],term4[3][3];
	int t1Andt2[3][3],t3Andt4[3][3],var[3][3];
	int i,j;

	shokika(3,3,aa);
	a=t(3,3,aa);
	b=dainyuu(3,3,aa);
	c=gyouretusiki(3,3,aa);

	kakezan(3,3,aa,aa,aa2);
	kakezan(3,3,aa2,aa,term1);
	teisuubai(a,3,3,aa2,term2);
	teisuubai(-1,3,3,term2,term2);
	teisuubai(b,3,3,aa,term3);
	teisuubai(-c,3,3,E,term4);

	tashizan(3,3,term1,term2,t1Andt2);
	tashizan(3,3,term3,term4,t3Andt4);
	tashizan(3,3,t1Andt2,t3Andt4,var);

	hyouji("Result of calcuration...\n",3,3,var);

	return(0);
}
