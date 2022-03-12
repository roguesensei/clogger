#include "clog.h"
#include "clogger_pch.h"
#include "console.h"

void format_timestamp(char* buffer)
{
	char timestamp_buffer[10];
	time_t now = time(NULL);
	struct tm* timestamp = localtime(&now);

	strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

	strncpy(buffer, timestamp_buffer, sizeof(timestamp_buffer));
}

CLoggerInt32 clog_messagef(CLoggerLevel level, CLogger* logger, const char* location, const char* format, va_list args)
{
	CLoggerInt32 written = 0;
	char timestamp[10];
	const char separator[] = " >> ";

	format_timestamp(timestamp);

	// Timestamp
	clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_CYAN, CLOGGER_COLOUR_CLEAR },
							CLOGGER_FOREGROUND_INTENSE);
	written += printf("%s", timestamp);
	clog_reset_console_colour();

	written += printf("%s", separator);

	// Logger name
	if (logger != NULL)
	{
		clog_set_console_colour(logger->console_colour, logger->colour_flags);
		written += printf("%s", logger->name);
		clog_reset_console_colour();

		written += printf("%s", separator);
	}

	// Log level
	switch (level)
	{
	case CLOGGER_LEVEL_INFO:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_BLUE, CLOGGER_COLOUR_CLEAR },
								CLOGGER_FOREGROUND_INTENSE);
		written += printf("[INFO]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_DEBUG:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_GREEN, CLOGGER_COLOUR_CLEAR },
								CLOGGER_FOREGROUND_INTENSE);
		written += printf("[DEBUG]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_WARNING:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR },
								CLOGGER_FOREGROUND_INTENSE);
		written += printf("[WARNING]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_ERROR:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_RED, CLOGGER_COLOUR_CLEAR },
								CLOGGER_FOREGROUND_INTENSE);
		written += printf("[ERROR]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_CRITICAL:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_WHITE, CLOGGER_COLOUR_RED },
								CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
		written += printf("[CRITICAL]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_FATAL_ASSERT:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_WHITE, CLOGGER_COLOUR_RED },
								CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);

		written += printf("[ASSERT FAILED]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	case CLOGGER_LEVEL_NON_FATAL_ASSERT:
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_WHITE, CLOGGER_COLOUR_YELLOW },
								CLOGGER_FOREGROUND_INTENSE);

		written += printf("[ASSERT FAILED]");
		clog_reset_console_colour();

		written += printf("%s", separator);
		break;
	default:
		break;
	}

	// Location
	if (location)
	{
		clog_set_console_colour((CLoggerConsoleColour){ CLOGGER_COLOUR_MAGENTA, CLOGGER_COLOUR_CLEAR },
								CLOGGER_FOREGROUND_INTENSE);
		written += printf("%s", location);
		clog_reset_console_colour();

		written += printf("%s", separator);
	}

	written += vprintf(format, args);
	written += printf("\n");

	if (logger != NULL && logger->callback != NULL)
	{
		logger->callback(level, logger->name, location);
	}

	return written;
}

void clog_message(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_MESSAGE, NULL, location, message, args);

	va_end(args);
}

void clog_info(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_INFO, NULL, location, message, args);
	va_end(args);
}

void clog_debug(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_DEBUG, NULL, location, message, args);
	va_end(args);
}

void clog_warning(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_WARNING, NULL, location, message, args);
	va_end(args);
}

void clog_error(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_ERROR, NULL, location, message, args);
	va_end(args);
}

void clog_critical(const char* location, const char* message, ...)
{
	va_list args;

	va_start(args, message);
	clog_messagef(CLOGGER_LEVEL_CRITICAL, NULL, location, message, args);
	va_end(args);
}

void clog_trace(const char* function_name, const char* file_name, int line)
{
	printf("Traceback:\n\tIn function: %s >> %s:%d\n", function_name, file_name, line);
}

CLoggerBool clog_append_to_file(const char* file_path, const char* location, const char* message, ...)
{
	va_list args;

	CLoggerBool result = CLOGGER_FALSE;
	FILE* file_ptr;

	file_ptr = fopen(file_path, "a+");

	if (file_ptr != NULL)
	{
		char timestamp[10];

		format_timestamp(timestamp);

		fputs(timestamp, file_ptr);
		fputs(" >> ", file_ptr);

		if (location)
		{
			fputs(location, file_ptr);
			fputs(" >> ", file_ptr);
		}

		va_start(args, message);
		vfprintf(file_ptr, message, args);
		va_end(args);

		fputs("\n", file_ptr);

		result = CLOGGER_TRUE;

		fclose(file_ptr);
	}
	else
	{
		perror(file_path);
	}

	return result;
}

CLoggerBool clog_prepend_to_file(const char* file_path, const char* location, const char* message, ...)
{
	va_list args;

	CLoggerBool result = CLOGGER_FALSE;
	FILE* file_ptr;

	// Open a temporary file
	const char* temp_file_name = "temp";
	FILE* temp;
	temp = fopen(temp_file_name, "a+");
	if (temp != NULL)
	{
		char timestamp[10];

		format_timestamp(timestamp);

		fputs(timestamp, temp);
		fputs(" >> ", temp);

		if (location)
		{
			fputs(location, temp);
			fputs(" >> ", temp);
		}

		va_start(args, message);
		vfprintf(temp, message, args);
		va_end(args);

		fputs("\n", temp);

		// Copy original contents to temporary file, if it exists
		file_ptr = fopen(file_path, "r");
		if (file_ptr != NULL)
		{
			int c;
			while ((c = fgetc(file_ptr)) != EOF)
			{
				fputc(c, temp);
			}
			fclose(file_ptr);
		}

		file_ptr = fopen(file_path, "w+");

		// Close and re-open the file in read mode
		fclose(temp);
		temp = fopen(temp_file_name, "r");

		// Copy contents back to original file
		int c;
		while ((c = fgetc(temp)) != EOF)
		{
			fputc(c, file_ptr);
		}
		fclose(file_ptr);

		// Delete the temporary file
		fclose(temp);
		remove(temp_file_name);

		result = CLOGGER_TRUE;
	}
	else
	{
		perror(file_path);
	}

	return result;
}
