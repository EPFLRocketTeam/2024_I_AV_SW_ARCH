//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_INTRANET_HPP
#define INC_2024_I_AV_SW_BASE_INTRANET_HPP

#include "base_data_component.hpp"
#include "logger.hpp"

template<typename Status>
class BaseIntranet : BaseDataComponent<Status> {
public:
	virtual void write_to(uint8_t) {
		LOG("BaseIntranet::write > OVERRIDE ME !");
	}
};

#endif //INC_2024_I_AV_SW_BASE_INTRANET_HPP
