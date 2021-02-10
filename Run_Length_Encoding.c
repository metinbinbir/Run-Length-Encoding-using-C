#include<stdio.h>
int main(){
	while(1)
	{
		int n,m,i,j,matris[100][100],a,b,tempEleman;
		int compArray[100];
		int index=0;
		int sonSayac=0; 
		int decompmat[200][200];
		float top,row,column,dif,ratio;
		
		printf("NUMBER OF ROWS OF MATRIX A (n):"); scanf("%d",&n);
		printf("NUMBER OF COLUMNS OF MATRIX A (m):"); scanf("%d",&m);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("A[%d][%d]:",i,j); 
				scanf("%d",&matris[i][j]); 
			}
		}
		printf("-------------------\n");
		
		printf("MATRIX YOU ENTERED: \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%d ",matris[i][j]); 
			printf("\n");
		}
		printf("-------------------\n");
		
		tempEleman=matris[0][0]; 
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(matris[i][j]==tempEleman)
					sonSayac++;
				else
				{
					compArray[index]=sonSayac; 
					compArray[index+1]=tempEleman; 
					sonSayac=1;
					tempEleman=matris[i][j]; 
					index=index+2;	
				}
			}
		}
		
		if((i==n)&&(j==m))
		{	
			compArray[index]=sonSayac; 
			compArray[index+1]=tempEleman; 
			sonSayac=1;
			tempEleman=matris[i][j]; 
			index=index+2;	
		}
		
		printf("COMPRESSED MATRIX AS AN ARRAY: \n[");
		for(i=0;i<index;i++){
			printf("%d ",compArray[i]);
		}
		printf("]\n");	
		printf("-------------------\n");
	
		a=1;
		b=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a<compArray[b])
				{
					decompmat[i][j]=compArray[b+1];
					a++;
				}
				else
				{ 
					decompmat[i][j]=compArray[b+1]; 
					b=b+2; 
					a=1;
				}
			}
		}
		printf("MATRIX FORM OF COMPRESSED ARRAY: \n");
		for(i=0;i<n;i++)
		{	
			for(j=0;j<m;j++)
				printf("%d ",decompmat[i][j]);
			printf("\n");
		}
		printf("--------------------------\n");
		top=b;
		row=n;
		column=m;
		dif= top/(row*column);
		ratio= 1-dif;
		printf("COMPRESSION RATIO: 1-%f=%f",dif,ratio);
	}
	return 0;
}



