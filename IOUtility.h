#pragma once
	namespace IOUtils {

		std::string read_string(const char* message) {
			std::string value;
			std::cout << message;
			std::cin >> value;
			return value;
		}

		int read_int(const char* message) {
			int value=0;
			std::cout << message;
			std::cin >> value;
			if (std::cin.fail() || value <= 0)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				return 0;
			}
			return value;
		}
	}
