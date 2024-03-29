#include<bits/stdc++.h>
using namespace std;

int heap[100000004],n,x,n_heap;
double v[100000002];

void add(int value)
{
    n_heap++;
    heap[n_heap]=value;
    int current=n_heap;
    while(current>1 && heap[current]<heap[current/2])
    {
        swap(heap[current],heap[current/2]);
        current/=2;
    }
}

void removee()
{
    heap[1]=heap[n_heap];
    heap[n_heap]=0;
    n_heap--;
    int current=2,p=1;
    while(current<=n_heap)
    {
        if(current+1<=n_heap && heap[current+1]<heap[current])
            current++;
        if(heap[current]<heap[p])
            swap(heap[current],heap[p]);
        p=current;
        current=2*p;
    }
}

int main()
{
    int i;
    ///Testul 1-numere deja sortate crescator
/*    n=1e6;
    auto start=chrono::high_resolution_clock::now();
    for(i=1;i<=n;i++)
        add(i);
    for(i=1;i<=n;i++)
    {
        //cout<<heap[1]<<" ";
        removee();
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Heap Sort"<<'\n';
    cout<<"N = "<<1000000<<" MAX = "<<1000000<<'\n'<<duration.count()<<" ms\n";//0.171*/
    ///
    ///Testul 2-numere aflate intr-o ordine random
    /*int x;
    n=1e8;
    auto start=chrono::high_resolution_clock::now();
    for(i=1;i<=n;i++)
        x=rand()%n,add(x);
    for(i=1;i<=n;i++)
    {
        //cout<<heap[1]<<" ";
        removee();
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Heap Sort"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//45.120*/
    ///
    ///Testul 3-numere REALE aflate intr-o ordine random
    /*n=1e8;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-1e6, 1e6);
    for(i = 1; i <= n; ++i) {
        v[i]=distr(gen);
    }
    auto start=chrono::high_resolution_clock::now();
    for(i=1;i<=n;i++)
        add(v[i]);
    for(i=1;i<=n;i++)
    {
        //cout<<heap[1]<<" ";
        removee();
    }
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Heap Sort"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<1000000<<'\n'<<duration.count()<<" ms\n";//51.216*/
    ///
    ///Heap-sort are complexitatea O(nlogn). Diferenta asa mare intre HeapSort si MergeSort
    ///este si din cauza faptului ca aici cronometrez si generarea random a numerelor,
    ///pentru a nu le mai stoca si astfel a micsora complexitatea memorie.
    ///Testul cu numere reale ruleaza mai lent decat cele cu numere intregi
    return 0;
}
