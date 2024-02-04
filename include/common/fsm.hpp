//
// Created by Samuel on 04/02/2024.
//

#ifndef INC_2024_I_AV_SW_FSM_HPP
#define INC_2024_I_AV_SW_FSM_HPP

enum FSMState {
	INIT_STATE,				// DEFAULT STATE (boot), rudimentary checks are performed here.
	CALIBRATION_STATE,		// Mission Calibration, Guidance Trajectory loaded here, Sensors calibrated here, Control Parameters loaded here.
	ARMED_STATE,			// Hopper is armed.
	PRESSURIZE_STATE,		// Tanks are pressurized.
	FLIGHTREADY_STATE,		// Hopper is mission-ready.
	IGNITE_STATE,			// Ignition order is sent, short timer for igniter.
	IGNITION_STATE,			// Ignition sequence here (igniter status TBD by HY-A). Hyperion has the Helm.
	ASCENT_STATE,			// Position reference. Controller has the helm.
	HOVERING_STATE,			// Position reference. Controller has the helm.
	DESCENT_STATE,			// Vel reference. Controller has the helm.
	TOUCHDOWN_STATE,		// Engine is cut off (the Hopper drops to the ground).
	ABORT_STATE,			// MISSION ABORTED
};

#endif //INC_2024_I_AV_SW_FSM_HPP
