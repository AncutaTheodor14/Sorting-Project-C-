#include<bits/stdc++.h>

using namespace std;

const int nmax = 1e8;

int n;
int v[nmax + 5];

/*
aceasta este prima implementare aparuta pentru ShellSort, insa in functie de diferite implementari (sau incrementari)
algoritmul poate avea complexitati diferite
exemplu :
daca pornim cu lungime ca fiind 1, 3, 7, ..., 2 ^ (k - 1), worst case pentru algoritmul ShellSort va fi N * sqrt(N)
*/

void ShellSort()
{
    int len,i,j;
    for(len=n/2;len>=1;len/=2)
    {
        for(i=len+1;i<=n;i++)
        {
            j=i;
            while(j-len>=1 && v[j-len] > v[j])
            {
                swap(v[j-len],v[j]);
                j--;
            }
        }
    }
}

int main()
{
    /*
    n = 1e6;
    for(int i = 1; i <= n; i ++)
    {
        v[i] = i;
    }
    auto start=chrono::high_resolution_clock::now();
    ShellSort();
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// valori cuprinse intre 0.05 - 0.08 s
    */
    /*
    n = 1e6;
    for(int i = 1; i <= n; i ++)
    {
        v[i] = n - i + 1;
    }
    auto start=chrono::high_resolution_clock::now();
    ShellSort();
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// valori cuprinse intre 0.18s - 0.22s
    */

    /*
    n = 1e8;
    for(int i = 1; i <= n; i ++)
    {
        v[i] = i;
    }
    auto start=chrono::high_resolution_clock::now();
    ShellSort();
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// 6.8s - 8.1s
    /// cazul cel mai favorabil pentru shellSort este in momentul in care sirul este deja sortat.
    /// cand sirul dar este deja sortat numarul total de comparatii pentru fiecare interval este egal cu dimensiunea listei date
    */

    /*
    n = 1e8;
    for(int i = 1; i <= n; i ++)
    {
        v[i] = n - i + 1;
    }
    auto start=chrono::high_resolution_clock::now();
    ShellSort();
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count() << '\n'; /// am rulat de mai multe ori pe acest caz cand sirul este in ordine inversa, si am avut urmatoarele rezultate
    /// 20s, 21s, 26s
    */
    return 0;
}
