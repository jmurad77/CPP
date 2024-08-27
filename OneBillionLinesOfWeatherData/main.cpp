// StudingInterviews.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <time.h> 
#include <chrono>

struct WeatherData_t
{
    float min;
    float avg;
    float max;
    unsigned int count;
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    
    // create a stream object to weather File
    std::ifstream weatherFile("weather_stations_1Gb.csv"); 

    std::string line = "";
    std::string city = "";
    float temperature = 0.0;
    char delimiter = ';';

    std::map<std::string, WeatherData_t> weatherDataMap;
    if (weatherFile.is_open())
    {
        // ignore first two lines that are comments
        getline(weatherFile, line);
        getline(weatherFile, line);

        while (getline(weatherFile, line))
        {
            std::stringstream ss(line);
            std::string token;
            getline(ss, token, delimiter);
            city = token;
            getline(ss, token, delimiter);
            float temperature = std::stof(token);

            auto weatherItem = weatherDataMap.find(city);
            if (weatherItem != weatherDataMap.end())
            {
                if (weatherItem->second.min > temperature)
                {
                    weatherItem->second.min = temperature;
                }
                else if (weatherItem->second.max < temperature)
                {
                    weatherItem->second.max = temperature;
                }        

                // Add up the total sum of the temperatures so we can calculate the avg later
                weatherItem->second.avg += temperature;

                // Add 1 to total number of weather temperature points to calulate avg
                weatherItem->second.count += 1;

                // Udpate Map weather data
                weatherDataMap.at(city) = weatherItem->second;
            }
            else
            {
                weatherDataMap.insert(std::make_pair(city, WeatherData_t{temperature,temperature,temperature,1}));
            }
        }
    }

    std::ofstream outputFile;
    outputFile.open("output.csv");
    for (auto it = weatherDataMap.begin(); it != weatherDataMap.end(); it++)
    {
        outputFile << it->first << ';' 
        << it->second.min << ';' 
        << it->second.avg/it->second.count << ';'
        << it->second.max << '\n';
        
    }

    outputFile.close();
    weatherFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    printf("Time Performance: %f sec\n", time_taken*1e-9);

    return 0;
}
