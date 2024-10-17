#ifndef __CMD_H_
#define __CMD_H_

#include "xbasic_types.h"
#include "xil_types.h"
#include "stdio.h"
#include "xparameters.h"
#include "fat/ff.h"
#include "nhc_amba.h"
#include "xstatus.h"
#include "mem_test.h"
#include "xllfifo_drv.h"
#include "FIFO.h"


#define 	OFFSET_SIZE             512*1024*1024   // 32M
//#define 	MAX_LEN             0x2000 0x27EC 0x5B4
#define 	MAX_LEN             0x400
//����ģʽ   6.17
#define     MODE_8x			    0x00010008
#define     MODE_1x		        0x00010001
#define     MODE_tcp		    0x0001000C
#define     DUMMY		        0x00000000
#define     READ_FINSHED		0xAAAAAAAA

//#define     WRITE_PACKET_SIZE   0x20000   //128k
#define     WRITE_PACKET_SIZE   0x100000   //1M


#define 	SRC_ID				0x0
#define 	DEST_ID				0x0
#define 	CMD_PACK_LEN		(1024*1024)
#define     MSG_MAX_DATA_LEN    6164
//#define     MSG_MAX_DATA_LEN    1050636
#define		MSG_QUERY		    12

#define		MSG_NULL		 	0x00
//#define		MSG_SERIAL			0x01	/
#define		MSG_WARNING			0x02

//#define		MSG_CMD_INPUT		0x10

#define		WARNING_MSG_OVERFLOW	0x01
//#define		WARNING_DISK_OVERFLOW	0x02
//#define	    WARNING_FILE_OVERFLOW   0x03
//#define		WARNING_DISK_W_ERR		0x04
//#define		WARNING_DISK_R_ERR		0x05
//#define		WARNING_DMA_TX_ERR		0x06
//#define		WARNING_DMA_RX_ERR		0x07


#define NEW_FILE			1   //1.31�Ÿ�   �ͻ�Ҫ��16�������ĳ�10������
#define NEW_FOLDER			2
#define DEL_FILE			3
#define DEL_FOLDER			4
#define RENAME_FILE			5
#define RENAME_FOLDER		6
#define MOVE_FOLDER			7
#define MOVE_FILE			8
#define OPEN_FILE			9
#define CLOSE_FILE			0x10
#define COPY_FILE			0x11
#define COPY_FOLDER			0x12
#define GET_DIR				0x13

#define DISK_FORMAT			1
#define DISK_REMOUNT		2
#define DISK_UNMOUNT		3

#define FILE_ATTRIBUTE		0X0
#define FOLDER_ATTRIBUTE	0X01

typedef	struct
{
		u32 HandType;			//
		u32 HandId;			//
		u32	DataLen;
		u32	PackNum;
		u8 	MsgData[MSG_MAX_DATA_LEN];

}__attribute__((__packed__)) StructMsg;

typedef	struct
{
		u8 Start;
		u8 End;
		StructMsg MsgQuery[MSG_QUERY];
}__attribute__((__packed__)) StructMsgQuery;

typedef struct
{
	u32		Head;
	u32		SrcId;
	u32		DestId;
	u32		HandType;
	u32		HandId;
	u32		PackNum;
	u32		AckPackNum;
	u32		AckHandType;
	u32		AckHandId;
	u32		AckResult;
	u32		backups[4];       // 1.31���տͻ�Э������
	u32		CheckCode;
	u32		Tail;
}__attribute__((__packed__))  StructA203Ack;

typedef struct
{
	u32		Head;
	u32		SrcId;
	u32		DestId;
	u32		HandType;
	u32		HandId;
	u32		PackNum;
//	u8		Name[1024];
//	u8		Dir[1024];
	u16		Name[512];
	u16		Dir[512];
	u64		Size;
//	u32		SubFolderNum;
//	u32		SubFileNum;
//	u8		CreateTime1[48];
//	u8		CreateTime2[48];
//	u8		ChangeTime1[48];
//	u8		ChangeTime2[48];
//	u8		AccessTime1[48];
//	u8		AccessTime2[48];
	u16		CreateTime1[24];
	u16		CreateTime2[24];
	u16		ChangeTime1[24];
	u16		ChangeTime2[24];
	u16		AccessTime1[24];
	u16		AccessTime2[24];
	u32		RWCtrl;
	u32		DisplayCtrl;
	u32		backups[12];       // 1.31���տͻ�Э������
	u32		CheckCode;
	u32		Tail;
}__attribute__((__packed__))  StructA206Ack;

typedef struct
{
	u32		Head;
	u32		SrcId;
	u32		DestId;
	u32		HandType;
	u32		HandId;
	u32		PackNum;
//	u8		Name[1024];
//	u8		Dir[1024];
	u16		Name[512];
	u16		Dir[512];
	u64		Size;
	u32		SubFolderNum;
	u32		SubFileNum;
//	u8		CreateTime1[48];
//	u8		CreateTime2[48];
//	u8		ChangeTime1[48];
//	u8		ChangeTime2[48];
//	u8		AccessTime1[48];
//	u8		AccessTime2[48];
	u16		CreateTime1[24];
	u16		CreateTime2[24];
	u16		ChangeTime1[24];
	u16		ChangeTime2[24];
	u16		AccessTime1[24];
	u16		AccessTime2[24];
	u32		RWCtrl;
	u32		DisplayCtrl;
	u32		backups;       // 1.31���տͻ�Э������
	u32		CheckCode;
	u32		Tail;
}__attribute__((__packed__))  StructA207Ack;

typedef struct
{
	u32		Head;
	u32		SrcId;
	u32		DestId;
	u32		HandType;
	u32		HandId;
	u32		PackNum;
	u32		AckHandType;
	u32		AckHandId;
	u32		FileNum;
	u32		DirNum;
//	u32     SubpackNum;
//	u32     LastPack;
//	u32     SubpackFileNum;
//	u32     SubpackDirNum;
	u32		CheckCode;
	u32		Tail;
	SingleFileOrDir *message;
}__attribute__((__packed__))  StructA208Ack;

typedef struct
{
	u32		Head;
	u32		SrcId;
	u32		DestId;
	u32		HandType;
	u32		HandId;
	u32		PackNum;
	u64		TotalCap;
	u64		UsedCap;
	u64		RemainCap;
	u32		FileNum;
	u32		WorkStatus;
	u32		WorkTemp;
	u32		Power;
	u32		PowerUpNum;
	u32		CheckCode;
	u32		Tail;
}__attribute__((__packed__))  StructHealthStatus;

int run_cmd_a201(StructMsg *pMsg);
int cmd_reply_a203(u32 packnum, u32 type, u32 id, u32 result);
u64 Reverse_u64(u64 element);

#define CW16(a,b) ( (uint16_t)((((uint16_t)(a))<<8) | ((uint16_t)b)) )
//#define CW32(a,b,c,d) ((uint32_t)((((uint32_t)(a))<<24) | (((uint32_t)b)<<16)| (((uint32_t)c)<<8)| ((uint32_t)d))) //��֮ǰ
#define CW32(a,b,c,d) ((uint32_t)((((uint32_t)(a))) | (((uint32_t)b)<<8)| (((uint32_t)c)<<16)| ((uint32_t)d)<<24))   //��֮��
#define CW64(a,b,c,d,e,f,g,h)  (     (uint64_t)((((uint64_t)(a))) | (((uint64_t)b)<<8)  | (((uint64_t)c)<<16) | (((uint64_t)d)<<24) | (((uint64_t)e)<<32)  | (((uint64_t)f)<<40)  | (((uint64_t)g)<<48) | ((uint64_t)h)<<56  ))

#define SW16(x) ((uint16_t)((((uint16_t)(x)&0x00ffU)<<8) | \
							(((uint16_t)(x)&0xff00U)>>8) ))

//#define SW16(x) ((uint16_t)((((uint16_t)(x)&0x00ffU)<<8) | \
//							(((uint16_t)(x)&0xff00U)>>8) ))


#define SW32(x) ((uint32_t)((x&0xff)<<24)|\
							(uint32_t)((x&0xff00)<<8)|\
							(uint32_t)((x&0xff0000)>>8)|\
							(uint32_t)((x&0xff000000)>>24))

#define SW64(x) ((uint64_t)((x&0xff)<<56)|\
							(uint64_t)((x&0xff00)<<40)|\
							(uint64_t)((x&0xff0000)<<24)|\
							(uint64_t)((x&0xff000000)<<8)|\
							(uint64_t)((x&0xff00000000)>>8)|\
							(uint64_t)((x&0xff0000000000)>>24)|\
							(uint64_t)((x&0xff000000000000)>>40)|\
							(uint64_t)((x&0xff00000000000000)>>56))   //1.31д
#endif