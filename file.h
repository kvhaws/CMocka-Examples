#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include <stdbool.h>

int32_t wrapMe(const int32_t num, const char *str, const int32_t call);
bool sendCommand(int32_t num, const char *str, const int32_t call);

#endif // FILE_H