#pragma once
#include <string>
#include <map>
#include <iostream>
#include<fstream>
#include <Windows.h>
#include "bus.h"
#include <bitset>

const int MAX_SEATS = 10;
const std::string SUCCESS = "Done!\n";

class Bus {
public:
	Bus() :
		number(0), seats{}, driver_name{}, departure_time{},
		arrival_time{}, starting_point{}, destination{}, existing_bus_numbers{}
	{};
	static int get_target_number(std::string show_what)
	{
		std::cout << show_what;
		int tmp;
		std::cin >> tmp;
		if (std::cin.fail()||tmp<0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return 0;
		}
		else
			return tmp;
	}

	bool add_new_bus()
	{
		number = get_target_number("Bus number	");
		if (!number)
			return false;

		std::cout << "driver name	";
		std::cin >> driver_name;
		std::cout << "departure time	";
		std::cin >> departure_time;
		std::cout << "arrival time	";
		std::cin >> arrival_time;
		std::cout << "starting point	";
		std::cin >> starting_point;
		std::cout << "destination	";
		std::cin >> destination;
		auto reply = existing_bus_numbers.insert(std::pair<int, Bus>(number, *this));
		if (reply.second == false)
			std::cout << ERRORS::existing_bus();
		return true;
	}

	std::string bus_info(int number) const
	{

		auto search_index = existing_bus_numbers.find(number);
		if (search_index != existing_bus_numbers.end())
		{
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
		else return ERRORS::wrong_bus_number();
	}


	std::string reserve(int bus_number, int seat_number)
	{
		auto search_index = existing_bus_numbers.find(bus_number);
		if (search_index != existing_bus_numbers.end())
		{
			if ((search_index->second).seats[seat_number - 1])
				return ERRORS::reserved_seat_number();
			else {
				(search_index->second).seats[seat_number - 1] = true;
				return SUCCESS;
			}
		}
		else return ERRORS::wrong_bus_number();
	}

	std::string info(int bus_number)
	{
		auto search_index = existing_bus_numbers.find(bus_number);
		if (search_index != existing_bus_numbers.end())
		{
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
				if (!(search_index->second).seats[i])
				{
					result += std::to_string(i + 1);
					result += " ";
				}
			}
			return 	 result+="\n";
		}
		else return ERRORS::wrong_bus_number();
	}

	std::string available_buses()
	{
		std::string result{};
		for (auto it = existing_bus_numbers.begin(); it != existing_bus_numbers.end(); ++it)
		{
			if (!(it->second).seats.all())
			{
				result += std::to_string(it->first);
				result += " ";
			}
		}
		return result==""?"NO AVAILABLE SEATS.\n":result;
	}

	unsigned get_number() const
	{
		return number;
	}
	std::string get_driver_name() const
	{
		return driver_name;
	}
	std::string get_departure_time() const
	{
		return departure_time;
	}
	std::string get_arrival_time() const
	{
		return arrival_time;
	}
	std::string get_starting_point() const
	{
		return starting_point;
	}
	std::string get_destination() const
	{
		return 	 destination;
	}

private:
	Bus(int other) :
		number(other), seats{}, driver_name{}, departure_time{},
		arrival_time{}, starting_point{}, destination{}, existing_bus_numbers{}
	{  }


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
