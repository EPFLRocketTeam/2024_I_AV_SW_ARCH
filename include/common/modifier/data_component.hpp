//
// Created by Samuel on 05/02/2024.
//

#ifndef INC_2024_I_AV_SW_DATA_COMPONENT_HPP
#define INC_2024_I_AV_SW_DATA_COMPONENT_HPP

template<typename Status>
class DataComponent {
public:
	virtual Status get();
	virtual void compute();
};


#endif //INC_2024_I_AV_SW_DATA_COMPONENT_HPP
