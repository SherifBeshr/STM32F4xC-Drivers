/*
 * MQTT.h
 *
 *  Created on: Mar 28, 2022
 *      Author: Sherif
 */

#ifndef INC_MQTT_H_
#define INC_MQTT_H_

#include "std_types.h"


void MQTT_Connect(u8* clientID);
void MQTT_Publish(u8* topic, u8* msg, u32 len, u8 QoS);
void MQTT_Subscribe(u8* topic);


#endif /* INC_MQTT_H_ */
