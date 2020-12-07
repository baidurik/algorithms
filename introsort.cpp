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

void introsort(int * arr, int l, int r, int depth, int limit)
{
    if(l < r)
    {
        if(depth > limit)
        {
            heapsort(arr + l, r-l+1);
        }
        else 
        {
            int p = partition(arr, l, r);
            introsort(arr, l, p, depth+1, limit);
            introsort(arr, p+1, r, depth+1, limit);
        }
    }
}

int main()
{
    clock_t start = clock();
    int test_number;
    cin >> test_number;
    string inputfilename = "sorting_tests/input" + to_string(test_number);
    string outputfilename = "intro_test/output" + to_string(test_number);
    ifstream fin(inputfilename);
    ofstream fout(outputfilename);
    int n;
    fin >> n;
    int lim = floor(log2(n));
    int arr[n];
    for(int i = 0; i < n; i++) fin >> arr[i];
    introsort(arr, 0, n-1, 0, lim);
    for(int i = 0; i < n; i++) fout << arr[i] << " ";
    fout << "\n";
    fout << (double)(clock() - start) / CLOCKS_PER_SEC;
}