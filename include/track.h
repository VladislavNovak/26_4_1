#ifndef INC_26_4_1_TRACK_H
#define INC_26_4_1_TRACK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "utilities.h"

using std::string;
using std::vector;

class Track {
    string name;
    time_t createDate;
    int length;
public:
    // ���� isAuto == true, �� ���� ����������� �������������, ��� ����������������� �����
    explicit Track(bool isAuto = false);

    // ��������� ������������ �����. �� ����� ���� - ���� ������������� ���������� � ���
    void About();
};

#endif //INC_26_4_1_TRACK_H
