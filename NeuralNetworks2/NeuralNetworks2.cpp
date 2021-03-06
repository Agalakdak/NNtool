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
	~NeuralNetworks()
	{
		for (int i = 0; i < n; i++)
			delete[] alpha[i];   
		delete[] alpha;
		delete[] alpha_KI;

		for (int i = 0; i < n - 1; i++)
			delete alpha_weight[i];
		delete[] alpha_weight;
	}
	NeuralNetworks()
	{
		cout << "Введите количество слоёв нейронной сети" << endl;
		cin >> n; // количество слоёв нейронной сети 
		double ** neuralKnot = new double*[n]; //массив который содержит узлы всей сети каждого слоя 
		int *arr_knot_int_network = new int[n]; //массив который содержит количество узлов в каждом слое 

		alpha_KI = arr_knot_int_network;
		for (int i = 0; i < n; i++) // создание слоёв сети и выделение под них памяти 
		{
			cout << "Введите количество узлов нейронной сети для " << i << "-того слоя" << endl;
			cin >> nk;
			arr_knot_int_network[i] = nk;
			neuralKnot[i] = new double[nk];
		}

		alpha = neuralKnot;//запись узлов сети в переменную класса
		cout << "Узлы" << endl;
		int count = 0;
		for (int i = 0; i < n; i++)//вывод значений узлов по слоям 
		{
			for (int j = 0; j < arr_knot_int_network[i]; j++)
			{
				alpha[i][j] = count;
				cout << " [ " << alpha[i][j] << " ] \t\t";
				count++;
			}
			cout << endl;
		}
		// 
		double ** arr_weight = new double*[n-1]; // выделение памяти для весовых коэфицентов для определённого количества узлов 

		for (int i = 0; i < n - 1; i++)
		{
			arr_weight[i] = new double[arr_knot_int_network[i] * arr_knot_int_network[i + 1]];//выделение памяти для связей в узлах сети 
		}

		alpha_weight = arr_weight;

		cout << "Весовые коэфиценты:" << endl;

		for (int i = 0; i < n - 1; i++)//вывод значений узлов по слоям 
		{
			for (int j = 0; j < arr_knot_int_network[i] * arr_knot_int_network[i + 1]; j++)
			{
				arr_weight[i][j] = ((rand() % 1000) / 1000.0); //присваивание весовым коэфицентам рандомные значения 
				cout << " [ " << arr_weight[i][j] << " ] \t\t";
			}
			cout << endl;
			cout << "Следующий слой" << endl;
		}
	}
	void work() // функция  для произведения вычислений сети по слоям
	{ 

	 for (int i = 0; i < n-1 ; i++) //начало цикла 
	 { //здесь известно какой слой сети выбран
		 int jj = 0;

		 for (int j = 0; j < alpha_KI[i]; j++)//узлы
		 { //здесь известно в каком узле какой слой
			 cout << "Вывод узначения узла [" << i << "][" << j << "] = " << alpha[i][j] << endl;
			 while (jj < alpha_KI[i] * alpha_KI[i + 1])
			 {
				 //здесь известно в каком слое, какой узел, какой весовой коэфицент
				 cout << "Вывод связи между слоем " << i << " и " << i + 1 << "\t" << alpha_weight[i][jj] << endl;

				 jj++;
			 }

		 }   
		 //for (int j = 0; j < alpha_KI[i] * alpha_KI[i + 1]; j++)//веса
		 //{
			// 
			// //cout << "Вывод узначения узла [" << i << "][" <<  << "]" << alpha_weight[i][j];
			//

		 //}
	  
	 } 
	
	} 
	void V1()
	{
		for (int i = 0; i < n; i++)//вывод значений узлов по слоям 
		{
			for (int j = 0; j < alpha_KI[i]; j++)
			{
				
				cout << "V1 [ " << alpha[i][j] << " ] \t\t";
			}
			cout << endl;
		}
	}

	void V2()
	{
		for (int i = 0; i < n-1; i++)//вывод значений весов по слоям 
		{
			for (int j = 0; j < alpha_KI[i] * alpha_KI[i + 1]; j++)
			{
				
				cout << "V2 [ " << alpha_weight[i][j] << " ] \t\t";
			}
			cout << endl;
		}
	}


protected:
	double **alpha;// указатель на указатель который хранит значения узлов в каждом из слоёв 
	double **alpha_weight;
	int * alpha_KI;
	int n; // переменная для хранения количества слоёв в сети 
	int nk; //временная переменная для указания узлов в слое 


};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	NeuralNetworks *NeuNet = new NeuralNetworks; 
	NeuNet->V1();
	NeuNet->V2();
	delete NeuNet;
	

	//cout « "Array have " « _msize(Array) / sizeof(Array[0]) « " items."; // определение количества слоёв в сети 
	// не используется в работе

	/*for (int i = 0; i < n; i++)
	{
		I[i][j] = who[i][j + n];
		n это количество входящих узлов в принимающий узел 
		вычисление значений 
		}
*/
	return 0;
}