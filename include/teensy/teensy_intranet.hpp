//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
#define INC_2024_I_AV_SW_TEENSY_INTRANET_HPP

#include "core/data/base_intranet.hpp"

/**
 * Template interface for the Teensy's intranet connection.
 */
template<typename IntranetStatus>
class TeensyIntranetClass : public virtual BaseIntranet<IntranetStatus> {
public:

};


#endif //INC_2024_I_AV_SW_TEENSY_INTRANET_HPP
