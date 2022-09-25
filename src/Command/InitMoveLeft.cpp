#include "Command.hpp"
#include "<string>"
#include "<iostream>"

class InitMoveLeft : public Command {
	public:

		void execute override() {
			std::cout << "InitMoveLeft command ran";
		}

};