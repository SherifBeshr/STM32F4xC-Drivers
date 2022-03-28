/*
 * MQTT.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Sherif
 */


#include "MQTT.h"
#include "UART_interface.h"
#include "string.h"



 u8 packetID = 1;
 u8 packet[200] = {0};
 u8 packetInd = 0;


 const char protocolName[] = "MQTT"; 
void MQTT_Connect(u8* clientID)
{
	u8 remLen = ( 12 + strlen(clientID));
	// encode packet
	packetInd = 0;
	packet[packetInd++] = 0x10;
	packet[packetInd++] = remLen;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(protocolName);
	strcpy(packet+packetInd,protocolName);
	packetInd += strlen(protocolName);

	packet[packetInd++] = 0x04;
	packet[packetInd++] = 0x02; 
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0xFF;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(clientID);
	strcpy(packet+packetInd,clientID);
	packetInd += strlen(clientID);

	// send packet
	UART_vSendString(UART_ID_1, packet, packetInd);

	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
}
void MQTT_Publish(u8* topic, u8* msg, u32 len, u8 QoS)
{
	u8 msgInd = 0;
	u8 remLen = (2 + strlen(topic) + len );
	// encode packet
	packetInd = 0;

	if(QoS > 0){
		remLen += 2;
		packet[packetInd++] = 0x32;
	}else{
		packet[packetInd++] = 0x30;
	}
	packet[packetInd++] = remLen;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	if(QoS > 0){
		packet[packetInd++] = (u8)(packetID >> 8);
		packet[packetInd++] = (u8)(packetID);
		packetID++;
	}

	for(msgInd = 0; msgInd < len; msgInd++){
		packet[packetInd++] = msg[msgInd];
	}

	// send packet
	UART_vSendString(UART_ID_1, packet, packetInd);
	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
}
void MQTT_Subscribe(u8* topic)
{
	u8 remLen = (5 + strlen(topic));
	// encode packet
	packetInd = 0;
	packet[packetInd++] = 0x82;
	packet[packetInd++] = remLen;

	packet[packetInd++] = (u8)(packetID >> 8);
	packet[packetInd++] = (u8)(packetID);
	packetID++;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	packet[packetInd++] = 0x01;
	// send packet
	UART_vSendString(UART_ID_1, packet, packetInd);
	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
}
