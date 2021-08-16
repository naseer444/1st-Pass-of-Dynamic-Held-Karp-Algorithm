/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<<<<<<<<<  Dynamic Programming Approach for Drone Routes Planning   >>>>>>>>>>>>>>>>>>>>>>>>>> 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

1st Pass of Dynamic Held Karp Algorithm i.e:
 The shortest path for a truck that
 starts at v, ends at w, and visits all nodes in S

*/

#include<iostream>
#include<fstream>
using namespace std; 
int arr[10][10],check[10],num,cost=0;

  
int leastPath(int x)
{
	int lst=999;
	int min=999,minAnother;
 
	for(int i=0; i < num; i++)
	{
		if((arr[x][i]!=0)&&(check[i]==0))
			if(arr[x][i]+arr[i][x] < min)
			{
				min=arr[i][0]+arr[x][i];
				minAnother=arr[x][i];
			    lst=i;
			}
	}
 
	if(min!=999)
		cost = cost + minAnother;
 
	return lst;
}
 
void mincost(int town)
{
	int i,townAnother;
 
	check[town]=1;
   
	cout <<town+1<<"--->";
	townAnother=leastPath(town);
 
	if(townAnother==999)
	{
		townAnother=0;
		cout << townAnother+1;
        cost+=arr[town][townAnother];
 
		return;
	}
 
	mincost(townAnother);
    
}

int main()
{
    /*
    
    INPUT FORMAT IS:
    For e.g;
    
    Number of routes : 4
    Then elements of matrix would be like:
    0 1 2 6
    1 5 9 8
    4 7 1 3
    5 2 6 8
    
    
    */
	cout <<"Enter the number of routes: \n";
	cin >> num;
 
	cout <<"Enter elements in a matrix (Basically the cost matrix) : \n";
 
	for(int i=0; i < num; i++)
	{
		for(int j=0; j < num; j++)
			cin >> arr[i][j];
 
		check[i]=0;
	}
 
	cout << "\nThe Shortest Path for a truck is:\n";
	mincost(0);
 
	cout <<"\nMinimum cost is : "<< cost;
 
	return 0;


}
