#include "utils.h"

std::string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", localtime(&now));
    return std::string(buffer);
}