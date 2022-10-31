#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace chrono;


int main(){
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> s, e;
    srand(time(0));
    setlocale(LC_ALL, "ru_RU.UTF-8"); //Я пишу в CLion, тут по другому русский язык подключать надо, в отличии от VS
    system("chcp 65001");
    const int n = 100;
    int arr[n], r, sort = 0, sr, nm, k,  max = -101, min = 101;

    //Создание массива (1)
    cout << "Создан неотсортированный массив из 100 элементов: ";
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 198 - 99;
        cout << arr[i] << " ";
    }
    sort = 0; //Проверка на сортировку
    cout << endl << endl;

    while (true){

        //Меню
        cout << "          Меню\n" <<
        "1 - создать новый массив\n" <<
        "2 - отсортировать массив\n" <<
        "3 - найти максимальный и минимальный элемент массива\n" <<
        "4 - найти среднее значение max и min, кол-ао элементов, равных ему, и их индексы\n" <<
        "5 - найти кол-во элементов отсортированного массива, меньше введённого вами числа\n" <<
        "6 - найти кол-во элементов отсортированного массива, больше введённого вами числа\n" <<
        "7 - поменять местами элементы массива\n" <<
        "0 - выйти из программы\n";
        
        cout << "Ваш выбор: ";
        cin >> r;
        if (r == 0) break;
        switch (r){
            
            case 1:
                //Создание нового массива (1)
                cout << "Создан неотсортированный массив из 100 элементов: ";
                for (int i = 0; i < n; i++){
                    arr[i] = rand() % 198 - 99;
                    cout << arr[i] << " ";
                }
                sort = 0;
                cout << endl << endl;
                break;

            case 2:
                //Сортировка массива shaker-sort (2)
                s = steady_clock::now();
                nm = n - 1;
                cout << "Получен отсортированный массив из 100 элементов: ";
                for (int i = 0; i < n; i++){
                    for(int j = 0; j < n - 1 - i; j++){
                        if (arr[j] > arr[j+1]){
                            swap (arr[j], arr[j+1]);
                        }
                        if (arr[nm-j] < arr[nm-(j+1)]){
                            swap (arr[nm-j], arr[nm-(j+1)]);
                        }
                    }
                }
                for (int i = 0; i < n; i++){
                    cout << arr[i] << " ";
                }
                sort = 1;
                e = steady_clock::now();
                cout << endl << "Время сортировки (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl << endl;
                break;

            case 3:
                //Нахождение max и min элемента массива (3)
                max = -101;
                min = 101;
                if (sort == 1){
                    s = steady_clock::now();
                    max = arr[n-1];
                    min = arr[0];
                    cout << "Отсортированный массив" << endl;
                    cout << "Максимальный элемент массива: " << max << endl << "Минимальный элемент массива: " << min;
                    e = steady_clock::now();
                    cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl << endl;
                }
                else{
                    s = steady_clock::now();
                    cout << "Неотсортированный массив" << endl;
                    for (int i = 0; i < n; i++){
                        if (arr[i] > max){
                            max = arr[i];
                        }
                        if (arr[i] < min){
                            min = arr[i];
                        }
                    }
                    cout << "Максимальный элемент массива: " << max << endl << "Минимальный элемент массива: " << min;
                    e = steady_clock::now();
                    cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl << endl;
                }
                break;

            case 4:
                //Среднее значение max и min,кол-во равных элементов и их индексы (4)
                sr = max+min;
                k = 0;
                if ((sr % 2) != 0) {
                    sr += 1;
                }
                sr /= 2;
                cout << "Среднее значение max и min: " << sr << endl;
                if (sort == 1) {
                    s = steady_clock::now();
                    cout << "Отсортированный массив" << endl;
                    cout << "Индексы равных элементов: ";
                    for(int i = 0; i < n; i++){
                        if (arr[i] == sr){
                            cout << i << " ";
                            k++;
                        }
                        if (arr[i] > sr){
                            e = steady_clock::now();
                            cout << endl << "Кол-во равных элементов: " << k;
                            cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl << endl;
                            break;
                        }
                    }
                }
                else {
                    s = steady_clock::now();
                    cout << "Неотсортированный массив" << endl;
                    cout << "Индексы равных элементов: ";
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == sr) {
                            cout << i << " ";
                            k++;
                        }
                    }
                    e = steady_clock::now();
                    cout << endl << "Кол-во равных элементов: " << k;
                    cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl << endl;
                }
                break;

            case 5:
                //Кол-во элементов отсортированного массива, которые меньше введённого числа (5)
                int a;
                k = 0;
                if (sort == 1){
                    cout << "Введите число: ";
                    cin >> a;
                    for (int i = 0; i < n; i++){
                        if (arr[i] < a){
                            k++;
                        }
                        else {
                            break;
                        }
                    }
                    cout << endl << "Чисел меньше " << a << ": " << k << endl;
                }
                else{
                    cout << "Сначала отсортируйте массив" << endl;
                }
                break;

            case 6:
                //Кол-во элементов отсортированного массива, которые больше введённого числа (6)
                int b;
                k = 0;
                if (sort == 1){
                    cout << "Введите число: ";
                    cin >> b;
                    for (int i = n-1; i >= 0; i--){
                        if (arr[i] > b){
                            k++;
                        }
                        else {
                            break;
                        }
                    }
                    cout << endl << "Чисел больше " << b << ": " << k << endl << endl;
                }
                else{
                    cout << "Сначала отсортируйте массив" << endl << endl;
                }
                break;

            case 7:
                //Поменять местами элементы массива (8)
                int i1, i2;
                s = steady_clock::now();
                cout << "Введите индекс 1 элемента: ";
                cin >> i1;
                cout << endl << "Введите индекс 2 элемента: ";
                cin >> i2;
                swap (arr[i1], arr[i2]);
                e = steady_clock::now();
                cout << endl << "Время замены элементов (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl;
                cout << "Получен массив: ";
                for (int i = 0; i < n; i++){
                    cout << arr[i] << " ";
                }
                cout << endl << endl;
                break;

            default:
                cout << "Пункт меню выбран неправильно\n";
        }
    }
}
