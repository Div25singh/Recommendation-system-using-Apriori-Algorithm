#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Sanidhya working on it

int main(){
	
	int i; 
	int j; 
	int k;
	int f;
	int min;
	int t1;
	int a[5][5];
	int l1[5];
	int items[5];
    int pos=0;
    int count=0;
    
    int l2[5][3];
    int l2t1; 
    int l2t2; 
    int l2pos1=0;
	int l2ocount=0;
    int l2jcount=0;
    int f1;
    int l;
    int f2;
    int f3;
    
    int p3pcount=0;
    int p3items[5]={-1,-1,-1,-1,-1};
    int p3pos=0;
    
    printf("\n ****************************************************************************************");
    printf("\n ****************************************************************************************"); 
    printf("\n ");
	printf("\n \t \t \t Recommendation system using Apriori Algorithm");
	printf("\n ");
	printf("\n ****************************************************************************************"); 	
	printf("\n ****************************************************************************************");
	printf("\n\n ");
	printf("This table tells us the Number belonging to the required item in the store: \n\n"); 

	printf("\t0 ----> No purchase\n");
	printf("\t1 ----> Potato\n");
	printf("\t2 ----> Tomato\n");
    printf("\t3 ----> onion\n");
    printf("\t4 ----> Lettuce\n");
    printf("\t5 ----> Carrot\n");
    
    printf("\n");
	printf("Now generating Association report for these Items\n");
	for(i=0;i<5;i++)
    {
      printf("\n Enter items from purchase %d :",i+1);
      printf("\n");
       for(j=0;j<5;j++)
        {
          scanf("%d",&a[i][j]);
        }
    }
 /**************************************************************************************************/
 //Defining minimum level for acceptence  
 printf("\n Enter minimum acceptance level ----> ");
 scanf("%d",&min);
	
 printf("\nInitial Input:\n");
 printf("\nTrasaction\tItems\n");
 
  for(i=0;i<5;i++)
	{
   printf("%d:\t",i+1);
   for(j=0;j<5;j++)
		{
  printf("%d \t",a[i][j]);
		}
printf("\n");
	}
	
/**************************************************************************************************/	
printf("\nAssumed minimum support ---> %d ",min);

//frequency 
for(i=0;i<5;i++)
	{
		t1=0;
		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
			if(a[j][k]==i+1)
				{
				t1++;
				}
			}
		}
		l1[i]=t1;
	}
	
/**************************************************************************************************/
//Printing first pass
printf("\n\nGenerating List 1 of frequency for the required data\n");
for(i=0;i<5;i++)
{
printf("%d: %d\n",i+1,l1[i]);

}
/**************************************************************************************************/
//Second pass
//Counting number of possibilities for pass2

for(i=0;i<5;i++)
{
if(l1[i]>=min)
{
count++;
items[pos]=i;
pos++;
}
}
//Printing selected items for second pass
printf("\nGenerating List 2 From List 1 data \n");
for(i=0;i<pos;i++)
{
printf("%d\t%d\n",items[i]+1,l1[items[i]]);
}
printf("\n*****     Item whose value is less than support is eliminated     *****\n");
/**************************************************************************************************/
//Joining items

for(i=0;i<count;i++)
{
for(j=i+1;j<count;j++)
{
l2t1=items[i]+1;
l2t2=items[j]+1;
if(l2t1==l2t2)
{
//it is self join
continue;
}
//join the elements
l2[l2pos1][0]=l2t1;
l2[l2pos1][1]=l2t2;
l2jcount++;

//count occurances
l2ocount=0; //reset counter
for(k=0;k<5;k++)
{
f1=f2=0; //resetting flag
//scan a purcahse
for(l=0;l<5;l++)
{
if(l2t1==a[k][l])
{
//one of the element found
f1=1;
}
if(l2t2==a[k][l])
{
//second elements also found
f2=1;
}
}
//one purchase scanned
if(f1==1&&f2==1) //both items are present in
{
l2ocount++;
}
}
//assign count
l2[l2pos1][2]=l2ocount;
l2pos1++;
}
}

//Printing second pass
printf("\n\nGenerating List 3 for new combination from List 2 values\n");
for(i=0;i<l2jcount;i++)
{
for(j=0;j<3;j++)
{
printf("%d\t",l2[i][j]);
}
printf("\n");
}
/**************************************************************************************************/

for(i=0;i<5;i++)
{
if(l2[i][2]>=min)
{
f=0;
for(j=0;j<5;j++)
{
if(p3items[j]==l2[i][0])
{
f=1;
}
}
if(f!=1)
{
p3items[p3pos]=l2[i][0];
p3pos++;
p3pcount++;
}
f=0;
for(j=0;j<5;j++)
{
if(p3items[j]==l2[i][1])
{
f=1;
}
}
if(f!=1)
{
p3items[p3pos]=l2[i][1];
p3pos++;
p3pcount++;
}
}
}
//Joining
int l3[5][4];
int l3ocount=0; //occurance counter
int l3jcount=0; //join counter
for(i=0;i<p3pcount;i++)
{
for(j=i+1;j<p3pcount;j++)
{
for(k=j+1;k<p3pcount;k++)
{
l3[i][0]=p3items[i];
l3[i][1]=p3items[j];
l3[i][2]=p3items[k];
l3jcount++;

//count occurances
l3ocount=0; //reset counter
for(k=0;k<5;k++)
{
f1=f2=f3=0; //resetting flag
//scan a purcahse
for(l=0;l<5;l++)
{
if(l3[i][0]==a[k][l])
{
//one of the element found
f1=1;
}
if(l3[i][1]==a[k][l])
{
//second elements also found
f2=1;
}
if(l3[i][2]==a[k][l])
{
//third element also found
f3=1;
}
}
//one purchase scanned
if(f1==1&&f2==1&&f3==1) //all items are present

{
l3ocount++;
}
}
//assign count
l3[i][3]=l3ocount;
}
}
}

//Printing third pass
printf("\n\nGenerating L3\n");
for(i=0;i<l3jcount;i++)
{
for(j=0;j<4;j++)
{
printf("%d\t",l3[i][j]);
}
printf("\n");
}
//Ending
}
