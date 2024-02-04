//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_TEENSY_DATA_HPP
#define INC_2024_I_AV_SW_TEENSY_DATA_HPP

template<typename IntranetStatus, typename SensorsStatus>
struct DataStatus {
	IntranetStatus intra;
	SensorsStatus sens;
};

template<class IntranetClass, typename IntranetStatus, class SensorsClass, typename SensorsStatus>
class TeensyDataClass {
protected:


public:
	IntranetClass intra;
	SensorsClass sens;

	DataStatus<IntranetStatus, SensorsStatus> get();
	virtual void compute();
};

#endif //INC_2024_I_AV_SW_TEENSY_DATA_HPP
