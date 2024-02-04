//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_PATHS_HPP
#define INC_2024_I_AV_SW_TEENSY_PATHS_HPP

#include "teensy_control_path.hpp"
#include "teensy_data_path.hpp"

struct TeensyPathsStatus {
	TeensyControlPathStatus ctrl;
	TeensyDataPathStatus out;
};

class TeensyPathsClass {
public:
	TeensyPathsStatus get();
	void update();

	TeensyControlPathClass ctrl;
	TeensyDataPathClass out;
};

#endif //INC_2024_I_AV_SW_TEENSY_PATHS_HPP
