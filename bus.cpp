#include "bus.h"

Bus::Bus(int number, std::string driver_name, std::string departure_time,
	 std::string arrival_time,  std::string starting_point, std::string destination) :
	number(number), seats{}, 
	driver_name{ std::move(driver_name) },
	departure_time{ std::move(departure_time) }, 
	arrival_time{ std::move(arrival_time) },
	starting_point{ std::move(starting_point) },
	destination{ std::move(destination) }
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
