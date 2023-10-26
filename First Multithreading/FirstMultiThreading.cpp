// lesson from: https://youtu.be/xPqnoB2hjjA

#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> forecastMap)
{
    while (true) {
        for (auto& item : forecastMap) {
            item.second++;
            std::cout << item.first << "-" << item.second << std::endl;
        }

        std::this_thread::sleep_for(2000ms);
    }
}

int main() {
    std::map<std::string, int> forecastMap = {
        {"New York", 18},
        {"Manila", 29},
        {"Los Angeles", 19},
    };

    std::thread bgWorker(RefreshForecast, forecastMap);

    system("pause>nul");
}