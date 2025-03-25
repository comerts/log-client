#ifndef NETSET_H_
#define NETSET_H_

#define LOG_BUF_SIZE					256

typedef enum _LOG_PACK_DEGREE
{
	LOG_PACK_DEGREE_WRITE_SEND = 0x03,
}LOG_PACKET_DEGREE;

typedef enum _LOG_PACK_TYPE
{
	LOG_PACK_TYPE_ALPHA,
	LOG_PACK_TYPE_HEX,
	LOG_PACK_TYPE_DEC,
	LOG_PACK_TYPE_ALPHANUMERIC
}LOG_PACK_TYPE;

typedef struct _log_packet_t
{
	char sender;
	char degree;
	char type;
	int log_array_len;
	char log_array[LOG_BUF_SIZE];
}log_packet_t;

#endif /*NETSET_H_*/

