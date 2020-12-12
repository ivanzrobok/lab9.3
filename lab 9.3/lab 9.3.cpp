// lab 9.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Варіант 9.
/*Є список товарів. Для кожного товару вказані його назва, назва магазину, в якому
продається товар, вартість одиниці товару в гривнях і його кількість з вказівкою одиниці
вимірювання (наприклад, кількість: 100 шт., одиниця вимірювання: упаковка по 20 кг.).
Написати програму, що виконує наступні дії:
 корегування списку з клавіатури (добавлення, вилучення, редагування
інформації);
 сортування за назвою магазину або за загальною вартістю;
 вивід на екран інформації про товари, що продаються в магазині, назва якого
введена з клавіатури;
 вивід на екран інформації про товари із заданого з клавіатури діапазону вартості.*/
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum goods { bread, butter, sausage, oil, chocolate };
string namegoods[] = { "хліб","масло","ковбаса","олія","шоколад" };



struct Goods
{
    goods GoodsP;

    float price;
    int count;
    int weight;
    string store;
};
void Create(Goods* p, const int N);
void Print(Goods* p, const int N);
void SortName(Goods* p, const int N);
void SortPrice(Goods* p, const int N);
void ShowPrice(Goods* p, const int N, float high,float low);
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N; 
    cout << "введіть кількість магазинів ";
    cin >> N;
    Goods* p = new Goods[N];

    float high, low;
    int menuItem;
   
    
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - сортувати за назвою магазину" << endl;
        cout << " [4] - сортувати за вартістю" << endl;
        cout << " [5] - вивід продуктів в заданому діапазоні цін " << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(p, N);
        case 2:
            Print(p, N);
        case 3 :
            SortName(p, N);
        case 4:
            SortName(p, N);
        case 5:
            cout << "введіть нижній діапазон ціни ";
            cin >> low;
            cout << "введіть верхній діапазон ціни ";
            cin >> high;
            ShowPrice(p, N, high, low);
        default:
            break;
        }
    } while (menuItem != 0);
    
}
void ShowPrice(Goods* p, const int N, float high, float low)
{
    for (int i = 0; i < N; i++)
    {
        if (p[i].price > low && p[i].price < high)
        {
            cout << namegoods[p[i].GoodsP] << endl;
        }
    }
}

void SortPrice(Goods* p, const int N)
{
    Goods tmp;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < i-1; j++)
        {
            if (p[j].price > p[j + 1].price) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}

void SortName(Goods* p, const int N)
{
    Goods tmp;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j <i-1; j++)
        {
            if (p[j].store > p[j + 1].store) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}

void Create(Goods* p, const int N)
{
    int produkt;
    for (int i = 0; i < N; i++)
    {
        cout << "магазин " << i + 1 << ":" << endl;
        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
        cout << " назва магазину "; getline(cin, p[i].store);
        cout << "виберіть товар "; cout << endl;
        cout << "введіть :" << endl << "0 - хліб " << endl
            << "1 - масло" << endl
            << "2-ковбаса" << endl
            << "3-олія" << endl
            << "4-шоколад" << endl;
        cin >> produkt;
        p[i].GoodsP = goods(produkt);
       
        cout << endl << "кількість одиниць товару в магазині " << endl;
        cin >> p[i].count;
        cout << "вага одиниці товару в кг " << endl;
        cin >> p[i].weight;
        cout << "введіть ціну на одиницю товару ";
        cin >> p[i].price;
		cout << endl;
        
    }
}
void Print(Goods* p, const int N)
{
	cout << "======================================================================="
		<< endl;
	cout << "| № | Назва товару   |store      | кількість    | вага     | ціна     |"
		<< endl;
	cout << "-----------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(15) << left << namegoods[p[i].GoodsP];

        cout << "| " << setw(4) << right << p[i].store << " "
            << "| " << setw(8) << left << p[i].count << "       |" << p[i].weight << "     |" << p[i].price << "     |"<<endl;
		
	}
	cout << "======================================================================="
		<< endl;
	cout << endl;
}