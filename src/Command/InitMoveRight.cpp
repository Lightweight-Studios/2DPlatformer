#include "Command.hpp"
#include "Logger.hpp"

class InitMoveRight : public Command {

	public void execute() override {
		LOG_MESSAGE("InitMoveRight command ran");
	}

}