//
// Created by Samuel on 05/02/2024.
//

#include "modifier/data_component.hpp"
#include "logger.hpp"

template <typename Status>
Status DataComponent<Status>::get() {
	LOG("DataComponent::get > OVERRIDE ME !");
	return {};
}

template <typename Status>
void DataComponent<Status>::compute() {
	LOG("DataComponent::compute > OVERRIDE ME !");
}
