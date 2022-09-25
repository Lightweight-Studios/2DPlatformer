#include "Command.hpp"
class NullCommand : public Command {

public:
	NullCommand() = default;
	~NullCommand() = default;
	void execute() override {};

}