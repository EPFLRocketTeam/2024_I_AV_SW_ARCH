//
// Created by Samuel on 05/02/2024.
//

#include "teensy_intranet.hpp"
#include "teensy_sensors.hpp"
#include "teensy_telecom.hpp"
#include "base_teensy_board.hpp"

struct IntranetStatus {
	bool ok_intra;
};

class Intranet : public TeensyIntranetClass<IntranetStatus> {
protected:
	bool ok_intra = true;
public:
	IntranetStatus get() override {
		return {
			.ok_intra = ok_intra,
		};
	}

	void update(SystemStatus status) override {
		ok_intra = !ok_intra;
	}

	void write_to(uint8_t board) override {
		std::cout << "Writing to: " << (int)board << std::endl;
	}
};

struct SensorsStatus {
	int ok_sens;
};

class Sensors : public TeensySensorsClass<SensorsStatus> {
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

struct TelecomStatus{
	char ok_tele;
	CommandID comId;
	uint8_t comVal;
};

class Telecom : public TeensyTelecomClass<TelecomStatus> {
protected:
	char ok_tele = 'A';
public:
	TelecomStatus get() override {
		return {
				.ok_tele = ok_tele,
				.comId = comId,
				.comVal = comVal,
		};
	}

	void update(SystemStatus status) override {
		ok_tele = 'B';
	}

};

class Board : public BaseTeensyBoardClass<Intranet, Telecom, Sensors> {
public:
	void update() override {
		SystemStatus systemStatus = sys.get();
		intra.update(systemStatus);
		tele.update(systemStatus);
		sens.update(systemStatus);
	}

	void output() override {
		intra.write_to(0);
	}
};

int main(){
	Board board{};
	board.init();
	board.loopOnce();
	return 0;
}