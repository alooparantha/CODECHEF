#include <bits/stdc++.h>

using namespace std;

int main()

{
//	array <int, 100000> arr {0};

	int t;
	int n;
	int k;

	int l;
	int r;

	cin >> t;

	while (t--) {
		cin >> n >> k;

		int arr[n][2];
		int val = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> arr[i][j];
				if (arr[i][j] > val) 
					val = arr[i][j];
			}
		}

		int rmv;

		int max;

		max = INT_MIN;

		rmv = 0;

		int j;

		int rough[val + 1];

		for (int i = 0; i < val + 1; i++) {
			rough[i] = 0;
		}

		
			for (int i = 0; i < n; i++) {
				if(i != rmv) {
					l = arr[i][0];
					r = arr[i][1];

				for (int x = l; x <= r; x++) {
					rough[x]++;		
				}

				int val1;
				val1 = count(rough, rough + val, k);

				if(val > max)
					max = val;
				}
			}

		cout << max << endl;
	}

	return 0;
}
