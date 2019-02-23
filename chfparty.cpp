#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	int num;

	cin >> t;

	while (t--) {
		vector <int> vec;
		
		cin >> num;
		int data;

		for (int i = 0; i < num; i++) {
			cin >> data;
			vec.push_back(data);
		}

		sort(vec.begin(), vec.end());

		int val;

		val = 0; 
		int  join ;

		join = 0;

		for (int i = 0; i < num; i++) {
			if ( vec.at(i) == 0) {
				val++;
				} else if (vec.at(i) <= val) {
				val++;
			}
		}

		cout << val << endl;
	}

	return 0;
}
