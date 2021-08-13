#include <iostream>
#include "transport_manager.h"
#include "IOUtility.h"

const std::string ADD = "add";
const std::string SEARCH = "search";
const std::string RESERVE = "reserve";
const std::string INFO = "info";
const std::string AVAILABLE_BUSSES = "buses available";
const std::string EXIT = "exit";

bool execute_add(transport_manager& manager)
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
	std::string name = IOUtils::read_string("Driver name\t");
	std::string Departure = IOUtils::read_string("Departure time\t");
	std::string Arrival = IOUtils::read_string("Arrival time\t");
	std::string Starting = IOUtils::read_string("Starting point\t");
	std::string Destination = IOUtils::read_string("Destination\t");

	manager.add_bus(Bus(bus_number, std::move(name),
					std::move(Departure), std::move(Arrival),
					std::move(Starting), std::move(Destination)));
	
	std::cout << SUCCESS;
	return true;
}

std::string execute_search(const transport_manager& manager)
{
	const int bus_number = IOUtils::read_int("Bus number\t");
	if (!manager.has_bus(bus_number)) {
		return ERRORS::wrong_bus_number();
	}
	return manager.get_bus_as_str(bus_number);
}

std::string execute_reserve(transport_manager& manager)
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
		 return ERRORS::wrong_bus_number();
	}
}

std::string execute_info(const transport_manager& manager)
{
	const int bus_number = IOUtils::read_int("Bus number\t");
	if (!manager.has_bus(bus_number)) {
		return ERRORS::wrong_bus_number();
	}
	 return manager.info(bus_number);
}

std::string execute_available_buses(const transport_manager& manager)
{
	return manager.info_with_seats();
}
bool execute(std::string command, transport_manager& manager)
{
	if (command == ADD)
		return	 execute_add(manager);
	else if (command == SEARCH)
		std::cout << execute_search(manager);
	else if (command == RESERVE)
		std::cout << execute_reserve(manager);
	else if (command == INFO)
		std::cout << execute_info(manager);
	else if (command == AVAILABLE_BUSSES)
		std::cout << execute_available_buses(manager);
	else
	{
		std::cout << ERRORS::wrong_command();
		return false;
	}
	return true;
}

void print_rules()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);
	std::cout
		<< "1. to add a new bus write <<add>>\n"
		<< "2. to search for information about certain bus write <<search>>\n"
		<< "3. to reserve a seat write <<reserve>>\n"
		<< "4. to search for information about certain bus with seats write "
		"<<info>>\n"
		<< "5. to see available busses write <<buses available>>\n"
		<< "6. to stop the program write <<exit>>\n";
	SetConsoleTextAttribute(hConsole, 15);
}


std::string to_lower(std::string str) {
	for (int i = 0; i < str.size(); ++i) {
		str[i] = tolower(str[i]);
	}
	return str;
}
int main()
{
	transport_manager manager;
	std::string command;
	print_rules();
	while (command != EXIT)
	{
		std::cout << "----type your command----\n";
		std::getline(std::cin, command);
		if (execute(to_lower(std::move(command)), manager))
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

