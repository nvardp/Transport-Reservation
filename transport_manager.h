#pragma once
#include <map>
#include "bus.h"

class transport_manager
{
public:
	bool add_bus(const Bus& bus);
	bool has_bus(int number) const;
	std::string get_bus_as_str(int number) const;
	std::string reserve(int b_number, int s_number);
	std::string info(int bus_number) const;
	std::string info_with_seats() const;

private:
	std::map<int, Bus> existing_bus_numbers;
};


