#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int num;
	int budget;
	int len;
	int wid;
	int price;
	int max;

	cin >> t;

	while (t--) {
		cin >> num >> budget;
		
		int area;
		
		int arr[num][3];

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < 3 ; j++) {
				cin >> arr[i][j];
			} 
		}

		max = 0;

		for (int i = 0; i < num; i++) {
			if ( arr[i][2] <= budget) {
				area = arr[i][0] * arr[i][1];
				if (area > max) {
					max = area;
				}
			}
		}
	
	if (max == 0) {
		cout << "no tablet" << endl;
	} else {
		cout << max << endl;
	}
	}

	return 0;

}
