#include <iostream>
using namespace std;
#include <string>

template <typename T>
class Array { // создаем шаблон массива
private:
    int size; // размер массива
    T *a;
public:
    Array(int s); // конструктор с размером массива
    ~Array();       // деструктор
    string index1(int index1,int index2); 
    string index2(int index1, int index2);
    void setarray(int size); // метод ввода массива с клавиатуры
    void getarray(int size);    // вывод содержимого массива
    string comp(T c, T c1);
    string comp1(T c2, T c3);
};

template <typename T>
//конструктор пустого массива
Array<T>::Array(int s) { 
    if (s > 0) {
        size = s;
        a[size];
        for (size_t i = 0; i != size; i++) {
            a[i] = 0;
        }
    }
    else cout << "введите положительное число";
}
template <typename T>
//деструктор массива
Array<T>::~Array() { 
    delete[]a;
}

template <typename T>
//индексикация
string index1(int index1, int index2) {
    string comp(int f, int e)
    {
        if (f == e)
            return "да, они равны";
        else return"нет, они неравны";
    }
    string comp(double f, double e)
    {
        if (f == e)
            return"да, они равны";
        else return "нет, они неравны";
    }
    cin >> index1;
    cin >> index2;
    if (index1 <= size && index2 <= size) {
        b = a[index1];
        c = a[index2];
        cout<<(comp(b, c));
    }
    //перегрузка равенства элементов массива
    
}
template <typename T>
string index2(int index1, int index2) {
    //перегрузка неравенства элементов массива
    string comp1(int f, int e)
    {
        if (f != e)
            return "да, они неравны";
        else return  "нет, они равны";
    }

    string comp1(double f, double e)
    {
        if (f != e)
            return "да, они неравны";
        else return "нет, они равны";
    }
    cin >> index1;
    cin >> index2;
    if (index1 <= size && index2 <= size) {
        b = a[index1];
        c = a[index2];
        cout <<(comp1(b, c));
    }
}

template <typename T>
//ввод массива с клавиатуры
void Array<T>::setarray(int size) { 
    for (size_t i = 0; i != size; i++) {
        cin >> a[i];
    }
}
template <typename T>
// вывод массива
void Array<T>::getarray(int size) { 
    for (size_t i = 0; i != size; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int x, y,c,i1,i2,i3,i4;
    setlocale(LC_ALL, "Russian");
    cout << "Введите число элементов массива:" << endl;
    cin >> c;
    Array<int> arr(c);
    cout << "Введите элементы массива" << endl;
    arr.setarray(c);
    cout << endl;

    cout << "массив:" << endl;
    arr.getarray(c);
    cout << endl<<endl;

    cout << "введите индексы элементов которые вы хотите проверить на равенство" << endl;
    cin >> i1; cin >>i2;
    arr.index1(i1,i2);

    cout << "введите индексы элементов которые вы хотите проверить на неравенство" << endl;
    cin >> i1; cin >> i2;
    arr.index2(i1, i2);
    arr.~Array();
}
