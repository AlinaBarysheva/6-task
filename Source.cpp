#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> mtrx;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(-999, 999);

	for (int i = 0; i < n; ++i) {
		vector<int> line;
		for (int j = 0; j < m; ++j) {
			int num = distribution(generator);
			line.push_back(num);
		}
		mtrx.push_back(line);
	}

	for (int i = 0; i < mtrx.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < mtrx[i].size(); ++j) {			// ������� ����� ��������� i-�� ������.
			sum += mtrx[i][j];
		}
		mtrx[i].push_back(sum);								// ��������� ����������� ����� m + 1 ��������� i-�� ������.
	}

	vector<int> line;										// ������ ������ ������.
	for (int j = 0; j < mtrx[0].size(); ++j) {
		int sum = 0;
		for (int i = 0; i < mtrx.size(); ++i) {				// ������� ����� j-��� �������.
			sum += mtrx[i][j];
		}
		line.push_back(sum);								// ��������� �������� ����� �� j ������� � ����� ������.
	}
	mtrx.push_back(line);									// ��������� �������������� ������ � �������.
	
	for (int i = 0; i < mtrx.size(); ++i) {
		for (int j = 0; j < mtrx[i].size(); ++j) {
			cout << mtrx[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}