#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 26


int main ()
{
	int arr[MAX_SIZE];
	int n;
	int t;
	char s1[200];

	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = 0;
	}

	scanf("%d", &t);

	while(t--) {
		
		for (int i = 0; i < MAX_SIZE; i++) {
			arr[i] = 0;
		}

		scanf("%d", &n);
		int round;

		round = 0;

		while (round < n) {
			

			scanf("%s", s1);

			for(int i = 0; i < strlen(s1); i++) {
				printf("%c ",s1[i]);
				printf("%d ", s1[i] - 'a');
				if( arr[s1[i] - 'a'] == round) {
					arr[s1[i] - 'a']++;
				}
			}
		for(int i = 0; i < MAX_SIZE; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");

			round++;
		}

		int count = 0;

		for(int i = 0 ; i < MAX_SIZE; i++) {
			printf("%d ",arr[i]);
			if(arr[i] == n) {
				count++;
			}
		}
		printf("%d\n",count);

	
	}

	return 0;
}
