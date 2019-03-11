#pragma once
#include <list>
#include <fstream>

template <class T> class Set
{
private:
	std::list<T> data;
	int followed_counter;
public:
	Set()
	{ 
		followed_counter = 0;
		data.clear();
	};
	~Set() 
	{
		auto ptr = data.begin();
		while (ptr != data.end())
			delete *ptr++;
		data.clear();
	};
	void operator+= (T a) 
	{ 
		data.push_back(a);
		if (a->IsFollowed())
			followed_counter++;
	};
	void operator-= (int a)
	{
		auto it = data.begin();
		for (int b = 1; b < a; b++)
			++it;
		if ((*it)->IsFollowed())
			followed_counter--;
		delete *it;
		data.erase(it);
	};
	int Length()
	{
		return data.size();
	}
	void DisplayAll()
	{
		system("cls");
		if (data.size() == 0)
		{
			std::cout << "Baza jest pusta\n";
			return;
		}
		auto ptr = data.begin();
		while (ptr != data.end())
		{
			(*ptr++)->Display();
			std::cout << std::endl;
		}
	}
	void DisplayAllWithNumbers()
	{
		system("cls");
		if (data.size() == 0)
		{
			std::cout << "Baza jest pusta\n";
			return;
		}
		auto ptr = data.begin();
		int i = 1;
		while (ptr != data.end())
			std::cout << i++ << ". " << (*ptr++)->GetTitle() << std::endl;
	}
	void ShowStatistics()
	{
		std::cout << "Liczba tytulow w bazie: " << data.size() << std::endl;
		std::cout << "Liczba tytulow sledzonych: " << followed_counter << std::endl;
	};
	void Edit(int a)
	{
		system("cls");
		auto it = data.begin();
		for (int i = 1; i < a; i++)
			it++;
		int type = (*it)->GetType();
		if (type == 0)
		{
			Series* ptr = (Series*)(*it);
			std::cout << "Wybierz element do zmiany:\n1. Tytul\n2. Liczba sezonow\n3. Zmien tryb sledzenia\n";
			char in;
			std::cin >> in;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (in!='1' && in!='2'&&in!='3')
			{
				std::string a = "Bledna dana wejsciowa\n";
				throw a;
			}
			system("cls");
			if (in == '1')
			{
				std::cout << "Nowy tytul: ";
				std::string title;
				std::cin >> title;
				ptr->SetTitle(title);
			}
			if (in == '2')
			{
				std::cout << "Nowa liczba sezonow: ";
				int season;
				std::cin >> season;
				ptr->SetSeasonCtr(season);
			}
			if (in == '3')
			{
				if (ptr->IsFollowed())
				{
					ptr->Unfollow();
					followed_counter--;
				}
				else
				{
					ptr->Follow();;
					followed_counter++;
				}
			}
			*it = ptr;
		}
		if (type == 1)
		{
			Film* ptr = (Film*)(*it);
			std::cout << "Wybierz element do zmiany:\n1. Tytul\n2. Miejsce w rankingu\n3. Zmien tryb sledzenia\n";
			char in;
			std::cin >> in;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (in != '1' && in != '2'&&in != '3')
			{
				std::string a = "Bledna dana wejsciowa\n";
				throw a;
			}
			system("cls");
			if (in == '1')
			{
				std::cout << "Nowy tytul: ";
				std::string title;
				std::cin >> title;
				ptr->SetTitle(title);
			}
			if (in == '2')
			{
				std::cout << "Nowe miejsce w rankingu: ";
				int place;
				std::cin >> place;
				ptr->SetPlace(place);
			}
			if (in == '3')
			{
				if (ptr->IsFollowed())
				{
					ptr->Unfollow();
					followed_counter--;
				}
				else
				{
					ptr->Follow();;
					followed_counter++;
				}
			}
			*it = ptr;
		}
		if (type == 2)
		{
			Stream* ptr = (Stream*)(*it);
			std::cout << "Wybierz element do zmiany:\n1. Tytul\n2. Data\n";
			char in;
			std::cin >> in;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			if (in != '1' && in != '2')
			{
				std::string a = "Bledna dana wejsciowa\n";
				throw a;
			}
			system("cls");
			if (in == '1')
			{
				std::cout << "Nowy tytul: ";
				std::string title;
				std::cin >> title;
				ptr->SetTitle(title);
			}
			if (in == '2')
			{
				std::cout << "Nowa data (DD MM): ";
				int day, month;
				std::cin >> day >>month;
				ptr->SetDate(day, month);
			}
			*it = ptr;
		}
	}
	void Suggest()
	{
		if (data.size() == 0)
		{
			std::cout << "Baza jest pusta\n";
			return;
		}
		T sug1, sug2, sug3;
		auto ptr = data.begin();
		srand(time(NULL));
		std::cout << "Propozycje na dzisiaj: \n" << std::endl;
		int i = rand()%data.size();
		for (int a = 0; a<i; a++) 
			ptr++;
		sug1 = *ptr;
		std::cout << "1. ";
		sug1->Display();
		std::cout << std::endl;
		if (data.size() == 1)
			return;
		int j = rand() % data.size();
		while (i == j)
			j = rand() % data.size();
		ptr = data.begin();
		for (int a = 0; a < j; a++) 
			ptr++;
		sug2 = *ptr;
		std::cout << "2. ";
		sug2->Display();
		std::cout << std::endl;
		if (data.size() == 2)
			return;
		int k = rand() % data.size();
		while (k == i || k == j)
			k = rand() % data.size();
		ptr = data.begin();
		for (int a = 0; a < k; a++)
			ptr++;
		sug3 = *ptr;
		std::cout << "3. ";
		sug3->Display();
		std::cout << std::endl;
	};
	int GetType(int a)
	{
		T* ptr = data.begin() + a - 1;
		return ptr->GetType();
	}
	void Load()
	{
		std::ifstream file("data.txt");
		if (file.fail())
			return;
		while (!file.eof())
		{
			int type;
			file >> type;
			if (type == 0)
			{
				Series* one = new Series;
				std::string title;
				file >> title;
				one->SetTitle(title);
				int season;
				file >> season;
				one->SetSeasonCtr(season);
				int fol;
				file >> fol;
				if (fol == 1)
				{
					one->Follow();
					followed_counter++;
				}
				else
					one->Unfollow();
				T ptr;
				ptr = one;
				data.push_back(ptr);
			}
			if (type == 1)
			{
				Film* one = new Film;
				std::string title;
				file >> title;
				one->SetTitle(title);
				int place;
				file >> place;
				one->SetPlace(place);
				int fol;
				file >> fol;
				if (fol == 1)
				{
					one->Follow();
					followed_counter++;
				}
				else
					one->Unfollow();
				T ptr = one;
				data.push_back(ptr);
			}
			if (type == 2)
			{
				Stream* one = new Stream;
				std::string title;
				file >> title;
				one->SetTitle(title);
				int day, month;
				file >> day >> month;
				one->SetDate(day, month);
				int fol;
				file >> fol;
				if (fol == 1)
				{
					one->Follow();
					followed_counter++;
				}
				else
					one->Unfollow();
				T ptr = one;
				data.push_back(ptr);
			}
		}
		if ((*--data.end())->IsFollowed())
			followed_counter--;
		data.erase(--data.end());
		file.close();
	}
	void Save()
	{
		std::ofstream file("data.txt");
		auto ptr = data.begin();
		while (ptr != data.end())
		{
			int type = (*ptr)->GetType();
			file << type << " ";
			if (type == 0)
			{
				Series* one = (Series*)*ptr++;
				file << one->GetTitle() << " ";
				file << one->GetSeasonCtr() << " ";
				if (one->IsFollowed())
					file << 1 << std::endl;
				else
					file << 0 << std::endl;
			}
			if (type == 1)
			{
				Film* one = (Film*)*ptr++;
				file << one->GetTitle() << " ";
				file << one->GetPlace() << " ";
				if (one->IsFollowed())
					file << 1 << std::endl;
				else
					file << 0 << std::endl;
			}
			if (type == 2)
			{
				Stream* one = (Stream*)*ptr++;
				file << one->GetTitle() << " ";
				file << one->GetDay() << " " << one->GetMonth() << " ";
				if (one->IsFollowed())
					file << 1 << std::endl;
				else
					file << 0 << std::endl;
			}
		}
	}
	void Alert()
	{
		auto it = data.begin();
		bool flag = true;
		while (it != data.end())
		{
			if ((*it)->GetType() == 2)
			{
				Stream* one = (Stream*)*it;
				time_t tmp = time(0);
				tm now;
				localtime_s(&now, &tmp);
				if (now.tm_mon + 1 == one->GetMonth() && now.tm_mday == one->GetDay())
				{
					if (flag)
					{
						flag = false;
						std::cout << "Wydarzenia na zywo dzisiaj!\n";
					}
					std::cout << one->GetTitle() << std::endl;
				}
			}
			it++;
		}
		if (!flag)
			system("pause");
	}
};
