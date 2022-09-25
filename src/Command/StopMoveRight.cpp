#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class StopMoveRight : public Command {

	public void execute() override {
		std::cout << "StopMoveRight command ran";
	}

}