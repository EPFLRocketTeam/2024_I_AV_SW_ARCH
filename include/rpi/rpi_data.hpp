//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_RPI_DATA_HPP
#define INC_2024_I_AV_SW_RPI_DATA_HPP


template<typename IntranetStatus, typename TelecomStatus>
struct DataStatus {
	IntranetStatus intra;
	TelecomStatus tele;
};

template<class IntranetClass, typename IntranetStatus, class TelecomClass, typename TelecomStatus>
class RpiDataClass {
protected:

public:
	IntranetClass intra;
	TelecomClass tele;

	DataStatus<IntranetStatus, TelecomStatus> get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_RPI_DATA_HPP
