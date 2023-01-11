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

void default_assert_fail_callback()
{
	exit(1);
}

void clogger_init(CLogger* logger, const char* clogger_name)
{
	char* default_file_path = "clogger.txt";
	clogger_init_filepath(logger, clogger_name, default_file_path);
}

void clogger_init_filepath(CLogger* logger, const char* clogger_name, const char* file_path)
{
	*logger = (CLogger){ clogger_name,
						 NULL,
						 &default_assert_fail_callback,
						 (CLoggerConsoleColour){ CLOGGER_COLOUR_BLUE, CLOGGER_COLOUR_CLEAR },
						 CLOGGER_LEVEL_WARNING,
						 0,
						 CLOGGER_FILE_OPT_DEFAULT,
						 file_path };
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
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
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
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
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
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
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
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
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
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
		}
	}
}

void clogger_assert(CLogger* logger, CLoggerBool condition, const char* location, const char* message, ...)
{
	if (!condition)
	{
		va_list args;
		int written = clog_messagef(CLOGGER_LEVEL_FATAL_ASSERT, logger, location, message, args);
		va_start(args, message);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_ASSERT_BIT)
		{
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
		}

		if (logger->assert_fail_callback)
		{
			logger->assert_fail_callback();
		}
	}
}

CLoggerBool clogger_expect(CLogger* logger, CLoggerBool condition, const char* location, const char* message, ...)
{
	if (!condition)
	{
		va_list args;

		va_start(args, message);
		int written = clog_messagef(CLOGGER_LEVEL_NON_FATAL_ASSERT, logger, location, message, args);
		va_end(args);

		// Log to file
		if (logger->file_opt & CLOGGER_FILE_OPT_EXPECT_BIT)
		{
			char* fmessage = malloc(sizeof(char) * ++written);
			memset(fmessage, '\0', sizeof(char));

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

			free(fmessage);
		}
	}

	return condition;
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
