#include <stdio.h>
#include <stdlib.h>

#define MAx_SIZE 100000

int main()
{

	int t;
	int n;
	long long int *jars;

	scanf("%d", &t);

	while (t--) {
	
		scanf("%d", &n);
		long long int max;
	
		long long int sum = 0;

		jars = malloc(sizeof(long long int) * n);

		for (int i = 0; i < n; i++) {
			scanf("%lld",&jars[i]);
			jars[i]--;
			sum += jars[i];
			}

		printf("%lld\n", sum + 1);

	}

	return 0;
}
