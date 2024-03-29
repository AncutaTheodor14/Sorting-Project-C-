#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lgmax = 1e8;


int n, base;
int output[lgmax + 5];
int countArr[(1 << 17) + 5];
int nmax;
int v[lgmax + 5];

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, int base)
{
    for(int i = 0; i < base; i ++){
        countArr[i] = 0;
    }
    int i;
    for (i = 0; i < n; i++)
        countArr[(arr[i] / exp) % base]++;
    for (i = 1; i < base; i++)
        countArr[i] += countArr[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[countArr[(arr[i] / exp) % base] - 1] = arr[i];
        countArr[(arr[i] / exp) % base]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n, int base)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= base)
        countSort(arr, n, exp, base);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

signed main()
{
    /*
    n = 1e6;
    base = 10;
    for(int i = 0; i < n; i ++){
        v[i] = rand() + 1e5;
    }
    auto start=chrono::high_resolution_clock::now();
    radixsort(v, n, base);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    /// pentru numere destul de mici, pana in 1e6, radixSort are un timp de executie de aproximativ 0.2 secunde daca consideram numerele in baza 10
    /// dar timpul de executie este extraordinar de mult influentat de baza pe care ne-o alegem de la inceput
    /// considerand constanta ca fiind numarul de cifre al numarului, o aplicatie a radixSort ar fi daca
    /// am considera numerele din input ca fiind numere intr-o baza mult mai mare : de exemplu, 2^16
    cout << duration.count() << '\n';
    */

    /*
    n = 1e6;
    base = (1 << 15);
    for(int i = 0; i < n; i ++){
        v[i] = 1e6 + rand() % 1000;
    }
    auto start=chrono::high_resolution_clock::now();
    radixsort(v, n, base);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    /// pentru numere destul de mici, pana in 1e6, radixSort are un timp de executie de aproximativ 0.06 daca consideram numerele in baza 2^16
    /// dar timpul de executie este extraordinar de mult influentat de baza pe care ne-o alegem de la inceput
    /// considerand constanta ca fiind numarul de cifre al numarului, o aplicatie a radixSort ar fi daca
    /// am considera numerele din input ca fiind numere intr-o baza mult mai mare : de exemplu, 2^16
    cout << duration.count() << '\n';
    */

    /*
    n = 1e8;
    /// base = (1 << 10); /// 20 de secunde
    /// base = (1 << 16); /// 15 secunde
    /// orice am pune mai mare decat 1 << 16, rezultatul e aproape asemanator, pentru ca oricum, un numar de 9 cifre de exemplu,
    /// fie ca este in baza 2 ^ 16 sau in baza 2 ^ 20, are tot 2 cifre (in baza respectiva)
    base = 10; /// 55 de secunde
    for(int i = 1; i <= n; i ++){
        v[i] = 1e8 + (rand() % 1000000);
    }
    auto start=chrono::high_resolution_clock::now();
    radixsort(v, n, base);
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << duration.count();
    */
    return 0;
}
