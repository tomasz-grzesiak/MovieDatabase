#include "Menu.h"

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::Display()
{
	std::cout << "Wybierz opcje z listy: \n1. Dodaj tytul\n";
	std::cout << "2. Usun tytul\n3. Edytuj tytul\n4. Wyswietl wszystkie tytuly\n";
	std::cout << "5. Wyswietl statystyki\n6. Rekomendacje\n7. Wyjdz z programu\n";
}

MovieishEntity* Menu::Add()
{
	system("cls");
	std::cout << "Wybierz typ:\n1. Serial\n2. Film\n3. Wydarzenie na zywo\n";
	char a;
	std::cin >> a;
	std::cin.clear();
	std::cin.ignore(100, '\n');
	system("cls");
		switch (a)
		{
		case '1':
		{
			Series* one = new Series;
			std::cout << "Tytul: ";
			std::string title;
			std::cin >> title;
			one->SetTitle(title);
			std::cout << "Liczba sezonow: ";
			int season;
			std::cin >> season;
			one->SetSeasonCtr(season);
			std::cout << "Sledzony? (y/n): ";
			char a;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (a == 'n' || a == 'N')
				one->Unfollow();
			else
				one->Follow();
			MovieishEntity* ptr;
			ptr = one;
			return ptr;
			break;
		}
		case '2':
		{
			Film* one = new Film;
			std::cout << "Tytul: ";
			std::string title;
			std::cin >> title;
			one->SetTitle(title);
			std::cout << "Miejsce w rankingu IMDb: ";
			int place;
			std::cin >> place;
			one->SetPlace(place);
			std::cout << "Sledzony? (y/n): ";
			char a;
			std::cin >> a;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (a == 'n' || a == 'N')
				one->Unfollow();
			else
				one->Follow();
			MovieishEntity* ptr;
			ptr = one;
			return ptr;
			break;
		}
		case '3':
		{
			Stream* one = new Stream;
			std::cout << "Tytul: ";
			std::string title;
			std::cin >> title;
			one->SetTitle(title);
			std::cout << "Data wydarzenia (DD MM): ";
			int day, month;
			std::cin >> day >> month;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			one->SetDate(day, month);
			MovieishEntity* ptr;
			ptr = one;
			return ptr;
			break;
		}
		default:
		{
			std::string a = "Bledna dana wejsciowa\n";
			throw a;
		}
		}

}