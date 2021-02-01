/*input
10 10 20 30
10 9
2 4
9 9
9 2
1 2
6 10
7 10
2 10
1 2
9 8
2 1
5 1
2 1
1 8
8 10
7 7
9 8
10 9
9 10
2 9
3 7 10 2
9 1 1 9
4 9 8 7
1 3 8 4
3 10 1 10
9 10 8 9
7 9 7 7
10 9 7 3
7 6 4 5
8 4 5 1
8 3 10 5
9 8 10 9
3 7 6 10
5 1 6 2
6 9 7 10
7 3 8 4
6 3 7 2
5 10 9 6
6 10 10 6
1 5 4 2
1 4 1 1
10 10 10 7
8 7 8 7
5 9 5 7
8 10 5 10
6 4 5 4
2 7 2 7
4 7 4 7
6 4 6 4
10 10 10 10

*/

#include <bits/stdc++.h>
using namespace std;

struct query {
	int a, queryType, leftY, rightY, queryID;
};

bool comp( query &qi,  query &qj) {
	if(qi.a == qj.a) {
		return (qi.queryType > qj.queryType);
	}
	else return (qi.a < qj.a);
}

bool swapped[100005];

int ans[100005][2];

int fen[100005][3];

int n, m, z, p;

int max_N;

void update(int idex, int typ){
    for(int i = idex; i <= max_N; i += i & -i)
        fen[i][typ] ++;
}

int sum(int idex, int typ) {
    int ans = 0;
    for(int i = idex; i; i -= i & -i)
        ans += fen[i][typ];
    return ans;
}

int get(int l, int r, int typ) {
	if(l > r) return 0;
	else return sum(r, typ) - sum(l - 1, typ);
}

signed main() {
	
	cin >> n >> m >> z >> p;
	// n *= 2, m *= 2;

	set<int> values;
	map<int, int> valuesMap;

	int infN = n + 1, infM = m + 1;
	vector<query> queries;

	for(int i = 0; i < z; i++) {

		int x, y;
		cin >> x >> y;
		// x *= 2, y *= 2;

		queries.push_back(query{x, 3, y, y, -1});
		queries.push_back(query{x - y, 4, y, y, -1});
		queries.push_back(query{x + y, 5, y, y, -1});

		values.insert(y);
	}

	values.insert(infM);
	values.insert(0);

	for(int i = 0; i < p; i++) {

		int px, py, qx, qy;

		cin >> px >> py >> qx >> qy;
		// px *= 2, py *= 2, qx *= 2, qy *= 2;

		if(px != qx) {
			if(px > qx) {
				swap(px, qx);
				swap(py, qy);
				swapped[i] = 1;
			}
		}
		else if(py > qy) {
			swap(py, qy);
			swapped[i] = 1;
		}

		int temp = (abs(qx - px) + abs(qy - py));

		if(px == qx) {
			if(py == qy) 
				ans[i][1] = z;
			else {
				if(temp % 2 == 0) {
					queries.push_back(query{infN, 0, 0, (py + qy) / 2 - 1, i * 2});
					queries.push_back(query{infN, 0, 0, (py + qy) / 2, i * 2 + 1});
				}
				else {
					queries.push_back(query{infN, 0, 0, (py + qy) / 2, i * 2});
					queries.push_back(query{infN, 0, 0, (py + qy) / 2, i * 2 + 1});
				}
				
			}
		}
		else {
			if(py < qy) {
				if(qx - px > qy - py) {

					if(temp % 2 == 0) {

						temp /= 2;

						queries.push_back(query{qx - temp - 1, 0, qy, infM, i * 2});
						queries.push_back(query{qx - temp + qy - 1, 2, py + 1, qy - 1, i * 2});
						queries.push_back(query{px + temp - 1, 0, 0, py, i * 2});

						queries.push_back(query{qx - temp, 0, qy, infM, i * 2 + 1});
						queries.push_back(query{qx - temp + qy, 2, py + 1, qy - 1, i * 2 + 1});
						queries.push_back(query{px + temp, 0, 0, py, i * 2 + 1});
					}
					else {
						queries.push_back(query{qx - temp / 2 - 1, 0, qy, infM, i * 2});
						queries.push_back(query{qx - temp / 2 + qy - 1, 2, py + 1, qy - 1, i * 2});
						queries.push_back(query{px + temp / 2, 0, 0, py, i * 2});

						queries.push_back(query{qx - temp / 2 - 1, 0, qy, infM, i * 2 + 1});
						queries.push_back(query{qx - temp / 2 + qy - 1, 2, py + 1, qy - 1, i * 2 + 1});
						queries.push_back(query{px + temp / 2, 0, 0, py, i * 2 + 1});
					}

				}
				else if(qx - px == qy - py) {

					queries.push_back(query{px + qy - 1, 2, py + 1, qy - 1, i * 2});
					queries.push_back(query{qx - 1, 0, 0, py, i * 2});

					queries.push_back(query{infN, 0, 0, py, i * 2 + 1});
					queries.push_back(query{px + qy, 2, py + 1, qy - 1, i * 2 + 1});
					queries.push_back(query{px, 0, qy, infM, i * 2 + 1});

				}
				else {

					if(temp % 2 == 0) {
						temp /= 2;
						queries.push_back(query{infN, 0, 0, qy - temp - 1, i * 2});
						queries.push_back(query{qy - temp + qx - 1, 2, qy - temp, py + temp - 1, i * 2});

						queries.push_back(query{infN, 0, 0, qy - temp, i * 2 + 1});
						queries.push_back(query{qy - temp + qx, 2, qy - temp + 1, py + temp, i * 2 + 1});
					}
					else {

						queries.push_back(query{infN, 0, 0, qy - temp / 2 - 1, i * 2});
						queries.push_back(query{qy - temp / 2 - 1 + qx, 2, qy - temp / 2, py + temp / 2, i * 2});

						queries.push_back(query{infN, 0, 0, qy - temp / 2 - 1, i * 2 + 1});
						queries.push_back(query{qy - temp / 2 - 1 + qx, 2, qy - temp / 2, py + temp / 2, i * 2 + 1});

					}	
				}
			}
			else if(py == qy) {

				if(temp % 2 == 0) {
					temp /= 2;
					queries.push_back(query{px + temp - 1, 0, 0, infM, i * 2});

					queries.push_back(query{px + temp, 0, 0, infM, i * 2 + 1});
				}
				else {
					queries.push_back(query{px + temp / 2, 0, 0, infM, i * 2});

					queries.push_back(query{px + temp / 2, 0, 0, infM, i * 2 + 1});
				}

				
			}
			else {
				if(qx - px > py - qy) {

					if(temp % 2 == 0) {
						temp /= 2;

						queries.push_back(query{qx - temp - 1, 0, 0, qy, i * 2});
						queries.push_back(query{qx - temp - qy - 1, 1, qy + 1, py - 1, i * 2});
						queries.push_back(query{px + temp - 1, 0, py, infM, i * 2});

						queries.push_back(query{qx - temp, 0, 0, qy, i * 2 + 1});
						queries.push_back(query{qx - temp - qy, 1, qy + 1, py - 1, i * 2 + 1});
						queries.push_back(query{px + temp, 0, py, infM, i * 2 + 1});
					}
					else {
						queries.push_back(query{qx - temp / 2 - 1, 0, 0, qy, i * 2});
						queries.push_back(query{qx - temp / 2 - qy - 1, 1, qy + 1, py - 1, i * 2});
						queries.push_back(query{px + temp / 2, 0, py, infM, i * 2});

						queries.push_back(query{qx - temp / 2 - 1, 0, 0, qy, i * 2 + 1});
						queries.push_back(query{qx - temp / 2 - qy - 1, 1, qy + 1, py - 1, i * 2 + 1});
						queries.push_back(query{px + temp / 2, 0, py, infM, i * 2 + 1});

					}
					
					

				}
				else if(qx - px == py - qy) {
					
					queries.push_back(query{qx - 1, 0, py, infM, i * 2});
					queries.push_back(query{qx - py - 1, 1, qy + 1, py - 1, i * 2});

					queries.push_back(query{px, 0, 0, qy, i * 2 + 1});
					queries.push_back(query{px - qy, 1, qy + 1, py - 1, i * 2 + 1});
					queries.push_back(query{infN, 0, py, infM, i * 2 + 1});

				}
				else {
					if(temp % 2 == 0) {
						temp /= 2;
						queries.push_back(query{px - py + temp - 1, 1, py - temp + 1, qy + temp, i * 2});
						queries.push_back(query{infN, 0, qy + temp + 1, infM, i * 2});

						queries.push_back(query{px - py + temp, 1, py - temp, qy + temp - 1, i * 2 + 1});
						queries.push_back(query{infN, 0, qy + temp, infM, i * 2 + 1});
					}
					else {
						queries.push_back(query{px - py + temp / 2, 1, py - temp / 2, qy + temp / 2, i * 2});
						queries.push_back(query{infN, 0, qy + temp / 2 + 1, infM, i * 2});

						queries.push_back(query{px - py + temp / 2, 1, py - temp / 2, qy + temp / 2, i * 2 + 1});
						queries.push_back(query{infN, 0, qy + temp / 2 + 1, infM, i * 2 + 1});
					}
					
				}
			}
		}
	}

	// define a query of 3 types: |, / and \
	// respectively:			  0, 1 and 2
	// 0: x <= a
	// 1: x - y <= a
	// 2: x + y <= a
	// a query is of type query, takes in five values: the "a" value, the type of query, the leftY and rightY values, with the queryID
	// the queries are then sorted by the "a" value, and the answer is given using Interval Tree
	// for updating, we also have 3 type: |, / and \
	// respectively:					  3, 4 and 5

	sort(queries.begin(), queries.end(), comp);

	// for(int i = 0; i < queries.size(); i ++) {
	// 	// if(queries[i].queryType % 3 == 0)
	// 		cout << queries[i].a << " " << queries[i].queryType << " " << queries[i].leftY << " " << queries[i].rightY << " " << queries[i].queryID << "\n";

	// }
	// cout << "\n";

	for(auto it = values.begin(); it != values.end(); it++) {
		valuesMap[*it] = valuesMap.size() + 1;
	}

	max_N = valuesMap.size();

	for(int i = 0; i < queries.size(); i++) {
		if(queries[i].queryID == -1) {
			queries[i].leftY = valuesMap[queries[i].leftY];
			queries[i].rightY = valuesMap[queries[i].rightY];
		}
		else {
			set<int>::iterator it = values.lower_bound(queries[i].leftY);
			queries[i].leftY = valuesMap[*it];
			it = values.upper_bound(queries[i].rightY);
			it--;
			queries[i].rightY = valuesMap[*it];
		}
		
	}

	// for(int i = 0; i < queries.size(); i ++) {
	// 	cout << queries[i].a << " " << queries[i].queryType << " " << queries[i].leftY << " " << queries[i].rightY << " " << queries[i].queryID << "\n";

	// }

	for(int i = 0; i < queries.size(); i++) {
		if(queries[i].queryType >= 3) {
			update(queries[i].leftY, queries[i].queryType % 3);
		}
		else {
			// if(queries[i].queryID / 2 == 0) {
			// 	cout << queries[i].queryID << " " << get(queries[i].leftY, queries[i].rightY, queries[i].queryType) << "\n";
			// }
			ans[queries[i].queryID / 2][queries[i].queryID % 2] += get(queries[i].leftY, queries[i].rightY, queries[i].queryType);
		}
	}

	for(int i = 0; i < p; i++) {
		// cout << swapped[i] << " " << endl;
		if(!swapped[i])
			cout << ans[i][0] << " " << z - ans[i][1] << " " << ans[i][1] - ans[i][0] << "\n";
		else
			cout << z - ans[i][1] << " " << ans[i][0] << " " << ans[i][1] - ans[i][0] << "\n";
	}

	return 0;

}