#include "Command.hpp"
#include "Logger.hpp"
class NullCommand : public Command {

public:
	NullCommand() = default;
	
	~NullCommand() = default;
	
	void execute() override {
		LOG_MESSAGE("NullCommandExecuted");
	};

}