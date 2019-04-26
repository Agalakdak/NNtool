// NeuralNetworks2.cpp: определяет точку входа для консольного приложения.
//
//Первая попытка написать удобный инструмент для создания сети любого размера с любым количетвом слоёв и узлов в этих слоях
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <random>
#include <cstdlib>
#include <cmath>
#include <malloc.h>

using namespace std;



class NeuralNetworks
{

public:
	NeuralNetworks()
	{
		cout << "Введите количество слоёв нейронной сети" << endl;
		cin >> n; // количество слоёв нейронной сети
		double ** neuralKnot = new double*[n]; //массив который содержит узлы всей сети каждого слоя
		int *arr_knot_int_network = new int[n]; //массив который содержит количество узлов в каждом слое
		for (int i = 0; i < n; i++) // создание слоёв сети и выделение под них памяти
		{
			cout << "Введите количество узлов нейронной сети для " << i << "-того слоя" << endl;
			cin >> nk;
			arr_knot_int_network[i] = nk;
			neuralKnot[i] = new double[nk];
		}
		alpha = neuralKnot;
		for (int i = 0; i < n; i++)//вывод значений узлов по слоям
		{
			for (int j = 0; j < arr_knot_int_network[i]; j++)
			{
				neuralKnot[i][j] = 0;
				cout << " [ " << neuralKnot[i][j] << " ] \t\t";
			}
			cout << endl;
		}
		//
		double ** arr_weight = new double*[n]; // выделение памяти для весовых коэфицентов для определённого количества узлов

		for (int i = 0; i < n-1; i++)
		{
			arr_weight[i] = new double[arr_knot_int_network[i]*arr_knot_int_network[i+1]];//выделение памяти для связей в узлах сети
		}
		cout << "Весовые коэфиценты:" << endl; 
		for (int i = 0; i < n-1; i++)//вывод значений узлов по слоям
		{
			for (int j = 0; j < arr_knot_int_network[i]* arr_knot_int_network[i+1]; j++)
			{
				arr_weight[i][j] = ((rand() % 1000) / 1000.0); //присваивание весовым коэфицентам рандомные значения
				cout << " [ " << arr_weight[i][j] << " ] \t\t";
			}
			cout << endl;
			cout  <<"Следующий слой" << endl;
		}
	}
	//void work() // функция не работает т.к. область видимости нарушена
	//{
	//	for (int i = 0; i < n - 1; i++)//вывод значений узлов по слоям
	//	{
	//		for (int j = 0; j < arr_knot_int_network[i] * arr_knot_int_network[i + 1]; j++)
	//		{
	//			arr_weight[i][j] = ((rand() % 1000) / 1000.0); //присваивание весовым коэфицентам рандомные значения
	//			cout << " [ " << arr_weight[i][j] << " ] \t\t";
	//		}
	//		cout << endl;
	//		cout << "Следующий слой" << endl;
	//	}
	//}
	void V1()
	{
		for (int i = 0; i < n; i++)//вывод значений узлов по слоям
		{
			for (int j = 0; j < 2; j++)
			{
				alpha[i][j] = 0;
				cout << "V1 [ " << alpha[i][j] << " ] \t\t";
			}
			cout << endl;
		}
		
	}
protected:
	double **alpha;// указатель на указатель который хранит значения узлов в каждом из слоёв
	int n; // переменная для хранения количества слоёв в сети
	int nk; //временная переменная для указания узлов в слое


};

int main()
{
	setlocale(LC_ALL, "Russian");
	NeuralNetworks NeuNet;
	NeuNet.V1();
	//double **Array = new double*[5];
	//int nk;
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "Enter count of knot ";
	//	cin >> nk;
	//	Array[i] = new double[nk];
	//}


	//cout << "Array have " << _msize(Array) / sizeof(Array[0]) << " items."; // определение количества слоёв в сети
	//


	return 0;
}

