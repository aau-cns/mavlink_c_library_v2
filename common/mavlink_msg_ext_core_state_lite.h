#pragma once
// MESSAGE EXT_CORE_STATE_LITE PACKING

#define MAVLINK_MSG_ID_EXT_CORE_STATE_LITE 6001


typedef struct __mavlink_ext_core_state_lite_t {
 uint64_t usec; /*< [us] Timestamp (UNIX)*/
 float p_wi[3]; /*<  position x y z of i expressed in w (NED)*/
 float v_wi[3]; /*<  velocity vx vy vz of i expressed in w (NED)*/
 float q_wi[4]; /*<  orientation qx qy qz qw from i to w (NED) in hamiltonian convention*/
} mavlink_ext_core_state_lite_t;

#define MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN 48
#define MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN 48
#define MAVLINK_MSG_ID_6001_LEN 48
#define MAVLINK_MSG_ID_6001_MIN_LEN 48

#define MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC 170
#define MAVLINK_MSG_ID_6001_CRC 170

#define MAVLINK_MSG_EXT_CORE_STATE_LITE_FIELD_P_WI_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_LITE_FIELD_V_WI_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_LITE_FIELD_Q_WI_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXT_CORE_STATE_LITE { \
    6001, \
    "EXT_CORE_STATE_LITE", \
    4, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ext_core_state_lite_t, usec) }, \
         { "p_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_ext_core_state_lite_t, p_wi) }, \
         { "v_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_ext_core_state_lite_t, v_wi) }, \
         { "q_wi", NULL, MAVLINK_TYPE_FLOAT, 4, 32, offsetof(mavlink_ext_core_state_lite_t, q_wi) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXT_CORE_STATE_LITE { \
    "EXT_CORE_STATE_LITE", \
    4, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ext_core_state_lite_t, usec) }, \
         { "p_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_ext_core_state_lite_t, p_wi) }, \
         { "v_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_ext_core_state_lite_t, v_wi) }, \
         { "q_wi", NULL, MAVLINK_TYPE_FLOAT, 4, 32, offsetof(mavlink_ext_core_state_lite_t, q_wi) }, \
         } \
}
#endif

/**
 * @brief Pack a ext_core_state_lite message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qx qy qz qw from i to w (NED) in hamiltonian convention
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN);
#else
    mavlink_ext_core_state_lite_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXT_CORE_STATE_LITE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
}

/**
 * @brief Pack a ext_core_state_lite message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qx qy qz qw from i to w (NED) in hamiltonian convention
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t usec,const float *p_wi,const float *v_wi,const float *q_wi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN);
#else
    mavlink_ext_core_state_lite_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXT_CORE_STATE_LITE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
}

/**
 * @brief Encode a ext_core_state_lite struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ext_core_state_lite C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ext_core_state_lite_t* ext_core_state_lite)
{
    return mavlink_msg_ext_core_state_lite_pack(system_id, component_id, msg, ext_core_state_lite->usec, ext_core_state_lite->p_wi, ext_core_state_lite->v_wi, ext_core_state_lite->q_wi);
}

/**
 * @brief Encode a ext_core_state_lite struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ext_core_state_lite C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ext_core_state_lite_t* ext_core_state_lite)
{
    return mavlink_msg_ext_core_state_lite_pack_chan(system_id, component_id, chan, msg, ext_core_state_lite->usec, ext_core_state_lite->p_wi, ext_core_state_lite->v_wi, ext_core_state_lite->q_wi);
}

/**
 * @brief Send a ext_core_state_lite message
 * @param chan MAVLink channel to send the message
 *
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qx qy qz qw from i to w (NED) in hamiltonian convention
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ext_core_state_lite_send(mavlink_channel_t chan, uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE, buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
#else
    mavlink_ext_core_state_lite_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE, (const char *)&packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
#endif
}

/**
 * @brief Send a ext_core_state_lite message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ext_core_state_lite_send_struct(mavlink_channel_t chan, const mavlink_ext_core_state_lite_t* ext_core_state_lite)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ext_core_state_lite_send(chan, ext_core_state_lite->usec, ext_core_state_lite->p_wi, ext_core_state_lite->v_wi, ext_core_state_lite->q_wi);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE, (const char *)ext_core_state_lite, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ext_core_state_lite_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE, buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
#else
    mavlink_ext_core_state_lite_t *packet = (mavlink_ext_core_state_lite_t *)msgbuf;
    packet->usec = usec;
    mav_array_memcpy(packet->p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet->v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet->q_wi, q_wi, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE, (const char *)packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_CRC);
#endif
}
#endif

#endif

// MESSAGE EXT_CORE_STATE_LITE UNPACKING


/**
 * @brief Get field usec from ext_core_state_lite message
 *
 * @return [us] Timestamp (UNIX)
 */
static inline uint64_t mavlink_msg_ext_core_state_lite_get_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field p_wi from ext_core_state_lite message
 *
 * @return  position x y z of i expressed in w (NED)
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_get_p_wi(const mavlink_message_t* msg, float *p_wi)
{
    return _MAV_RETURN_float_array(msg, p_wi, 3,  8);
}

/**
 * @brief Get field v_wi from ext_core_state_lite message
 *
 * @return  velocity vx vy vz of i expressed in w (NED)
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_get_v_wi(const mavlink_message_t* msg, float *v_wi)
{
    return _MAV_RETURN_float_array(msg, v_wi, 3,  20);
}

/**
 * @brief Get field q_wi from ext_core_state_lite message
 *
 * @return  orientation qx qy qz qw from i to w (NED) in hamiltonian convention
 */
static inline uint16_t mavlink_msg_ext_core_state_lite_get_q_wi(const mavlink_message_t* msg, float *q_wi)
{
    return _MAV_RETURN_float_array(msg, q_wi, 4,  32);
}

/**
 * @brief Decode a ext_core_state_lite message into a struct
 *
 * @param msg The message to decode
 * @param ext_core_state_lite C-struct to decode the message contents into
 */
static inline void mavlink_msg_ext_core_state_lite_decode(const mavlink_message_t* msg, mavlink_ext_core_state_lite_t* ext_core_state_lite)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ext_core_state_lite->usec = mavlink_msg_ext_core_state_lite_get_usec(msg);
    mavlink_msg_ext_core_state_lite_get_p_wi(msg, ext_core_state_lite->p_wi);
    mavlink_msg_ext_core_state_lite_get_v_wi(msg, ext_core_state_lite->v_wi);
    mavlink_msg_ext_core_state_lite_get_q_wi(msg, ext_core_state_lite->q_wi);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN? msg->len : MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN;
        memset(ext_core_state_lite, 0, MAVLINK_MSG_ID_EXT_CORE_STATE_LITE_LEN);
    memcpy(ext_core_state_lite, _MAV_PAYLOAD(msg), len);
#endif
}
