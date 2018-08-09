#ifndef __LOGGER____H__
#define __LOGGER____H__

typedef enum {
    N_LOG_ERROR,
    N_LOG_WARNING,
    N_LOG_DEBUG,
    N_LOG_INFO
} ocnet_loglevel_t;

#ifdef __cplusplus
extern "C" {
#endif

void    ocnet_log_init(ocnet_loglevel_t level);
int     ocnet_log_write(ocnet_loglevel_t level, char *tags,
            char *function, int line, char *fmt, ...);
void    ocnet_log_final(void);

#define LOG(level, tag, fmt, ...) \
    do {    \
        ocnet_log_write(level, tag, (char *)__FUNCTION__, \
                __LINE__, fmt, ##__VA_ARGS__); \
    } while (0)

#define LOGE(tag, fmt, ...) LOG(N_LOG_ERROR, tag, fmt, ##__VA_ARGS__)
#define LOGW(tag, fmt, ...) LOG(N_LOG_WARNING, tag, fmt, ##__VA_ARGS__)
#define LOGD(tag, fmt, ...) LOG(N_LOG_DEBUG, tag, fmt, ##__VA_ARGS__)
#define LOGI(tag, fmt, ...) LOG(N_LOG_INFO, tag, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
