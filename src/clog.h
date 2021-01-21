#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

void clog_message(const char* location, const char* message);
void clog_debug(const char* location, const char* format, ...);

#endif //CLOGGER_CLOG_H
