#pragma once
// MESSAGE SET_ROLL_PITCH_YAW_THRUST PACKING

#define MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST 55

MAVPACKED(
typedef struct __mavlink_set_roll_pitch_yaw_thrust_t {
 float roll; /*< Desired roll angle in radians*/
 float pitch; /*< Desired pitch angle in radians*/
 float yaw; /*< Desired yaw angle in radians*/
 float thrust; /*< Collective thrust, normalized to 0 .. 1*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
}) mavlink_set_roll_pitch_yaw_thrust_t;

#define MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN 18
#define MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN 18
#define MAVLINK_MSG_ID_55_LEN 18
#define MAVLINK_MSG_ID_55_MIN_LEN 18

#define MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC 100
#define MAVLINK_MSG_ID_55_CRC 100



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_ROLL_PITCH_YAW_THRUST { \
	55, \
	"SET_ROLL_PITCH_YAW_THRUST", \
	6, \
	{  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, yaw) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, thrust) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, target_component) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_ROLL_PITCH_YAW_THRUST { \
	"SET_ROLL_PITCH_YAW_THRUST", \
	6, \
	{  { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, yaw) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, thrust) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_set_roll_pitch_yaw_thrust_t, target_component) }, \
         } \
}
#endif

/**
 * @brief Pack a set_roll_pitch_yaw_thrust message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param roll Desired roll angle in radians
 * @param pitch Desired pitch angle in radians
 * @param yaw Desired yaw angle in radians
 * @param thrust Collective thrust, normalized to 0 .. 1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_roll_pitch_yaw_thrust_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, float roll, float pitch, float yaw, float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, thrust);
	_mav_put_uint8_t(buf, 16, target_system);
	_mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN);
#else
	mavlink_set_roll_pitch_yaw_thrust_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.thrust = thrust;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
}

/**
 * @brief Pack a set_roll_pitch_yaw_thrust message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param roll Desired roll angle in radians
 * @param pitch Desired pitch angle in radians
 * @param yaw Desired yaw angle in radians
 * @param thrust Collective thrust, normalized to 0 .. 1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_roll_pitch_yaw_thrust_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,float roll,float pitch,float yaw,float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, thrust);
	_mav_put_uint8_t(buf, 16, target_system);
	_mav_put_uint8_t(buf, 17, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN);
#else
	mavlink_set_roll_pitch_yaw_thrust_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.thrust = thrust;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
}

/**
 * @brief Encode a set_roll_pitch_yaw_thrust struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_roll_pitch_yaw_thrust C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_roll_pitch_yaw_thrust_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_roll_pitch_yaw_thrust_t* set_roll_pitch_yaw_thrust)
{
	return mavlink_msg_set_roll_pitch_yaw_thrust_pack(system_id, component_id, msg, set_roll_pitch_yaw_thrust->target_system, set_roll_pitch_yaw_thrust->target_component, set_roll_pitch_yaw_thrust->roll, set_roll_pitch_yaw_thrust->pitch, set_roll_pitch_yaw_thrust->yaw, set_roll_pitch_yaw_thrust->thrust);
}

/**
 * @brief Encode a set_roll_pitch_yaw_thrust struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_roll_pitch_yaw_thrust C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_roll_pitch_yaw_thrust_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_roll_pitch_yaw_thrust_t* set_roll_pitch_yaw_thrust)
{
	return mavlink_msg_set_roll_pitch_yaw_thrust_pack_chan(system_id, component_id, chan, msg, set_roll_pitch_yaw_thrust->target_system, set_roll_pitch_yaw_thrust->target_component, set_roll_pitch_yaw_thrust->roll, set_roll_pitch_yaw_thrust->pitch, set_roll_pitch_yaw_thrust->yaw, set_roll_pitch_yaw_thrust->thrust);
}

/**
 * @brief Send a set_roll_pitch_yaw_thrust message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param roll Desired roll angle in radians
 * @param pitch Desired pitch angle in radians
 * @param yaw Desired yaw angle in radians
 * @param thrust Collective thrust, normalized to 0 .. 1
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_roll_pitch_yaw_thrust_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, float roll, float pitch, float yaw, float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN];
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, thrust);
	_mav_put_uint8_t(buf, 16, target_system);
	_mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST, buf, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
#else
	mavlink_set_roll_pitch_yaw_thrust_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.thrust = thrust;
	packet.target_system = target_system;
	packet.target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST, (const char *)&packet, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
#endif
}

/**
 * @brief Send a set_roll_pitch_yaw_thrust message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_roll_pitch_yaw_thrust_send_struct(mavlink_channel_t chan, const mavlink_set_roll_pitch_yaw_thrust_t* set_roll_pitch_yaw_thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_roll_pitch_yaw_thrust_send(chan, set_roll_pitch_yaw_thrust->target_system, set_roll_pitch_yaw_thrust->target_component, set_roll_pitch_yaw_thrust->roll, set_roll_pitch_yaw_thrust->pitch, set_roll_pitch_yaw_thrust->yaw, set_roll_pitch_yaw_thrust->thrust);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST, (const char *)set_roll_pitch_yaw_thrust, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_roll_pitch_yaw_thrust_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, float roll, float pitch, float yaw, float thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, roll);
	_mav_put_float(buf, 4, pitch);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, thrust);
	_mav_put_uint8_t(buf, 16, target_system);
	_mav_put_uint8_t(buf, 17, target_component);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST, buf, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
#else
	mavlink_set_roll_pitch_yaw_thrust_t *packet = (mavlink_set_roll_pitch_yaw_thrust_t *)msgbuf;
	packet->roll = roll;
	packet->pitch = pitch;
	packet->yaw = yaw;
	packet->thrust = thrust;
	packet->target_system = target_system;
	packet->target_component = target_component;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST, (const char *)packet, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_MIN_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_ROLL_PITCH_YAW_THRUST UNPACKING


/**
 * @brief Get field target_system from set_roll_pitch_yaw_thrust message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_set_roll_pitch_yaw_thrust_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field target_component from set_roll_pitch_yaw_thrust message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_set_roll_pitch_yaw_thrust_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field roll from set_roll_pitch_yaw_thrust message
 *
 * @return Desired roll angle in radians
 */
static inline float mavlink_msg_set_roll_pitch_yaw_thrust_get_roll(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pitch from set_roll_pitch_yaw_thrust message
 *
 * @return Desired pitch angle in radians
 */
static inline float mavlink_msg_set_roll_pitch_yaw_thrust_get_pitch(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw from set_roll_pitch_yaw_thrust message
 *
 * @return Desired yaw angle in radians
 */
static inline float mavlink_msg_set_roll_pitch_yaw_thrust_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field thrust from set_roll_pitch_yaw_thrust message
 *
 * @return Collective thrust, normalized to 0 .. 1
 */
static inline float mavlink_msg_set_roll_pitch_yaw_thrust_get_thrust(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a set_roll_pitch_yaw_thrust message into a struct
 *
 * @param msg The message to decode
 * @param set_roll_pitch_yaw_thrust C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_roll_pitch_yaw_thrust_decode(const mavlink_message_t* msg, mavlink_set_roll_pitch_yaw_thrust_t* set_roll_pitch_yaw_thrust)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	set_roll_pitch_yaw_thrust->roll = mavlink_msg_set_roll_pitch_yaw_thrust_get_roll(msg);
	set_roll_pitch_yaw_thrust->pitch = mavlink_msg_set_roll_pitch_yaw_thrust_get_pitch(msg);
	set_roll_pitch_yaw_thrust->yaw = mavlink_msg_set_roll_pitch_yaw_thrust_get_yaw(msg);
	set_roll_pitch_yaw_thrust->thrust = mavlink_msg_set_roll_pitch_yaw_thrust_get_thrust(msg);
	set_roll_pitch_yaw_thrust->target_system = mavlink_msg_set_roll_pitch_yaw_thrust_get_target_system(msg);
	set_roll_pitch_yaw_thrust->target_component = mavlink_msg_set_roll_pitch_yaw_thrust_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN? msg->len : MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN;
        memset(set_roll_pitch_yaw_thrust, 0, MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST_LEN);
	memcpy(set_roll_pitch_yaw_thrust, _MAV_PAYLOAD(msg), len);
#endif
}
