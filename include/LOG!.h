/******************************************************************************
 * Not a header for logging
 *
 * Use with care.
 *
 * Do not declare these functions in an actual header.
 *
 *****************************************************************************/

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

#define LOGH_DEF(STATUS) \
static inline void LOGH_##STATUS(const char * message, ...) { \
    va_list argp; \
    va_start(argp, message); \
    fprintf(stderr, "[%s]: ", #STATUS); \
    vfprintf(stderr, message, argp); \
    fprintf(stderr, "\n"); \
    va_end(argp); \
}

#endif /* LOG_H */
