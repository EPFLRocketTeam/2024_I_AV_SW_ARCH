//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_PATHS_HPP
#define INC_2024_I_AV_SW_RPI_PATHS_HPP

#include "rpi_control_path.hpp"
#include "rpi_data_path.hpp"

struct RpiPathsStruct {
	RpiControlPathStatus ctrl;
	RpiDataPathStatus out;
};

class RpiPathsClass {
protected:

public:
	RpiPathsStruct get();
	void update();

	RpiControlPathClass ctrl;
	RpiDataPathClass out;
};


#endif //INC_2024_I_AV_SW_RPI_PATHS_HPP
