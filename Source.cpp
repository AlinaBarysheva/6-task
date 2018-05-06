Условие: Дана матрица m*n,посчитать суммы в каждой строке и столбце.
Вывести суммы строк в конце каждой строки,аналогично для столбцов сумму аод каждым столбцом.
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
		for (int j = 0; j < mtrx[i].size(); ++j) {		// Считаем сумму элементов i-ой строки.
			sum += mtrx[i][j];
		}
		mtrx[i].push_back(sum);					// Добавляем посчитанную сумму m + 1 элементов i-ой строки.
	}

	vector<int> line;						// Создаём пустую строку.
	for (int j = 0; j < mtrx[0].size(); ++j) {
		int sum = 0;
		for (int i = 0; i < mtrx.size(); ++i) {			// Находим сумму  j-ого столбца.
			sum += mtrx[i][j];
		}
		line.push_back(sum);				        // Добавляем найденную сумму на j позицию в новую строку.
	}
	mtrx.push_back(line);						// Добавляем сформированную  строку к матрице.
	
	for (int i = 0; i < mtrx.size(); ++i) {
		for (int j = 0; j < mtrx[i].size(); ++j) {
			cout << mtrx[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}
