#include <bits/stdc++.h>
using namespace std;

int partition(int * arr, int l, int r)
{
    int m = arr[(l+r) / 2];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(arr[i] < m) i ++;
        while(arr[j] > m) j --;
        // cout << i << " " << j << "\n";
        if(i >= j) return j;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
    return j;
}

void qsort(int * arr, int l, int r)
{
    if(l < r)
    {
        int p = partition(arr, l, r);
        qsort(arr, l, p);
        qsort(arr, p+1, r);
    }
}

int main()
{
    clock_t start = clock();
    int test_number;
    cin >> test_number;
    string inputfilename = "sorting_tests/input" + to_string(test_number);
    string outputfilename = "hoar_test/output" + to_string(test_number);
    ifstream fin(inputfilename);
    ofstream fout(outputfilename);
    int n;
    fin >> n;
    // fout << n << "\n";
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        fin >> arr[i];
        // cout << arr[i] << "\n";
    }
    // for(int i = 0; i < n; i++) cout << arr[i] << " ";
    qsort(arr, 0, n-1);
    for(int i = 0; i < n; i++) fout << arr[i] << " ";
    fout << "\n";
    fout << (double)(clock() - start) / CLOCKS_PER_SEC;
    // delete [] arr;
    // fout << "anime";
    // cout << test_number << "\n";
    // fout << test_number;
}