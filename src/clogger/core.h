//! @file
//! @brief Common types and macros used in the library

#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

	typedef int8_t CLoggerInt8;
	typedef int16_t CLoggerInt16;
	typedef int32_t CLoggerInt32;
	typedef int64_t CLoggerInt64;
	typedef uint8_t CLoggerUInt8;
	typedef uint16_t CLoggerUInt16;
	typedef uint32_t CLoggerUInt32;
	typedef uint64_t CLoggerUInt64;
	typedef CLoggerUInt8 CLoggerBool;

#define CLOGGER_TRUE (CLoggerBool)1
#define CLOGGER_FALSE (CLoggerBool)0

	/// @brief Enum representing the log message level
	typedef enum CLoggerLevel
	{
		CLOGGER_LEVEL_MESSAGE,		   ///< Standard level, not of particular interest
		CLOGGER_LEVEL_INFO,			   ///< `INFO` level
		CLOGGER_LEVEL_DEBUG,		   ///< `DEBUG` level
		CLOGGER_LEVEL_WARNING,		   ///< `WARNING` level
		CLOGGER_LEVEL_ERROR,		   ///< `ERROR` level
		CLOGGER_LEVEL_CRITICAL,		   ///< `CRITICAL` level
		CLOGGER_LEVEL_FATAL_ASSERT,	   ///< A failed assertion that should abort the program
		CLOGGER_LEVEL_NON_FATAL_ASSERT ///< A failed assertion that should keep calm and carry on
	} CLoggerLevel;

	/// @brief Enum representing colours
	typedef enum CLoggerColour
	{
		CLOGGER_COLOUR_CLEAR,
		CLOGGER_COLOUR_BLACK,
		CLOGGER_COLOUR_RED,
		CLOGGER_COLOUR_GREEN,
		CLOGGER_COLOUR_YELLOW,
		CLOGGER_COLOUR_BLUE,
		CLOGGER_COLOUR_MAGENTA,
		CLOGGER_COLOUR_CYAN,
		CLOGGER_COLOUR_WHITE
	} CLoggerColour;

	/// @brief Data structure representing a pair of colours used for text in the terminal/console
	typedef struct CLoggerConsoleColour
	{
		CLoggerColour foreground_colour; ///< Colour of the text
		CLoggerColour background_colour; ///< Colour of the text highlight
	} CLoggerConsoleColour;

	/// @brief US English variant of CLoggerColour
	typedef CLoggerColour CLoggerColor;

	/// @brief US English variant of CLoggerConsoleColour
	typedef CLoggerConsoleColour CLoggerConsoleColor;

#define CLOGGER_COLOR_CLEAR CLOGGER_COLOUR_CLEAR
#define CLOGGER_COLOR_BLACK CLOGGER_COLOUR_BLACK
#define CLOGGER_COLOR_RED CLOGGER_COLOUR_RED
#define CLOGGER_COLOR_GREEN CLOGGER_COLOUR_GREEN
#define CLOGGER_COLOR_YELLOW CLOGGER_COLOUR_YELLOW
#define CLOGGER_COLOR_BLUE CLOGGER_COLOUR_BLUE
#define CLOGGER_COLOR_MAGENTA CLOGGER_COLOUR_MAGENTA
#define CLOGGER_COLOR_CYAN CLOGGER_COLOUR_CYAN
#define CLOGGER_COLOR_WHITE CLOGGER_COLOUR_WHITE

	/// @brief Data structure representing a `clogger`
	/// @details This struct is what allows you to configure multiple "logging" instances, with a configurable name,
	/// colour, level etc.
	typedef struct CLogger
	{
		const char* name; ///< Name of the `clogger`, such as the project name or module
		void (*error_callback)(
			CLoggerLevel level, const char* clogger_name,
			const char* location);		///< Function pointer that calls on an `ERROR` or `CRITICAL` level message
		void (*assert_fail_callback)(); ///< Function pointer that calls on an assert failure (default set to invoke
										///< `exit()`)
		CLoggerConsoleColour console_colour; ///< Colour dictating how the name should display in the console
		CLoggerLevel log_level;				 ///< The minimum level to log messages
		CLoggerUInt16 colour_flags;			 ///< Flags to modify the colour
		CLoggerUInt8 file_opt;				 ///< Flags to determine the file logging options
		const char* log_file_path;			 ///< File log path
	} CLogger;

#ifdef __cplusplus
}
#endif

#endif // CLOGGER_CORE_H
