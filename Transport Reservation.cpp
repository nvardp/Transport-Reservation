#include <iostream>
#include "errors.h"
#include "bus.h"

const std::string ADD = "add";
const std::string SEARCH = "search";
const std::string RESERVE = "reserve";
const std::string INFO = "info";
const std::string AVAILABLE_BUSSES = "buses available";
const std::string EXIT = "exit";




bool execute(std::string& command, Bus& bus)
{
	for (int i = 0; i < command.size(); i++)
	{
		command[i] = tolower(command[i]);
	}

	if (command == ADD)
	{
		if (bus.add_new_bus())
		{
			std::cout << SUCCESS;
			return true;
		}
		else
		{
			std::cout << ERRORS::not_integer();
			return false;
		}
	}
	else if (command == SEARCH)
	{
		auto number = Bus::get_target_number("Enter bus number ");
		if (number)
		{
			std::cout << bus.bus_info(number);
			return true;
		}
		else
		{
			std::cout << ERRORS::not_integer();
			return false;
		}
	}
	else if (command == RESERVE)
	{
		auto b_number = Bus::get_target_number("Enter bus number ");
		auto s_number = Bus::get_target_number("Enter seat number ");
		if (s_number > MAX_SEATS || s_number <= 0)
		{
			std::cout << ERRORS::out_of_range();
		}
		else if (b_number && s_number)
		{
			std::cout << bus.reserve(b_number, s_number);
		}
		else
		{
			std::cout << ERRORS::not_integer();
		}
			return true;
			
	}
	else if (command == INFO)
	{
		auto b_number = Bus::get_target_number("Enter bus number ");
		if (b_number)
			std::cout << bus.info(b_number);
		else std::cout << ERRORS::not_integer();
		return true;
	}
	else if (command == AVAILABLE_BUSSES)
	{
		std::cout << bus.available_buses();
	}
	else
	{
		std::cout << ERRORS::wrong_command();
		return false;
	}
}

void rules()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);
	std::string str = "1. to add a new bus write <<add>>\n";
	str += "2. to search for information about certain bus write <<search>>\n";
	str += "3. to reserve a seat write <<reserve>>\n";
	str += "4. to search for information about certain bus with seats write <<info>>\n";
	str += "5. to see available busses write <<buses available>>\n";
	str += "6. to stop the program write <<exit>>\n";
	std::cout << str;
	SetConsoleTextAttribute(hConsole, 15);
}




int main()
{
	Bus bus;
	std::string command{};
	rules();
	while (command != EXIT)
	{
		std::cout << "----type your command----\n";

		std::getline(std::cin, command);
		if (execute(command, bus))
		{
			std::cin.clear();
			std::cin.ignore();
		}

	}
}

