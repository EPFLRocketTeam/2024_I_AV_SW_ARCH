//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_INTRANET_HPP
#define INC_2024_I_AV_SW_RPI_INTRANET_HPP

#include "core/data/base_intranet.hpp"
#include "modifier/command_handler.hpp"

/**
 * Template interface for the RPI's intranet connection.
 */
template<typename IntranetStatus>
class RpiIntranetClass : public virtual BaseIntranet<IntranetStatus>, public virtual CommandHandler {
public:

};


#endif //INC_2024_I_AV_SW_RPI_INTRANET_HPP
