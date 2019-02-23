#include <stdio.h>
#include <stdlib.h>


long long int gcd( long int a,long long int b)
  {
  	if(b == 0) {
		return a;
	}else {
		return gcd(b , a % b);
	}
  }

int main()
{
	int t;
	long long int a;
	long long int b;
	long long int k;
	long long int n;

	scanf("%d", &t);

	while (t--) {
	
		scanf("%lld %lld %lld %lld",&n, &a, &b, &k);

	
		long long int two;
		long long int three;
		long long int both;
		long long int lcm;

		lcm = (a * b) / gcd (a, b);

		two = n / a;
		three = n / b;
		both = n / lcm;

//		printf("%lld %lld %lld" , two , three , both);

		if ( (two + three - 2 * both) < k ) {
			printf("Lose\n");
		} else {
			printf("Win\n");
		}
	}

	return 0;
}	
