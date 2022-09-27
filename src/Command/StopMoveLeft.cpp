#include "Command.hpp"
#include "Logger.hpp"

class StopMoveLeft : public Command {

public:

	StopMoveLeft() = default;

	~StopMoveLeft() = default;

	void execute() override {
		LOG_MESSAGE("StopMoveLeft command ran");
	}

}