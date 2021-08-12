#include "bus.h"

Bus::Bus(int number, const std::string& driver_name, const std::string& departure_time,
	const std::string& arrival_time, const std::string& starting_point, const std::string& destination) :
	number(number), seats{}, driver_name{ driver_name}, departure_time{ departure_time },
	arrival_time{ arrival_time}, starting_point{ starting_point }, destination{ destination }
{};
Bus::Bus(int other) :
	number(other), seats{}, driver_name{}, departure_time{},
	arrival_time{}, starting_point{}, destination{}
{};


std::bitset<MAX_SEATS> Bus::get_seats() const
{
	return seats;
}

void Bus::set_seats(int index)
{
	seats[index] = true;
}
unsigned Bus::get_number() const
{
	return number;
}
std::string Bus::get_driver_name() const
{
	return driver_name;
}
std::string Bus::get_departure_time() const
{
	return Bus::departure_time;
}
std::string Bus::get_arrival_time() const
{
	return arrival_time;
}
std::string Bus::get_starting_point() const
{
	return starting_point;
}
std::string Bus::get_destination() const
{
	return 	 destination;
}

bool operator<(const Bus& lhs, const Bus& rhs)
{
	return lhs.get_number() < rhs.get_number();
}