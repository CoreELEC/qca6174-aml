/*****< ss1btusb.h >***********************************************************/
/*      Copyright 2007 - 2014 Stonestreet One.                                */
/*      All Rights Reserved.                                                  */
/*                                                                            */
/*  SS1BTUSB - Linux USB Device Driver Constants for the Stonestreet One      */
/*             Bluetooth HCI USB Device Driver (Linux Only).                  */
/*                                                                            */
/*  Author:  Tim Thomas                                                       */
/*                                                                            */
/*** MODIFICATION HISTORY *****************************************************/
/*                                                                            */
/*   mm/dd/yy  F. Lastname    Description of Modification                     */
/*   --------  -----------    ------------------------------------------------*/
/*   01/02/07  T. Thomas      Initial Creation.                               */
/*   05/16/07  D. Wooldridge  Cleanup/Functionality additions for SCO Data.   */
/******************************************************************************/
#ifndef __SS1BTUSBH__
#define __SS1BTUSBH__

#include <linux/ioctl.h>                 /* Included for IOCTL MACRO's.       */

   /* The following constant defines the actual device name prefix of   */
   /* the USB Device.  This prefix will have an index number appended to*/
   /* it to generate the actual physical device name.                   */
#define SS1BTUSB_DEVICE_NAME_PREFIX                   "SS1BTUSB"

   /* The following constant defines the 'seed' value that is used to   */
   /* generate the IOCTL's defined for the device.                      */
#define BTUSB_IOCTL_MAGIC                             'b'

   /* Wait for an asynchronous USB Device Event (ACL/SCO/Event Data)    */
   /* received.                                                         */
#define BTUSB_IOCTL_WAIT_DATA                         _IOR(BTUSB_IOCTL_MAGIC,  0, void *)
#define BTUSB_IOCTL_WAIT_DATA32                       _IOR(BTUSB_IOCTL_MAGIC,  0, uint32_t)

   /* Send/Receive HCI Packets to/from USB Bluetooth Device.            */
#define BTUSB_IOCTL_SEND_PACKET                       _IOW(BTUSB_IOCTL_MAGIC,  1, void *)
#define BTUSB_IOCTL_SEND_PACKET32                     _IOW(BTUSB_IOCTL_MAGIC,  1, uint32_t)

#define BTUSB_IOCTL_READ_PACKET                       _IOWR(BTUSB_IOCTL_MAGIC, 2, void *)
#define BTUSB_IOCTL_READ_PACKET32                     _IOWR(BTUSB_IOCTL_MAGIC, 2, uint32_t)

   /* Enable/Disable SCO Data transfers.                                */
#define BTUSB_IOCTL_ENABLE_SCO_DATA                   _IOW(BTUSB_IOCTL_MAGIC,  3, int)

   /* The following constants are used to identify a packet type for the*/
   /* USBTransferInformation_t structure.                               */
   /* * NOTE * These correspond to the Packet Type values used by HCI   */
   /*          UART protocol.                                           */
#define BTUSB_PACKET_TYPE_COMMAND                     0x01
#define BTUSB_PACKET_TYPE_ACL                         0x02
#define BTUSB_PACKET_TYPE_SCO                         0x03
#define BTUSB_PACKET_TYPE_EVENT                       0x04

   /* The following Constants are used as an Event Mask for the IOCTL   */
   /* function IOCTL_WAIT_DATA and represent the event(s) that occurred */
   /* causing the wait event to return.  These constants are also used  */
   /* as valid packet types in the ioctl_info_t structure.              */
   /* * NOTE * The packet type values were specifically chosen so that  */
   /*          the value would equal (1 << HCI Packet Type).  This was  */
   /*          done so that the bits in the event mask can be           */
   /*          set/cleared using the packet type as the bit number.     */
#define BTUSB_WAIT_DRIVER_EVENT_ACL_DATA              (1 << BTUSB_PACKET_TYPE_ACL)
#define BTUSB_WAIT_DRIVER_EVENT_SCO_DATA              (1 << BTUSB_PACKET_TYPE_SCO)
#define BTUSB_WAIT_DRIVER_EVENT_HCI_EVENT             (1 << BTUSB_PACKET_TYPE_EVENT)

   /* The following Constants represent the maximum packet size for the */
   /* various Bluetooth Packets.                                        */
#define BTUSB_HCI_MAX_ACL_LENGTH                      1024
#define BTUSB_HCI_MAX_SCO_LENGTH                      256
#define BTUSB_HCI_MAX_EVENT_LENGTH                    260
#define BTUSB_HCI_MAX_COMMAND_LENGTH                  260
#define BTUSB_PKT_IND_LENGTH                          (1)
#define BTUSB_HCI_EVT_HDR_LENGTH                      (2)
#define BTUSB_HCI_ACL_HDR_LENGTH                      (4)

#define BTUSB_HCI_ACL_HDR_LEN_OFFSET                  (3)

   /* This structure is used for for transferring data to/from the USB  */
   /* Driver.                                                           */
typedef struct _tagUSBPacketInformation_t
{
   unsigned int   PacketType;
   unsigned int   BufferSize;
   unsigned char *Buffer;
} USBPacketInformation_t;

   /* The following constants represent the constants that can be used  */
   /* with the IOCTL_ENABLE_SCO_DATA IOCTL to enable/disable SCO traffic*/
   /* on the USB Bus.                                                   */
#define BTUSB_SCO_DATA_NO_CHANNELS                    0x00
#define BTUSB_SCO_DATA_ONE_EIGHT_BIT_CHANNEL          0x01
#define BTUSB_SCO_DATA_TWO_EIGHT_BIT_CHANNELS         0x02
#define BTUSB_SCO_DATA_THREE_EIGHT_BIT_CHANNELS       0x03
#define BTUSB_SCO_DATA_ONE_SIXTEEN_BIT_CHANNEL        0x04
#define BTUSB_SCO_DATA_TWO_SIXTEEN_BIT_CHANNELS       0x05
#define BTUSB_SCO_DATA_THREE_SIXTEEN_BIT_CHANNELS     0x06

#endif
