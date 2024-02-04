//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_INTRANET_HPP
#define INC_2024_I_AV_SW_RPI_INTRANET_HPP

struct RpiIntranetStatus {

};

class RpiIntranetClass {
public:
	virtual RpiIntranetStatus get();
	virtual void compute();
};


#endif //INC_2024_I_AV_SW_RPI_INTRANET_HPP
