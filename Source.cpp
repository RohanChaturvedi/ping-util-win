//Ping utility
//Rohan Chaturvedi 2017

#include <iostream>
#include <string>
#include <windows.h>

void ping()
{
	
	static std::string host;//host address for single pings
	
	class ping_host//simple class to hold addresses and respective countries
	{
	public:
		std::string country;
		std::string address;
		ping_host(){ country = "", address = ""; }//default constructor
		ping_host(std::string c, std::string a){ this->country = c; this->address = a; }//parameter constructor
	};
	
	system("Color 0A");//make console text green :D
	system("cls");
	
	std::cout << "\n===============================================================\n";
	std::cout << "\t\t\tPing utility";
	std::cout << "\n===============================================================\n";
	int menu;
	
	while (1)
	{
		try//input validation for selection
		{
			std::cout << "\n[1] Ping single address\n\n[2] Ping common addresses\n";
			std::cin >> menu;
			if (menu != 1 && menu != 2)
			{
				throw ("Invalid option!\n");//throw exception
			}
			break;//break out of while if no exception
		}
		catch (const char* s){ std::cout << "Error: " << s; }
	}
	switch(menu)
	{
	case 1:std::cout << "Host: ";//single ping
		std::cin >> host;
		system(("ping " + host + " -n 10").c_str());//system pibg call with given address (10 times)
		std::cout << '\n';
		break;
	case 2://ping hardcoded addresses
		static ping_host commonHosts[7] = //array of hosts
		{ 
			   ping_host("Australia", "ftp.au.debian.org"),
			   ping_host("Beligum", "ftp.be.debian.org"), 
			   ping_host("France", "ftp.fr.debian.org"), 
			   ping_host("Russia", "ftp.ru.debian.org"), 
			   ping_host("Singapore", "ftp.sg.debian.org"), 
			   ping_host("United Kingdom", "ftp.uk.debian.org"), 
			   ping_host("United States", "ftp.us.debian.org"),
		};
		int num = 7;//size of array
		
		std::cout << "\nPinging " << num << " addresses...\n";
		for (int i = 0; i < num; i++)
		{
			   
			std::cout << '\n' +  commonHosts[i].country + ":\n";
			system(("ping " + commonHosts[i].address + " -n 5").c_str());
			std::cout << "\n-------------------------\n";
			   
		}
		   break;

	}
	char choice;
	std::cout << "\nPing again? [Y] [N]\n";
	std::cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		ping();
	}
	else
	{
		system("exit");
	}

	
	
	
}

int main()
{
	SetConsoleTitle("Ping in C++ by ascendance");
	
	ping();//function call

	return(0);
}