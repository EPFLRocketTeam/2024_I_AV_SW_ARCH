//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_DATA_HPP
#define INC_2024_I_AV_SW_RPI_DATA_HPP

#include "rpi_command.hpp"
#include "rpi_output.hpp"

struct RpiDataStruct {
	RpiCommandStatus com;
	RpiOutputStatus out;
};

class RpiDataClass {
protected:

public:
	RpiDataStruct get();

	RpiCommandClass com;
	RpiOutputClass out;
};


#endif //INC_2024_I_AV_SW_RPI_DATA_HPP
