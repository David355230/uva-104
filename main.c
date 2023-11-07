#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
//10 16 10 16 10 is accepted output//原本想法是錯的..... 
void dfs(int arr2[],int n1,int depth,int used[],int temp[],int length1,int index,double *sum,double arr[][20],int a[],int *found)
{
	int i,tp,start,j;
	if(depth==length1)
	{
		for(i=0;i<n1;i++)
		{
			if(temp[i]==0)
			break;
			else
			{
				a[i+1]=temp[i];
			}
		}
		for(i=0;i<length1;i++)
		{
			 if(i==0)
			{
			(*sum)*=arr[index-1][a[i+1]-1];
			}
			
			if(i==length1-1)
			{
				(*sum)*=arr[a[i+1]-1][index-1];
			}
		    else
		    {
		    	(*sum)*=arr[a[i+1]-1][a[i+2]-1];
			}
			
		}
		if(*sum>1.01&&(*found)==0)
		{
			for(j=0;j<length1+2;j++)
	     {
	  	    printf("%d ",a[j]);
	     }
	      printf("\n");
	      *found=1; 
		}
		return;
	}
	
        for(i=0;i<n1;i++)
		{
			if(used[i]==1)
			{
			  continue;
			}
			used[i]=1;
			temp[depth]=arr2[i];
			dfs(arr2,n1,depth+1,used,temp,length1,index,sum,arr,a,found);
			*sum=1;
			used[i]=0;
			temp[depth]=0;
				
		}
}

void produce(int index,double arr[][20],int length,int a[],int n,int *found)
{
	double sum=1.0;
	int i;
	int arr2[n-1];
    int k=0;
	for(i=0;i<n-1;i++)
	{
		if(i+1==index)
		{
			k++;
		}
		arr2[i]=k+1;
		k++;
	}
	

	int used[n-1],temp[n-1],depth;
	for(i=0;i<n-1;i++)
	{
		used[i]=0;
		temp[i]=0;
	}
	depth=0;
	dfs(arr2,n-1,depth,used,temp,length-2,index,&sum,arr,a,found);
	
}

void arbitage(int n,double arr[][20],int *found)
{
	int i,j;
	int length;
	length=3;
	double sum=1.0;
	while(length<=n+1)
	{
	  int a[length];
	  for(i=1;i<=n;i++)
	  {
	  	a[0]=i;
	    a[length-1]=i;
		produce(i,arr,length,a,n,found);
		if(*found==1)
	    break;
	  }
	  if(*found==1)
	  break;
	  length++;
	}
}

int main()
{
	int n,i,j;
	double arr[20][20];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				arr[i][j]=1.0;
				else
				scanf("%lf",&arr[i][j]);
			}
		}
		int found=0;
		arbitage(n,arr,&found);
		if(found==0)
		printf("no arbitrage sequence exists\n");
	}
	return 0;
	
}
