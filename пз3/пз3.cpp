#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
/*
A ~ (!B^C v !(A^D) -> !(C^D))
*/
/*
порядок действий
1. !B
2. (1) ^ C
3. A ^ D
4. !(3)
5. (2) v (4)
6. C ^ D
7. !(6)
8. (5) -> (7)
9. A ~ (8)
*/
bool converting(int func, bool x, bool y)
{
	switch (func)
	{
	case 12:
		/* ¬x*/
		return !x;
		break;
	case 1:
		/* x ^ y */
		return (x && y);
		break;
	case 7:
		/* x v y*/
		return (x || y);
		break;

	case 9:
		/* Eqv */
		if (x == y)
			return 1;
		break;
	case 13:
		/* Imp */
		/* x -> y = !x v y */
		return converting(7, converting(12, x, 0), y);
	}
}
void print(int f, string func) {
	int len = func.length() / 2 + 1;
	if (func.length() % 2 == 0) {
		len--;
		cout << " ";
	}
	for (int i = 0; i < len; i++) {
		cout << " ";
	}
	cout << f;
	for (int i = 0; i < len; i++) {
		cout << " ";
	}
	cout << "|";
}
int main()
{
	string funcs[] = { "", "a", "b", "c", "d", "!B", "!B^C", "A^D", "!(A^D)", "!B^C v !(A ^ D)", "C ^ D","!(C ^ D)", "(!B ^ C v !(A ^ D))-> !(C ^ D)", "A~(!B ^ C v !(A ^ D))-> !(C ^ D)" };
	cout << "\nFunction: A ~ (!B^C v !(A^D) -> !(C^D))\n" << endl;
	cout << "+---+---+---+---+----+------+-----+--------+---------------+-----+--------+------------------------- - +---------------------------- + " << endl;
	cout << "| a | b | c | d | !B | !B^C | A^D | !(A^D) | !B^C v !(A^D) | C^D | !(C^D) |(!B ^ C v !(A ^ D))-> !(C ^ D) | A~(!B ^ C v !(A ^ D))-> !(C ^ D) | " << endl;
	cout << "+---+---+---+---+----+------+-----+--------+---------------+-----+--------+------------------------- - +---------------------------- + " << endl;
	bool f1, f2, f3, f4, f5, f6, f7, f8, f9 = 0;
	for (int a = 0; a < 2; a++)
	for (int b = 0; b < 2; b++)
	for (int c = 0; c < 2; c++)
	for (int d = 0; d < 2; d++)
	{
	cout << "|";
	print(a, funcs[1]);
	print(b, funcs[2]);
	print(c, funcs[3]);
	print(d, funcs[4]);
	f1 = converting(12, b, 0);
	f2 = converting(1, f1, c);
	print(f1, funcs[5]);
	print(f2, funcs[6]);
	f3 = converting(1, a, d);

	f4 = converting(12, f3, 0);
	print(f3, funcs[7]);
	print(f4, funcs[8]);
	f5 = converting(7, f2, f4);
	print(f5, funcs[9]);
	f6 = converting(1, c, d);
	f7 = converting(12, f6, 0);
	print(f6, funcs[10]);
	print(f7, funcs[11]);
	f8 = converting(13, f5, f7);
	f9 = converting(9, a, f8);
	print(f8, funcs[12]);
	print(f9, funcs[13]);
	cout << endl;

	}
	cout << "+---+---+---+---+----+------+-----+--------+---------------+-----+--------+------------------------- - +---------------------------- + " << endl;
	return 0;
	}