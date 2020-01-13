#ifndef __PROTO_H
#define __PROTO_H

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sqlite3.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>
#include <pthread.h>

#pragma pack(1)    //指定字节对齐  

#define SERVER_PORT	6666
#define SERVER_IP	"192.168.154.129"

#define NAME_SIZE   65
#define ADDR_SIZE   65
#define PWD_SIZE    33
#define CNT_SIZE    6
#define MAX_LEN    1024

/*调试使用*/
#define DEBUG       1

enum{DEVICE_NAME=0, DEVICE_ID, DEVICE_ADDR, TEMP, HUM, DP_TEMP, DIP_FIRE, SMOG, PM25};

/*
device_id--2101
callback--device_addr--02#-101
callback--temp--24
callback--hum--66
callback--dp_temp--18
callback--dip_fire--0
callback--smog--200
callback--PM25--12
*/

typedef struct regdate
{
    char name[NAME_SIZE];
    char count[CNT_SIZE];
    char pwd[PWD_SIZE];
}reg_date_t;

/*设备数据结构*/
typedef struct device_data
{
    char device_name[NAME_SIZE];
    char device_addr[64];
    int device_id;
    uint8_t temp;
    uint8_t hum;
    int8_t dp_temp;        //露点温度
    uint8_t dip_fire;      //浸水—火光开关量  第0位 dip   第1位 fire    1 有信号   0无信号
    int smog;              //烟雾
    int PM25;
}DEVICE_DATA;

/*多个设备数据存储*/
typedef struct device_data_buf
{
    int expect_num;           //期望提取的数据个数
    int actual_num;           //实际个数
    DEVICE_DATA *device;
}DEVICE_DATA_BUF;

#endif
