/*********************************************************
*	copyright: 
*	fileName: main.c
*	date: 2019.3.30
*	author: Liu Guicheng
*	mail: 
*********************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

#ifndef LOG_H_
#define LOG_H_


#define NONE         "\033[m"  
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"



typedef enum
{
    ERROR = 1,
    WARN  = 2,
    INFO  = 3,
    DEBUG = 4
} LogLevel;

typedef enum 
{
	MAIN,
	DRIVER,
    PHY,
    MAC,
    RLC,
    PDCP,
    RRC,
    NAS,

} comp_name_t;

void log_info(const char* filename, int line, comp_name_t comp, LogLevel level, const char* fmt, ...) __attribute__((format(printf,5,6)));

#define LOG_ERROR(comp, format, ...) log_info(__FILE__, __LINE__, comp, ERROR, format, ## __VA_ARGS__)
#define LOG_WARN(comp, format, ...)  log_info(__FILE__, __LINE__, comp, WARN, format, ## __VA_ARGS__)
#define LOG_INFO(comp, format, ...)  log_info(__FILE__, __LINE__, comp, INFO, format, ## __VA_ARGS__)
#define LOG_DEBUG(comp, format, ...) log_info(__FILE__, __LINE__, comp, DEBUG, format, ## __VA_ARGS__)

#define _Assert_Exit_  {                       \
	exit(1);                                     \
	}



#define  _Assert_(cOND,comp, aCTION, fORMAT, ...)   \
if (!(cOND)) \
{ \
			LOG_ERROR(comp,fORMAT,##__VA_ARGS__);                \
			aCTION                         \
}   \


#define AssertFatal(cOND, comp,fORMAT, ...)          _Assert_(cOND,comp, _Assert_Exit_, fORMAT, ##__VA_ARGS__)


#endif

