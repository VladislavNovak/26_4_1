#ifndef INC_26_4_1_UTILITIES_H
#define INC_26_4_1_UTILITIES_H

#include <iostream>
#include <ctime>
#include <vector>

// Получить случайное число в диапазоне
int getRandomIntInRange(int, int);

// Конвертирует строку и возвращает объект stringstream
std::stringstream convertStringsToSS(const std::vector<std::string> &);

// Пользовательский ввод. Возвращает любое число (int), которое не менее нуля
int putInput(int min);

// Возвращает случайную дату между 1/01/1970 и настоящим моментом
std::time_t getRandomDate();

// Сбрасывает поток. Вспомогательная функция для putTime
void reloadStream();

// Пользовательский ввод для получения заданной даты. timeType - формат
time_t putTime(char timeType, time_t basisTime);

// Обёртка для putTime. Возвращает дату в соответствии с переданным форматом
time_t putTimeByFormat(const std::string &format, char delim = '/');

int selectMenuItem(const std::vector<std::string> &list);

#endif //INC_26_4_1_UTILITIES_H
