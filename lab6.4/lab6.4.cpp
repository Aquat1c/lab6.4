#include <iostream>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;


void Create(int* c, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        c[i] = Low + rand() % (High - Low + 1);
}

void Print(int* c, const int n) {
    for (int i = 0; i < n; i++)
        cout << setw(4) << c[i];
    cout << endl;
}
int Pos(int* c, int n) {
    int k = 0;
    for (int i = 0; i < n; i++)
        if (c[i] > 0)
            k++;
    return (k);
}
int Sum(int* c, const int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (abs(c[i]) == 0) {
            for (; i < n; i++) s += abs(c[i]);
            break;
        }
    }
    return s;
}
void Sort(int* c, const int size, int a, int b)
{
    for (int i = 1; i < size; i++)
    {
        int k = 0;
        for (int j = 0; j < size - i; j++)
            if (c[j] >= a && c[j] <= b)
            {
                int tmp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = tmp;
                k = 1;
            }
        if (k == 0)
            return;
    }
}
int main()
{
    srand(time_t(NULL));
    setlocale(LC_ALL, "Ukr");

    int n;
    int* c;
    int Low = -20;
    int High = 20;
    int a, b;

    cout << "Введiть розмiр:\n";
    cin >> n;

    c = new int[n];
    if (!c) {
        cout << "Помилка!!!";
        exit(0);
    }

    Create(c, n, Low, High);
    Print(c, n);
    cout << "\n\n";
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;

    cout << "Кiлькiсть додатнiх елементiв массиву: " << Pos(c, n) << endl;
    cout << "Сума псля першого нуля = " << Sum(c, n) << endl;
    //Shuffle(c, n);
    Print(c, n);
    Sort(c, n, a, b);

    return 0;
}   