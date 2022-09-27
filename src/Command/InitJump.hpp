#pragma once
#include "Command.hpp"

class InitJump : public Command {
	
public:
	InitJump() = default;
	~InitJump() = default;

	void execute() override;

}