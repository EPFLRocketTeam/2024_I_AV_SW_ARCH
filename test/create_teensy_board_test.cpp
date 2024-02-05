//
// Created by Samuel on 05/02/2024.
//

#include <iostream>
#include "teensy_intranet.hpp"
#include "teensy_sensors.hpp"
#include "base_teensy_board.hpp"

struct IntranetStatus {
	bool ok_intra;
	uint8_t comId;
	uint8_t comVal;
};

class Intranet : public TeensyIntranetClass<IntranetStatus> {
protected:
	bool ok_intra = true;
public:
	IntranetStatus get() override {
		return {
			.ok_intra = ok_intra,
			.comVal = comVal,
		};
	}

	void update(SystemStatus status) override {
		ok_intra = !ok_intra;
		comVal++;
	}
};

struct SensorsStatus {
	int ok_sens;
};

class Sensors : public TeensySensorsData<SensorsStatus> {
protected:
	int ok_sens = 3;
public:
	SensorsStatus get() override {
		return {
			.ok_sens = ok_sens,
		};
	}

	void update(SystemStatus status) override {
		ok_sens--;
	}

};

class Board : public BaseTeensyBoardClass<Intranet, Sensors> {
public:

	void update() override {
		SystemStatus sysStatus = sys.get();
		intra.update(sysStatus);
		sens.update(sysStatus);
	}

	void output() override {
		int i = intra.get().comVal;														// DOING THIS OTHERWISE COUT TREATS COMVAL AS A CHAR
		std::cout << "COM VAL " << i << std::endl;
	}
};

int main(){
	Board board{};
	board.output();
	std::cout << std::endl;
	board.loopOnce();
	return 0;
}