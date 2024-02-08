//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_TELECOM_HPP
#define INC_2024_I_AV_SW_TEENSY_TELECOM_HPP

#include "core/data/base_data_component.hpp"
#include "modifier/command_handler.hpp"

/**
 * Template interface for the Teensy's telecom connection.
 */
template<typename TelecomStatus>
class TeensyTelecomClass : public BaseDataComponent<TelecomStatus>, public CommandHandler {
public:

};


#endif //INC_2024_I_AV_SW_TEENSY_TELECOM_HPP