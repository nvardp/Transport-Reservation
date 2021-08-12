#include "transport_manager.h"

bool transport_manager::add_bus(const Bus& bus)
{
	auto reply = existing_bus_numbers.insert(std::pair<int, Bus>(bus.get_number(), bus));
	if (reply.second == false)
		std::cout << ERRORS::existing_bus();
	return true;
}

bool transport_manager::has_bus(int number) const
{
	auto search_index = existing_bus_numbers.find(number);
	if (search_index != existing_bus_numbers.end())
	{
		return true;
	}
}

std::string transport_manager::get_bus_as_str(int number) const
{
	auto search_index = existing_bus_numbers.find(number);
	std::string result{ "Bus number " };
	result += std::to_string((search_index->second).get_number());
	result += "\nDriver name ";
	result += (search_index->second).get_driver_name();
	result += "\nDeparture time ";
	result += (search_index->second).get_departure_time();
	result += "\nArrival time ";
	result += (search_index->second).get_arrival_time();
	result += "\nStarting point ";
	result += (search_index->second).get_starting_point();
	result += "\nDestination ";
	result += (search_index->second).get_destination();
	result += "\n";
	return 	 result;
}
std::string transport_manager::reserve(int b_number, int s_number)
{
	auto search_index = existing_bus_numbers.find(b_number);
	if ((search_index->second).get_seats()[s_number - 1])
		return ERRORS::reserved_seat_number();
	else
	{
		(search_index->second).set_seats(s_number - 1);
		return SUCCESS;
	}
}

std::string transport_manager::info(int bus_number) const
{
	auto search_index = existing_bus_numbers.find(bus_number);
	std::string result{ "Bus number " };
	result += std::to_string((search_index->second).get_number());
	result += "\nDriver name ";
	result += (search_index->second).get_driver_name();
	result += "\nDeparture time ";
	result += (search_index->second).get_departure_time();
	result += "\nArrival time ";
	result += (search_index->second).get_arrival_time();
	result += "\nStarting point ";
	result += (search_index->second).get_starting_point();
	result += "\nDestination ";
	result += (search_index->second).get_destination();
	result += "\n\nAvailable seats ";
	for (int i = 0; i < MAX_SEATS; i++)
	{
		if (!(search_index->second).get_seats()[i])
		{
			result += std::to_string(i + 1);
			result += " ";
		}
	}
	return 	 result += "\n";
}

std::string transport_manager::info_with_seats() const
{
	std::string result{};
	for (auto it = existing_bus_numbers.begin(); it != existing_bus_numbers.end(); ++it)
	{
		if (!(it->second).get_seats().all())
		{
			result += std::to_string(it->first);
			result += " ";
		}
	}
	return result == "" ? "NO AVAILABLE SEATS.\n" : result;
}