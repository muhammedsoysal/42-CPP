#include <iostream>
#include <fstream>

std::string ft_replace(std::string line, std::string s1, std::string s2)
{
	if (s1.empty())
		return line;

	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return line;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream infile(filename);
	if (!infile)
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cout << "Error: could not create file " << filename + ".replace" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(infile, line))
	{
		outfile << ft_replace(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}