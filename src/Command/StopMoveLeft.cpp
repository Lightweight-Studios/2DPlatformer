#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class StopMoveLeft : public Command {

	public void execute() override {
		std::cout << "StopMoveLeft command ran";
	}

}