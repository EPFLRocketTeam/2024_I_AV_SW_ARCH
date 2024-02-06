//
// Created by Samuel on 06/02/2024.
//

#include "rpi_intranet.hpp"
#include "base_rpi_board.hpp"

struct IntranetStatus {
	bool ok_intra;
	CommandID comId;
	uint8_t comVal;
};

class Intranet : public RpiIntranetClass<IntranetStatus> {
protected:
	bool ok_intra = true;
public:
	IntranetStatus get() override {
		return {
				.ok_intra = ok_intra,
				.comId = comId,
				.comVal = comVal,
		};
	}

	void update(SystemStatus status) override {
		ok_intra = !ok_intra;
	}

	void write_to(uint8_t board) override {
		std::cout << "Writing to: " << (int) board << std::endl;
	}
};

class Board : public BaseRpiBoardClass<Intranet> {
public:
	void update() override {
		SystemStatus sysStatus = sys.get();
		intra.update(sysStatus);
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