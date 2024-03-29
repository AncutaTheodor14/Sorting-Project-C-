#include<bits/stdc++.h>
using namespace std;

int n,v[100000002],ans[100000002],w[100000002];

void merge_sort(int st, int dr)
{
    if(st>=dr)
        return;
    int mij=(st+dr)/2;
    merge_sort(st,mij);
    merge_sort(mij+1,dr);
    int i=st,j=mij+1,k=0;
    while(i<=mij && j<=dr)
    {
        if(v[i]<v[j])
            ans[++k]=v[i],i++;
        else
            ans[++k]=v[j],j++;
    }
    while(i<=mij)
        ans[++k]=v[i],i++;
    while(j<=dr)
        ans[++k]=v[j],j++;
    for(i=st,j=1;i<=dr;i++,j++)
        v[i]=ans[j];
}

int main()
{
    int i,N1;
    /// Primul test consta din numere deja sortate crescator
    /*N1=1e8;
    for(i=1;i<=N1;i++)
        v[i]=i;
    auto start=chrono::high_resolution_clock::now();
    merge_sort(1,N1);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Merge Sort"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//9.749
    start=chrono::high_resolution_clock::now();
    sort(v+1,v+N1+1);
    stop=chrono::high_resolution_clock::now();
    duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Sort-ul din STL"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//7.513*/
    ///
    /// Al doilea din numere deja sortate descrescator
    /*N1=1e8;
    for(i=1;i<=N1;i++)
        v[N1-i+1]=i,w[N1-i+1]=i;
    auto start=chrono::high_resolution_clock::now();
    merge_sort(1,N1);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Merge Sort"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//9.625
    start=chrono::high_resolution_clock::now();
    sort(w+1,w+N1+1);
    stop=chrono::high_resolution_clock::now();
    duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Sort-ul din STL"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//5.576*/
    /// Al treilea din numere aflate intr-o ordine random
    /*N1=1e8;
    for(i=1;i<=N1;i++)
        v[i]=rand()%N1,w[i]=rand()%N1;
    auto start=chrono::high_resolution_clock::now();
    merge_sort(1,N1);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Merge Sort"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//19.347
    start=chrono::high_resolution_clock::now();
    sort(w+1,w+N1+1);
    stop=chrono::high_resolution_clock::now();
    duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout<<"Sortez folosind Sort-ul din STL"<<'\n';
    cout<<"N = "<<100000000<<" MAX = "<<100000000<<'\n'<<duration.count()<<" ms\n";//19.335*/
    ///complexitatea este O(nlogn), dar in cazul in care valorile sunt random in vector si nu
    ///intr-o ordine anume, procesorul nu se poate folosi de branch pradiction si atunci
    ///creste timpul de rulare
    ///complexitate memorie O(n)
    return 0;
}
