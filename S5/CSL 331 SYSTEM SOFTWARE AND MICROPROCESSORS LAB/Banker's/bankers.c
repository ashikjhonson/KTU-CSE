#include <stdio.h>
int main(){
	int n, m, completed = 0, success = 0;
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	printf("Enter no. of available instances: ");
	scanf("%d",&m);
	int allocation[n][m], max[n][m], available[m], need[n][m], status[n];
/*
	int need[n][m], status[n];
	int allocation[5][3] = {{1,1,2},
				{2,1,2},
			        {4,0,1},
				{0,2,0},
				{1,1,2}
			       };

	int max[5][3] = {{4,3,3},
			 {3,2,2},
		         {9,0,2},
			 {7,5,3},
			 {1,1,2}
		        };
	int available[3] = {2,1,0};
*/

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			need[i][j] = max[i][j] - allocation[i][j];			
		}
		status[i] = 0;
	}

	// User Input

	printf("Enter allocation matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter max matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];			
		}
		status[i] = 0;
	}
	
	printf("Enter available instances:\n");
	for(int i=0; i<m; i++){		
		scanf("%d",&available[i]);		
	}

	
	printf("\nEntered available matrix\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d\t",allocation[i][j]);
		}
		printf("\n");
	}


	printf("\nEntered available matrix\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}

	printf("\nNeed matrix\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}

	printf("\nSafe sequence = {");

	while(completed < n){
		for(int i=0; i<n; i++){
			if(!status[i])
			{
				for(int j=0; j<m; j++){
					if(need[i][j] <= available[j]){
						success = 1;
					}	
					else{
						success = 0;
						break;
					}
				}
				
				if(success){
					status[i] = 1;
					for(int j=0; j<m; j++){
						available[j] += allocation[i][j];
					}
					printf("P%d ", i);
					completed++;
				}
			}
		}
	}
	printf("}\nTotal available: ");
	for(int i=0; i<m; i++){		
	    printf("%d ",available[i]);		
	}
	printf("\n");
	return 0;
}