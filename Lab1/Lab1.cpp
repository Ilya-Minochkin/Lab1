#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>

#define N 5
#define MIN "min"
#define MAX "max"
#define MAXSTACK 2048
using namespace std;

float v[N][N];
float avg = 0;




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
	for (k = 1; k <= N; k++)
	{
		for (int i = k; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				f[i][j] = f[i][j] - (f[k - 1][j] * f[i][k - 1]) / f[k - 1][k - 1];
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
		for (int j = i; j < N - i; j++)
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

float findAverage(float f[N][N])
{
	int i, j, count = 0;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[i][j];
			count++;
		}
	}
	cout << "Average :" << v / count << endl;
	return v / count;
}

void findSummRow(float f[N][N])
{
	int i, j;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[i][j];
		}
		cout << "Summ row №" << i + 1 << " = " << v << endl;
		v = 0;
	}
}

void findSummCol(float f[N][N])
{
	int i, j;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[j][i];
		}

		cout << "Summ col №" << i + 1 << " = " << v << endl;
		v = 0;
	}
}

void findMinOrMaxRow(float f[N][N], string stance)
{
	int i, j;
	float v = f[0][0];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (stance == "min")
			{
				if (v > f[i][j]) v = f[i][j];
			}
			else if (stance == "max")
			{
				if (v < f[i][j]) v = f[i][j];
			}
		}
		cout << stance << " of " << i + 1 << "str = " << v << endl;
		v = f[i][j];
	}

}

void findMinOrMaxCol(float f[N][N], string stance)
{
	//int i, j, count = 0;
	float v = f[0][0];
	int j = 0;
	//for (i = 0; i < N; i++)
	//{
	//	for (j = 0; j < N-1; j++)
	//	{
	//		if (stance == "min")
	//		{
	//			if (v > f[j][i]) v = f[j][i];
	//			count++;
	//		}
	//		else if (stance == "max")
	//		{
	//			if (v < f[j][i]) v = f[j][i];
	//		}
	//	}
	//	cout << stance << " of " << i + 1 << "col = " << v << endl;
	//	v = f[j][i];
	//}
	for (int i = 0; i < N; i++)
	{
		j = 0;
		v = f[j][i];
		for (j = 0; j < N; j++)
		{
			if (stance == "min")
			{
				if (v > f[j][i]) v = f[j][i];
				//count++;
			}
			else if (stance == "max")
			{
				if (v < f[j][i]) v = f[j][i];
			}
		}
		cout << stance << " of " << i + 1 << "col = " << v << endl;
	}
}

void findAverageRow(float f[N][N])
{
	int i, j, count;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[i][j];
		}
		cout << "average " << "of " << i + 1 << "str = " << v / N << endl;
		v = 0;
	}
}

void findAverageCol(float f[N][N])
{
	int i, j, count;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[j][i];
		}
		cout << "average " << "of " << i + 1 << "col = " << v / N << endl;
		v = 0;
	}
}

void findSumTriangleMatrix(float f[N][N])
{
	int i, j;
	float v = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			v += f[i][j];
		}
	}

	cout << "Sum of 2 triangle matrix is " << v * 2 << endl;
}

float findCloserToAverage(float f[N][N])
{
	int k = 0, l = 0;
	float avg = findAverage(f);
	float diff = INFINITY;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(avg - f[i][j]) < diff)
			{
				diff = abs(avg - f[i][j]);
				k = i;
				l = j;
			}
		}
	}
	return f[k][l];
}






int mainLab1and2()
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
	findMinOrMax(m, MIN);
	//buildTriangleMatrix(m);


	findMinOrMaxDiag(m, MIN, "sub");
	cout << endl;

	findAverage(m);
	cout << endl;

	findSummRow(m);
	cout << endl;

	findSummCol(m);
	cout << endl;

	findMinOrMaxRow(m, MAX);
	cout << endl;

	findMinOrMaxCol(m, MIN);
	cout << endl;


	findAverageRow(m);
	cout << endl;

	findAverageCol(m);
	cout << endl;

	cout << "Closer to average is " << findCloserToAverage(m)  << endl;



	buildTriangleMatrix(m);
	findSumTriangleMatrix(m);
		findMinOrMaxTriangle(v, MAX);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << setw(8) << setprecision(5) << m[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (i = N - 1; i >= 0; i--)
		{
			for (j = N - 1; j >= 0; j--)
			{
				cout << setw(8) << setprecision(5) << m[i][j];
			}
			cout << endl;
		}
		return 0;
	//getch();
}


void showArray(int arr[], int arraySize)
{
	//int buffArr[] = arr;
	int n = arraySize;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void sortBubble(int arr[], int arraySize)
{
	int i, j, x, n = arraySize;
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			x = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = x;
		}
	}
}

void minMaxSort(int arr[], int arraySize)
{
	int iMin, n = arraySize;
	for (int i = 0; i < n; i++)
	{
		iMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[iMin]) iMin = j;
		}
		int t = arr[i];
		arr[i] = arr[iMin];
		arr[iMin] = t;
	}
}


void quickSort(int arr[], int arraySize)
{
	int i, j;
	int lb, ub;
	int lbstack[MAXSTACK], ubstack[MAXSTACK];
	int stackPos = 1;
	int ppos;
	int pivot;
	int temp;
	lbstack[1] = 0; ubstack[1] = arraySize - 1;
	do {
		lb = lbstack[stackPos]; 
		ub = ubstack[stackPos];
		stackPos--;
		do {
			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = arr[ppos];
			do {
				while (arr[i] < pivot) i++;
				while (pivot < arr[j]) j--;
				if (i <= j)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
			}
			while (i <= j);
			if (i < ppos)
			{
				if (i < ub)
				{
					stackPos++;
					lbstack[stackPos] = i;
					ubstack[stackPos] = ub;
				}
				ub = j;
			}
			else
			{
				if (j > lb) 
				{
					stackPos++;
					lbstack[stackPos] = lb;
					ubstack[stackPos] = j;
				}
				lb = i;
			}
		} while (lb < ub);
	} while (stackPos != 0);
}

void quickSort(int arr[], int arraySize, int lowb, int upperb)
{
	int i, j;
	int lb, ub;
	int lbstack[MAXSTACK], ubstack[MAXSTACK];
	int stackPos = 1;
	int ppos;
	int pivot;
	int temp;
	lbstack[1] = lowb; ubstack[1] = upperb - 1;
	do {
		lb = lbstack[stackPos];
		ub = ubstack[stackPos];
		stackPos--;
		do {
			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = arr[ppos];
			do {
				while (arr[i] < pivot) i++;
				while (pivot < arr[j]) j--;
				if (i <= j)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
			} while (i <= j);
			if (i < ppos)
			{
				if (i < ub)
				{
					stackPos++;
					lbstack[stackPos] = i;
					ubstack[stackPos] = ub;
				}
				ub = j;
			}
			else
			{
				if (j > lb)
				{
					stackPos++;
					lbstack[stackPos] = lb;
					ubstack[stackPos] = j;
				}
				lb = i;
			}
		} while (lb < ub);
	} while (stackPos != 0);
}

void quickSortDESC(int arr[], int arraySize, int lowb, int upperb)
{
	int i, j;
	int lb, ub;
	int lbstack[MAXSTACK], ubstack[MAXSTACK];
	int stackPos = 1;
	int ppos;
	int pivot;
	int temp;
	lbstack[1] = lowb; ubstack[1] = upperb - 1;
	do {
		lb = lbstack[stackPos];
		ub = ubstack[stackPos];
		stackPos--;
		do {
			ppos = (lb + ub) >> 1;
			i = lb; j = ub; pivot = arr[ppos];
			do {
				while (arr[i] > pivot) i++;
				while (pivot > arr[j]) j--;
				if (i <= j)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
			} while (i <= j);
			if (i < ppos)
			{
				if (i < ub)
				{
					stackPos++;
					lbstack[stackPos] = i;
					ubstack[stackPos] = ub;
				}
				ub = j;
			}
			else
			{
				if (j > lb)
				{
					stackPos++;
					lbstack[stackPos] = lb;
					ubstack[stackPos] = j;
				}
				lb = i;
			}
		} while (lb < ub);
	} while (stackPos != 0);
}
void sortEvenUneven(int arr[], int arraySize)
{
	int i, j, count = 0, k = 0, temp, evenCount = 0, unevenCount = 0;
	for (i = 0; i < arraySize; i++)
	{
		if (arr[i] % 2 == 0) evenCount++;
		else unevenCount++;
	}
	
	//cout << unevenCount << " - uneven Count" << endl;
	//cout << evenCount << " - even Count " << endl;

	for (i = 0; i < arraySize; i++)
	{
		if (arr[i] % 2 == 0)
		{
			temp = arr[count];
			arr[count] = arr[i];
			arr[i] = temp;
			count++;
		}
	}

	minMaxSort(arr, evenCount);

	for (i = evenCount; i < arraySize; i++)
	{
		for (j = arraySize - 1; j > i; j--)
		{
			k = i;
			for (int j = i + 1; j < arraySize; j++)
			{
				if (arr[j] > arr[k]) k = j;
			}
			int t = arr[i];
			arr[i] = arr[k];
			arr[k] = t;
		}
	}
}




int main()
{
	int arr[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
	int iMin, iMax;
	int n = sizeof(arr) / sizeof(int);
	int i;
	iMin = i = 0;
	iMax = i = 0;
	system("cls");

	showArray(arr, n);
	//for (i = 0; i < n; i++)
	//{
	//	iMin = i;
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (arr[j] < arr[iMin]) iMin = j;
	//	}
	//	int t = arr[i];
	//	arr[i] = arr[iMin];
	//	arr[iMin] = t;
	//}


//	sortBubble(arr, n);
//	quickSort(arr, n);

//	sortEvenUneven(arr, n);
//	quickSort(arr, n, 0, 7);
	quickSortDESC(arr, n, 3, 7);
	showArray(arr, n);


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
