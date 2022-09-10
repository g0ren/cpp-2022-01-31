/*
 * Дано целое число. Определить количество и сумму цифр в десятичной записи этого числа. Вывести само число,
 * сумму цифр  и число, получающееся из него при вычеркивании первой и последней цифр.
 Указания:
 Оформить в виде функций каждое из действий:
 • определение количества цифр в десятичной записи числа:
 int count_dig(int a); //параметр передается по значению
 • вычисление суммы цифр числа:
 int sum_dig(int a); //параметр передается по значению
 • преобразование числа путем вычеркивания из него первой и последней цифры:
 void del_last_dig(int* a); //параметр передается по указателю
 int del_first_dig(int* a); //параметр передается по указателю
 *
 */
#include <iostream>
using namespace std;

int count_dig(int a);
int sum_dig(int a);
void del_last_dig(int *a);
int del_first_dig(int *a);

int pow(int n, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return n;
	if (!(p % 2)) {
		return pow(n * n, p / 2);
	} else {
		return n * pow(n * n, (p - 1) / 2);
	}
}

int main() {
	int a { 2128507 };
	cout << "a=" << a << endl;
	cout << "There are " << count_dig(a) << " digits" << endl;
	cout << "Sum of digits is " << sum_dig(a) << endl;
	cout << "Without the first digit a is " << del_first_dig(&a) << endl;
	del_last_dig(&a);
	cout << "Without the last digit a is " << a << endl;

	return 0;
}

int del_first_dig(int *a) {
	int r { *a };
	r %= pow(10, count_dig(r) - 1);
	return r;
}

void del_last_dig(int *a) {
	*a /= 10;
}

int count_dig(int a) {
	if (a / 10 == 0)
		return 1;
	return 1 + count_dig(a / 10);
}

int sum_dig(int a) {
	if (a / 10 == 0)
		return a;
	return (a % 10) + sum_dig(a / 10);
}
