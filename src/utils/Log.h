#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <cstdarg>

/**
* Author Jon C. 2022
*/


// Poorly designed Static Class that I should probably rewrite (Oh well): Don't forget to call Log::Create BEFORE using! You silly goose
namespace MIR
{
	constexpr bool DEBUG = 1; // Flag to enable or disable all of log function ( if 0, Data still gets created if Log functions are used, but the methods themselves do nothing)
	constexpr bool PRINT = 1; // Flag to enable or disable printing to console, file writing still works when disabled

	//Static class Logs information supplied (errors, warnings, dbg) etc...
	class Log
	{
	public:

		//Constructor ?? nah static member fields so call Log::Create() instead

		//Destructor
		~Log();

		//The type of data to be logged (Information = 0, Warning = 1, or Error Message = 2)
		enum l_type { INFO = 0, WARN = 1, ERR = 2 };

		//Creates the file
		static void create(const char* engine_version = "1.0", const char* filename = "jc-log-util.txt");

		//Finalizes the log, cleans and closes the file (Prints error list... etc...)
		static void close();

		//Writes a raw character string to the log
		static void writeRaw(const char* data);

		//Writes a raw character string to the log adds a new line
		static void writeRawln(const char* data);

		//Now for a SHITLOAD of wrapper methods with slightly different functionality to suit whatever needs I may have (FEATURE CREEP BEGINS!)

		//Logs some info...
		static void write(const l_type type, const char* location, const char* message);

		//logs an info flagged msg (Wraps the write method for ease of use)
		static void writeInfo(const char *location, const char *message);

		//logs a warning (Wraps the write method for ease of use)
		static void writeWarn(const char *location, const char *message);

		//logs an error (Wraps the write method for ease of use)
		static void writeEr(const char *location, const char *message);

		//Variadic print function that works like printf but also writes the string to the log file
		static void writef(const char* fmt...);

		//Variadic print function that works like printf but also writes the string to the log file starts a new line
		static void writefln(const char *fmt ...);

		//Variadic print function that works like printf but also writes the string to the log file for debug info
		static void writefInfo(const char* location, const char* fmt...);

		//Variadic print function that works like printf but also writes the string to the log file for warnings
		static void writefWarn(const char* location, const char* fmt...);

		//Variadic print function that works like printf but also writes the string to the log file for errors
		static void writefEr(const char* location, const char* fmt...);
	
		static inline std::ofstream& get() { return m_file; }

	private:

		//Whether or not the log has been created
		static bool m_Created;
		//The file stream
		static std::ofstream m_file;
		//Number or warnings logged
		static uint32_t m_numWarnings;
		//Number of errors logged
		static uint32_t m_numErrors;
		//Number of lines written
		static uint32_t m_numLines;

		//Contains the logged info .... duh xD
		struct logInfo
		{
			//The line of the log file that has the message
			uint32_t logLine;

			//The supplied location in code 
			std::string codeLocation;
			//const char* codeLocation; // I'm leaving this here to remind me not to be dumb

			//The message
			std::string logMessage;
			//const char* logMessage; // I'm leaving this here to remind me not to be dumb
		};


		static std::vector<logInfo> m_Warnings;
		static std::vector<logInfo> m_Errors;
	};
}

