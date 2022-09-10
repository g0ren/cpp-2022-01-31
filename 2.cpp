/*
 * Написать программу с функцией сортировки трех значений с возможностью задать направление сортировки.
 * Реализовать тестирующую программу.
 Подробно:
 Создать функцию:
 void sort ( double *a, double *b, double *c, bool asc = 0);
 которая выполняет сортировку трех значений с возможностью задать направление сортировки.
 Параметры функции:
 a, b, c – значения для сортировки.
 asc — флаг направления сортировки:
 — false — по убыванию (по умолчанию),
 — true — по возрастанию.
 Возвращаемое значение: нет
 Результат:
 a, b, c отсортированные по хранимым значениям в соответствии со значением asc.
 */
#define MAX(X,Y) (((X)>(Y))?(X):(Y))
#define MIN(X,Y) (((X)<(Y))?(X):(Y))

void sort(double *a, double *b, double *c, bool asc = 0);

#include <iostream>
using namespace std;

int main() {
	double *a = new double { };
	double *b = new double { };
	double *c = new double { };
	cout << "Enter three numbers:" << endl;
	cin >> *a;
	cin >> *b;
	cin >> *c;
	cout << endl;
	sort(a, b, c, 1);
	cout << endl;
	sort(a, b, c, 0);
	delete a;
	delete b;
	delete c;
	return 0;
}

void sort(double *a, double *b, double *c, bool asc) {
	double min { MIN(*a, MIN(*b, *c)) };
	double mid { MIN(MIN(MAX(*a, *b), MAX(*b, *c)), MAX(*a, *c)) };
	double max { MAX(*a, MAX(*b, *c)) };
	if (asc) {
		cout << min << endl;
		cout << mid << endl;
		cout << max << endl;
	} else {
		cout << max << endl;
		cout << mid << endl;
		cout << min << endl;
	}
}
