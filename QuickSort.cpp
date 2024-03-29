#include <bits/stdc++.h>

using namespace std;

int n, v[10000005];
int nmax;

int partitionare(int st, int dr)
{
    int poz=st+rand()%(dr-st+1);
    swap(v[poz],v[dr]);
    int p=st;
    for(int i=st;i<dr;i++)
    {
        if(v[i]<v[dr])
            swap(v[p++],v[i]);
    }
    swap(v[p],v[dr]);
    return p;
}

void quick_sort(int st, int dr)
{
    if(st>=dr)
        return ;
    int p=partitionare(st,dr);
    quick_sort(st,p-1);
    quick_sort(p+1,dr);
}

int main()
{
    int i;
    ///Primul test cu date aleatorii si n,nmax<=10^6
    /*n = 1e6;
    nmax = 1e6;
    for(i=1;i<=n;i++)
        v[i]=1+(rand()%nmax);
    auto start=chrono::high_resolution_clock::now();
    quick_sort(1,n);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Quick Sort"<<'\n';
    cout<<"N = "<<1000000<<" MAX = "<<1000000<<'\n'<<duration.count()<<" ms\n";//0.187*/
    ///Al doilea test cu date aleatorii si n,nmax<=10^7
    /*n = 1e7;
    nmax = 1e7;
    for(i=1;i<=n;i++)
        v[i]=1+(rand()%nmax);
    auto start=chrono::high_resolution_clock::now();
    quick_sort(1,n);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Quick Sort"<<'\n';
    cout<<"N = "<<10000000<<" MAX = "<<10000000<<'\n'<<duration.count()<<" ms\n";//4.298*/
    ///Testul 3- toate elementele sortate
    /*n = 1e7;
    nmax = 1e7;
    for(int i = 1; i <= n; i++)
        v[i] = i;
    auto start=chrono::high_resolution_clock::now();
    quick_sort(1,n);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Quick Sort"<<'\n';
    cout<<"N = "<<10000000<<" MAX = "<<10000000<<'\n'<<duration.count()<<" ms\n";//6.682*/
    ///Testul 4- toate elementele constante
    n=1e4;
    nmax=22;
    for(int i = 1; i <= n; i++)
        v[i] = 22;
    auto start=chrono::high_resolution_clock::now();
    quick_sort(1,n);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Quick Sort"<<'\n';
    cout<<"N = "<<10000<<" MAX = "<<22<<'\n'<<duration.count()<<" ms\n";
    /*Explicatie ultimul caz:
        Cel mai mare n pentru care nu crapa sortarea este 10^4 (0.093). Pentru valori mai mari
        10^5,10^6,... programul nu afiseaza nimic, crapand la functia de sortare
    */
    ///Quick-sort are o complexitate medie de O(nlogn), dar in anumite conditii,
    ///poate degenera la O(n^2). Alegerea pivotului influenteaza semnificativ performanta algoritmului, dar,
    ///datorita faptului ca am ales pivotul aleator, ajuta in general sa se evite cazurile de timp O(n^2).
    return 0;
}
