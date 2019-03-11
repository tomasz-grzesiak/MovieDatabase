#include "Menu.h"
#include <Windows.h>

int main()
{
	Menu menu;
	Set<MovieishEntity*> database;
	database.Load();
	database.Alert();
	while (true)
	{
		try
		{
		system("cls");
		menu.Display();
		char a;
		std::cin >> a;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		switch (a)
		{
		case '1':				//dodaj tytu³
		{
			MovieishEntity* one = menu.Add();
			database += one;
			database.Save();
			break;
		}
		case '2':				//usuñ tytu³
		{
			database.DisplayAllWithNumbers();
			std::cout << "Numer tytulu do usuniecia: ";
			int a;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (a<1 || a>database.Length())
			{
				std::string a = "Bledna dana wejsciowa\n";
				throw a;
			}
			database -= a;
			database.Save();
			break;
		}
		case '3':				//zmieñ tytu³
		{
			database.DisplayAllWithNumbers();
			std::cout << "Numer tytulu do zmiany: ";
			int a;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (a<1 || a>database.Length())
			{
				std::string a = "Bledna dana wejsciowa\n";
				throw a;
			}
			database.Edit(a);
			database.Save();
			break;
		}
		case '4':				//wypisz wszystkie
		{
			system("cls");
			database.DisplayAll();
			system("pause");
			break;
		}
		case '5':				//statystyki
		{
			system("cls");
			database.ShowStatistics();
			system("pause");
			break;
		}
		case '6':				//sugeruj
		{
			system("cls");
			database.Suggest();
			system("pause");
			break;
		}
		case '7':				//wyjdŸ
		{
			system("cls");
			std::cout << "Do zobaczenia!\n\n";
			Sleep(2000);
			return 0;
		}
		default:
		{
			std::string a = "Bledna dana wejsciowa\n";
			throw a;
		}
		}
		}
		catch (std::string a)
		{
			std::cout << a << std::endl;
			system("pause");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			system("pause");
		}
	}
}