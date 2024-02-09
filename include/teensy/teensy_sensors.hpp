//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
#define INC_2024_I_AV_SW_TEENSY_SENSORS_HPP

#include "types.hpp"
#include "core/data/base_data_component.hpp"

/**
 * Template interface for the Teensy's sensors acquisition class.
 */
template<typename SensorsStatus>
class TeensySensorsClass : public virtual BaseDataComponent<SensorsStatus> {

};

#endif //INC_2024_I_AV_SW_TEENSY_SENSORS_HPP
