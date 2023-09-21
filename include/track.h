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
    // Если isAuto == true, то трек формируется автоматически, без пользовательского ввода
    explicit Track(bool isAuto = false);

    // Имитирует проигрывание трека. На самом деле - лишь распечатывает информацию о нем
    void About();
};

#endif //INC_26_4_1_TRACK_H
