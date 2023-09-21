#include "track.h"

vector<string> list = { "Sting", "Bon Jovi", "Depeche mode", "Sandra", "The Beatles" };

Track::Track(bool isAuto) {
    if (isAuto) {
        name = list[getRandomIntInRange(0, (int)list.size() - 1)];
        name += " track # ";
        name += std::to_string(getRandomIntInRange(0, 100));

        createDate = getRandomDate();
        length = getRandomIntInRange(60, 60*4);
    }
    else {
        // В рамках программы не производится проверка на корректность ввода
        std::cout << "Enter track title:";
        std::getline(std::cin, name);

        std::cout << "--- Set data ---" << std::endl;
        createDate = putTimeByFormat("YYYY/mm/dd");

        // В рамках программы не производится проверка на корректность ввода
        std::cout << "Enter track length";
        std::cin >> length;
    }
}

void Track::About() {
    std::cout << "Track: " << name << std::endl;
    std::tm* local = std::localtime(&createDate);
    std::cout << "Length: " << length << " seconds" << std::endl;
    std::cout << "Created: " << std::put_time(local, "%d/%m/%Y") << std::endl;
}