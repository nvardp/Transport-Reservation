#pragma once
#include <iostream>
 
namespace ERRORS {

	std::string wrong_command()
	{
		return "no such command, try again.\n";
	}
	std::string not_integer()
	{
		return  "Bus number should be only positive number. try again.\n";
	}
	std::string existing_bus()
	{
		return "Bus with such number already exis.\n";
	}

	std::string wrong_bus_number()
	{
		return "no such bus number, try again.\n";
	}

	std::string reserved_seat_number()
	{
		return "this seat is already reserved. Try again.\n";
	}
	std::string out_of_range()
	{
		return  "Bus has only 10 available seats. try again.\n";
	}
}
