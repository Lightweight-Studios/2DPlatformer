#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class StopMoveLeft : public Command {

public:

	StopMoveLeft() = default;

	~StopMoveLeft() = default;

	void execute() override {
		std::cout << "StopMoveLeft command ran";
	}

}