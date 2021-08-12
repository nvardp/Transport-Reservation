#pragma once
#include <iostream>
 
namespace ERRORS {

	std::string wrong_command();
	std::string not_integer();
	std::string existing_bus();

	std::string wrong_bus_number();

	std::string reserved_seat_number();
	std::string out_of_range();
}
