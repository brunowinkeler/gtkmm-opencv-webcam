#include "utilities/date_time_utils.h"

namespace utilities
{
    std::string DateTimeUtils::dateTimeToString()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, 80, "%d-%m-%Y_%Hh%Mm%Ss", timeinfo);
        return std::string(buffer);
    }
} // namespace image_processing