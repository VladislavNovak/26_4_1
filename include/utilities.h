#ifndef INC_26_4_1_UTILITIES_H
#define INC_26_4_1_UTILITIES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <limits>
#include <ctime>
#include <vector>

// �������� ��������� ����� � ���������
int getRandomIntInRange(int, int);

// ������������ ������ � ���������� ������ stringstream
std::stringstream convertStringsToSS(const std::vector<std::string> &);

// ���������������� ����. ���������� ����� ����� (int), ������� �� ����� ����
int putInput(int min);

// ���������� ��������� ���� ����� 1/01/1970 � ��������� ��������
std::time_t getRandomDate();

// ���������� �����. ��������������� ������� ��� putTime
void reloadStream();

// ���������������� ���� ��� ��������� �������� ����. timeType - ������
time_t putTime(char timeType, time_t basisTime);

// ������ ��� putTime. ���������� ���� � ������������ � ���������� ��������
time_t putTimeByFormat(const std::string &format, char delim = '/');

int selectMenuItem(const std::vector<std::string> &list);

#endif //INC_26_4_1_UTILITIES_H
