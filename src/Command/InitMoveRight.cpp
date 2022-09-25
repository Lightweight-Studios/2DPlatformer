#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class InitMoveRight : public Command {

	public void execute() override {
		std::cout << "InitMoveRight command ran";
	}

}