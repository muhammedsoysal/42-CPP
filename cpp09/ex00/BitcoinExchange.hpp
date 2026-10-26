#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> _rates;

  bool checkDate(const std::string &date) const;
  bool checkValue(const std::string &valStr, double &val);
  std::string ft_trim(const std::string &str) const;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void readData(const std::string &dataFile);
  void calculate(const std::string &inputFile);
  double getRate(const std::string &date) const;
};

#endif