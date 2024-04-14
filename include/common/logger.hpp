//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_LOGGER_HPP
#define INC_2024_I_AV_SW_LOGGER_HPP

#ifndef NO_IOSTREAM
#include <iostream>

#define LOG(x) std::cout << x << std::endl
#endif
#ifdef NO_IOSTREAM
#define LOG(x)
#endif

#endif //INC_2024_I_AV_SW_LOGGER_HPP
