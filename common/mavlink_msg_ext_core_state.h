#pragma once
// MESSAGE EXT_CORE_STATE PACKING

#define MAVLINK_MSG_ID_EXT_CORE_STATE 6000


typedef struct __mavlink_ext_core_state_t {
 uint64_t usec; /*< [us] Timestamp (UNIX)*/
 float p_wi[3]; /*<  position x y z of i expressed in w (NED)*/
 float v_wi[3]; /*<  velocity vx vy vz of i expressed in w (NED)*/
 float q_wi[4]; /*<  orientation qw qx qy qz from i to w (NED) in hamiltonian convention*/
 float b_a[3]; /*<  accelerometer bias*/
 float b_w[3]; /*<  gyroscope bias*/
 float cov_urt[45]; /*<  position orientation and velocity upper triangular covariance in Row-Major order*/
} mavlink_ext_core_state_t;

#define MAVLINK_MSG_ID_EXT_CORE_STATE_LEN 252
#define MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN 252
#define MAVLINK_MSG_ID_6000_LEN 252
#define MAVLINK_MSG_ID_6000_MIN_LEN 252

#define MAVLINK_MSG_ID_EXT_CORE_STATE_CRC 225
#define MAVLINK_MSG_ID_6000_CRC 225

#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_P_WI_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_V_WI_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_Q_WI_LEN 4
#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_B_A_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_B_W_LEN 3
#define MAVLINK_MSG_EXT_CORE_STATE_FIELD_COV_URT_LEN 45

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXT_CORE_STATE { \
    6000, \
    "EXT_CORE_STATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ext_core_state_t, usec) }, \
         { "p_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_ext_core_state_t, p_wi) }, \
         { "v_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_ext_core_state_t, v_wi) }, \
         { "q_wi", NULL, MAVLINK_TYPE_FLOAT, 4, 32, offsetof(mavlink_ext_core_state_t, q_wi) }, \
         { "b_a", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_ext_core_state_t, b_a) }, \
         { "b_w", NULL, MAVLINK_TYPE_FLOAT, 3, 60, offsetof(mavlink_ext_core_state_t, b_w) }, \
         { "cov_urt", NULL, MAVLINK_TYPE_FLOAT, 45, 72, offsetof(mavlink_ext_core_state_t, cov_urt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXT_CORE_STATE { \
    "EXT_CORE_STATE", \
    7, \
    {  { "usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ext_core_state_t, usec) }, \
         { "p_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_ext_core_state_t, p_wi) }, \
         { "v_wi", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_ext_core_state_t, v_wi) }, \
         { "q_wi", NULL, MAVLINK_TYPE_FLOAT, 4, 32, offsetof(mavlink_ext_core_state_t, q_wi) }, \
         { "b_a", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_ext_core_state_t, b_a) }, \
         { "b_w", NULL, MAVLINK_TYPE_FLOAT, 3, 60, offsetof(mavlink_ext_core_state_t, b_w) }, \
         { "cov_urt", NULL, MAVLINK_TYPE_FLOAT, 45, 72, offsetof(mavlink_ext_core_state_t, cov_urt) }, \
         } \
}
#endif

/**
 * @brief Pack a ext_core_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qw qx qy qz from i to w (NED) in hamiltonian convention
 * @param b_a  accelerometer bias
 * @param b_w  gyroscope bias
 * @param cov_urt  position orientation and velocity upper triangular covariance in Row-Major order
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ext_core_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi, const float *b_a, const float *b_w, const float *cov_urt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_put_float_array(buf, 48, b_a, 3);
    _mav_put_float_array(buf, 60, b_w, 3);
    _mav_put_float_array(buf, 72, cov_urt, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN);
#else
    mavlink_ext_core_state_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
    mav_array_memcpy(packet.b_a, b_a, sizeof(float)*3);
    mav_array_memcpy(packet.b_w, b_w, sizeof(float)*3);
    mav_array_memcpy(packet.cov_urt, cov_urt, sizeof(float)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXT_CORE_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
}

/**
 * @brief Pack a ext_core_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qw qx qy qz from i to w (NED) in hamiltonian convention
 * @param b_a  accelerometer bias
 * @param b_w  gyroscope bias
 * @param cov_urt  position orientation and velocity upper triangular covariance in Row-Major order
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ext_core_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t usec,const float *p_wi,const float *v_wi,const float *q_wi,const float *b_a,const float *b_w,const float *cov_urt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_put_float_array(buf, 48, b_a, 3);
    _mav_put_float_array(buf, 60, b_w, 3);
    _mav_put_float_array(buf, 72, cov_urt, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN);
#else
    mavlink_ext_core_state_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
    mav_array_memcpy(packet.b_a, b_a, sizeof(float)*3);
    mav_array_memcpy(packet.b_w, b_w, sizeof(float)*3);
    mav_array_memcpy(packet.cov_urt, cov_urt, sizeof(float)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXT_CORE_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
}

/**
 * @brief Encode a ext_core_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ext_core_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ext_core_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ext_core_state_t* ext_core_state)
{
    return mavlink_msg_ext_core_state_pack(system_id, component_id, msg, ext_core_state->usec, ext_core_state->p_wi, ext_core_state->v_wi, ext_core_state->q_wi, ext_core_state->b_a, ext_core_state->b_w, ext_core_state->cov_urt);
}

/**
 * @brief Encode a ext_core_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ext_core_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ext_core_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ext_core_state_t* ext_core_state)
{
    return mavlink_msg_ext_core_state_pack_chan(system_id, component_id, chan, msg, ext_core_state->usec, ext_core_state->p_wi, ext_core_state->v_wi, ext_core_state->q_wi, ext_core_state->b_a, ext_core_state->b_w, ext_core_state->cov_urt);
}

/**
 * @brief Send a ext_core_state message
 * @param chan MAVLink channel to send the message
 *
 * @param usec [us] Timestamp (UNIX)
 * @param p_wi  position x y z of i expressed in w (NED)
 * @param v_wi  velocity vx vy vz of i expressed in w (NED)
 * @param q_wi  orientation qw qx qy qz from i to w (NED) in hamiltonian convention
 * @param b_a  accelerometer bias
 * @param b_w  gyroscope bias
 * @param cov_urt  position orientation and velocity upper triangular covariance in Row-Major order
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ext_core_state_send(mavlink_channel_t chan, uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi, const float *b_a, const float *b_w, const float *cov_urt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXT_CORE_STATE_LEN];
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_put_float_array(buf, 48, b_a, 3);
    _mav_put_float_array(buf, 60, b_w, 3);
    _mav_put_float_array(buf, 72, cov_urt, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE, buf, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
#else
    mavlink_ext_core_state_t packet;
    packet.usec = usec;
    mav_array_memcpy(packet.p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet.v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet.q_wi, q_wi, sizeof(float)*4);
    mav_array_memcpy(packet.b_a, b_a, sizeof(float)*3);
    mav_array_memcpy(packet.b_w, b_w, sizeof(float)*3);
    mav_array_memcpy(packet.cov_urt, cov_urt, sizeof(float)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE, (const char *)&packet, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
#endif
}

/**
 * @brief Send a ext_core_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ext_core_state_send_struct(mavlink_channel_t chan, const mavlink_ext_core_state_t* ext_core_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ext_core_state_send(chan, ext_core_state->usec, ext_core_state->p_wi, ext_core_state->v_wi, ext_core_state->q_wi, ext_core_state->b_a, ext_core_state->b_w, ext_core_state->cov_urt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE, (const char *)ext_core_state, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXT_CORE_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ext_core_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t usec, const float *p_wi, const float *v_wi, const float *q_wi, const float *b_a, const float *b_w, const float *cov_urt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, usec);
    _mav_put_float_array(buf, 8, p_wi, 3);
    _mav_put_float_array(buf, 20, v_wi, 3);
    _mav_put_float_array(buf, 32, q_wi, 4);
    _mav_put_float_array(buf, 48, b_a, 3);
    _mav_put_float_array(buf, 60, b_w, 3);
    _mav_put_float_array(buf, 72, cov_urt, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE, buf, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
#else
    mavlink_ext_core_state_t *packet = (mavlink_ext_core_state_t *)msgbuf;
    packet->usec = usec;
    mav_array_memcpy(packet->p_wi, p_wi, sizeof(float)*3);
    mav_array_memcpy(packet->v_wi, v_wi, sizeof(float)*3);
    mav_array_memcpy(packet->q_wi, q_wi, sizeof(float)*4);
    mav_array_memcpy(packet->b_a, b_a, sizeof(float)*3);
    mav_array_memcpy(packet->b_w, b_w, sizeof(float)*3);
    mav_array_memcpy(packet->cov_urt, cov_urt, sizeof(float)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXT_CORE_STATE, (const char *)packet, MAVLINK_MSG_ID_EXT_CORE_STATE_MIN_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN, MAVLINK_MSG_ID_EXT_CORE_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE EXT_CORE_STATE UNPACKING


/**
 * @brief Get field usec from ext_core_state message
 *
 * @return [us] Timestamp (UNIX)
 */
static inline uint64_t mavlink_msg_ext_core_state_get_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field p_wi from ext_core_state message
 *
 * @return  position x y z of i expressed in w (NED)
 */
static inline uint16_t mavlink_msg_ext_core_state_get_p_wi(const mavlink_message_t* msg, float *p_wi)
{
    return _MAV_RETURN_float_array(msg, p_wi, 3,  8);
}

/**
 * @brief Get field v_wi from ext_core_state message
 *
 * @return  velocity vx vy vz of i expressed in w (NED)
 */
static inline uint16_t mavlink_msg_ext_core_state_get_v_wi(const mavlink_message_t* msg, float *v_wi)
{
    return _MAV_RETURN_float_array(msg, v_wi, 3,  20);
}

/**
 * @brief Get field q_wi from ext_core_state message
 *
 * @return  orientation qw qx qy qz from i to w (NED) in hamiltonian convention
 */
static inline uint16_t mavlink_msg_ext_core_state_get_q_wi(const mavlink_message_t* msg, float *q_wi)
{
    return _MAV_RETURN_float_array(msg, q_wi, 4,  32);
}

/**
 * @brief Get field b_a from ext_core_state message
 *
 * @return  accelerometer bias
 */
static inline uint16_t mavlink_msg_ext_core_state_get_b_a(const mavlink_message_t* msg, float *b_a)
{
    return _MAV_RETURN_float_array(msg, b_a, 3,  48);
}

/**
 * @brief Get field b_w from ext_core_state message
 *
 * @return  gyroscope bias
 */
static inline uint16_t mavlink_msg_ext_core_state_get_b_w(const mavlink_message_t* msg, float *b_w)
{
    return _MAV_RETURN_float_array(msg, b_w, 3,  60);
}

/**
 * @brief Get field cov_urt from ext_core_state message
 *
 * @return  position orientation and velocity upper triangular covariance in Row-Major order
 */
static inline uint16_t mavlink_msg_ext_core_state_get_cov_urt(const mavlink_message_t* msg, float *cov_urt)
{
    return _MAV_RETURN_float_array(msg, cov_urt, 45,  72);
}

/**
 * @brief Decode a ext_core_state message into a struct
 *
 * @param msg The message to decode
 * @param ext_core_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_ext_core_state_decode(const mavlink_message_t* msg, mavlink_ext_core_state_t* ext_core_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ext_core_state->usec = mavlink_msg_ext_core_state_get_usec(msg);
    mavlink_msg_ext_core_state_get_p_wi(msg, ext_core_state->p_wi);
    mavlink_msg_ext_core_state_get_v_wi(msg, ext_core_state->v_wi);
    mavlink_msg_ext_core_state_get_q_wi(msg, ext_core_state->q_wi);
    mavlink_msg_ext_core_state_get_b_a(msg, ext_core_state->b_a);
    mavlink_msg_ext_core_state_get_b_w(msg, ext_core_state->b_w);
    mavlink_msg_ext_core_state_get_cov_urt(msg, ext_core_state->cov_urt);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXT_CORE_STATE_LEN? msg->len : MAVLINK_MSG_ID_EXT_CORE_STATE_LEN;
        memset(ext_core_state, 0, MAVLINK_MSG_ID_EXT_CORE_STATE_LEN);
    memcpy(ext_core_state, _MAV_PAYLOAD(msg), len);
#endif
}
