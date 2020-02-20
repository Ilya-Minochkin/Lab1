// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>

#define N 5
using namespace std;

float v[N][N];


void obmen1(int a, int b) {
	int *v1;
	v1 = &a;
	*v1 = 1;
}

void obmen2(int *a, int *b) {
	int v;
	v = *a;
	*a = *b;
	*b = v;

	swap(a, b);
}

void obmen3(int &a, int &b) {
	//int v;
	//v = a;
	//a = b;
	//b = v;

	swap(a, b);

}
void buildTriangleMatrix(float f[N][N])
{
	int i, j, k;
	//float v[N][N];
	for ( k = 1; k <= N; k++ )
	{
		for (int i = k; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				f[i][j] = f[i][j] - (f[k-1][j] * f[i][k-1]) / f[k-1][k-1];
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v[i][j] = f[i][j];
		}
		cout << endl;
	}
}

void findMinOrMax(float m[N][N], string stance)
{
	float v = m[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (stance == "min")
			{
				if (m[i][j] < v) v = m[i][j];
			}
			else if (stance == "max")
			{
				if (m[i][j] > v) v = m[i][j];
			}

		}
	}

	cout << stance << ":" << v << endl;
}
void findMinOrMaxTriangle(float m[N][N], string stance)
{
	float v = m[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N-i; j++)
		{
			//j += i;
			if (stance == "min")
			{
				if (m[i][j] < v) v = m[i][j];
			}
			else if (stance == "max")
			{
				if (m[i][j] > v) v = m[i][j];
			}

		}
	}

	cout << stance << ":" << v << endl;
	cout << endl;
}

void findMinOrMaxDiag(float m[N][N], string stance, string diag)
{

	if (diag == "main")
	{
		float v = m[0][0];
		for (int i = 0; i < N; i++)
		{
			if (stance == "min")
			{
				if (m[i][i] < v) v = m[i][i];
			}
			else if (stance == "max")
			{
				if (m[i][i] > v) v = m[i][i];
			}

		}

		cout << stance << ":" << v << endl;
		cout << endl;
	}
	else if (diag == "sub")
	{
		float v = m[0][4];
		for (int i = 0; i < N; i++)
		{
			//for (int j = N - 1; j >= 0; j--)
			//{
				if (stance == "min")
				{
					if (m[i][N - i - 1] < v) v = m[i][N - i - 1];
				}
				else if (stance == "max")
				{
					if (m[i][N - i - 1] > v) v = m[i][N - i - 1];
				}
			//}


		}
		cout << stance << ":" << v << endl;
		cout << endl;
	}

}
int main()
{
//{
//
//	int a = 2, b = 5;
//	cout << a << endl << b << endl;
//	obmen2(&a, &b);
//	cout << a << endl << b << endl;
//	//obmen3(a, b);
//	//cout << a << endl << b << endl;
//  
//
float m[N][N];
int i, j;
for (i = 0; i < N; i++)
{
	for (j = 0; j < N; j++)
	{
		m[i][j] = rand() / 10.;
	}
}
for (i = 0; i < N; i++)
{
	for (j = 0; j < N; j++)
	{
		cout << setw(8) << setprecision(5) << m[i][j];
	}
	cout << endl;
}
findMinOrMax(m, "min");
//buildTriangleMatrix(m);
for (i = 0; i < N; i++)
{
	for (j = 0; j < N; j++)
	{
		cout << setw(8) << setprecision(5) << m[i][j];
	}
	cout << endl;
}
findMinOrMaxTriangle(v, "max");


for (i = N-1; i >= 0; i--)
{
	for (j = N-1; j >= 0; j--)
	{
		cout << setw(8) << setprecision(5) << m[i][j];
	}
	cout << endl;
}


findMinOrMaxDiag(m, "min", "sub");

cout << "TestCo1it";



//getch();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
