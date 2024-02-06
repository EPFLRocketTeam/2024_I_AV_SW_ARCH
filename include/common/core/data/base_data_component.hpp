//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_DATA_COMPONENT_HPP
#define INC_2024_I_AV_SW_BASE_DATA_COMPONENT_HPP

#include "core/system.hpp"
#include "logger.hpp"

template<typename Status>
class BaseDataComponent {
public:
	virtual Status get() {
		LOG("DataComponent::get > OVERRIDE ME !");
		return {};
	}

	virtual void update(SystemStatus) {
		LOG("DataComponent::update > OVERRIDE ME !");
	}
};


#endif //INC_2024_I_AV_SW_BASE_DATA_COMPONENT_HPP
