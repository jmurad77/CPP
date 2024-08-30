#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <time.h>

int main()
{
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::duration<float, std::milli> mil;

	std::srand(std::time(0));
    std::string output;

	std::string name = "My Name is: John Murad";
	std::string age = ", My age is: ";
	std::string height = ", My height is: 6foot";
	std::string temp = ", Temperature outside is: ";
	int ageNumber = std::rand();
	float temperature = float(std::rand()) + 0.69f;
	const int reserveSize = 128;

	/*<><><><><><><> START STRING CONCATINATION <><><><><><><>*/
	// using Seq '+' operator in one line to concat
	auto start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name + age + height;
	}
	auto end = clock::now();
	printf("SEQ '+'\t\t\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	// Using += to concatinate
	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name;
		output += age;
		output += height;
	}
	end = clock::now();
	printf("'+='\t\t\t TIME: %fms\n", mil(end-start).count());
	output.clear();
	
	//Using .append from string class
	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name;
		output.append(age);
		output.append(height);
	}
	end = clock::now();
	printf("STRING.APPEND\t\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	// using ostring stream to append strings
	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		std::ostringstream oss;
		oss << name << age << height;
		output = oss.str();
	}
	end = clock::now();
	printf("OSTRING STREAM\t\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	// using stringstream
	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		std::stringstream ss;
        ss << name << age << height;
        output = ss.str();
	}
	end = clock::now();
	printf("STRING STREAM\t\t TIME: %fms\n", mil(end-start).count());	
	output.clear();
	/*<><><><><><><> END STRING CONCATINATION <><><><><><><>*/

	/*<><><><><><><> FORAMTED STRING CONCATINATION <><><><><><><>*/
	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name + age + std::to_string(ageNumber) +  height + temp + std::to_string(temperature);
	}
	end = clock::now();
	printf("FORMATED SEQ '+'\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name;
		output += age;
		output += std::to_string(ageNumber);
		output += height;
		output += temp;
		output += std::to_string(temperature);
	}
	end = clock::now();
	printf("FORMATED '+='\t\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		output = name;
		output.append(age);
		output.append(std::to_string(ageNumber));
		output.append(height);
		output.append(temp);
		output.append(std::to_string(temperature));
	}
	end = clock::now();
	printf("FORMATED STRING.APPEND\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		std::ostringstream oss;
		oss << name << age << ageNumber << height << temp << temperature;
		output = oss.str();
	}
	end = clock::now();
	printf("FORMATED OSTRING STREAM\t TIME: %fms\n", mil(end-start).count());
	output.clear();

	start = clock::now();
	for (int i = 0; i < 100000; i++)
	{
		std::stringstream ss;
        ss << name << age << ageNumber << height << temp << temperature;
        output = ss.str();
	}
	end = clock::now();
	printf("FORMATED STRING STREAM\t TIME: %fms\n", mil(end-start).count());	
	output.clear();
	/*<><><><><><><> END FORAMTED STRING CONCATINATION <><><><><><><>*/
}
