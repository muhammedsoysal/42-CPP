#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

// Constructor
BitcoinExchange::BitcoinExchange()
{
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

// Assignment Operatorne
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _rates = other._rates;
    }
    return *this;
}

std::string BitcoinExchange::ft_trim(const std::string &str) const
{
	std::string result = str;

	size_t first = result.find_first_not_of(" ");
	if (std::string::npos == first)
		return result;
	size_t last = result.find_last_not_of(" ");
	return result.substr(first, (last - first + 1));
}

bool BitcoinExchange::checkDate(const std::string &date) const
{
	if (date.length() != 10 || date[4]!='-' || date[7]!='-')
		return false;

	// Burada tirelerin dişindaki karakterlerin rakam olup olmadığını kontrol ediyoruz. 
	//isdigit rakam ise true dondurur.
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i ==4 ||i ==7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	// 1 Ocak 2009'dan onceki tarihler gecersizdir.
	// Aylar 1 ile 12 arasinda olmalidir.	
	// Gunler 1 ile 31 arasinda olmalidir.	
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// Yıl 
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;
    if (day < 1 || day > daysInMonth[month])
        return false;
    return true;
}

bool BitcoinExchange::checkValue(const std::string &valStr, double &val)
{
	std::string trim_valStr = ft_trim(valStr);
	
	if (trim_valStr.empty())
	{
		std::cerr << "Error: bad input => " << valStr << std::endl;
		return false;
	}
	
	char *endptr;
	val = strtod(trim_valStr.c_str(), &endptr);

	if (*endptr != '\0' || endptr == trim_valStr.c_str())
	{
		std::cerr << "Error: bad input => " << valStr << std::endl;
		return false;
	}
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	// 1000'den buyukse hata ver.
	if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::readData(const std::string &fileName)
{
	std::ifstream dataFile(fileName.c_str());

	// Dosya acilamazsa hata ver.
	if (!dataFile.is_open())
		throw  std::runtime_error("Error: could not open file: " + fileName);
	
	std::string line;
	std::getline(dataFile, line); // Header satırını oku ve atla.
	if (line !="date,exchange_rate")
		throw std::runtime_error("Error: invalid file format");

	while (std::getline(dataFile, line))
	{
		size_t commaPos = line.find(",");
		if (commaPos == std::string::npos)
			continue;
		
		// sol taraf date, sağ taraf value
		std::string date = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);

		char *endptr;
		double rate = strtod(value.c_str(), &endptr);
		
		// map'e ekle
		if (*endptr == '\0' && rate >= 0)
			_rates[date] = rate;	
	}
	dataFile.close();
}

double BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.upper_bound(date);

	// eğer map in listesinde en başta ise yani  yeni aranan tarih 
	//  bitcoinun ilk tarihinden daha eskiyse 0 döner.
	if(it == _rates.begin())
		return 0;
	// bir önceki elemana gel
	--it;
	return it->second;
}
void BitcoinExchange::calculate(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	
	std::string line;
	std::getline(file, line);

	if (line !="date | value" && line.find("date") == std::string::npos)
	{
		file.clear();
		file.seekg(0);
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		
		size_t pipePos = line.find("|");
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;	
		}
		std::string dateStr = ft_trim(line.substr(0, pipePos));
		std::string valueStr = ft_trim(line.substr(pipePos + 1));

		if (!checkDate(dateStr))
		{
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		double value;
		if (!checkValue(valueStr, value))
			continue;

		double rate = getRate(dateStr);
		std::cout << dateStr << " => " << value << " = " << value * rate << std::endl;
	}
	file.close();
}
