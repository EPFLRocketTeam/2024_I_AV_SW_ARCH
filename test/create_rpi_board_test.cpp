//
// Created by Samuel on 05/02/2024.
//

#include <iostream>
#include "rpi_intranet.hpp"
#include "rpi_telecom.hpp"
#include "base_rpi_board.hpp"

struct IntranetStatus {
	bool ok_intra;
};

class Intranet : public RpiIntranetClass<IntranetStatus> {
protected:
	bool ok_intra = true;
public:
	IntranetStatus get() override {
		return {.ok_intra = ok_intra};
	}

	void update(SystemStatus status) override {
		ok_intra = !ok_intra;
	}
};

struct TelecomStatus {
	int ok_tele;
	uint8_t comId;
	uint8_t comVal;
};

class Telecom : public RpiTelecomClass<TelecomStatus> {
protected:
	int ok_tele = 3;
public:
	TelecomStatus get() override {
		return {
			.ok_tele = ok_tele,
			.comVal = comVal,
		};
	}

	void update(SystemStatus status) override {
		ok_tele++;
		comVal++;
	}

};

class Board : public BaseRpiBoardClass<Intranet, Telecom> {
public:

	void update() override {
		SystemStatus sysStatus = sys.get();
		intra.update(sysStatus);
		tele.update(sysStatus);
	}

	void output() override {
		int i = tele.get().comVal;														// DOING THIS OTHERWISE COUT TREATS COMVAL AS A CHAR

		std::cout << intra.get().ok_intra << std::endl;
		std::cout << tele.get().ok_tele << std::endl;
		std::cout << i << std::endl;
	}
};

int main(){
	Board board{};
	board.output();
	std::cout << std::endl;
	board.loopOnce();
	return 0;
}
