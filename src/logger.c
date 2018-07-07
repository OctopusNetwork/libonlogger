#include <stdarg.h>
#include <stdio.h>

#include "logger.h"

static ocnet_loglevel_t     g_level = N_LOG_ERROR;

void ocnet_log_init(ocnet_loglevel_t level)
{
    g_level = level;
}

int ocnet_log_write(ocnet_loglevel_t level, char *tags,
        char *function, int line, char *fmt, ...)
{
    va_list args;
    char log_str[4096];

    va_start(args, fmt);
    vsnprintf(log_str, sizeof(log_str), fmt, args);
    va_end(args);

    fprintf(stdout, "%s\n", log_str);

    return 0;
}

void ocnet_log_final(void)
{
}
