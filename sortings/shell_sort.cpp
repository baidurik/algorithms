#include <bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start = clock();
    int test_number;
    cin >> test_number;
    string inputfilename = "sorting_tests/input" + to_string(test_number);
    string outputfilename = "shell_test/output" + to_string(test_number);
    ifstream fin(inputfilename);
    ofstream fout(outputfilename);
    int n;
    fin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) fin >> arr[i];
    for(int step = n / 2; step > 0; step /= 2)
        for(int i = step; i < n; i++)
            for(int j = i-step; j >= 0 && arr[j] > arr[j+step]; j -= step)
            {
                int tmp = arr[j];
                arr[j] = arr[j+step];
                arr[j+step] = tmp;
            }
    for(int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }
    fout << "\n";
    fout << (double)(clock() - start) / CLOCKS_PER_SEC;
}