#include "Command.hpp"
#include "Logger.hpp"

class InitJump : public Command {
	public void execute() {
		LOG_MESSAGE("InitJump command ran");
	}
};