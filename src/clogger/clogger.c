#include "clogger.h"
#include "clog.h"
#include "clog_assert.h"
#include "clogger_pch.h"

CLoggerUInt8 clear_flags(CLoggerUInt8 bits, CLoggerUInt8 flags)
{
	bits &= ~flags;

	return bits;
}

CLoggerUInt8 set_flags(CLoggerUInt8 bits, CLoggerUInt8 flags)
{
	bits |= flags;

	return bits;
}

void clogger_init(CLogger* logger, const char* clogger_name)
{
	*logger = (CLogger){};
	char* default_file_path = "clogger.txt";

	logger->name = clogger_name;
	logger->callback = NULL;
	logger->console_colour = (CLoggerConsoleColour){ CLOGGER_COLOUR_BLUE, CLOGGER_COLOUR_CLEAR };
	logger->log_level = CLOGGER_LEVEL_WARNING;
	logger->colour_flags = 0;
	logger->file_opt = CLOGGER_FILE_OPT_DEFAULT;
	logger->log_file_path = calloc(strlen(default_file_path) + 1, sizeof(char));

	memset(logger->log_file_path, 0, sizeof(char));
	strncpy(logger->log_file_path, default_file_path, strlen(default_file_path));
}

void clogger_info(CLogger* logger, const char* location, const char* message, ...)
{
	if (logger->log_level <= CLOGGER_LEVEL_INFO)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_INFO, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_INFO_BIT)
		{
			char fmessage[++written];

			va_start(args, message);
			vsnprintf(fmessage, sizeof(fmessage), message, args);
			va_end(args);

			if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
			{
				clog_prepend_to_file(logger->log_file_path, location, "%s >> [INFO] >> %s", logger->name, fmessage);
			}
			else
			{
				clog_append_to_file(logger->log_file_path, location, "%s >> [INFO] >> %s", logger->name, fmessage);
			}
		}
	}
}

void clogger_debug(CLogger* logger, const char* location, const char* message, ...)
{
	if (logger->log_level <= CLOGGER_LEVEL_DEBUG)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_DEBUG, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_DEBUG_BIT)
		{
			char fmessage[++written];

			va_start(args, message);
			vsnprintf(fmessage, sizeof(fmessage), message, args);
			va_end(args);

			if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
			{
				clog_prepend_to_file(logger->log_file_path, location, "%s >> [DEBUG] >> %s", logger->name, fmessage);
			}
			else
			{
				clog_append_to_file(logger->log_file_path, location, "%s >> [DEBUG] >> %s", logger->name, fmessage);
			}
		}
	}
}

void clogger_warning(CLogger* logger, const char* location, const char* message, ...)
{
	if (logger->log_level <= CLOGGER_LEVEL_WARNING)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_WARNING, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_WARNING_BIT)
		{
			char fmessage[++written];

			va_start(args, message);
			vsnprintf(fmessage, sizeof(fmessage), message, args);
			va_end(args);

			if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
			{
				clog_prepend_to_file(logger->log_file_path, location, "%s >> [WARNING] >> %s", logger->name, fmessage);
			}
			else
			{
				clog_append_to_file(logger->log_file_path, location, "%s >> [WARNING] >> %s", logger->name, fmessage);
			}
		}
	}
}

void clogger_error(CLogger* logger, const char* location, const char* message, ...)
{
	if (logger->log_level <= CLOGGER_LEVEL_ERROR)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_ERROR, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_ERROR_BIT)
		{
			char fmessage[++written];

			va_start(args, message);
			vsnprintf(fmessage, sizeof(fmessage), message, args);
			va_end(args);

			if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
			{
				clog_prepend_to_file(logger->log_file_path, location, "%s >> [ERROR] >> %s", logger->name, fmessage);
			}
			else
			{
				clog_append_to_file(logger->log_file_path, location, "%s >> [ERROR] >> %s", logger->name, fmessage);
			}
		}
	}
}

void clogger_critical(CLogger* logger, const char* location, const char* message, ...)
{
	if (logger->log_level <= CLOGGER_LEVEL_CRITICAL)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_CRITICAL, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_CRITICAL_BIT)
		{
			char fmessage[++written];

			va_start(args, message);
			vsnprintf(fmessage, sizeof(fmessage), message, args);
			va_end(args);

			if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
			{
				clog_prepend_to_file(logger->log_file_path, location, "%s >> [CRITICAL] >> %s", logger->name, fmessage);
			}
			else
			{
				clog_append_to_file(logger->log_file_path, location, "%s >> [CRITICAL] >> %s", logger->name, fmessage);
			}
		}
	}
}

void clogger_set_file_opt_option(CLogger* logger, CLoggerFileOpt option, CLoggerBool enabled)
{
	if (enabled)
	{
		logger->file_opt = set_flags(logger->file_opt, option);
	}
	else
	{
		logger->file_opt = clear_flags(logger->file_opt, option);
	}
}

void clogger_set_file_opt_path(CLogger* logger, const char* path)
{
	void* result = realloc(logger->log_file_path, (strlen(path) * sizeof(char) + sizeof(char)));
	clog_assert(result != NULL, __FUNCTION__, "Could not set the file path to %s because the realloc() failed", path);

	strncpy(logger->log_file_path, path, strlen(logger->log_file_path));
}
