#include <bits/stdc++.h>
using namespace std;

void build_heap(int * arr, int n, int i)
{
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[mx]) mx = l;
    if(r < n && arr[r] > arr[mx]) mx = r;
    if(mx != i)
    {
        swap(arr[i], arr[mx]);
        build_heap(arr, n, mx);
    }
}

void heapsort(int * arr, int n)
{
    for(int i = n / 2 - 1; i >= 0; i --) build_heap(arr, n, i);
    for(int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        build_heap(arr, i, 0);
    }
}

int main()
{
    clock_t start = clock();
    int test_number;
    cin >> test_number;
    string inputfilename = "sorting_tests/input" + to_string(test_number);
    string outputfilename = "heap_test/output" + to_string(test_number);
    ifstream fin(inputfilename);
    ofstream fout(outputfilename);
    int n;
    fin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) fin >> arr[i];
    heapsort(arr, n);
    for(int i = 0; i < n; i++) fout << arr[i] << " ";
    fout << "\n";
    fout << (double)(clock() - start) / CLOCKS_PER_SEC;
}