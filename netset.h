#ifndef NETSET_H_
#define NETSET_H_

#ifndef DSP_DRV_INCLUDE
#include <netinet/in.h>
#endif // DSP_DRV_INCLUDE

#define MAX_BUF_LEN_NET 				256
#define	CONF_BUF_SIZE					256
#define NETPORT							28666
//#define LOCALADDR						"127.0.0.1"
#define FTOK_PATH						"/home/workspace"
#define LOG_BUF_SIZE					256
#define USER_INFO_SIZE					60
#define MAX_ACCESS_INFO					10
#define RTPP_NOTIF_REASON_SIZE			20
#define MAX_MAIL_ADDR_SIZE				64
#define MAX_FILENAME_LEN				80 // donot increase -> may cause mess queue overflow
#define MAX_EMAIL_ADDRESS_LEN			60
#define MAX_EMAIL_LIST_CHECK_CNT		10
#define CONFIG_BUNDLE_NOTIF_STR_SIZE	20
#define CONFIG_BUNDLE_MAX_PATH_SIZE		100
#define MAX_USB_ERROR_MSG_SIZE			100
#define MAX_USB_FILE_SYSTEM_NAME_SIZE	20
#define MAX_USB_MOUNT_PATH_SIZE			100
#define MAX_USB_DEVICE_PATH				20
#define MAX_MIDEA_SLOT_NO				8
#define MAX_ANALOG_SUBSCRIBER_COUNT		( ( MAX_MIDEA_SLOT_NO ) * 2 )
#define MAX_ANALOG_TRUNK_COUNT			( ( MAX_MIDEA_SLOT_NO ) * 2 )

//typedef unsigned int UINT;
//typedef unsigned char UCHAR;

#ifndef DSP_DRV_INCLUDE

typedef enum{
	SYS_NET = 1,
	IP_SIM = 2,
	WEB_EV = 3,
	GODFATHER = 4,
	MSSIP_MSG = 5,
	LOGGER_MSG = 6,
	CONSOLE_MSG = 7,
	TIMER_MSG = 8,
	SERIAL_MSG = 9,
	SOUND_RECORD_MANAGER_MSG = 10,
	MS_MASTER = 11,
	MS_BACKUP_UTIL_MSG_ADDR = 12,
	VUGB_MSG_ADDR,
	NO_PROCESS
}messAddress; 

typedef enum _INDICATION_COMMAND
{
	MASTER_IP_CHANGE,
	AC_GREETS_CP,
	RTP_PORT_CHANGE,
	AC_IP_CHANGE,
	CODEC_STR_CHANGE,
	UPDATE_MASTER_KEY,
	RESET_MASTER_KEY
}INDICATION_COMMAND;

typedef enum {
	NCS_LICENSE_TYPE_NA = 0x00,
	NCS_LICENSE_TYPE_CM,
	NCS_LICENSE_TYPE_WCM,
	NCS_LICENSE_TYPE_NO_LICENSE
}NCS_LICENSE_TYPE_E;

typedef enum _WEB_SERVER_MSG
{
	IP_SRC_ADDR_CHANGED 	= 0x10,
	MGW_IP_CHANGED			= 0x20,
	MTR_VERSION				= 0x30,
	LOG_QUERRY				= 0x40,
	MC_UPDATE_OK			= 0x50,
	MGW_PORT_CHANGED		= 0x60,
	RTP_PROXY_QUERY			= 0x61,
	SIPTPC_IP_CHANGED		= 0x70,
	TELNETD_QUERRY			= 0x71,
	REFRESH_REGISTER_TAB	= 0x72,
	NCS_LICENSE_OK			= 0x73,
	NCS_LICENSE_FAIL		= 0x74,
	WEB_LANG_CHANGE			= 0x75,
	USER_INFO_QUERRY		= 0x76,
	KARELPORT_ACCESS_CHANGE	= 0x77,
	PROTOCOL_CHANGE			= 0x78,
	SSH_QUERRY				= 0x79
}WEB_SERVER_MSG;


typedef enum
{
	DHCP_SUCCESS, 			/* 00 */
	DHCP_FAIL,				/* 01 */
	WEB_CHANGE,				/* 02 */
	MASTER_CHANGE,			/* 03 */
	RTP_PORTS,				/* 04 */
	CODEC_CHANGE,			/* 05 */
	RTP_CHANGE,				/* 06 */
	UPDATE_MASTER,			/* 07 */
	LOGING_CHANGE,			/* 08 */
	UPDATE_ALL,				/* 09 */
	MGW_COMMAND,			/* 10-0x0a */
	RESET_MASTER,			/* 11-0x0b */
	FXNT_CHANGED,			/* 12-0x0c */
	MGW_IP_CHANGE,			/* 13-0x0d */
	MGW_PORT_CHANGE,		/* 14-0x0e */
	WEB_CHANGE_2,			/* 15-0x0f */
	UPDATE_TELNETD,			/* 16-0x10 */							/* conflict IP_SRC_ADDR_CHANGED */
	UPDATE_TELNETD_PORT,	/* 17-0x11 */
	NCS_LICENSE,			/* 18-0x12 */
	NCS_LICENSE_QUERRY,		/* 19-0x13 */
	LEAST_MEMORY_MODE,		/* 20-0x14 */
	USER_INFO_CHANGE,		/* 21-0x15 */
	UPDATE_SSH,				/* 22-0x16 */
	UPDATE_LOG2FILE,		/* 23-0x17 */
	LOG2FILE_QUERRY,		/* 24-0x18 */
	VOIP_LICENSE_QUERRY,	/* 25-0x19 */
	VOIP_LICENSE_EVENT,		/* 26-0x1a */
	PSEUDO_LICENSE_ACTIVATE_EVENT,		/* 27-0x1b */
	SEND_MAIL_REQ,						/* 28-0x1c */
	DSP_LOG_ACTIVATION_EVENT,			/* 29-0x1d */
	DSP_LOG_QUERRY,						/* 30-0x1e */
	DHCP6_SUCCESS,						/* 31-0x1f */
	SOUND_SERVER_CHANGE,				/* 32-0x20 */				/* conflict MGW_IP_CHANGED */
	SOUND_SERVER_QUERY,					/* 33-0x21 */
	COPY_FILE_TO_SERVER_COMMAND,		/* 34-0x22 */
	CONVERT_FILE_REMOVE_ORIGINAL_COMMAND,			/* 35-0x23 */
	UPDATE_RTP_PROXY,								/* 36-0x24 */
	COPY_FILE_TO_SERVER_EMAIL_COMMAND,				/* 37-0x25 */
	COPY_FILE_TO_SERVER_MAKE_COPY_COMMAND,			/* 38-0x26 */
	COPY_FILE_TO_SERVER_EMAIL_MAKE_COPY_COMMAND,	/* 39-0x27 */
	CONVERT_FILE_MAKE_COPY2SERVER_COMMAND,			/* 40-0x28 */
	CONVERT_FILE_MAKE_COPY2SERVER_EMAIL_COMMAND,	/* 41-0x29 */
	CONVERT_FILE_EMAIL_COMMAND,						/* 42-0x2a */
	MAIL_SERVER_CHANGE,								/* 43-0x2b */
	MAIL_INFO_QUERY,								/* 44-0x2c */
	MAIL_FILE_COMMAND,								/* 45-0x2d */
	LOADER_SERVICE_CHANGE_EVENT,					/* 46-0x2e */
	FS_SERVER_CHANGE_EVENT,							/* 47-0x2f */
	FS_SERVER_STATUS_QUERY,							/* 48-0x30 */	/* conflict MTR_VERSION */
	SUBS_MAIL_MODIFIED,								/* 49-0x31 */
	CONVERT_FILE_MOVE_COMMAND,						/* 50-0x32 */
	CONVERT_FILE_FANCY_EMAIL_COMMAND,				/* 51-0x33 */
	COPY_FILE_TO_SERVER_FANCY_EMAIL_COMMAND,		/* 52-0x34 */
	CONF_CHANGE_EVENT,								/* 53-0x35 */
	WEB_LANGUAGE_UPDATE,							/* 54-0x36 */
	MAIL_EVENT,										/* 55-0x37 */
	FAX_TYPE_CHANGE,								/* 56-0x38 */
	MASTER_FS_IP_INFO,								/* 57-0x39 */
	PLAY_RECORD_CONF_CHANGE_EVENT,					/* 58-0x3a */
	MERGE_COPIED_FILES,								/* 59-0x3b */
	MERGE_COPIED_FILES_MANUAL_SK,					/* 60-0x3c */
	LOAD_CONFIG_BUNDLE_STATUS,						/* 61-0x3d */
	SYS_FACTORY_SETTINGS_FROM_WEB,					/* 62-0x3e */
	COPY_FILE_TO_SERVER_RESULT,						/* 63-0x3f */
	HW_VERSION_INFO,								/* 64-0x40 */	/* conflict LOG_QUERRY */
	USB_MSG,										/* 65-0x41 */
	SOUND_RECORD_LOCATION_CHANGE_EVENT,				/* 66-0x42 */
	MASTER_LOG_CHANGE_EVENT,						/* 67-0x43 */
	REFRESH_NKS_CONNECTION,							/* 68-0x44 */
	RING_GAIN_SETTINGS_MSG,							/* 69-0x45 */
#if 0
	SUBSCRIBER_GAIN_SETTINGS,						/* 69-0x45 */
	SUBSCRIBER_GAIN_SETTINGS_QUERY,					/* 70-0x46 */
	TRUNK_GAIN_SETTINGS,							/* 71-0x47 */
	TRUNK_GAIN_SETTINGS_QUERY,						/* 72-0x48 */
	RING_DETECTION_SETTINGS,						/* 73-0x49 */
	RING_DETECTION_SETTINGS_QUERY,					/* 74-0x4a */
#endif
	WEB_SERVER_MSG_DO_NOT_USE_MC_UPDATE_OK				= 0x50,
	WEB_SERVER_MSG_DO_NOT_USE_MGW_PORT_CHANGED			= 0x60,
	WEB_SERVER_MSG_DO_NOT_USE_RTP_PROXY_QUERY			= 0x61,
	WEB_SERVER_MSG_DO_NOT_USE_SIPTPC_IP_CHANGED			= 0x70,
	WEB_SERVER_MSG_DO_NOT_USE_TELNETD_QUERRY			= 0x71,
	WEB_SERVER_MSG_DO_NOT_USE_REFRESH_REGISTER_TAB		= 0x72,
	WEB_SERVER_MSG_DO_NOT_USE_NCS_LICENSE_OK			= 0x73,
	WEB_SERVER_MSG_DO_NOT_USE_NCS_LICENSE_FAIL			= 0x74,
	WEB_SERVER_MSG_DO_NOT_USE_WEB_LANG_CHANGE			= 0x75,
	WEB_SERVER_MSG_DO_NOT_USE_USER_INFO_QUERRY			= 0x76,
	WEB_SERVER_MSG_DO_NOT_USE_KARELPORT_ACCESS_CHANGE	= 0x77,
	WEB_SERVER_MSG_DO_NOT_USE_PROTOCOL_CHANGE			= 0x78,
	WEB_SERVER_MSG_DO_NOT_USE_SSH_QUERRY				= 0x79,


	UGB_MESSAGE											= 0x7A,

	/*
	mipsel is Little Endian,
	x86 is Little Endian,
	NET_EVENT-TRUNK_GAIN_SETTINGS => 0x47 0x00 0x00 0x00
	Silly design-
	some uses first byte of array, some uses NET_EVENT, first byte value is same with NET_EVENT value ( event < 0x100 )
	So do not use any NET_EVENT value conflicting with WEB_SERVER_MSG_DO_NOT_USE_XXX
	*/
	WEB_MESSAGES_ABOVE_HERE = 0x100, /* since messages sent to web can only be byte, put those above, others below! */
	MASTER_LOG_DUMP,
	MGW_DSP_INIT_DONE,
	MGW_EXTERNAL_FRAME_SOURCE_RESET,
	SAVE_PERSISTENT_MEMORY,
	SAVE_PERSISTENT_MEMORY_DONE,
	MAIL_SERVER_SECURITY_CHANGE,
	MAIL_SEND_RATE_SETTING,
}NET_EVENT;

typedef enum{
	E_UGB_MESSAGE_ACTIVATION_KEY,
	E_UGB_MESSAGE_ACTIVATION_KEY_SET,
	E_UGB_MESSAGE_SERIAL_NO,
	E_UGB_MESSAGE_LICENSE_INFO,
	E_UGB_MESSAGE_CERTIFICATE_UPLOADED,
	E_UGB_MESSAGE_REFRESH_INFO,
	E_UGB_MESSAGE_UGB_AND_LICENSES_INFO,
	E_UGB_MESSAGE_UGB_AND_LICENSES_INFO_SET,
}E_UGB_MESSAGE;

enum{ UGB_ACTIVATION_KEY_STR_SIZE = 33 };
enum{ UGB_SERIAL_NO_STR_SIZE = 17 };
enum{ UGB_UUID_STR_SIZE = 37 };

enum{
	UGB_PRODUCT_NO_SIP_SUBSCRIBER = 4,
	UGB_PRODUCT_NO_KAREL_SIP_SUBSCRIBER = 15,
	UGB_PRODUCT_NO_WEBCM_NETCM = 1
};

enum{
	UGB_IPF40_SIP_SUBSCRIBER_FLAG = 5,
	UGB_IPF40_KAREL_SIP_SUBSCRIBER_FLAG = 4,
	UGB_IPF40_NETCM_FLAG = 0,
	UGB_IPF40_WEBCM_FLAG = 1,
};

#pragma pack(push, 1) /* structures are byte aligned */

typedef union {
	NET_EVENT eEvent;
	uint8_t nEvent;
}msgq_event_t;

typedef struct{
	union {
		NET_EVENT eEvent;
		uint8_t nEvent;
	}event;
	E_UGB_MESSAGE message;
	messAddress eMessageAddress;
}ugbMsgHeader_t;

typedef struct{
	ugbMsgHeader_t header;
	uint8_t nProductNo;
}ugbLicenseQuery_t;

typedef struct{
	ugbMsgHeader_t header;
	uint8_t nProductNo;
	char szActivationKey[ UGB_ACTIVATION_KEY_STR_SIZE ];
}ugbActivationKey_t;

typedef struct{
	ugbMsgHeader_t header;
	char szSerialNo[ UGB_SERIAL_NO_STR_SIZE ];
}ugbSerialNo_t;

typedef struct {
	unsigned short reserved_data;
	unsigned short license_expire_time;
	unsigned short license_count;
	unsigned char expired;
	unsigned char flag;
	unsigned char activation;
} ugb_license_info_duplicate_t;

typedef struct{
	char szActivationKey[ UGB_ACTIVATION_KEY_STR_SIZE ];
	uint8_t nProductNo;
	ugb_license_info_duplicate_t ugb_license_info;
}ugbLicenseInfo_t;

typedef struct{
	ugbMsgHeader_t header;
	ugbLicenseInfo_t ugbLicenseInfo;
}ugbLicenseInfoPack_t;

enum { UGB_LICENSES_ARRAY_SIZE = 3 };

typedef struct{
	ugbMsgHeader_t header;
	int nVersion;
	char szSerialNo[ UGB_SERIAL_NO_STR_SIZE ];
	char szUUID[ UGB_UUID_STR_SIZE ];
	ugbLicenseInfo_t aUgbLicenseInfo[ UGB_LICENSES_ARRAY_SIZE ];
}ugbAllLicensesInfo_t;

#pragma pack(pop)

typedef struct
{
	NET_EVENT event;
	unsigned int nLogLevel;
}masterLogLevel_t;

typedef enum
{
	E_SOUND_RECORD_LOCATION_PC,
	E_SOUND_RECORD_LOCATION_USB
}E_SOUND_RECORD_LOCATION;

typedef struct
{
	NET_EVENT event;
	E_SOUND_RECORD_LOCATION eLocation;
}soundRecordLocation_t;

typedef enum{
	E_USB_MSG_INFO_REQUEST,
	E_USB_MSG_INFO,
	E_USB_MSG_FORMAT_REQUEST,
	E_USB_MSG_MOUNT_REQUEST,
	E_USB_MSG_UMOUNT_REQUEST,
	E_USB_MSG_EXTENDED_INFO,
}E_USB_MSG;

typedef enum
{
	E_USB_REQUEST_STATUS_SUCCESS,
	E_USB_REQUEST_STATUS_FAILURE,
}E_USB_REQUEST_STATUS;

typedef struct
{
	NET_EVENT event;
	E_USB_MSG usb_message;
}usbRequest_t;

typedef struct
{
	unsigned char event;
	E_USB_MSG usb_message;
	E_USB_REQUEST_STATUS status;
	char szErrorMsg[ MAX_USB_ERROR_MSG_SIZE ];
}usbResponse_t;

typedef enum{
	E_USB_PHYSICAL_STATUS_UNPLUGGED,
	E_USB_PHYSICAL_STATUS_PLUGGED
}E_USB_PHYSICAL_STATUS;

typedef enum{
	E_USB_MOUNT_NOT_MOUNTED,
	E_USB_MOUNT_MOUNTED,
}E_USB_MOUNT_STATUS;

typedef struct{
	unsigned char usb_status;
	unsigned char mount_status;
	unsigned char used_percentage;
	unsigned int size_in_kb_high;
	unsigned int size_in_kb_low;
	char szFileSystem[ MAX_USB_FILE_SYSTEM_NAME_SIZE ];
	char szMountPath[ MAX_USB_MOUNT_PATH_SIZE ];
}usbInfo_t;

typedef struct{
	usbInfo_t usbInfo;
	char szDevicePath[ MAX_USB_DEVICE_PATH ];
}usbExtendedInfo_t;

typedef struct{
	unsigned char event;
	E_USB_MSG usb_message;
	usbInfo_t usbInfo;
}usbInfoMessage_t;

typedef struct{
	NET_EVENT event;
	E_USB_MSG usb_message;
	usbExtendedInfo_t usbExtendedInfo;
}usbExtendedInfoMessage_t;

typedef enum
{
	ACG_UPDATE_CHANNELS,
	ACG_CREATE_CONNECTION,
	ACG_CHANNEL_INFO_DELETE,
	ACG_PLAY_TONE,
	ACG_ACTIVATE_RTP,
	ACG_DEACTIVATE_RTP,
	ACG_INIT_DEVICE_PARAMS,
	ACG_INITIALIZE_DSP,
	ACG_OPEN_CHANNEL,
	ACG_CLOSE_CHANNEL,
	ACG_DEBUG_INFO_ACTIVATION,
	ACG_GET_DEFAULT_CHANNEL_PARAMS,
	ACG_START_T38,
	ACG_STOP_T38,
	ACG_UPDATE_CHANNELS_EACH,
	ACG_RESET_BUFFER_DES,
	ACG_DEBUG_INFORMATION_ACTIVATION_ALL,
	ACG_TDM_PLAYBACK_START,
	ACG_TDM_PLAYBACK_STOP,
	ACG_TDM_RECORD_START,
	ACG_TDM_RECORD_STOP,
	ACG_TDM_PLAYBACK_VOICE,
	ACG_RESET_SERIAL_PORT,
	ACG_GET_REGULAR_RTCP_PARAMS,
	ACG_RESET_DSP_DEVICES
}ACG_COMMANDS;

typedef enum
{
	E_MIDEA_PORT_TYPE_EMPTY,
	E_MIDEA_PORT_TYPE_SUBSCRIBER,
	E_MIDEA_PORT_TYPE_TRUNK
}E_MIDEA_PORT_TYPE;

typedef struct
{
	E_MIDEA_PORT_TYPE type;
	int port_no_1;
	int port_no_2;
}mideaSlotInfo_t;

typedef struct{
	mideaSlotInfo_t slots[ MAX_MIDEA_SLOT_NO ];
}mideaConfigurationInfo_t;

typedef struct 
{
	NET_EVENT event;
	int master_iptype;
	char master_ipaddr[20];
	char master_subnet[20];
}MASTER_CHANGE_ARRAY_STCT;

typedef struct 
{
	NET_EVENT event;
	char codecStr[20];
}CODEC_CHANGE_ARRAY_STCT;

typedef struct 
{
	NET_EVENT event;
	char ipaddr[20];
	char router_ip[20];
	char dns_ip1[20];
	char dns_ip2[20];
	char subnetmask[20];
}DHCP_ARRAY_STCT;

typedef struct
{
	NET_EVENT event;
	char ipaddr[60];
	char dns_ip1[20];
	char dns_ip2[20];
}DHCP6_ARRAY_STCT;

typedef struct 
{
	NET_EVENT event;
	char rtp_portStart[6];
	/*
	char rtp_port0[6];
	char rtp_port1[6];
	char rtp_port2[6];
	char rtp_port3[6];
	*/
}RTP_PORT_CHANGE_STCT;

typedef struct _logingChangedPacket
{
	NET_EVENT event;
	char logEnabled;
#ifdef IPV6
	char logAddr[50];
#else
	in_addr_t logAddr;
#endif
#ifdef MGW3_OR_VRC200
	unsigned char bLog2MasterEnabled;
#endif
	//UINT port;
}logingChangedPacket;

#define MAX_DOMAIN_NAME_LEN	64

typedef struct _soundServerInfo_t
{
	NET_EVENT event;
	char ip[64];
	char userName[30];
	char password[16];
	char id[5];
	char szMACAddr[18];
	int bMacVerificationEnabled;
	char szDoaminName[ MAX_DOMAIN_NAME_LEN ];
	int bDomainNameEnabled;
}soundServerInfo_t;

typedef struct _mailServerInfo_t
{
	NET_EVENT event;
	char hostName[80];
	char mailAddress[MAX_EMAIL_ADDRESS_LEN];
	char port[8];
	char userName[60];
	char password[16];
	unsigned char utf8Enabled;
}mailServerInfo_t;

typedef struct
{
	NET_EVENT event;
	char mailServerFingerprint[60];
	int bTLSCertCheckEnabled;
}mailServerSecurityInfo_t;

typedef struct _copyFile2ServerCmd_t
{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
}copyFile2ServerCmd_t;

typedef struct _converFileCmd_t
{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
}converFileCmd_t;

typedef struct _copyFile2ServerEmailCmd_t
{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}copyFile2ServerEmailCmd_t;

typedef struct _convertMakeCopyCmd_t{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
	char pseudoFileName[MAX_FILENAME_LEN];
}convertMakeCopyCmd_t;

typedef struct _converFileEmailCmd_t
{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}converFileEmailCmd_t;

typedef struct _mergeFileCmd_t
{
	NET_EVENT event;
	unsigned int lastPartNo;
	char fileName[MAX_FILENAME_LEN];
}mergeFileCmd_t;

typedef struct _mergeFileManualSKCmd_t
{
	NET_EVENT event;
	unsigned int lastPartNo;
	char fileName[MAX_FILENAME_LEN];
	char pseudoFileName[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}mergeFileManualSKCmd_t;

typedef enum _MAIL_TYPE{
	MAIL_TYPE_NA =		0x00,
	MAIL_TYPE_SM,
	MAIL_TYPE_SK,
	MAIL_TYPE_RESOURCE_NOK,
	MAIL_TYPE_GENERIC,
	MAIL_TYPE_GENERIC_ATTACH_FILE,
	MAIL_TYPE_GENERIC_ATTACH_FILE_DYNAMIC,
	MAIL_TYPE_USB_FREE_SPACE_UNDER_THRESHOLD,
	MAIL_TYPE_USB_FREE_SPACE_NO_SPACE,
	MAIL_TYPE_USB_NOK,
}MAIL_TYPE;

typedef struct _convertMakeCopyEmailCmd_t{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
	char pseudoFileName[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}convertMakeCopyEmailCmd_t;

typedef struct _convertFileFancyEmailCmd_t{
	NET_EVENT event;
	unsigned char mailType;
	char fileName[MAX_FILENAME_LEN];
	char pseudoFileName[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}convertFileFancyEmailCmd_t;

typedef struct _copyFile2ServerFancyEmailCmd_t
{
	copyFile2ServerEmailCmd_t cmd;
	unsigned char mailType;
}copyFile2ServerFancyEmailCmd_t;

typedef struct _mailFileCmd_t{
	NET_EVENT event;
	char fileName[MAX_FILENAME_LEN];
	char fileName2[MAX_FILENAME_LEN];
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
	unsigned char remove;
	unsigned int ticks;
	unsigned char retryCnt;
	unsigned char mailType;
}mailFileCmd_t;

typedef struct _mailInfoCmd_t{
	NET_EVENT event;
	MAIL_TYPE mailType;
	char emailAddr[MAX_EMAIL_ADDRESS_LEN];
}mailInfoCmd_t;

typedef struct _sendMailCmd_t{
	mailInfoCmd_t cmd;
	char subject[40];
	char body[120];
}sendMailCmd_t;

typedef struct _sendAttachedMailCmd_t{
	mailInfoCmd_t cmd;
	char subject[40];
	char body[60];
	char fileName[60];
	unsigned char removeFile;
}sendAttachedMailCmd_t;

typedef struct _sendAttachedMailFlexCmd_t{
	NET_EVENT event;
	MAIL_TYPE mailType;
	char mailText[230];
	unsigned char removeFile;
}sendAttachedMailFlexCmd_t;

typedef enum
{
	E_MAIL_SEND_RATE_NORMAL,
	E_MAIL_SEND_RATE_SLOW,
	E_MAIL_SEND_RATE_PAUSE,
}E_MAIL_SEND_RATE;

typedef struct
{
	NET_EVENT event;
	E_MAIL_SEND_RATE emailSendRate;
}mailSendRateSetting_t;

typedef enum
{
	E_COPY_FILE_TO_SERVER_FAILED,
	E_COPY_FILE_TO_SERVER_OK
}E_COPY_FILE_TO_SERVER_RESULT;

typedef struct _copyFileToServerResult_t
{
	NET_EVENT event;
	E_COPY_FILE_TO_SERVER_RESULT result;
	char fileName[MAX_FILENAME_LEN];
}copyFileToServerResult_t;

typedef enum _FS_SERVER_STATUS{
	FS_SERVER_STATUS_NA,
	FS_SERVER_STATUS_TRYING,
	FS_SERVER_STATUS_OFFLINE,
	FS_SERVER_STATUS_ONLINE = 0x01,
	FS_SERVER_STATUS_MTR_NA = 0x10,
	FS_SERVER_STATUS_MTR_ONLINE,
	FS_SERVER_STATUS_MTR_TRYING,
	FS_SERVER_STATUS_MTR_OFFLINE,

	FS_SERVER_STATUS_USB_NA = 0x20,
	FS_SERVER_STATUS_USB_NOT_MOUNTED_OR_UNPLUGGED,
	FS_SERVER_STATUS_USB_OK,
	FS_SERVER_STATUS_USB_UNDER_THRESHOLD,
	FS_SERVER_STATUS_USB_NO_SPACE,

	FS_SERVER_STATUS_X_NA = 0x30,
}FS_SERVER_STATUS;

typedef struct _masterFsIpPack_t{
	NET_EVENT event;
	char ipAddr[50];
	unsigned short port;
}masterFsIpPack_t;

typedef struct _fsServerChange_t{
	NET_EVENT event;
	FS_SERVER_STATUS status;
}fsServerChange_t;

typedef struct _userInfoChangePack_t
{
	NET_EVENT event;
	char userInfo[USER_INFO_SIZE];
}userInfoChangePack_t;

typedef struct _mgwCommandPacket
{
	NET_EVENT event;
	ACG_COMMANDS command;
	int 	argc;
	char 	args[7][25];
}mgwCommandPacket;

typedef struct _mcMasterChangePacket
{
	char macAddr[6];
	char packetType;
	char ipType;
	char ipAddr[4];
	char subnet_mask[4];
}mcMasterChangePacket;

typedef struct _log2FileChangedPacket_t
{
	NET_EVENT event;
	char log2FileEnabled;
}log2FileChangedPacket_t;

typedef struct _messStct
{
	long int sendTo;
	char  mess_array[MAX_BUF_LEN_NET];
}messStct;

#ifndef CONFIG_IPF40
typedef struct _registered_subs_t
{
	unsigned char command;
	unsigned char subs_info_cnt;
	char subs_name_arr[24][5];
	//unsigned int subs_name_arr[24];
	unsigned char subs_ip[24][4];
}registered_subs_t;
#else // CONFIG_IPF40
#define REGISTERED_SUBS_MAX_INFO_COUNT	50
typedef struct _registered_subs_t
{
	unsigned char command;
	unsigned char nFirstSubsPort;
	unsigned char subs_info_cnt;
	unsigned char subs_ip[ REGISTERED_SUBS_MAX_INFO_COUNT ][4];
}registered_subs_t;
#endif // CONFIG_IPF40

#define PROTO_LENGTH 	6
#define POLICY_LENGTH 	10

typedef struct _fw_mngr_pack_t
{
	unsigned char 	command;
	unsigned int 	port_start;
	unsigned int 	port_bandwidth;
	char 			proto[PROTO_LENGTH];
	char 			policy[POLICY_LENGTH];
}fw_mngr_pack_t;


typedef enum _E_FW_COMMAND
{
	E_FW_COMMAND_DROP,
	E_FW_COMMAND_ACCEPT
}E_FW_COMMAND;

typedef struct _rtpPortIntervalPack_t
{
	char notif_reason[RTPP_NOTIF_REASON_SIZE];
	unsigned int rtpPortStart;
}rtpPortIntervalPack_t;

typedef struct _rtppWebManagementPack_t
{
	char notif_reason[RTPP_NOTIF_REASON_SIZE];
	unsigned int minrtppPort;
	unsigned int maxrtppPort;
}rtppWebManagementPack_t;

typedef struct _msAccessInfo_t
{
	unsigned char command;
	unsigned char serviceProviderTab[MAX_ACCESS_INFO];
}msAccessInfo_t;

typedef enum _E_SERVICE_PROVIDERS_TR
{
	E_SERVICE_PROVIDERS_TR_TURKTELEKOM	=	0x00,
	E_SERVICE_PROVIDERS_TR_VOIP			=	0x01,
	E_SERVICE_PROVIDERS_TR_AVEA			=	0x02,
	E_SERVICE_PROVIDERS_TR_TURKCELL		=	0x03,
	E_SERVICE_PROVIDERS_TR_VODAFONE		=	0x04,
}E_SERVICE_PROVIDERS_TR;


typedef enum _E_FAX_METHODS
{
	E_FAX_METHODS_T38,
	E_FAX_METHODS_G711_A,
	E_FAX_METHODS_G711_U,
	E_FAX_METHODS_NONE
}E_FAX_METHODS;

typedef enum _E_TRANSFER_METHODS
{
	E_TRANSFER_METHODS_EXTERNAL,
	E_TRANSFER_METHODS_INTERNAL,
	E_TRANSFER_METHODS_NONE
}E_TRANSFER_METHODS;

typedef enum _E_BUSY_SUBS_METHODS
{
	E_BUSY_SUBS_METHODS_BUSY,
	E_BUSY_SUBS_METHODS_RINGING,
	E_BUSY_SUBS_METHODS_NONE
}E_BUSY_SUBS_METHODS;

typedef struct _protocolSettings_t
{
	unsigned char command;
	E_FAX_METHODS faxMethod;
	E_TRANSFER_METHODS transferMethod;
	E_BUSY_SUBS_METHODS busySubsMethod;
}protocolSettings_t;

typedef struct{
	NET_EVENT event;
	E_FAX_METHODS faxMethod;
}faxTypeEvent_t;

typedef struct _mtrNetModifyPack_t
{
	unsigned char event;
	unsigned char ipAddr[4];
	unsigned char gwAddr[4];
	unsigned char subnetMask[4];
	unsigned char ipAddr2[4];
}mtrNetModifyPack_t;

typedef struct _pseudoLicensePack_t
{

}pseudoLicensePack_t;


typedef struct _dspLogInfo_t
{
	NET_EVENT event;
	unsigned char logEnabled;
	unsigned int port;
	unsigned char addr[128];
}dspLogInfo_t;

typedef struct _subsMailInfoPack_t{
	NET_EVENT event;
	unsigned char port;
	char mailAddr[MAX_MAIL_ADDR_SIZE+1];
}subsMailInfoPack_t;


typedef enum _WEB_LANGUAGE
{
	WEB_LANGUAGE_TR,
	WEB_LANGUAGE_EN,
	WEB_LANGUAGE_RU
}WEB_LANGUAGE;

typedef struct _webLanguageInfo_t{
	NET_EVENT event;
	WEB_LANGUAGE lang;
}webLanguageInfo_t;


enum{
	E_subscriber_analog_gain_0_db = 0,
	E_subscriber_analog_gain_Minus_3_5_db,
	E_subscriber_analog_gain_3_5_db,
	E_subscriber_analog_gain_mute,
};

enum{
	E_subscriber_digital_gain_mute = 0,
	E_subscriber_digital_gain_minus_5_5_db,
	E_subscriber_digital_gain_minus_5_0_db,
	E_subscriber_digital_gain_minus_4_5_db,
	E_subscriber_digital_gain_minus_4_0_db,
	E_subscriber_digital_gain_minus_3_5_db,
	E_subscriber_digital_gain_minus_3_0_db,
	E_subscriber_digital_gain_minus_2_5_db,
	E_subscriber_digital_gain_minus_2_0_db,
	E_subscriber_digital_gain_minus_1_5_db,
	E_subscriber_digital_gain_minus_1_0_db,
	E_subscriber_digital_gain_minus_0_5_db,
	E_subscriber_digital_gain_0_0_db,
	E_subscriber_digital_gain_0_5_db,
	E_subscriber_digital_gain_1_0_db,
	E_subscriber_digital_gain_1_5_db,
	E_subscriber_digital_gain_2_0_db,
	E_subscriber_digital_gain_2_5_db,
	E_subscriber_digital_gain_3_0_db,
	E_subscriber_digital_gain_3_5_db,
	E_subscriber_digital_gain_4_0_db,
	E_subscriber_digital_gain_4_5_db,
	E_subscriber_digital_gain_5_0_db,
	E_subscriber_digital_gain_5_5_db,
	E_subscriber_digital_gain_6_0_db,
};

enum{
	E_trunk_analog_gain_0_db = 0,
	E_trunk_analog_gain_1_db,
	E_trunk_analog_gain_2_db,
	E_trunk_analog_gain_3_db,
	E_trunk_analog_gain_4_db,
	E_trunk_analog_gain_5_db,
	E_trunk_analog_gain_6_db,
	E_trunk_analog_gain_7_db,
	E_trunk_analog_gain_8_db,
	E_trunk_analog_gain_9_db,
	E_trunk_analog_gain_10_db,
	E_trunk_analog_gain_11_db,
	E_trunk_analog_gain_12_db,
	E_trunk_analog_gain_NA_db_13,
	E_trunk_analog_gain_NA_db_14,
	E_trunk_analog_gain_NA_db_15,
	E_trunk_analog_gain_NA_db_16,
	E_trunk_analog_gain_minus_1_db, /* 17 */
	E_trunk_analog_gain_minus_2_db,
	E_trunk_analog_gain_minus_3_db,
	E_trunk_analog_gain_minus_4_db,
	E_trunk_analog_gain_minus_5_db,
	E_trunk_analog_gain_minus_6_db,
	E_trunk_analog_gain_minus_7_db,
	E_trunk_analog_gain_minus_8_db,
	E_trunk_analog_gain_minus_9_db,
	E_trunk_analog_gain_minus_10_db,
	E_trunk_analog_gain_minus_11_db,
	E_trunk_analog_gain_minus_12_db,
	E_trunk_analog_gain_minus_13_db,
	E_trunk_analog_gain_minus_14_db,
	E_trunk_analog_gain_minus_15_db, /* 31 */
};

enum {
	E_AGC_GAIN_minus_9_dBm = 0,
	E_AGC_GAIN_minus_12_dBm = 1,
	E_AGC_GAIN_minus_15_dBm = 2,
	E_AGC_GAIN_minus_18_dBm = 3,
	E_AGC_GAIN_minus_21_dBm = 4,
	E_AGC_GAIN_minus_24_dBm = 5,
	E_AGC_GAIN_DEFAULT = 0xFF,
	E_AGC_GAIN_NONE = 0xFF
};

enum{
	E_trunk_ACTermination_600ohm_FCC68 = 0,
	E_trunk_ACTermination_900ohm,
	E_trunk_ACTermination_270ohm_750ohm_150nf,
	E_trunk_ACTermination_220ohm_820ohm_120nf,
	E_trunk_ACTermination_370ohm_620ohm_310nf,
	E_trunk_ACTermination_320ohm_1050ohm_230nf,
	E_trunk_ACTermination_370ohm_820ohm_110nf,
	E_trunk_ACTermination_275ohm_780ohm_115nf,
	E_trunk_ACTermination_120ohm_820ohm_110nf,
	E_trunk_ACTermination_350ohm_1000ohm_210nf,
	E_trunk_ACTermination_200ohm_680ohm_100nf,
	E_trunk_ACTermination_600ohm_2_16uf,
	E_trunk_ACTermination_900ohm_1uf,
	E_trunk_ACTermination_900ohm_2_16uf,
	E_trunk_ACTermination_600ohm_1uf,
	E_trunk_ACTermination_complex,
};

#pragma pack(push, 1) /* structures are byte aligned */

typedef enum
{
	E_RING_GAIN_SUBSCRIBER_GAIN_SETTINGS,
	E_RING_GAIN_SUBSCRIBER_GAIN_SETTINGS_QUERY,
	E_RING_GAIN_TRUNK_GAIN_SETTINGS,
	E_RING_GAIN_TRUNK_GAIN_SETTINGS_QUERY,
	E_RING_GAIN_RING_DETECTION_SETTINGS,
	E_RING_GAIN_RING_DETECTION_SETTINGS_QUERY,
}E_RING_GAIN;

typedef struct
{
	NET_EVENT event;
	E_RING_GAIN eRingGain;
}ringGainGenericPack_t;

typedef struct
{
	unsigned  char nAnalogGain_RX;
	unsigned  char nAnalogGain_TX;
	unsigned  char nDigitalGain_RX;
	unsigned  char nDigitalGain_TX;
}subscriberPortGainSettings_t;

typedef struct
{
	NET_EVENT event; /* SUBSCRIBER_GAIN_SETTINGS, */
	E_RING_GAIN eRingGain;
	subscriberPortGainSettings_t aSubscriberPortGainSettings[ MAX_ANALOG_SUBSCRIBER_COUNT ];
}subscriberGainSettings_t;


typedef struct
{
	unsigned  char nAnalogGain_RX;
	unsigned  char nAnalogGain_TX;
	unsigned  char nTrunkACTermination; // 4 bits 0-15
}trunkPortGainSettings_t;

typedef struct
{
	NET_EVENT event; /* TRUNK_GAIN_SETTINGS, */
	E_RING_GAIN eRingGain;
	trunkPortGainSettings_t aTrunkPortGainSettings[ MAX_ANALOG_TRUNK_COUNT ];
}trunkGainSettings_t;

enum
{
	E_ring_timeout_NA = 0,
	E_ring_timeout_128_ms,
	E_ring_timeout_256_ms,
	E_ring_timeout_384_ms,
	E_ring_timeout_512_ms,
	E_ring_timeout_640_ms,
	E_ring_timeout_768_ms,
	E_ring_timeout_896_ms,
	E_ring_timeout_1024_ms,
	E_ring_timeout_1152_ms,
	E_ring_timeout_1280_ms,
	E_ring_timeout_1408_ms,
	E_ring_timeout_1536_ms,
	E_ring_timeout_1664_ms,
	E_ring_timeout_1792_ms,
	E_ring_timeout_1920_ms,
};

enum
{
	E_ring_confirmation_100_ms = 0,
	E_ring_confirmation_150_ms,
	E_ring_confirmation_200_ms,
	E_ring_confirmation_256_ms,
	E_ring_confirmation_384_ms,
	E_ring_confirmation_512_ms,
	E_ring_confirmation_640_ms,
	E_ring_confirmation_1024_ms,
};

enum{
	E_ring_detect_voltage_13_5__16_5 = 0,
	E_ring_detect_voltage_19_35__23_65,
	E_ring_detect_voltage_40_5__49_5
};

typedef struct
{
	unsigned char bRingValidationEnabled; 	/* false, true */
	unsigned char nDelay; 					/* 3 bits - (0-7) * 256 milisecond */
	unsigned char nAssertionMaxCount; 		/* 6 bits 0-63 */
	unsigned char nRingTimeout; 			/* 4 bits ( 0 -15 ) * 128 milisecond, ( 0 is NA ) */
	unsigned char nConfirmationTime; 		/* 3 bits */
	unsigned char nAssertionTime; 			/* 6 bits 0-63 */
	unsigned char nThreshold;
}ringValidationSettings_t;

typedef struct
{
	NET_EVENT event; 						/* RING_DETECTION_SETTINGS, */
	E_RING_GAIN eRingGain;
	ringValidationSettings_t ringValidationSettings;
}ringValidationSettingsPack_t;

#pragma pack(pop)

#endif //DSP_DRV_INCLUDE

typedef enum _LOG_PACK_DEGREE
{
	LOG_PACK_DEGREE_SEND = 0x01,
	LOG_PACK_DEGREE_WRITE = 0x02,
	LOG_PACK_DEGREE_WRITE_SEND = 0x03,
	LOG_PACK_DEGREE_MAIL = 0x04,
	LOG_PACK_DEGREE_WRITE_MAIL = 0x06,
	LOG_PACK_DEGREE_SEND_MAIL = 0x05,
	LOG_PACK_DEGREE_WRITE_SEND_MAIL = 0x07,
	LOG_PACK_DEGREE_MTR = 0x08,
	LOG_PACK_DEGREE_DSLOG = 0x10,
	LOG_PACK_DEGREE_WRITE_SEND_DSLOG = 0x13,
}LOG_PACKET_DEGREE;

typedef enum _LOG_PACK_TYPE
{
	LOG_PACK_TYPE_ALPHA,
	LOG_PACK_TYPE_HEX,
	LOG_PACK_TYPE_DEC,
	LOG_PACK_TYPE_ALPHANUMERIC,
	LOG_PACK_TYPE_MTR
}LOG_PACK_TYPE;

typedef struct _log_packet_t
{
	char sender;
	char degree;
	char type;
	int log_array_len;
	char log_array[LOG_BUF_SIZE];
}log_packet_t;

typedef struct _configBundlePack_t
{
	char notif_reason[CONFIG_BUNDLE_NOTIF_STR_SIZE];
	char bundlePath[CONFIG_BUNDLE_MAX_PATH_SIZE];
}configBundlePack_t;

enum
{
	E_LOAD_CONFIG_BUNDLE_STATUS_INFO_STARTED,
	E_LOAD_CONFIG_BUNDLE_STATUS_INFO_BUNDLE_VALID,
	E_LOAD_CONFIG_BUNDLE_STATUS_INFO_BUNDLE_INVALID,
	E_LOAD_CONFIG_BUNDLE_STATUS_INFO_EXTRACT_FAILED,
	E_LOAD_CONFIG_BUNDLE_STATUS_INFO_EXTRACT_OK,
};

typedef enum
{
	E_HW_VERSION_INFO_TYPE_DSP,
	E_HW_VERSION_INFO_TYPE_DSP_BOOTLOADER,
	E_HW_VERSION_INFO_TYPE_DSP_MUSIC,
	E_HW_VERSION_INFO_TYPE_FPGA,
}E_HW_VERSION_INFO_TYPE;

#define MAX_VERSION_STR_LEN	100
typedef struct
{
	unsigned char packet;
	E_HW_VERSION_INFO_TYPE type;
	char info[ MAX_VERSION_STR_LEN ];
}hwVersionInfoPack_t;

#endif /*NETSET_H_*/

