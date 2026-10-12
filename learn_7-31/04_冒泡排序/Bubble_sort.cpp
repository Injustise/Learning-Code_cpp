#include <iostream>
using namespace std;

const int N = 1e5 + 10;

void bubble_sort(int a[], int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n - i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {

    int n, a[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    bubble_sort(a, n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    system("pause");

    return 0;
}