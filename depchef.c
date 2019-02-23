#include <stdio.h>
#define defence 1
#define attack 0

int main ()
{
	int t;
	int n;
	int def;
	int best;
	int sol;
	int arr[100][2];
	
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0 ; j < n; j++) {
				scanf("%d", &arr[j][i]);
			}
		}
		
	/*	for (int i = 0; i < n; i++){
			for(int j = 0; j <2 ; j++){
				printf("%d ", arr[i][j]);
			}
			printf("\n");
			}*/


		best = -1;
		sol = -1;


		for (int i = 0; i < n; i++) {
			if ( i == 0 ) {
				if (arr[0][defence] > (arr[n-1][attack] + arr[i + 1][attack])) {
					def = arr[i][defence];
					if(best < def)
						best = def;
					sol = i + 1;
				
				}
			} else if (i == n - 1)  {
				if ( arr[i][defence] > (arr[0][attack] + arr[i - 1][attack])) {
					def = arr[i][defence];

					if (best < def) {
						best = def;
						sol = i + 1;
						
					} 
					
				}
			} else {

				if ( arr[i][defence] > (arr[i-1][attack] + arr[i+1][attack])) {
					def = arr[i][defence];
					if ( best < def) {
						best = def;
						sol = i + 1;
					}
				}
			
			}
		}
		if ( best  == -1)
			printf("-1\n");
		else
			printf("%d\n",arr[sol - 1][defence]);
	
	}

	return 0;
}
