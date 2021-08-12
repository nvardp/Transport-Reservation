#pragma once
#include "errors.h"

std::string ERRORS::wrong_command()
{
	return "no such command, try again.\n";
}
std::string ERRORS::not_integer()
{
	return  "Bus number should be only positive number. try again.\n";
}
std::string ERRORS::existing_bus()
{
	return "Bus with such number already exis.\n";
}

std::string ERRORS::wrong_bus_number()
{
	return "no such bus number, try again.\n";
}

std::string ERRORS::reserved_seat_number()
{
	return "this seat is already reserved. Try again.\n";
}
std::string ERRORS::out_of_range()
{
	return  "Bus has only 10 available seats. try again.\n";
}
