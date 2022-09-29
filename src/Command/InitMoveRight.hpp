#pragma once
#include "Command.hpp"

class InitMoveRight : public Command {

public:

	InitMoveRight() = default;
	~InitMoveRight() = default;
	InitMoveRight(const InitMoveRight& imr) = default;

	void execute() override;

};