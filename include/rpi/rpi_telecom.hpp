//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_TELECOM_HPP
#define INC_2024_I_AV_SW_RPI_TELECOM_HPP

#include "types.hpp"
#include "core/data/base_data_component.hpp"
#include "modifier/command_handler.hpp"

template<typename TelecomStatus>
class RpiTelecomClass : public BaseDataComponent<TelecomStatus>, public CommandHandler {

};

#endif //INC_2024_I_AV_SW_RPI_TELECOM_HPP
