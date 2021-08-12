#include <iostream>
#include "transport_manager.h"
#include "IOUtility.h"

const std::string ADD = "add";
const std::string SEARCH = "search";
const std::string RESERVE = "reserve";
const std::string INFO = "info";
const std::string AVAILABLE_BUSSES = "buses available";
const std::string EXIT = "exit";


bool _execute_add(transport_manager& manager)
{
	const int bus_number = IOUtils::read_int("Bus number\t");
	if (bus_number)
	{
		if (manager.has_bus(bus_number)) {
			std::cout<< ERRORS::existing_bus();
			return true;
		}
	}
	else {
		std::cout << ERRORS::not_integer();
		return false;
	}
	manager.add_bus(Bus(bus_number,
		IOUtils::read_string("Driver name\t"),
		IOUtils::read_string("Departure time\t"),
		IOUtils::read_string("Arrival time\t"),
		IOUtils::read_string("Starting point\t"),
		IOUtils::read_string("Destination\t")
	));
	std::cout << SUCCESS;
	return true;
}

std::string _execute_search(const transport_manager& manager)
{
	const int bus_number = IOUtils::read_int("Bus number\t");
	if (!manager.has_bus(bus_number)) {
		return ERRORS::wrong_bus_number();
	}
	else return manager.get_bus_as_str(bus_number);
}

std::string _execute_reserve(transport_manager& manager)
{
	const int b_number = IOUtils::read_int("Bus number\t");
	const int s_number = IOUtils::read_int("Seat number\t");
	if (s_number > MAX_SEATS || s_number <= 0)
	{
		return ERRORS::out_of_range();
	}
	else if (b_number && s_number)
	{
		if (manager.has_bus(b_number)) {
			return  manager.reserve(b_number, s_number);
		}
		else return ERRORS::wrong_bus_number();
	}
}

std::string _execute_info(const transport_manager& manager)
{
	const int bus_number = IOUtils::read_int("Bus number\t");
	if (!manager.has_bus(bus_number)) {
		return ERRORS::wrong_bus_number();
	}
	else return manager.info(bus_number);
}

std::string _execute_available_buses(const transport_manager& manager)
{
	return manager.info_with_seats();
}
bool execute(std::string& command, transport_manager& manager)
{
	for (int i = 0; i < command.size(); i++)
	{
		command[i] = tolower(command[i]);
	}
	if (command == ADD)
		return	 _execute_add(manager);
	else if (command == SEARCH)
		std::cout << _execute_search(manager);
	else if (command == RESERVE)
		std::cout << _execute_reserve(manager);
	else if (command == INFO)
		std::cout << _execute_info(manager);
	else if (command == AVAILABLE_BUSSES)
		std::cout << _execute_available_buses(manager);
	else
	{
		std::cout << ERRORS::wrong_command();
		return false;
	}
	return true;
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
	transport_manager manager;
	std::string command{};
	rules();
	while (command != EXIT)
	{
		std::cout << "----type your command----\n";
		std::getline(std::cin, command);
		if (execute(command, manager))
		{
			std::cin.clear();
			std::cin.ignore();
		}

	}
}

