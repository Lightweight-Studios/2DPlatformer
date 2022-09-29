#include "NullCommand.hpp"
#include "Logger.hpp"
	
void NullCommand::execute() override {
	LOG_MESSAGE("NullCommandExecuted");
};
