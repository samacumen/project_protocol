#pragma once
// MESSAGE SCALED_PRESSURE PACKING

#define MAVLINK_MSG_ID_SCALED_PRESSURE 38

MAVPACKED(
typedef struct __mavlink_scaled_pressure_t {
 uint64_t usec; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float press_abs; /*< Absolute pressure (hectopascal)*/
 float press_diff; /*< Differential pressure 1 (hectopascal)*/
 int16_t temperature; /*< Temperature measurement (0.01 degrees celsius)*/
}) mavlink_scaled_pressure_t;

#define MAVLINK_MSG_ID_SCALED_PRESSURE_LEN 18
#define MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN 18
#define MAVLINK_MSG_ID_38_LEN 18
#define MAVLINK_MSG_ID_38_MIN_LEN 18

#define MAVLINK_MSG_ID_SCALED_PRESSURE_CRC 229
#define MAVLINK_MSG_ID_38_CRC 229



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SCALED_PRESSURE { \
	38, \
	"SCALED_PRESSURE", \
	4, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_scaled_pressure_t, usec) }, \
         { "press_abs", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_scaled_pressure_t, press_abs) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_scaled_pressure_t, press_diff) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_scaled_pressure_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SCALED_PRESSURE { \
	"SCALED_PRESSURE", \
	4, \
	{  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_scaled_pressure_t, usec) }, \
         { "press_abs", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_scaled_pressure_t, press_abs) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_scaled_pressure_t, press_diff) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_scaled_pressure_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a scaled_pressure message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t usec, float press_abs, float press_diff, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SCALED_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, press_abs);
	_mav_put_float(buf, 12, press_diff);
	_mav_put_int16_t(buf, 16, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN);
#else
	mavlink_scaled_pressure_t packet;
	packet.usec = usec;
	packet.press_abs = press_abs;
	packet.press_diff = press_diff;
	packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
}

/**
 * @brief Pack a scaled_pressure message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_scaled_pressure_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t usec,float press_abs,float press_diff,int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SCALED_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, press_abs);
	_mav_put_float(buf, 12, press_diff);
	_mav_put_int16_t(buf, 16, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN);
#else
	mavlink_scaled_pressure_t packet;
	packet.usec = usec;
	packet.press_abs = press_abs;
	packet.press_diff = press_diff;
	packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SCALED_PRESSURE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
}

/**
 * @brief Encode a scaled_pressure struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param scaled_pressure C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_pressure_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_scaled_pressure_t* scaled_pressure)
{
	return mavlink_msg_scaled_pressure_pack(system_id, component_id, msg, scaled_pressure->usec, scaled_pressure->press_abs, scaled_pressure->press_diff, scaled_pressure->temperature);
}

/**
 * @brief Encode a scaled_pressure struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param scaled_pressure C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_scaled_pressure_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_scaled_pressure_t* scaled_pressure)
{
	return mavlink_msg_scaled_pressure_pack_chan(system_id, component_id, chan, msg, scaled_pressure->usec, scaled_pressure->press_abs, scaled_pressure->press_diff, scaled_pressure->temperature);
}

/**
 * @brief Send a scaled_pressure message
 * @param chan MAVLink channel to send the message
 *
 * @param usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param press_abs Absolute pressure (hectopascal)
 * @param press_diff Differential pressure 1 (hectopascal)
 * @param temperature Temperature measurement (0.01 degrees celsius)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_scaled_pressure_send(mavlink_channel_t chan, uint64_t usec, float press_abs, float press_diff, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SCALED_PRESSURE_LEN];
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, press_abs);
	_mav_put_float(buf, 12, press_diff);
	_mav_put_int16_t(buf, 16, temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SCALED_PRESSURE, buf, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
#else
	mavlink_scaled_pressure_t packet;
	packet.usec = usec;
	packet.press_abs = press_abs;
	packet.press_diff = press_diff;
	packet.temperature = temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SCALED_PRESSURE, (const char *)&packet, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
#endif
}

/**
 * @brief Send a scaled_pressure message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_scaled_pressure_send_struct(mavlink_channel_t chan, const mavlink_scaled_pressure_t* scaled_pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_scaled_pressure_send(chan, scaled_pressure->usec, scaled_pressure->press_abs, scaled_pressure->press_diff, scaled_pressure->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SCALED_PRESSURE, (const char *)scaled_pressure, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SCALED_PRESSURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_scaled_pressure_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, float press_abs, float press_diff, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, usec);
	_mav_put_float(buf, 8, press_abs);
	_mav_put_float(buf, 12, press_diff);
	_mav_put_int16_t(buf, 16, temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SCALED_PRESSURE, buf, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
#else
	mavlink_scaled_pressure_t *packet = (mavlink_scaled_pressure_t *)msgbuf;
	packet->usec = usec;
	packet->press_abs = press_abs;
	packet->press_diff = press_diff;
	packet->temperature = temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SCALED_PRESSURE, (const char *)packet, MAVLINK_MSG_ID_SCALED_PRESSURE_MIN_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN, MAVLINK_MSG_ID_SCALED_PRESSURE_CRC);
#endif
}
#endif

#endif

// MESSAGE SCALED_PRESSURE UNPACKING


/**
 * @brief Get field usec from scaled_pressure message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_scaled_pressure_get_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field press_abs from scaled_pressure message
 *
 * @return Absolute pressure (hectopascal)
 */
static inline float mavlink_msg_scaled_pressure_get_press_abs(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field press_diff from scaled_pressure message
 *
 * @return Differential pressure 1 (hectopascal)
 */
static inline float mavlink_msg_scaled_pressure_get_press_diff(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field temperature from scaled_pressure message
 *
 * @return Temperature measurement (0.01 degrees celsius)
 */
static inline int16_t mavlink_msg_scaled_pressure_get_temperature(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Decode a scaled_pressure message into a struct
 *
 * @param msg The message to decode
 * @param scaled_pressure C-struct to decode the message contents into
 */
static inline void mavlink_msg_scaled_pressure_decode(const mavlink_message_t* msg, mavlink_scaled_pressure_t* scaled_pressure)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	scaled_pressure->usec = mavlink_msg_scaled_pressure_get_usec(msg);
	scaled_pressure->press_abs = mavlink_msg_scaled_pressure_get_press_abs(msg);
	scaled_pressure->press_diff = mavlink_msg_scaled_pressure_get_press_diff(msg);
	scaled_pressure->temperature = mavlink_msg_scaled_pressure_get_temperature(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SCALED_PRESSURE_LEN? msg->len : MAVLINK_MSG_ID_SCALED_PRESSURE_LEN;
        memset(scaled_pressure, 0, MAVLINK_MSG_ID_SCALED_PRESSURE_LEN);
	memcpy(scaled_pressure, _MAV_PAYLOAD(msg), len);
#endif
}
