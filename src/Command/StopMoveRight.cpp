#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class StopMoveRight : public Command {

public:
	StopMoveRight() = default;

	~StopMoveRight() = default;

	void execute() override {
		std::cout << "StopMoveRight command ran";
	}

}