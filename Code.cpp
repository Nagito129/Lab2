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
    int arr[n], arr_[n];
    int r, sort = 0, sr, nm, k,  max, min;

    //Создание массива (1)
    cout << "Создан неотсортированный массив из 100 элементов: ";
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 198 - 99;
        arr_[i] = arr[i];
        cout << arr[i] << " ";
    }
    sort = 0; //Проверка на сортировку
    cout << endl << "Для продолжения нажмите enter";
    getchar();
    cout << endl;

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
                    arr_[i] = arr[i];
                    cout << arr[i] << " ";
                }
                sort = 0;
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                getchar();
                cout << endl;
                break;

            case 2:
                //Сортировка массива shaker-sort (2)
                nm = n - 1;
                cout << "Получен отсортированный массив из 100 элементов: ";
                s = steady_clock::now();
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
                e = steady_clock::now();
                for (int i = 0; i < n; i++){
                    cout << arr[i] << " ";
                }
                sort = 1;
                cout << endl << "Время сортировки (наносекунды): "<< duration_cast<nanoseconds>(e - s).count();
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                getchar();
                cout << endl;
                break;

            case 3:
                //Нахождение max и min элемента массива (3)
                max = -101;
                min = 101;

                s = steady_clock::now();
                max = arr[n-1];
                min = arr[0];
                e = steady_clock::now();
                cout << "Максимальный элемент массива: " << max << endl << "Минимальный элемент массива: " << min;
                cout << endl << "Время поиска в отсортированном массиве (наносекунды): "<< duration_cast<nanoseconds>(e - s).count();

                s = steady_clock::now();
                for (int i = 0; i < n; i++) {
                    if (arr_[i] > max) {
                        max = arr_[i];
                    }
                    if (arr_[i] < min) {
                        min = arr_[i];
                    }
                }
                e = steady_clock::now();
                cout << endl << "Время поиска в неотсортированном массиве (наносекунды): "<< duration_cast<nanoseconds>(e - s).count();
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                getchar();
                cout << endl;

                break;

            case 4:
                //Среднее значение max и min,кол-во равных элементов и их индексы (4)
                sr = max+min;
                k = 0;
                if ((sr % 2) != 0) {
                    sr += 1;
                }
                sr /= 2;
                cout << "Среднее значение max и min: " << sr << endl << endl;
                cout << "Отсортированный массив" << endl;
                cout << "Индексы равных элементов: ";
                s = steady_clock::now();
                for(int i = 0; i < n; i++) {
                    if (arr[i] == sr) {
                        cout << i << " ";
                        k++;
                    }
                    if (arr[i] > sr){
                        e = steady_clock::now();
                        cout << endl << "Кол-во равных элементов: " << k;
                        cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl;
                        break;
                    }
                }
                k = 0
                cout << endl << "Неотсортированный массив" << endl;
                cout << "Индексы равных элементов: ";
                s = steady_clock::now();
                for (int i = 0; i < n; i++) {
                    if (arr[i] == sr) {
                        cout << i << " ";
                        k++;
                    }
                }
                e = steady_clock::now();
                cout << endl << "Кол-во равных элементов: " << k;
                cout << endl << "Время поиска (наносекунды): "<< duration_cast<nanoseconds>(e - s).count();
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                getchar();
                cout << endl;

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
                    cout << endl << "Чисел меньше " << a << ": " << k;
                    cout << endl << "Для продолжения нажмите enter";
                    getchar();
                    getchar();
                    cout << endl;
                }
                else{
                    cout << "Сначала отсортируйте массив" ;
                    cout << endl << "Для продолжения нажмите enter";
                    getchar();
                    getchar();
                    cout << endl;
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
                    cout << endl << "Чисел больше " << b << ": " << k;
                    cout << endl << "Для продолжения нажмите enter";
                    getchar();
                    getchar();
                    cout << endl;
                }
                else{
                    cout << "Сначала отсортируйте массив";
                    cout << endl << "Для продолжения нажмите enter";
                    getchar();
                    getchar();
                    cout << endl;
                }
                break;

            case 7:
                //Поменять местами элементы массива (8)
                int i1, i2;
                cout << "Введите индекс 1 элемента: ";
                cin >> i1;
                cout << endl << "Введите индекс 2 элемента: ";
                cin >> i2;
                s = steady_clock::now();
                swap (arr[i1], arr[i2]);
                e = steady_clock::now();
                cout << endl << "Время замены элементов (наносекунды): "<< duration_cast<nanoseconds>(e - s).count() << endl;
                cout << "Получен массив: ";
                for (int i = 0; i < n; i++){
                    cout << arr[i] << " ";
                }
                cout << endl << "Для продолжения нажмите enter";
                getchar();
                getchar();
                cout << endl;
                break;

            default:
                cout << "Пункт меню выбран неправильно\n";
        }
    }
}
