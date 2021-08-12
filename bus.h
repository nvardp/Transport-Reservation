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
	Bus(int, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);

public:
	unsigned get_number() const;
	std::string get_driver_name() const;
	std::string get_departure_time() const;
	std::string get_arrival_time() const;
	std::string get_starting_point() const;
	std::string get_destination() const;
	std::bitset<MAX_SEATS> get_seats() const;
	void set_seats(int index);

private:
	const unsigned int number;
	const std::string driver_name;
	const std::string departure_time;
	const std::string arrival_time;
	const std::string starting_point;
	const std::string destination;
	std::bitset<MAX_SEATS> seats;
};


