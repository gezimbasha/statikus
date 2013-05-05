#include <string>
#include <stdio.h>
#include <time.h>

// Globalet
const std::string PROG_VERSIONI = "0.01";
const std::string PROG_STATUSI = "Alpha Testing";
const std::string currentDateTime();
std::string TITULLI = currentDateTime() + " "+PROG_STATUSI+" - Statikus v "+PROG_VERSIONI;

// Kodi i marre nga TrungTN ne www.stackoverflow.com
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct, &now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}