//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
#define INC_2024_I_AV_SW_TEENSY_INTRANET_HPP

#include "modifier/command_receiver.hpp"
#include "modifier/data_component.hpp"

#define INTRANET_TEMPLATE template<typename> class IntranetClass, typename IntranetStatus
#define INTRANET_WILDCARD IntranetClass, IntranetStatus

template<typename IntranetStatus>
class TeensyIntranetClass : public DataComponent<IntranetStatus>, public CommandReceiver {

};

#endif //INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
