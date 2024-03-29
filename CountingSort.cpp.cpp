#include <bits/stdc++.h>
using namespace std;

vector<int> inputArray;
vector<int> outputArray;

vector<int> countSort(vector<int>& inputArray)
{

	int N = inputArray.size();

	int M = 0;

	for (int i = 0; i < N; i++)
		M = max(M, inputArray[i]);

	vector<int> countArray(M + 1, 0);


	for (int i = 0; i < N; i++)
		countArray[inputArray[i]]++;

	for (int i = 1; i <= M; i++)
		countArray[i] += countArray[i - 1];

	vector<int> outputArray(N);

	for (int i = N - 1; i >= 0; i--)
	{
		outputArray[countArray[inputArray[i]] - 1]
			= inputArray[i];

		countArray[inputArray[i]]--;
	}

	return outputArray;
}

int main()
{
    /// complexitatea pentru CountingSort este O(N + M), unde N si M sunt dimensiunile lui inputArray[] si countArray[]
    /// putem spune ca nu exista un worst case sau best case, pentru ca algoritmul se executa la fel in functie de orice input primit.
    /// in schimb, sunt niste avantaje si dezavantaje semnificative.


    /// countingSort este un algoritm usor de scris care se misca mult mai rapid in comparatie cu alti algoritmi existenti
    /// insa, sunt si cateva dezavantaje anume ca :
    /// 1. countSort nu poate sorta orice fel de numere, din cauza faptului ca necesita memorie auxiliara.
    /// range-ul de valori ale elementelor din input poate fi prea mare incat sa putem aloca suficienta memorie.

    /// 2. acest algoritm nu functioneaza pe numere reale neintregi.

    /*
    for(int i = 1; i <= 1000000; i ++)
    {
        inputArray.push_back(rand() % 10000);
    }
    auto start=chrono::high_resolution_clock::now();
    outputArray = countSort(inputArray);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// 0.02s
    */

    /*
    for(int i = 1; i <= 10000000; i ++)
    {
        inputArray.push_back(rand() % 10000);
    }
    auto start=chrono::high_resolution_clock::now();
    outputArray = countSort(inputArray);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// 0.25s
    */

    /*
    for(int i = 1; i <= 100000000; i ++)
    {
        inputArray.push_back(rand() % 10000);
    }
    auto start=chrono::high_resolution_clock::now();
    outputArray = countSort(inputArray);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// 2.8s
    */

	return 0;
}

