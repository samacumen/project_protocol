#pragma once
// MESSAGE GPS_SET_GLOBAL_ORIGIN PACKING

#define MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN 48

MAVPACKED(
typedef struct __mavlink_gps_set_global_origin_t {
 int32_t latitude; /*< global position * 1E7*/
 int32_t longitude; /*< global position * 1E7*/
 int32_t altitude; /*< global position * 1000*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_gps_set_global_origin_t;

#define MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN 14
#define MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN 14
#define MAVLINK_MSG_ID_48_LEN 14
#define MAVLINK_MSG_ID_48_MIN_LEN 14

#define MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC 170
#define MAVLINK_MSG_ID_48_CRC 170



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS_SET_GLOBAL_ORIGIN { \
	48, \
	"GPS_SET_GLOBAL_ORIGIN", \
	5, \
	{  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_set_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_set_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_set_global_origin_t, altitude) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gps_set_global_origin_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_gps_set_global_origin_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS_SET_GLOBAL_ORIGIN { \
	"GPS_SET_GLOBAL_ORIGIN", \
	5, \
	{  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_set_global_origin_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_set_global_origin_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_gps_set_global_origin_t, altitude) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_gps_set_global_origin_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_gps_set_global_origin_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a gps_set_global_origin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param latitude global position * 1E7
 * @param longitude global position * 1E7
 * @param altitude global position * 1000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_set_global_origin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN);
#else
	mavlink_gps_set_global_origin_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Pack a gps_set_global_origin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param latitude global position * 1E7
 * @param longitude global position * 1E7
 * @param altitude global position * 1000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_set_global_origin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,int32_t latitude,int32_t longitude,int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN);
#else
	mavlink_gps_set_global_origin_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
}

/**
 * @brief Encode a gps_set_global_origin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps_set_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_set_global_origin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_set_global_origin_t* gps_set_global_origin)
{
	return mavlink_msg_gps_set_global_origin_pack(system_id, component_id, msg, gps_set_global_origin->target_system, gps_set_global_origin->target_component, gps_set_global_origin->latitude, gps_set_global_origin->longitude, gps_set_global_origin->altitude);
}

/**
 * @brief Encode a gps_set_global_origin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_set_global_origin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_set_global_origin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_set_global_origin_t* gps_set_global_origin)
{
	return mavlink_msg_gps_set_global_origin_pack_chan(system_id, component_id, chan, msg, gps_set_global_origin->target_system, gps_set_global_origin->target_component, gps_set_global_origin->latitude, gps_set_global_origin->longitude, gps_set_global_origin->altitude);
}

/**
 * @brief Send a gps_set_global_origin message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param latitude global position * 1E7
 * @param longitude global position * 1E7
 * @param altitude global position * 1000
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_set_global_origin_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN, buf, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
#else
	mavlink_gps_set_global_origin_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.target_system = target_system;
	packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN, (const char *)&packet, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
#endif
}

/**
 * @brief Send a gps_set_global_origin message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_set_global_origin_send_struct(mavlink_channel_t chan, const mavlink_gps_set_global_origin_t* gps_set_global_origin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_set_global_origin_send(chan, gps_set_global_origin->target_system, gps_set_global_origin->target_component, gps_set_global_origin->latitude, gps_set_global_origin->longitude, gps_set_global_origin->altitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN, (const char *)gps_set_global_origin, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_set_global_origin_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN, buf, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
#else
	mavlink_gps_set_global_origin_t *packet = (mavlink_gps_set_global_origin_t *)msgbuf;
	packet->latitude = latitude;
	packet->longitude = longitude;
	packet->altitude = altitude;
	packet->target_system = target_system;
	packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN, (const char *)packet, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_MIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS_SET_GLOBAL_ORIGIN UNPACKING


/**
 * @brief Get field target_system from gps_set_global_origin message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_gps_set_global_origin_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field target_component from gps_set_global_origin message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_gps_set_global_origin_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field latitude from gps_set_global_origin message
 *
 * @return global position * 1E7
 */
static inline int32_t mavlink_msg_gps_set_global_origin_get_latitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from gps_set_global_origin message
 *
 * @return global position * 1E7
 */
static inline int32_t mavlink_msg_gps_set_global_origin_get_longitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from gps_set_global_origin message
 *
 * @return global position * 1000
 */
static inline int32_t mavlink_msg_gps_set_global_origin_get_altitude(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Decode a gps_set_global_origin message into a struct
 *
 * @param msg The message to decode
 * @param gps_set_global_origin C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_set_global_origin_decode(const mavlink_message_t* msg, mavlink_gps_set_global_origin_t* gps_set_global_origin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	gps_set_global_origin->latitude = mavlink_msg_gps_set_global_origin_get_latitude(msg);
	gps_set_global_origin->longitude = mavlink_msg_gps_set_global_origin_get_longitude(msg);
	gps_set_global_origin->altitude = mavlink_msg_gps_set_global_origin_get_altitude(msg);
	gps_set_global_origin->target_system = mavlink_msg_gps_set_global_origin_get_target_system(msg);
	gps_set_global_origin->target_component = mavlink_msg_gps_set_global_origin_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN? msg->len : MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN;
        memset(gps_set_global_origin, 0, MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN_LEN);
	memcpy(gps_set_global_origin, _MAV_PAYLOAD(msg), len);
#endif
}