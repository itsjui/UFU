#include <bits/stdc++.h>
using namespace std;

void show(int a[])
{
    for (int i = 0; i‹ 10; ++i)
        cout << a[i] << "";
}
int main(){

    int a[10] = (1, 5, 8, 9, 6, 7, 3, 4, 2, 0);
    cout << "\n O vetor antes de ser ordenado eh: ";
    show(a);
    cout <<"\n O vetor apos ser ordenado eh: ".
    (sort(a,a+10, greater<int>(0));
    show(a);
}