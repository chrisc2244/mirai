#include "Log.h"
#include <ctime>
#include <iostream>
#include <cstdio>

//IF DEBUG flag (in Log.h) is set to 0 (false) all of these functions do absolutely nothing

/**
* Author Jon C. 2022
*/

namespace MIR
{

	//Static members
	uint32_t Log::m_numLines = 0;
	uint32_t Log::m_numWarnings = 0;
	uint32_t Log::m_numErrors = 0;

	std::ofstream Log::m_file;

	std::vector<Log::logInfo> Log::m_Warnings;
	std::vector<Log::logInfo> Log::m_Errors;
	
	bool Log::m_Created = false;


	Log::~Log()
	{
		if(DEBUG)
			if(m_Created)
				close();
	}

	void Log::create(const char * engine_version, const char * filename) 
	{
		if (DEBUG)
		{
			
			m_numLines = 0;
			m_numWarnings = 0;
			m_numErrors = 0;
			m_file.open(filename);

			m_Created = true;

			//Log the welcome info
			writeRaw("Log for \"");
			writeRaw(engine_version);
			writeRaw("\" File: \"");
			writeRaw(filename);
			writeRaw("\"\n");
			writeInfo("Log::Log()", "Logging initialized");

		}
	}

	void Log::close()
	{
		if (DEBUG)
		{
			if(m_Created)
			{
				//Print the summary of warnings and errors 
				std::string finalMessage = "Program executed with " + std::to_string(m_Warnings.size()) + " warnings and " + std::to_string(m_Errors.size()) + " errors\n";
				writeRaw(finalMessage.c_str());

				if (m_Warnings.size() > 0)
				{
					//Warnings
					writeRaw("Warnings:\n");
					int count = 1;
					std::string line = "\t";
					for (logInfo linfo : m_Warnings)
					{
						line = "\t";
						std::string msg(linfo.logMessage);
						std::string loc(linfo.codeLocation);
						line += std::to_string(count) + ": " + msg + " @ " + loc + "\n\t\t See Log Line #: " + std::to_string(linfo.logLine) + "\n";
						writeRaw(line.c_str());
						count++;
					}
				}

				if (m_Errors.size() > 0)
				{
					//Errors
					writeRaw("Errors:\n");
					int count = 1;
					std::string line = "\t";
					for (logInfo linfo : m_Errors)
					{
						line = "\t";
						std::string msg(linfo.logMessage);
						std::string loc(linfo.codeLocation);
						line += std::to_string(count) + ": " + msg + " @ " + loc + "\n\t\t See Log Line #: " + std::to_string(linfo.logLine) + "\n";
						writeRaw(line.c_str());
						count++;
					}
				}

				m_file.close();
				m_Created = false;
			}
		}
	}

	void Log::writeRaw(const char * data)
	{
		if (DEBUG)
		{
			if (m_Created)
			{
				if (m_file.is_open())
				{
					if(PRINT)
						std::cout << data;
					m_file << data;
				}
			}
		}
	}

	void Log::writeRawln(const char * data)
	{
		if (DEBUG)
		{
			if (m_Created)
			{
				if (m_file.is_open())
				{
					if(PRINT)
						std::cout << data << std::endl;
					m_file << data << std::endl;
				}
			}
		}
	}

	void Log::write(const l_type type, const char * location, const char * message)
	{
		if (DEBUG)
		{
			std::string finalLine = "";

			//Add the current line number to the string
			finalLine += std::to_string(m_numLines) + '.';

			//Add the current time to the string
			time_t curTime;

			std::time(&curTime);

			tm curTm;

			localtime_s(&curTm, &curTime);

			curTm.tm_sec;

			std::string strhours = "";
			std::string strmins = "";
			std::string strsecs = "";

			int hours = curTm.tm_hour;
			int mins = curTm.tm_min;
			int secs = curTm.tm_sec;

			//Format hours minutes secs to [hh:mm:ss]

			if (hours <= 9)
				strhours = "0";
			if (mins <= 9)
				strmins = "0";
			if (secs <= 9)
				strsecs = "0";

			strhours += std::to_string(hours);
			strmins += std::to_string(mins);
			strsecs += std::to_string(secs);



			//Format is [hh:mm:ss] 
			finalLine += "[" + strhours + ":" + strmins + ":" + strsecs + "] ";

			logInfo info = { m_numLines, location, message };
			switch (type)
			{
			case INFO:
				finalLine += "INFO";
				break;
			case WARN:
				finalLine += "WARNING";
				m_numWarnings++;
				m_Warnings.push_back(info);
				break;
			case ERR:
				finalLine += "ERROR";
				m_numErrors++;
				m_Errors.push_back(info);
				break;
			}
			std::string l(location);
			finalLine += " @ " + l + ": ";

			std::string m(message);


			finalLine += m + "\n";


			//Increase the number lines
			m_numLines++;

			//Write the line to the log file
			writeRaw(finalLine.c_str());
		}
	}

	void Log::writeInfo(const char * location, const char * message)
	{
		if (DEBUG)
			write(INFO, location, message);
	}

	void Log::writeWarn(const char * location, const char * message)
	{
		if (DEBUG)
			write(WARN, location, message);
	}

	void Log::writeEr(const char * location, const char * message)
	{
		if (DEBUG)
			write(ERR, location, message);
	}

	// Write a formatted string to the log file
	void Log::writef(const char *fmt ...)
	{
		if (DEBUG)
		{
			char buffer[4096];
			va_list args;
			va_start(args, fmt);
			int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
			va_end(args);
			writeRaw(buffer);
		}
	}

	void Log::writefln(const char *fmt ...)
	{
		if (DEBUG)
		{
			char buffer[4096];
			va_list args;
			va_start(args, fmt);
			int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
			va_end(args);
			writeRawln(buffer);
		}
	}

	void Log::writefInfo(const char * location, const char *fmt ...)
	{
		if (DEBUG)
		{
			char buffer[4096];
			va_list args;
			va_start(args, fmt);
			int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
			va_end(args);

			write(INFO, location, buffer);
		}
	}

	void Log::writefWarn(const char * location, const char *fmt ...)
	{
		if (DEBUG)
		{
			char buffer[4096];
			va_list args;
			va_start(args, fmt);
			int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
			va_end(args);


			write(WARN, location, buffer);
		}
	}

	void Log::writefEr(const char * location, const char *fmt ...)
	{
		if (DEBUG)
		{
			char buffer[4096];
			va_list args;
			va_start(args, fmt);
			int rc = vsnprintf(buffer, sizeof(buffer), fmt, args);
			va_end(args);

			write(ERR, location, buffer);
		}
	}

}