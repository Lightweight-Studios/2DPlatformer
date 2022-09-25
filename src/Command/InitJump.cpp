#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class InitJump : public Command {
	public void execute() {
		std::cout << "InitJump command ran"
	}
};