#pragma once
#include "Command.hpp"

class InitMoveRight : public Command {

public:
	InitMoveRight() = default;
	~InitMoveRight() = default;

	void execute() override;

}