#pragma once
// MESSAGE DATA96 PACKING

#define MAVLINK_MSG_ID_DATA96 172

MAVPACKED(
typedef struct __mavlink_data96_t {
 uint8_t type; /*< data type*/
 uint8_t len; /*< data length*/
 uint8_t data[96]; /*< raw data*/
}) mavlink_data96_t;

#define MAVLINK_MSG_ID_DATA96_LEN 98
#define MAVLINK_MSG_ID_DATA96_MIN_LEN 98
#define MAVLINK_MSG_ID_172_LEN 98
#define MAVLINK_MSG_ID_172_MIN_LEN 98

#define MAVLINK_MSG_ID_DATA96_CRC 22
#define MAVLINK_MSG_ID_172_CRC 22

#define MAVLINK_MSG_DATA96_FIELD_DATA_LEN 96

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DATA96 { \
	172, \
	"DATA96", \
	3, \
	{  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_data96_t, type) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_data96_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 96, 2, offsetof(mavlink_data96_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA96 { \
	"DATA96", \
	3, \
	{  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_data96_t, type) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_data96_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 96, 2, offsetof(mavlink_data96_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a data96 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type data type
 * @param len data length
 * @param data raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data96_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA96_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, len);
	_mav_put_uint8_t_array(buf, 2, data, 96);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA96_LEN);
#else
	mavlink_data96_t packet;
	packet.type = type;
	packet.len = len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*96);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA96_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA96;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
}

/**
 * @brief Pack a data96 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type data type
 * @param len data length
 * @param data raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data96_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t type,uint8_t len,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA96_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, len);
	_mav_put_uint8_t_array(buf, 2, data, 96);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA96_LEN);
#else
	mavlink_data96_t packet;
	packet.type = type;
	packet.len = len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*96);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA96_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_DATA96;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
}

/**
 * @brief Encode a data96 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data96 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data96_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data96_t* data96)
{
	return mavlink_msg_data96_pack(system_id, component_id, msg, data96->type, data96->len, data96->data);
}

/**
 * @brief Encode a data96 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data96 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data96_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data96_t* data96)
{
	return mavlink_msg_data96_pack_chan(system_id, component_id, chan, msg, data96->type, data96->len, data96->data);
}

/**
 * @brief Send a data96 message
 * @param chan MAVLink channel to send the message
 *
 * @param type data type
 * @param len data length
 * @param data raw data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data96_send(mavlink_channel_t chan, uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA96_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, len);
	_mav_put_uint8_t_array(buf, 2, data, 96);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA96, buf, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
#else
	mavlink_data96_t packet;
	packet.type = type;
	packet.len = len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*96);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA96, (const char *)&packet, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
#endif
}

/**
 * @brief Send a data96 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_data96_send_struct(mavlink_channel_t chan, const mavlink_data96_t* data96)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_data96_send(chan, data96->type, data96->len, data96->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA96, (const char *)data96, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA96_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data96_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, len);
	_mav_put_uint8_t_array(buf, 2, data, 96);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA96, buf, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
#else
	mavlink_data96_t *packet = (mavlink_data96_t *)msgbuf;
	packet->type = type;
	packet->len = len;
	mav_array_memcpy(packet->data, data, sizeof(uint8_t)*96);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA96, (const char *)packet, MAVLINK_MSG_ID_DATA96_MIN_LEN, MAVLINK_MSG_ID_DATA96_LEN, MAVLINK_MSG_ID_DATA96_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA96 UNPACKING


/**
 * @brief Get field type from data96 message
 *
 * @return data type
 */
static inline uint8_t mavlink_msg_data96_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field len from data96 message
 *
 * @return data length
 */
static inline uint8_t mavlink_msg_data96_get_len(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from data96 message
 *
 * @return raw data
 */
static inline uint16_t mavlink_msg_data96_get_data(const mavlink_message_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 96,  2);
}

/**
 * @brief Decode a data96 message into a struct
 *
 * @param msg The message to decode
 * @param data96 C-struct to decode the message contents into
 */
static inline void mavlink_msg_data96_decode(const mavlink_message_t* msg, mavlink_data96_t* data96)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	data96->type = mavlink_msg_data96_get_type(msg);
	data96->len = mavlink_msg_data96_get_len(msg);
	mavlink_msg_data96_get_data(msg, data96->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DATA96_LEN? msg->len : MAVLINK_MSG_ID_DATA96_LEN;
        memset(data96, 0, MAVLINK_MSG_ID_DATA96_LEN);
	memcpy(data96, _MAV_PAYLOAD(msg), len);
#endif
}
