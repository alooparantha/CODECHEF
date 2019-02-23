#include <bits/stdc++.h>

using namespace std;

int is_prime(int length) 
{
	for (int i = 2; i < length; i++) {
		if (length % i == 0) {
			return 0;
		}
	}

	return 1;
}

void prime(string str) 
{
	set <int> fact;
	array <int, 26> hash {0,0};
	
	for(int i = 0; i < str.length(); i++) {
			hash[str[i] - 'A']++;
			 //cout<< hash[str[i] - 'A'] << "-- ";
	}

	if (str.length() > 26) {
		auto it = max_element(hash.begin(), hash.end());

		int opr = str.length() - (*it);
		cout << opr << endl;
	} else {
		int val = count(hash.begin(), hash.end(), 1);
		int val1 = 0;
		for (int i = 0; i < 26; i++) {
			if (hash[i] > 1) {
				val1++;
			}
		}
		
		int opr1 = str.length() - (val + val1);

		auto it = max_element(hash.begin(), hash.end());

		int opr2 = str.length() - (*it) ;

		if (opr1 < opr2) {
			cout << opr1 << endl;
		} else {
			cout << opr2 << endl;
		}
	}

}

void not_prime(string str) 
{
	set <int> fact;
	array <int, 26> hash {0};
	vector <int> vec;

	for (int i = 1; i <= sqrt(str.length()); i++) {
		if (str.length() % i == 0 ) {
			fact.insert(i);
			fact.insert(str.length() / i);
		}
	}

	for (int i = 0; i < str.length(); i++) {
		hash[str[i] - 'A']++;
	}

	auto it = fact.begin();

	while (it != fact.end() ) {
		int opr;

		if( (*it == 1) &&  str.length() <= 26) {
			opr = 0;

			for_each(hash.begin(), hash.end(), [&opr](int &x) { if(x != 0) opr += (x-1);});
			
			vec.push_back(opr);
			cout <<"For " << *it << "-->"<< opr << endl;

		} else if ((*it >1 && *it < str.length()) && (*it) * 26 >= str.length()) {

			opr = 0;
			
			array <int, 26> rough = hash;
			
			sort(rough.begin(), rough.end());

			auto it1 = rough.rbegin();

			int change = 0;

			while (it1 != rough.rend() && *it1 != 0) {
				//This one is to count the leverage
				if (*it1 >= *it) {
					change += (*it1 - *it);
					opr += (*it1 - *it);
					//cout << opr <<"buffer"<< endl;
					it1++;
				} else if (*it1 < *it) {
					if (change != 0 ) {
						//spending the leverage
						while(change != 0) {
							if(*it1 == *it) { 
								break;
							} else {
								change--;
								*it1++;
							}
						}
						if (*it1 != *it) {
							
				
							for (int i = 0 ; i < 26; ) {
								if (rough[i] != 0) {
									if(*it1 == *it) 
										break;
										rough[i]--;
										*it1++;
										opr++;
									//	cout << "updated value change 1 : " << opr << endl;
									} else {
										i++;
									}
								}
							}
						it1++;
						} else if (change == 0 ) {
							//No leverage
							
				
							for(int i = 0; i < 26;) {
								if (rough[i] != 0) {
										if(*it == *it1)
											break;
										rough[i]--;
										*it1++;
										opr++;
									//	cout << " updated value change 0 " << opr << endl;
									} else {
										i++;
									}
								}
							it1++;
							}

						}
			
				}
			cout << "For " << *it << "--> " << opr+change <<endl;
			vec.push_back(opr+change);
			

			}  else if (*it == str.length()) {
				opr = 0;
				auto i = max_element(hash.begin(), hash.end());
				opr = str.length() - (*i);
				cout <<"For " << *it << "--> "<< opr << endl;
				vec.push_back(opr);
			}

			++it;
		}

		cout << *min_element(vec.begin(), vec.end()) << endl;


	}

int main()
{
	int t;
	string str;
	cin >> t;

	while (t--) {
		cin >> str;
		int length = str.length();

		int value = is_prime(length);

		if (value == 1) {
			prime(str);
		} else if (value == 0) {
			not_prime(str);
		}
		
	}

	return 0;
}
