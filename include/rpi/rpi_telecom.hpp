//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_TELECOM_HPP
#define INC_2024_I_AV_SW_RPI_TELECOM_HPP

#include "config.hpp"
#include "modifier/command_handler.hpp"
#include "modifier/data_component.hpp"

#define TELECOM_TEMPLATE template<typename> class TelecomClass, typename TelecomStatus
#define TELECOM_WILDCARD TelecomClass, TelecomStatus

template<typename TelecomStatus>
class RpiTelecomClass : public DataComponent<TelecomStatus>, public CommandHandler {
protected:
public:

};

#endif //INC_2024_I_AV_SW_RPI_TELECOM_HPP
