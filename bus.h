#pragma once
#include <string>
#include <map>
#include <iostream>
#include<fstream>
#include <Windows.h>
#include <bitset>
#include "errors.h"

const int MAX_SEATS = 10;
const std::string SUCCESS = "Done!\n";

class Bus {
public:
	Bus();
	static int get_target_number(std::string show_what);

	bool add_new_bus();

	std::string bus_info(int number) const;
	std::string reserve(int bus_number, int seat_number);
	std::string info(int bus_number) const;
	std::string available_buses() const;

	unsigned get_number() const;
	std::string get_driver_name() const;
	std::string get_departure_time() const;
	std::string get_arrival_time() const;
	std::string get_starting_point() const;
	std::string get_destination() const;

private:
	Bus(int other);


private:
	unsigned int number;
	std::string driver_name;
	std::string departure_time;
	std::string arrival_time;
	std::string starting_point;
	std::string	 destination;

	std::bitset<MAX_SEATS> seats;
	std::map<int, Bus> existing_bus_numbers;

};

bool operator<(Bus lhs, Bus rhs)
{
	return lhs.get_number() < rhs.get_number();
}
