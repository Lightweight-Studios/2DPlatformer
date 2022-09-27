#include "Command.hpp"
#include "Logger.hpp"

class StopMoveRight : public Command {

public:
	StopMoveRight() = default;

	~StopMoveRight() = default;

	void execute() override {
		LOG_MESSAGE("StopMoveRight command ran");
	}

}