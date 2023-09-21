#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <limits>
#include "utilities.h"

int getRandomIntInRange(int from, int to) {
    return (from + std::rand() % (to - from + 1)); // NOLINT(cert-msc50-cpp)
}

std::stringstream convertStringsToSS(const std::vector<std::string> &strings) {
    std::string delim = " ";
    std::stringstream ss;
    std::copy(
            strings.begin(),
            strings.end(),
            std::ostream_iterator<std::string>(ss, delim.c_str()));

    return ss;
}

int putInput(int min) {
    int input;

    while (true) {
        std::cin >> input;

        if (std::cin.fail() || input < min) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input is invalid. Please try again:";
            continue;
        }

        break;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}

std::time_t getRandomDate() {
    std::vector<std::vector<int>> parts = { { 1970, 2022 }, { 1, 12 }, { 1, 31 } };
    std::vector<std::string> randoms;
    for (const auto &part : parts) {
        randoms.emplace_back(std::to_string(getRandomIntInRange(part[0], part[1])));
    }

    std::time_t now = time(nullptr);
    std::tm toParse = *localtime(&now);
    auto ss = convertStringsToSS(randoms);
    ss >> std::get_time(&toParse, "%Y %m %d");

    return mktime(&toParse);
}

void reloadStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

time_t putTime(char timeType, time_t basisTime) {
    std::string fmtDate = { '%', timeType };
    std::tm* localTime = localtime(&basisTime);

    while(true) {
        std::cin >> std::get_time(localTime, fmtDate.c_str());

        if (std::cin.fail()) {
            std::cout << "Wrong format. Try again:";
            reloadStream();
            continue;
        }

        if (mktime(localTime) < 0) {
            std::cout << "The date must be no earlier than January 1, 1970. Try again:";
            reloadStream();
            continue;
        }

        reloadStream();
        return mktime(localTime);
    }
}

// Например, putTimeByFormat("YYYY/mm/dd");
time_t putTimeByFormat(const std::string &format, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(format);
    std::string temp;

    while(std::getline(ss, temp, delim)) parts.emplace_back(temp);

    time_t date = time(nullptr);

    for (const auto &dateType : parts) {
        std::cout << "Enter data (" << dateType << "):";
        date = putTime(dateType[0], date);
    }

    return date;
}

int selectMenuItem(const std::vector<std::string> &list) {
    while (true) {
        std::cout << (list.size() > 1 ? ("Select one of the options:") : ("Enter the command:"));
        for (const auto &item : list) std::cout << item << (item != list[list.size() - 1] ? "|" : "\n");

        while (true) {
            std::string userInput;
            std::cout << "Type the command:";
            std::getline(std::cin, userInput);

            for (int i = 0; i < list.size(); ++i)
                if (list[i] == userInput) return i;

            std::cout << "Error. Try again!" << std::endl;
        }
    }
}