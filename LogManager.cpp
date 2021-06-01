#include <iostream>
#include <fstream>

using namespace std;

//Design patterns
//Singletone
class LogManager
{
private:

	std::ofstream _out;

	LogManager(std::string fileName)
	{
		_out.open(fileName);
	}

	static LogManager* gCounter;

public:

	LogManager() = delete;

	static LogManager* GetInstance()
	{
		if (gCounter == nullptr)
		{
			gCounter = new LogManager("C:\\Temp\\log.txt");
		}

		return gCounter;
	}

	void AddNewLog(std::string message)
	{
		ofstream out("C:\\Temp\\log.txt");
		_out << message;
	}

	~LogManager()
	{
		if (gCounter == nullptr)
			_out.close();

		delete gCounter;
		
	}
};

LogManager* LogManager::gCounter = nullptr;

void Work(string word)
{
	LogManager* log1 = LogManager::GetInstance();
	log1->AddNewLog(word);
	LogManager* log2 = LogManager::GetInstance();
}

int main()
{
	LogManager* log1 = LogManager::GetInstance();
	log1->AddNewLog("QQ!");
	LogManager* log2 = LogManager::GetInstance();
	Work("some!");
}