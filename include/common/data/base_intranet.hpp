//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_BASE_INTRANET_HPP
#define INC_2024_I_AV_SW_BASE_INTRANET_HPP

template<typename IntranetStatus>
class BaseIntranetClass {
public:
	virtual IntranetStatus get();
	virtual void update();
};


#endif //INC_2024_I_AV_SW_BASE_INTRANET_HPP
