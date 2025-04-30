/**
 * @file packet.hpp
 * @brief header only lilbrary for ilidar packet
 * @author JSon (json@hybo.co)
 * @date 2025-01-03
 * @version 1.12.2
 */

//////////////////////////////////////////////////////////////////////////////////////
//	MIT License(MIT)																//
//																					//
//	Copyright(c) 2022 - Present HYBO Inc.											//
//																					//
//	Permission is hereby granted, free of charge, to any person obtaining a copy	//
//	of this software and associated documentation files(the "Software"), to deal	//
//	in the Software without restriction, including without limitation the rights	//
//	to use, copy, modify, merge, publish, distribute, sublicense, and /or sell		//
//	copies of the Software, and to permit persons to whom the Software is			//
//	furnished to do so, subject to the following conditions :						//
//																					//
//	The above copyright notice and this permission notice shall be included in all	//
//	copies or substantial portions of the Software.									//
//																					//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR		//
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,		//
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE		//
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER			//
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,	//
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE	//
//	SOFTWARE.																		//
//////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdio.h>

namespace iTFX {
	constexpr uint8_t	ilidar_pack_ver[3] = { 2, 12, 1 };
}

namespace iTFS {
	namespace packet {
		constexpr uint8_t	ilidar_pack_ver[3] = { 2, 12, 1 };

		/*
		iTFS PACKET STRUCTURE DESCRIPTIONS

		idx	field	SIZE	VALUE
		0	STX0	1		0xA5
		1	STX1	1		0x5A
		2	ID		2		0x0000 for img_data, ...
		4	LEN		2		N
		6	PAYLOAD	N 	
		N+6	ETX0	1		0xA5
		N+7	ETX1	1		0x5A		 	
		TOTAL SIZE	N+8

		See ilidar.cpp to use this packet with encode and decode functions
		*/

		constexpr uint8_t	stx0				= 0xA5;		// FW V1.4.0+
		constexpr uint8_t	stx1				= 0x5A;		// FW V1.4.0+
		constexpr int		stx_len				= 2;		// FW V1.4.0+
		constexpr int		id_len				= 2;		// FW V1.4.0+
		constexpr int		len_len				= 2;		// FW V1.4.0+
		constexpr int		header_len			= 6;		// FW V1.4.0+
		constexpr uint8_t	etx0				= 0xA5;		// FW V1.4.0+
		constexpr uint8_t	etx1				= 0x5A;		// FW V1.4.0+
		constexpr int		overheader_len		= 8;		// FW V1.4.0+

		constexpr uint16_t	img_data_id			= 0x0000;	// FW V1.4.0+
		constexpr uint16_t	img_data_len		= 1282;		// FW V1.4.0+

		constexpr uint16_t	status_id			= 0x0010;	// FW V1.4.0+
		constexpr uint16_t	status_len			= 28;		// FW V1.4.0+

		constexpr uint16_t	status_full_id		= 0x0011;	// FW V1.4.0+
		constexpr uint16_t	status_full_len		= 312;		// FW V1.4.0+

		constexpr uint16_t	sync_ack_id			= 0x0012;	// FW V1.5.5+
		constexpr uint16_t	sync_ack_len		= 26;		// FW V1.5.5+

		constexpr uint16_t	info_id				= 0x0020;	// FW V1.4.0+
		constexpr uint16_t	info_len			= 110;		// FW V1.4.0+

		constexpr uint16_t	info_v2_id			= 0x0021;	// FW V1.5.0+
		constexpr uint16_t	info_v2_len			= 166;		// FW V1.5.0+

		constexpr uint16_t	cmd_id				= 0x0030;	// FW V1.4.0+
		constexpr uint16_t	cmd_len				= 4;		// FW V1.4.0+

		constexpr uint16_t	cmd_sync			= 0x0000;	// FW V1.4.0+, BROADCAST only
		constexpr uint16_t	cmd_select			= 0x0001;	// FW V1.4.0+, BROADCAST only

		constexpr uint16_t	cmd_measure			= 0x0100;	// FW V1.4.0+
		constexpr uint16_t	cmd_pause			= 0x0101;	// FW V1.4.0+
		constexpr uint16_t	cmd_reboot			= 0x0102;	// FW V1.4.0+
		constexpr uint16_t	cmd_store			= 0x0103;	// FW V1.4.0+
		constexpr uint16_t	cmd_safe_boot		= 0x0104;	// FW V1.5.0+

		constexpr uint16_t	cmd_reset_factory	= 0x0200;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn
		constexpr uint16_t	cmd_reset_log		= 0x0201;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn

		constexpr uint16_t	cmd_read_info		= 0x0300;	// FW V1.4.0+
		constexpr uint16_t	cmd_read_log		= 0x0301;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn
		constexpr uint16_t	cmd_read_depth		= 0x0302;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn
		constexpr uint16_t	cmd_read_tf			= 0x0303;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn

		constexpr uint16_t	cmd_req_flash_ack	= 0x0310;	// FW V1.5.0+, UNICAST only, cmd_msg = sensor_sn

		constexpr uint16_t	cmd_redirect		= 0x0400;	// FW V1.4.0+

		constexpr uint16_t	cmd_lock			= 0x0500;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn
		constexpr uint16_t	cmd_unlock			= 0x0501;	// FW V1.4.0+, UNICAST only, cmd_msg = sensor_sn

		constexpr uint16_t	cmd_flash_start		= 0x0600;	// FW V1.5.0+, UNICAST only, cmd_msg = sensor_sn 
		constexpr uint16_t	cmd_flash_finish	= 0x06FF;	// FW V1.5.0+, UNICAST only, cmd_msg = sensor_sn 

		constexpr uint16_t	ack_id				= 0x0040;	// FW V1.5.0+
		constexpr uint16_t	ack_len				= 34;		// FW V1.5.0+

		constexpr uint16_t	ack_flash_start		= 0x0600;	// FW V1.5.0+
		constexpr uint16_t	ack_flash_finish	= 0x06FF;	// FW V1.5.0+

		constexpr uint16_t	flash_block_id		= 0x0100;	// FW V1.5.0+
		constexpr uint16_t	flash_block_len		= 1062;		// FW V1.5.0+

		constexpr uint16_t	stream_status_id	= 0x1000;	// SW V1.12.2+
		constexpr uint16_t	stream_status_len	= 130;		// SW V1.12.2+

		// FW V1.4.0+
		// Image data packet for depth and intensity images (definition only)
		typedef struct {
			uint8_t		row;
			uint8_t		mframe;
			uint16_t	data[640];
		}img_data_packet_t;

		// FW V1.4.0+
		// Status packet for sensor internal infomation
		typedef struct {
			uint8_t		capture_mode;				// Mode, 0 = GRAY, 1 = MODE1(NB), 2 = MODE2(VB), 3 = MODE3(HV)
			uint8_t		capture_frame;				// Frame number, repeats 0 ~ 63
			uint16_t	sensor_sn;					// Serial number
			uint64_t	sensor_time_th;				// Sensor time in [ms]
			uint16_t	sensor_time_tl;				// Sensor time in [us]
			uint16_t	sensor_frame_status;		// Sensor status flag for depth image
			int16_t		sensor_temp_rx;				// Sensor RX temperature in [C]
			int16_t		sensor_temp_core;			// Sensor core temperature in [C]
			int16_t		sensor_vcsel_level;			// Sensor VCSEL voltage
			int16_t		sensor_power_level;			// Sensor internal power voltage
			uint32_t	sensor_warning;				// Sensor warning flag
		}status_t;

		// FW V1.4.0+
		// Extended status packet for sensor internal infomation
		typedef struct {
			uint8_t		capture_mode;				// Mode, 0 = GRAY, 1 = MODE1(NB), 2 = MODE2(VB), 3 = MODE3(HV)
			uint8_t		capture_frame;				// Frame number, repeats 0 ~ 63
			uint16_t	sensor_sn;					// Serial number
			uint64_t	sensor_time_th;				// Sensor time in [ms]
			uint16_t	sensor_time_tl;				// Sensor time in [us]
			uint16_t	sensor_frame_status;		// Sensor status flag for depth image
			int16_t		sensor_temp_rx;				// Sensor RX temperature in [C]
			int16_t		sensor_temp_core;			// Sensor core temperature in [C]
			int16_t		sensor_temp[4];				// Sensor housing temperature in [C]
			int16_t		sensor_vcsel_level;			// Sensor VCSEL voltage
			int16_t		sensor_vcsel_on[4][16];		// Sensor VCSEL dynamic voltage for debugging
			int16_t		sensor_power_level;			// Sensor internal power voltage
			int16_t		sensor_power_on[4][16];		// Sensor internal power dynamic voltage for debugging
			int16_t		sensor_level[10];			// Sensor internal voltage for debugging
			uint32_t	sensor_warning;				// Sensor warning flag
		}status_full_t;

		// FW V1.5.5+
		// Extended sync status packet for sensor synchronization
		// This message will be activated when sync mode = sync_mode_udp
		typedef struct {
			uint16_t	sensor_sn;					// Serial number
			uint64_t	sensor_time_th;				// Sensor time in [ms]
			uint16_t	sensor_time_tl;				// Sensor time in [us]
			uint8_t		sync_cmd_ip[4];				// Synchronization command owner IP
			uint16_t	sync_cmd_port;				// Synchronization command owner port
			uint64_t	sync_elapsed_time_us;		// Synchronization elapsed time in [us]
		}sync_ack_t;

		// FW V1.4.0+
		// Parameter packet for sensor configuration
		typedef struct {							// [RW]
			uint16_t	sensor_sn;					// [R-] Sensor serial number
			uint8_t		sensor_hw_id[30];			// [R-] Sensor HW ID
			uint8_t		sensor_fw_ver[3];			// [R-] Sensor firmware version
			char		sensor_fw_date[12];			// [R-] Sensor firmware date
			char		sensor_fw_time[9];			// [R-] Sensor firmware time
			uint32_t	sensor_calib_id;			// [R-] Sensor calibration ID
			uint8_t		capture_mode;				// [RW] Capture mode, 0 = GRAY, 1 = MODE1(NB), 2 = MODE2(VB), 3 = MODE3(HV)
			uint8_t		capture_row;				// [RW] Capture row number, 4 <= ROW <= 160, default = 160, only the value in multiples of 4
			uint16_t	capture_period;				// [RW] Capture period, 50 <= period <= 1000, default = 100
			uint16_t	capture_shutter[5];			// [RW] Capture shutter integration time, 2 <= shutter <= 600, 2 <= gray <= 10000, default = [400 40 4 4 8000]
			uint16_t	capture_limit[2];			// [RW] Capture intensity limit, 0 <= limit <= 500, default = 200
			uint8_t		data_output;				// [RW] Data output flag
			uint32_t	data_baud;					// [RW] UART baudrate, 9600 <= baud <= 6000000, default = 115200
			uint8_t		data_sensor_ip[4];			// [RW] Sensor IP
			uint8_t		data_dest_ip[4];			// [RW] Destination IP
			uint8_t		data_subnet[4];				// [RW] Subnet Mask
			uint8_t		data_gateway[4];			// [RW] Gateway
			uint16_t	data_port;					// [RW] Data output port number
			uint8_t		sync;						// [RW] flag, default = 0
			uint16_t	sync_delay;					// [RW] delay <= period, default = 0
			uint8_t		arb;						// [RW] flag, default = 0
			uint32_t	arb_timeout;				// [RW] timeout <= 60 * 60 * 1000, default = 5 * 60 * 1000
			uint8_t		lock;						// [RW] flag, configuration locker, default = 0
		}info_t;

		// FW V1.5.0+
		// Extended parameter packet for sensor configuration
		typedef struct {							// [RW]
			/*			Sensor parameters			*/
			uint16_t	sensor_sn;					// [R-] Serial number
			uint8_t		sensor_hw_id[30];			// [R-] HW ID
			uint8_t		sensor_fw_ver[3];			// [R-] Firmware version
			char		sensor_fw_date[12];			// [R-] Firmware date
			char		sensor_fw_time[9];			// [R-] Firmware time
			uint32_t	sensor_calib_id;			// [R-] Calibration ID
			/*			Updated						*/
			uint8_t		sensor_fw0_ver[3];			// [R-] Sensor firmware version of backup firmware
			uint8_t		sensor_fw1_ver[3];			// [R-] Sensor firmware version on flash sector 1
			uint8_t		sensor_fw2_ver[3];			// [R-] Sensor firmware version on flash sector 2
			uint8_t		sensor_model_id;			// [R-] Sensor model identifier
			uint8_t		sensor_boot_mode;			// [R-] Sensor boot mode register 
			/****************************************/


			/*			Capture parameters			*/
			uint8_t		capture_mode;				// [RW] Capture mode, 0 = GRAY, 1 = MODE1(NB), 2 = MODE2(VB), 3 = MODE3(HV)
			uint8_t		capture_row;				// [RW] Capture row number, 4 <= ROW <= 160, default = 160, only the value in multiples of 4
			//uint16_t	capture_period;				// [RW] Deprecated, use capture_period_us
			uint16_t	capture_shutter[5];			// [RW] Capture shutter integration time in (us), 2 <= shutter <= 600, 2 <= gray <= 10000, default = [400 80 16 8 8000]
			uint16_t	capture_limit[2];			// [RW] Capture intensity limit, 0 <= limit <= 500, default = [200, 200]
			/*			Updated						*/
			uint32_t	capture_period_us;			// [RW] (us) Capture period, period = [80000, 1000000]
			uint8_t		capture_seq;				// [RW] Capture sequence flag, default = 0 (forward)
			/****************************************/


			/*			Data output parameters		*/
			uint8_t		data_output;				// [RW] Data output flag
			uint32_t	data_baud;					// [RW] UART baudrate, 9600 <= baud <= 6000000, default = 115200
			uint8_t		data_sensor_ip[4];			// [RW] Sensor IP
			uint8_t		data_dest_ip[4];			// [RW] Destination IP
			uint8_t		data_subnet[4];				// [RW] Subnet Mask
			uint8_t		data_gateway[4];			// [RW] Gateway
			uint16_t	data_port;					// [RW] Data output port number
			/*			Updated						*/
			uint8_t		data_mac_addr[6];			// [RW] MAC address of the sensor
			/****************************************/


			/*			Sync parameters				*/
			uint8_t		sync;						// [RW] Sync flag, default = 5
			//uint16_t	sync_delay;					// [RW] Deprecated, use sync_trig_delay_us
			/*			Updated						*/
			uint32_t 	sync_trig_delay_us;			// [RW] Trigger to illumination delay in (us), default = 0
			uint16_t 	sync_ill_delay_us[15];		// [RW] Delay between illuminations in (us), default = { 0, }
			uint8_t		sync_trig_trim_us;			// [RW] Trigger to illumination trimmer in (us), default = 4
			uint8_t		sync_ill_trim_us;			// [RW] Illumination trimmer in (us), default = 2
			uint16_t	sync_output_delay_us;		// [RW] Illumination to transmission delay in (us), default = 0
			/****************************************/


			/*			Additional parameters		*/
			uint8_t		arb;						// [RW] flag, default = 0
			uint32_t	arb_timeout;				// [RW] timeout <= 60 * 60 * 1000, default = 5 * 60 * 1000
			uint8_t		lock;						// [RW] flag, configuration locker, default = 0
			/****************************************/
		}info_v2_t;

		// FW V1.4.0+
		// Command packet for sensor operation
		typedef struct {
			uint16_t	cmd_id;						// Command ID
			uint16_t	cmd_msg;					// Extended message for some commands
		}cmd_t;

		// FW V1.5.0+
		// Acknowledge packet for sensor flashing
		typedef struct {
			uint16_t	ack_id;						// Acknowledge ID
			uint8_t		ack_msg[32];				// Acknowledge message
		}ack_t;

		// FW V1.5.0+
		// Flash block packet for sensor flashing
		typedef struct {
			uint8_t		hw_id[30];					// Sensor HW ID for valid parameter set
			uint8_t		type;						// Flash data type
			uint8_t		size;						// size of flash block, 1 or 2 (block)
			uint8_t		offset;						// Address offset, addr = offset * 1024  
			uint8_t		ver[3];						// Version of firmware or param
			uint8_t		bin[1024];					// 1 KB flash block
			uint16_t	bin_crc16;					// CRC-16-CCITT for bin
		}flash_block_t;

		// SW V1.12.2+
		// Output packet for sensor streamer
		typedef struct {
			uint8_t		sensor_cnt;					// Number of the sensors
			uint8_t		shm_idx;					// Shared memory index
			uint16_t	sensor_sn[32];				// Sensor serial number table
			uint8_t		sensor_frame[32];			// Sensor frame number table
			uint8_t		read_status[32];			// Sensor read status table
		}stream_status_t;


		// FW V1.5.0+
		// Sensor boot mode flag
		constexpr int		sensor_boot_mode_pos		= 0;
		constexpr uint8_t	sensor_boot_mode_mask		= (0x01 << sensor_boot_mode_pos);
		constexpr uint8_t	sensor_boot_mode_normal		= (0 << sensor_boot_mode_pos);
		constexpr uint8_t	sensor_boot_mode_safemode	= (1 << sensor_boot_mode_pos);


		// FW V1.4.0+
		// Sensor capture mode flag
		constexpr int		capture_mode_bin_pos		= 0;
		constexpr uint8_t	capture_mode_bin_mask		= (0x03 << capture_mode_bin_pos);
		constexpr uint8_t	capture_mode_bin_mode0		= (0 << capture_mode_bin_pos);
		constexpr uint8_t	capture_mode_bin_mode1		= (1 << capture_mode_bin_pos);
		constexpr uint8_t	capture_mode_bin_mode2		= (2 << capture_mode_bin_pos);
		constexpr uint8_t	capture_mode_bin_mode3		= (3 << capture_mode_bin_pos);
		//constexpr int		capture_mode_filter_pos		= 2;
		//constexpr uint8_t	capture_mode_filter_mask	= (0x03 << capture_mode_filter_pos);

		// FW V1.5.0+
		// Sensor capture direction flag
		constexpr int		capture_seq_dir_pos			= 0;
		constexpr uint8_t	capture_seq_dir_mask		= (0x01 << capture_seq_dir_pos);
		constexpr uint8_t	capture_seq_dir_forward		= (0 << capture_seq_dir_pos);
		constexpr uint8_t	capture_seq_dir_backward	= (1 << capture_seq_dir_pos);


		// FW V1.4.0+
		// Sensor depth output flag
		constexpr int		data_output_depth_pos		= 0;
		constexpr uint8_t	data_output_depth_mask		= (0x01 << data_output_depth_pos);
		constexpr uint8_t	data_output_depth_off		= (0 << data_output_depth_pos);
		constexpr uint8_t	data_output_depth_on		= (1 << data_output_depth_pos);

		// FW V1.4.0+
		// Sensor intensity output flag
		constexpr int		data_output_intensity_pos	= 1;
		constexpr uint8_t	data_output_intensity_mask	= (0x01 << data_output_intensity_pos);
		constexpr uint8_t	data_output_intensity_off	= (0 << data_output_intensity_pos);
		constexpr uint8_t	data_output_intensity_on	= (1 << data_output_intensity_pos);

		// FW V1.4.0+
		// Sensor status output flag
		constexpr int		data_output_status_pos		= 2;
		constexpr uint8_t	data_output_status_mask		= (0x01 << data_output_status_pos);
		constexpr uint8_t	data_output_status_normal	= (0 << data_output_status_pos);
		constexpr uint8_t	data_output_status_full		= (1 << data_output_status_pos);
		

		// FW V1.4.0+
		// Sensor sync trigger flag
		constexpr int		sync_mode_pos				= 0;
		constexpr uint8_t	sync_mode_mask				= (0x03 << sync_mode_pos);
		constexpr uint8_t	sync_mode_off				= (0 << sync_mode_pos);
		constexpr uint8_t	sync_mode_udp				= (1 << sync_mode_pos);
		constexpr uint8_t	sync_mode_trigger			= (2 << sync_mode_pos);
		//constexpr uint8_t	sync_mode_uart				= (3 << sync_mode_pos);

		// FW V1.4.0+
		// Sensor sync strobe flag
		constexpr int		sync_strobe_pos				= 2;
		constexpr uint8_t	sync_strobe_mask			= (0x03 << sync_strobe_pos);
		constexpr uint8_t	sync_strobe_off				= (0 << sync_strobe_pos);
		constexpr uint8_t	sync_strobe_on				= (1 << sync_strobe_pos);
		//constexpr uint8_t	sync_strobe_uart			= (3 << sync_strobe_pos);


		// FW V1.4.0+
		// Sensor auto-reboot mode flag
		constexpr int		arb_mode_pos				= 0;
		constexpr uint8_t	arb_mode_mask				= (0x03 << arb_mode_pos);
		constexpr uint8_t	arb_mode_off				= (0 << arb_mode_pos);
		constexpr uint8_t	arb_mode_udp				= (1 << arb_mode_pos);
		constexpr uint8_t	arb_mode_trigger			= (2 << arb_mode_pos);
		//constexpr uint8_t	arb_mode_uart				= (3 << arb_mode_pos);


		// FW V1.4.0+
		// Sensor configuration lock flag
		constexpr uint8_t	lock_mode_unlocked			= 0x00;
		constexpr uint8_t	lock_mode_locked			= 0xA5;

		
		static void decode_status(uint8_t* src, status_t* dst) {
			dst->capture_mode = src[0];
			dst->capture_frame = src[1];

			dst->sensor_sn = (src[3] << 8) | src[2];
			uint64_t th = src[11];
			for (int _i = 0; _i < 7; _i++) {
				th <<= 8;
				th |= src[10 - _i];
			}
			dst->sensor_time_th = th;
			dst->sensor_time_tl = (src[13] << 8) | src[12];
			dst->sensor_frame_status = (src[15] << 8) | src[14];
			dst->sensor_temp_rx = (src[17] << 8) | src[16];
			dst->sensor_temp_core = (src[19] << 8) | src[18];
			dst->sensor_vcsel_level = (src[21] << 8) | src[20];
			dst->sensor_power_level = (src[23] << 8) | src[22];
			dst->sensor_warning = (src[27] << 24) | (src[26] << 16) | (src[25] << 8) | src[24];
		}

		static void decode_status_full(uint8_t* src, status_full_t* dst) {
			dst->capture_mode = src[0];
			dst->capture_frame = src[1];

			dst->sensor_sn = (src[3] << 8) | src[2];
			uint64_t th = src[11];
			for (int _i = 0; _i < 7; _i++) {
				th <<= 8;
				th |= src[10 - _i];
			}
			dst->sensor_time_th = th;
			dst->sensor_time_tl = (src[13] << 8) | src[12];
			dst->sensor_frame_status = (src[15] << 8) | src[14];
			dst->sensor_temp_rx = (src[17] << 8) | src[16];
			dst->sensor_temp_core = (src[19] << 8) | src[18];
			for (int _i = 0; _i < 4; _i++) { dst->sensor_temp[_i] = (src[21 + 2 * _i] << 8) | src[20 + 2 * _i]; }
			dst->sensor_vcsel_level = (src[29] << 8) | src[28];
			for (int _i = 0; _i < 16; _i++) { dst->sensor_vcsel_on[0][_i] = (src[31 + 2 * _i] << 8) | src[30 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_vcsel_on[1][_i] = (src[63 + 2 * _i] << 8) | src[62 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_vcsel_on[2][_i] = (src[95 + 2 * _i] << 8) | src[94 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_vcsel_on[3][_i] = (src[127 + 2 * _i] << 8) | src[126 + 2 * _i]; }
			dst->sensor_power_level = (src[159] << 8) | src[158];
			for (int _i = 0; _i < 16; _i++) { dst->sensor_power_on[0][_i] = (src[161 + 2 * _i] << 8) | src[160 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_power_on[1][_i] = (src[193 + 2 * _i] << 8) | src[192 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_power_on[2][_i] = (src[225 + 2 * _i] << 8) | src[224 + 2 * _i]; }
			for (int _i = 0; _i < 16; _i++) { dst->sensor_power_on[3][_i] = (src[257 + 2 * _i] << 8) | src[256 + 2 * _i]; }
			for (int _i = 0; _i < 10; _i++) { dst->sensor_level[_i] = (src[289 + 2 * _i] << 8) | src[288 + 2 * _i]; }
			dst->sensor_warning = (src[311] << 24) | (src[310] << 16) | (src[309] << 8) | src[308];
		}

		static void decode_sync_ack(uint8_t* src, sync_ack_t* dst) {
			dst->sensor_sn = (src[1] << 8) | src[0];
			uint64_t th = src[9];
			for (int _i = 0; _i < 7; _i++) {
				th <<= 8;
				th |= src[8 - _i];
			}
			dst->sensor_time_th = th;
			dst->sensor_time_tl = (src[11] << 8) | src[10];
			dst->sync_cmd_ip[0] = src[12];
			dst->sync_cmd_ip[1] = src[13];
			dst->sync_cmd_ip[2] = src[14];
			dst->sync_cmd_ip[3] = src[15];
			dst->sync_cmd_port = (src[17] << 8) | src[16];
			uint64_t te = src[25];
			for (int _i = 0; _i < 7; _i++) {
				te <<= 8;
				te |= src[24 - _i];
			}
			dst->sync_elapsed_time_us = te;
		}

		static void encode_info(info_t* src, uint8_t* dst) {
			dst[0] = src->sensor_sn % 256;
			dst[1] = src->sensor_sn / 256;

			for (int _i = 0; _i < (30 + 3 + 12 + 9); _i++) { dst[2 + _i] = 0; }	// Read only

			dst[60] = src->capture_mode;
			dst[61] = src->capture_row;
			dst[62] = (src->capture_period >> 0) & 0xFF;
			dst[63] = (src->capture_period >> 8) & 0xFF;
			dst[64] = (src->capture_shutter[0] >> 0) & 0xFF;
			dst[65] = (src->capture_shutter[0] >> 8) & 0xFF;
			dst[66] = (src->capture_shutter[1] >> 0) & 0xFF;
			dst[67] = (src->capture_shutter[1] >> 8) & 0xFF;
			dst[68] = (src->capture_shutter[2] >> 0) & 0xFF;
			dst[69] = (src->capture_shutter[2] >> 8) & 0xFF;
			dst[70] = (src->capture_shutter[3] >> 0) & 0xFF;
			dst[71] = (src->capture_shutter[3] >> 8) & 0xFF;
			dst[72] = (src->capture_shutter[4] >> 0) & 0xFF;
			dst[73] = (src->capture_shutter[4] >> 8) & 0xFF;
			dst[74] = (src->capture_limit[0] >> 0) & 0xFF;
			dst[75] = (src->capture_limit[0] >> 8) & 0xFF;
			dst[76] = (src->capture_limit[1] >> 0) & 0xFF;
			dst[77] = (src->capture_limit[1] >> 8) & 0xFF;

			dst[78] = src->data_output;

			dst[79] = src->arb;

			dst[80] = (src->data_baud >> 0) & 0xFF;
			dst[81] = (src->data_baud >> 8) & 0xFF;
			dst[82] = (src->data_baud >> 16) & 0xFF;
			dst[83] = (src->data_baud >> 24) & 0xFF;
			dst[84] = src->data_sensor_ip[0];
			dst[85] = src->data_sensor_ip[1];
			dst[86] = src->data_sensor_ip[2];
			dst[87] = src->data_sensor_ip[3];
			dst[88] = src->data_dest_ip[0];
			dst[89] = src->data_dest_ip[1];
			dst[90] = src->data_dest_ip[2];
			dst[91] = src->data_dest_ip[3];
			dst[92] = src->data_subnet[0];
			dst[93] = src->data_subnet[1];
			dst[94] = src->data_subnet[2];
			dst[95] = src->data_subnet[3];
			dst[96] = src->data_gateway[0];
			dst[97] = src->data_gateway[1];
			dst[98] = src->data_gateway[2];
			dst[99] = src->data_gateway[3];
			dst[100] = (src->data_port >> 0) & 0xFF;
			dst[101] = (src->data_port >> 8) & 0xFF;

			dst[102] = src->sync;
			dst[103] = 0;	// This flag will not be written with info packet

			dst[104] = (src->sync_delay >> 0) & 0xFF;
			dst[105] = (src->sync_delay >> 8) & 0xFF;

			dst[106] = (src->arb_timeout >> 0) & 0xFF;
			dst[107] = (src->arb_timeout >> 8) & 0xFF;
			dst[108] = (src->arb_timeout >> 16) & 0xFF;
			dst[109] = (src->arb_timeout >> 24) & 0xFF;
		}

		static void decode_info(uint8_t* src, info_t* dst) {
			uint16_t	sensor_sn = (src[1] << 8) | src[0];
			uint8_t		sensor_hw_id[30] = { src[2], src[3], src[4], src[5], src[6], src[7], src[8], src[9],
											src[10], src[11], src[12], src[13], src[14], src[15], src[16], src[17],
											src[18], src[19], src[20], src[21], src[22], src[23], src[24], src[25],
											src[26], src[27], src[28], src[29], src[30], src[31] };
			uint8_t		sensor_fw_ver[3] = { src[32], src[33], src[34] };
			uint8_t		sensor_fw_date[12] = { src[35], src[36], src[37], src[38],
											src[39], src[40], src[41], src[42],
											src[43], src[44], src[45], src[46] };
			uint8_t		sensor_fw_time[9] = { src[47], src[48], src[49], src[50],
											src[51], src[52], src[53], src[54], src[55] };
			uint32_t	sensor_calib_id = (src[59] << 24) | (src[58] << 16) | (src[57] << 8) | src[56];

			uint8_t		capture_mode = src[60];
			uint8_t		capture_row = src[61];
			uint16_t	capture_period = (src[63] << 8) | src[62];
			uint16_t	capture_shutter[5] = { (uint16_t)((src[65] << 8) | src[64]),
											(uint16_t)((src[67] << 8) | src[66]),
											(uint16_t)((src[69] << 8) | src[68]),
											(uint16_t)((src[71] << 8) | src[70]),
											(uint16_t)((src[73] << 8) | src[72]) };
			uint16_t	capture_limit[2] = { (uint16_t)((src[75] << 8) | src[74]),
											(uint16_t)((src[77] << 8) | src[76]) };

			uint8_t		data_output = src[78];

			uint8_t		arb = src[79];

			uint32_t	data_baud = (src[83] << 24) | (src[82] << 16) | (src[81] << 8) | src[80];
			uint8_t		data_sensor_ip[4] = { src[84], src[85], src[86], src[87] };
			uint8_t		data_dest_ip[4] = { src[88], src[89], src[90], src[91] };
			uint8_t		data_subnet[4] = { src[92], src[93], src[94], src[95] };
			uint8_t		data_gateway[4] = { src[96], src[97], src[98], src[99] };
			uint16_t	data_port = (src[101] << 8) | src[100];

			uint8_t		sync = src[102];

			uint8_t		lock = src[103];

			uint16_t	sync_delay = (src[105] << 8) | src[104];

			uint32_t	arb_timeout = (src[109] << 24) | (src[108] << 16) | (src[107] << 8) | src[106];


			dst->sensor_sn = sensor_sn;
			for (int _i = 0; _i < 30; _i++) { dst->sensor_hw_id[_i] = sensor_hw_id[_i]; }
			for (int _i = 0; _i < 3; _i++) { dst->sensor_fw_ver[_i] = sensor_fw_ver[_i]; }
			for (int _i = 0; _i < 12; _i++) { dst->sensor_fw_date[_i] = sensor_fw_date[_i]; }
			for (int _i = 0; _i < 9; _i++) { dst->sensor_fw_time[_i] = sensor_fw_time[_i]; }
			dst->sensor_calib_id = sensor_calib_id;

			dst->capture_mode = capture_mode;
			dst->capture_row = capture_row;
			dst->capture_period = capture_period;
			dst->capture_shutter[0] = capture_shutter[0];
			dst->capture_shutter[1] = capture_shutter[1];
			dst->capture_shutter[2] = capture_shutter[2];
			dst->capture_shutter[3] = capture_shutter[3];
			dst->capture_shutter[4] = capture_shutter[4];
			dst->capture_limit[0] = capture_limit[0];
			dst->capture_limit[1] = capture_limit[1];

			dst->data_output = data_output;
			dst->data_baud = data_baud;
			dst->data_sensor_ip[0] = data_sensor_ip[0];
			dst->data_sensor_ip[1] = data_sensor_ip[1];
			dst->data_sensor_ip[2] = data_sensor_ip[2];
			dst->data_sensor_ip[3] = data_sensor_ip[3];
			dst->data_dest_ip[0] = data_dest_ip[0];
			dst->data_dest_ip[1] = data_dest_ip[1];
			dst->data_dest_ip[2] = data_dest_ip[2];
			dst->data_dest_ip[3] = data_dest_ip[3];
			dst->data_subnet[0] = data_subnet[0];
			dst->data_subnet[1] = data_subnet[1];
			dst->data_subnet[2] = data_subnet[2];
			dst->data_subnet[3] = data_subnet[3];
			dst->data_gateway[0] = data_gateway[0];
			dst->data_gateway[1] = data_gateway[1];
			dst->data_gateway[2] = data_gateway[2];
			dst->data_gateway[3] = data_gateway[3];
			dst->data_port = data_port;

			dst->sync = sync;
			dst->sync_delay = sync_delay;

			dst->arb = arb;
			dst->arb_timeout = arb_timeout;

			dst->lock = lock;
		}

		static void encode_info_v2(info_v2_t* src, uint8_t* dst) {
			dst[0] = src->sensor_sn % 256;
			dst[1] = src->sensor_sn / 256;
			for (int _i = 0; _i < (30 + 3 + 12 + 9); _i++) { dst[2 + _i] = 0; }	// Read only
			dst[56] = 0;	// Read only
			dst[57] = 0;	// Read only
			dst[58] = 0;	// Read only
			dst[59] = 0;	// Read only
			for (int _i = 0; _i < (3 + 3 + 3); _i++) { dst[60 + _i] = 0; }	// Read only
			dst[69] = 0;	// Read only
			dst[70] = 0;	// Read only

			dst[71] = src->capture_mode;
			dst[72] = src->capture_row;
			dst[73] = (src->capture_shutter[0] >> 0) & 0xFF;
			dst[74] = (src->capture_shutter[0] >> 8) & 0xFF;
			dst[75] = (src->capture_shutter[1] >> 0) & 0xFF;
			dst[76] = (src->capture_shutter[1] >> 8) & 0xFF;
			dst[77] = (src->capture_shutter[2] >> 0) & 0xFF;
			dst[78] = (src->capture_shutter[2] >> 8) & 0xFF;
			dst[79] = (src->capture_shutter[3] >> 0) & 0xFF;
			dst[80] = (src->capture_shutter[3] >> 8) & 0xFF;
			dst[81] = (src->capture_shutter[4] >> 0) & 0xFF;
			dst[82] = (src->capture_shutter[4] >> 8) & 0xFF;
			dst[83] = (src->capture_limit[0] >> 0) & 0xFF;
			dst[84] = (src->capture_limit[0] >> 8) & 0xFF;
			dst[85] = (src->capture_limit[1] >> 0) & 0xFF;
			dst[86] = (src->capture_limit[1] >> 8) & 0xFF;
			dst[87] = (src->capture_period_us >> 0) & 0xFF;
			dst[88] = (src->capture_period_us >> 8) & 0xFF;
			dst[89] = (src->capture_period_us >> 16) & 0xFF;
			dst[90] = (src->capture_period_us >> 24) & 0xFF;
			dst[91] = src->capture_seq;

			dst[92] = src->data_output;
			dst[93] = (src->data_baud >> 0) & 0xFF;
			dst[94] = (src->data_baud >> 8) & 0xFF;
			dst[95] = (src->data_baud >> 16) & 0xFF;
			dst[96] = (src->data_baud >> 24) & 0xFF;
			dst[97] = src->data_sensor_ip[0];
			dst[98] = src->data_sensor_ip[1];
			dst[99] = src->data_sensor_ip[2];
			dst[100] = src->data_sensor_ip[3];
			dst[101] = src->data_dest_ip[0];
			dst[102] = src->data_dest_ip[1];
			dst[103] = src->data_dest_ip[2];
			dst[104] = src->data_dest_ip[3];
			dst[105] = src->data_subnet[0];
			dst[106] = src->data_subnet[1];
			dst[107] = src->data_subnet[2];
			dst[108] = src->data_subnet[3];
			dst[109] = src->data_gateway[0];
			dst[110] = src->data_gateway[1];
			dst[111] = src->data_gateway[2];
			dst[112] = src->data_gateway[3];
			dst[113] = (src->data_port >> 0) & 0xFF;
			dst[114] = (src->data_port >> 8) & 0xFF;
			dst[115] = src->data_mac_addr[0];
			dst[116] = src->data_mac_addr[1];
			dst[117] = src->data_mac_addr[2];
			dst[118] = src->data_mac_addr[3];
			dst[119] = src->data_mac_addr[4];
			dst[120] = src->data_mac_addr[5];

			dst[121] = src->sync;
			dst[122] = (src->sync_trig_delay_us >> 0) & 0xFF;
			dst[123] = (src->sync_trig_delay_us >> 8) & 0xFF;
			dst[124] = (src->sync_trig_delay_us >> 16) & 0xFF;
			dst[125] = (src->sync_trig_delay_us >> 24) & 0xFF;
			dst[126] = (src->sync_ill_delay_us[0] >> 0) & 0xFF;
			dst[127] = (src->sync_ill_delay_us[0] >> 8) & 0xFF;
			dst[128] = (src->sync_ill_delay_us[1] >> 0) & 0xFF;
			dst[129] = (src->sync_ill_delay_us[1] >> 8) & 0xFF;
			dst[130] = (src->sync_ill_delay_us[2] >> 0) & 0xFF;
			dst[131] = (src->sync_ill_delay_us[2] >> 8) & 0xFF;
			dst[132] = (src->sync_ill_delay_us[3] >> 0) & 0xFF;
			dst[133] = (src->sync_ill_delay_us[3] >> 8) & 0xFF;
			dst[134] = (src->sync_ill_delay_us[4] >> 0) & 0xFF;
			dst[135] = (src->sync_ill_delay_us[4] >> 8) & 0xFF;
			dst[136] = (src->sync_ill_delay_us[5] >> 0) & 0xFF;
			dst[137] = (src->sync_ill_delay_us[5] >> 8) & 0xFF;
			dst[138] = (src->sync_ill_delay_us[6] >> 0) & 0xFF;
			dst[139] = (src->sync_ill_delay_us[6] >> 8) & 0xFF;
			dst[140] = (src->sync_ill_delay_us[7] >> 0) & 0xFF;
			dst[141] = (src->sync_ill_delay_us[7] >> 8) & 0xFF;
			dst[142] = (src->sync_ill_delay_us[8] >> 0) & 0xFF;
			dst[143] = (src->sync_ill_delay_us[8] >> 8) & 0xFF;
			dst[144] = (src->sync_ill_delay_us[9] >> 0) & 0xFF;
			dst[145] = (src->sync_ill_delay_us[9] >> 8) & 0xFF;
			dst[146] = (src->sync_ill_delay_us[10] >> 0) & 0xFF;
			dst[147] = (src->sync_ill_delay_us[10] >> 8) & 0xFF;
			dst[148] = (src->sync_ill_delay_us[11] >> 0) & 0xFF;
			dst[149] = (src->sync_ill_delay_us[11] >> 8) & 0xFF;
			dst[150] = (src->sync_ill_delay_us[12] >> 0) & 0xFF;
			dst[151] = (src->sync_ill_delay_us[12] >> 8) & 0xFF;
			dst[152] = (src->sync_ill_delay_us[13] >> 0) & 0xFF;
			dst[153] = (src->sync_ill_delay_us[13] >> 8) & 0xFF;
			dst[154] = (src->sync_ill_delay_us[14] >> 0) & 0xFF;
			dst[155] = (src->sync_ill_delay_us[14] >> 8) & 0xFF;
			dst[156] = src->sync_trig_trim_us;
			dst[157] = src->sync_ill_trim_us;
			dst[158] = (src->sync_output_delay_us >> 0) & 0xFF;
			dst[159] = (src->sync_output_delay_us >> 8) & 0xFF;

			dst[160] = src->arb;
			dst[161] = (src->arb_timeout >> 0) & 0xFF;
			dst[162] = (src->arb_timeout >> 8) & 0xFF;
			dst[163] = (src->arb_timeout >> 16) & 0xFF;
			dst[164] = (src->arb_timeout >> 24) & 0xFF;

			dst[165] = 0;	// This flag will not be written with info packet
		}

		static void decode_info_v2(uint8_t* src, info_v2_t* dst) {
			uint16_t	sensor_sn = (src[1] << 8) | src[0];
			uint8_t		sensor_hw_id[30] = { src[2], src[3], src[4], src[5], src[6], src[7], src[8], src[9],
											src[10], src[11], src[12], src[13], src[14], src[15], src[16], src[17],
											src[18], src[19], src[20], src[21], src[22], src[23], src[24], src[25],
											src[26], src[27], src[28], src[29], src[30], src[31] };
			uint8_t		sensor_fw_ver[3] = { src[32], src[33], src[34] };
			uint8_t		sensor_fw_date[12] = { src[35], src[36], src[37], src[38],
											src[39], src[40], src[41], src[42],
											src[43], src[44], src[45], src[46] };
			uint8_t		sensor_fw_time[9] = { src[47], src[48], src[49], src[50],
											src[51], src[52], src[53], src[54], src[55] };
			uint32_t	sensor_calib_id = (src[59] << 24) | (src[58] << 16) | (src[57] << 8) | src[56];
			uint8_t		sensor_fw0_ver[3] = { src[60], src[61], src[62] };
			uint8_t		sensor_fw1_ver[3] = { src[63], src[64], src[65] };
			uint8_t		sensor_fw2_ver[3] = { src[66], src[67], src[68] };
			uint8_t		sensor_model_id = src[69];
			uint8_t		sensor_boot_ctrl = src[70];

			uint8_t		capture_mode = src[71];
			uint8_t		capture_row = src[72];
			uint16_t	capture_shutter[5] = { (uint16_t)((src[74] << 8) | src[73]),
											(uint16_t)((src[76] << 8) | src[75]),
											(uint16_t)((src[78] << 8) | src[77]),
											(uint16_t)((src[80] << 8) | src[79]),
											(uint16_t)((src[82] << 8) | src[81]) };
			uint16_t	capture_limit[2] = { (uint16_t)((src[84] << 8) | src[83]),
											(uint16_t)((src[86] << 8) | src[85]) };
			uint32_t	capture_period_us = (uint32_t)((src[90] << 24) | (src[89] << 16) | (src[88] << 8) | src[87]);
			uint8_t		capture_seq = src[91];

			uint8_t		data_output = src[92];
			uint32_t	data_baud = (src[96] << 24) | (src[95] << 16) | (src[94] << 8) | src[93];
			uint8_t		data_sensor_ip[4] = { src[97], src[98], src[99], src[100] };
			uint8_t		data_dest_ip[4] = { src[101], src[102], src[103], src[104] };
			uint8_t		data_subnet[4] = { src[105], src[106], src[107], src[108] };
			uint8_t		data_gateway[4] = { src[109], src[110], src[111], src[112] };
			uint16_t	data_port = (src[114] << 8) | src[113];
			uint8_t		data_mac_addr[6] = { src[115], src[116], src[117], src[118], src[119], src[120] };

			uint8_t		sync = src[121];
			uint32_t	sync_trig_delay_us = (uint32_t)((src[125] << 24) | (src[124] << 16) | (src[123] << 8) | src[122]);
			uint16_t	sync_ill_delay_us[15] = { (uint16_t)((src[127] << 8) | src[126]),
											(uint16_t)((src[129] << 8) | src[128]),
											(uint16_t)((src[131] << 8) | src[130]),
											(uint16_t)((src[133] << 8) | src[132]),
											(uint16_t)((src[135] << 8) | src[134]),
											(uint16_t)((src[137] << 8) | src[136]),
											(uint16_t)((src[139] << 8) | src[138]),
											(uint16_t)((src[141] << 8) | src[140]),
											(uint16_t)((src[143] << 8) | src[142]),
											(uint16_t)((src[145] << 8) | src[144]),
											(uint16_t)((src[147] << 8) | src[146]),
											(uint16_t)((src[149] << 8) | src[148]),
											(uint16_t)((src[151] << 8) | src[150]),
											(uint16_t)((src[153] << 8) | src[152]),
											(uint16_t)((src[155] << 8) | src[154]) };
			uint8_t		sync_trig_trim_us = src[156];
			uint8_t		sync_ill_trim_us = src[157];
			uint16_t	sync_output_delay_us = (uint16_t)((src[159] << 8) | src[158]);

			uint8_t		arb = src[160];
			uint32_t	arb_timeout = (src[164] << 24) | (src[163] << 16) | (src[162] << 8) | src[161];
			uint8_t		lock = src[165];


			dst->sensor_sn = sensor_sn;
			for (int _i = 0; _i < 30; _i++) { dst->sensor_hw_id[_i] = sensor_hw_id[_i]; }
			for (int _i = 0; _i < 3; _i++) { dst->sensor_fw_ver[_i] = sensor_fw_ver[_i]; }
			for (int _i = 0; _i < 12; _i++) { dst->sensor_fw_date[_i] = sensor_fw_date[_i]; }
			for (int _i = 0; _i < 9; _i++) { dst->sensor_fw_time[_i] = sensor_fw_time[_i]; }
			dst->sensor_calib_id = sensor_calib_id;
			for (int _i = 0; _i < 3; _i++) { dst->sensor_fw0_ver[_i] = sensor_fw0_ver[_i]; }
			for (int _i = 0; _i < 3; _i++) { dst->sensor_fw1_ver[_i] = sensor_fw1_ver[_i]; }
			for (int _i = 0; _i < 3; _i++) { dst->sensor_fw2_ver[_i] = sensor_fw2_ver[_i]; }
			dst->sensor_boot_mode = sensor_boot_ctrl;


			dst->capture_mode = capture_mode;
			dst->capture_row = capture_row;
			dst->capture_shutter[0] = capture_shutter[0];
			dst->capture_shutter[1] = capture_shutter[1];
			dst->capture_shutter[2] = capture_shutter[2];
			dst->capture_shutter[3] = capture_shutter[3];
			dst->capture_shutter[4] = capture_shutter[4];
			dst->capture_limit[0] = capture_limit[0];
			dst->capture_limit[1] = capture_limit[1];
			dst->capture_period_us = capture_period_us;
			dst->capture_seq = capture_seq;

			dst->data_output = data_output;
			dst->data_baud = data_baud;
			dst->data_sensor_ip[0] = data_sensor_ip[0];
			dst->data_sensor_ip[1] = data_sensor_ip[1];
			dst->data_sensor_ip[2] = data_sensor_ip[2];
			dst->data_sensor_ip[3] = data_sensor_ip[3];
			dst->data_dest_ip[0] = data_dest_ip[0];
			dst->data_dest_ip[1] = data_dest_ip[1];
			dst->data_dest_ip[2] = data_dest_ip[2];
			dst->data_dest_ip[3] = data_dest_ip[3];
			dst->data_subnet[0] = data_subnet[0];
			dst->data_subnet[1] = data_subnet[1];
			dst->data_subnet[2] = data_subnet[2];
			dst->data_subnet[3] = data_subnet[3];
			dst->data_gateway[0] = data_gateway[0];
			dst->data_gateway[1] = data_gateway[1];
			dst->data_gateway[2] = data_gateway[2];
			dst->data_gateway[3] = data_gateway[3];
			dst->data_port = data_port;
			dst->data_mac_addr[0] = data_mac_addr[0];
			dst->data_mac_addr[1] = data_mac_addr[1];
			dst->data_mac_addr[2] = data_mac_addr[2];
			dst->data_mac_addr[3] = data_mac_addr[3];
			dst->data_mac_addr[4] = data_mac_addr[4];
			dst->data_mac_addr[5] = data_mac_addr[5];

			dst->sync = sync;
			dst->sync_trig_delay_us = sync_trig_delay_us;
			dst->sync_ill_delay_us[0] = sync_ill_delay_us[0];
			dst->sync_ill_delay_us[1] = sync_ill_delay_us[1];
			dst->sync_ill_delay_us[2] = sync_ill_delay_us[2];
			dst->sync_ill_delay_us[3] = sync_ill_delay_us[3];
			dst->sync_ill_delay_us[4] = sync_ill_delay_us[4];
			dst->sync_ill_delay_us[5] = sync_ill_delay_us[5];
			dst->sync_ill_delay_us[6] = sync_ill_delay_us[6];
			dst->sync_ill_delay_us[7] = sync_ill_delay_us[7];
			dst->sync_ill_delay_us[8] = sync_ill_delay_us[8];
			dst->sync_ill_delay_us[9] = sync_ill_delay_us[9];
			dst->sync_ill_delay_us[10] = sync_ill_delay_us[10];
			dst->sync_ill_delay_us[11] = sync_ill_delay_us[11];
			dst->sync_ill_delay_us[12] = sync_ill_delay_us[12];
			dst->sync_ill_delay_us[13] = sync_ill_delay_us[13];
			dst->sync_ill_delay_us[14] = sync_ill_delay_us[14];
			dst->sync_trig_trim_us = sync_trig_trim_us;
			dst->sync_ill_trim_us = sync_ill_trim_us;
			dst->sync_output_delay_us = sync_output_delay_us;

			dst->arb = arb;
			dst->arb_timeout = arb_timeout;
			dst->lock = lock;
		}

		static void encode_cmd(cmd_t* src, uint8_t* dst) {
			dst[0] = (src->cmd_id >> 0) & 0xFF;
			dst[1] = (src->cmd_id >> 8) & 0xFF;
			dst[2] = (src->cmd_msg >> 0) & 0xFF;
			dst[3] = (src->cmd_msg >> 8) & 0xFF;
		}

		static void decode_ack(uint8_t* src, ack_t* dst) {
			dst->ack_id = (src[1] << 8) | src[0];
			for (int _i = 0; _i < 32; _i++) { dst->ack_msg[_i] = src[2 + _i]; }
		}

		static void encode_flash_block(flash_block_t* src, uint8_t* dst) {
			for (int _i = 0; _i < 30; _i++) { dst[_i] = src->hw_id[_i]; }
			dst[30] = src->type;
			dst[31] = src->size;
			dst[32] = src->offset;
			dst[33] = src->ver[0];
			dst[34] = src->ver[1];
			dst[35] = src->ver[2];
			for (int _i = 0; _i < 1024; _i++) { dst[36 + _i] = src->bin[_i]; }
			dst[1060] = (src->bin_crc16 >> 0) & 0xFF;
			dst[1061] = (src->bin_crc16 >> 8) & 0xFF;
		}

		static void decode_flash_block(uint8_t* src, flash_block_t* dst) {
			for (int _i = 0; _i < 30; _i++) { dst->hw_id[_i] = src[_i]; }
			dst->type = src[30];
			dst->size = src[31];
			dst->offset = src[32];
			dst->ver[0] = src[33];
			dst->ver[1] = src[34];
			dst->ver[2] = src[35];
			for (int _i = 0; _i < 1024; _i++) { dst->bin[_i] = src[36 + _i]; }
			dst->bin_crc16 = (src[1061] << 8) | src[1060];
		}

		static void encode_stream_status(stream_status_t* src, uint8_t* dst) {
			dst[0] = src->sensor_cnt;
			dst[1] = src->shm_idx;

			for (int _i = 0; _i < 32; _i++) {
				dst[2 + 4 * _i] = (src->sensor_sn[_i] >> 0) & 0xFF;
				dst[3 + 4 * _i] = (src->sensor_sn[_i] >> 8) & 0xFF;
				dst[4 + 4 * _i] = src->sensor_frame[_i];
				dst[5 + 4 * _i] = src->read_status[_i];
			}
		}

		static void decode_stream_status(uint8_t* src, stream_status_t* dst) {
			dst->sensor_cnt		= src[0];
			dst->shm_idx		= src[1];

			for (int _i = 0; _i < 32; _i++) {
				dst->sensor_sn[_i]		= (src[3 + 4 * _i] << 8) | src[2 + 4 * _i];
				dst->sensor_frame[_i]	= src[4 + 4 * _i];
				dst->read_status[_i]	= src[5 + 4 * _i];
			}
		}

		/*
			// About iLidar sensor time
			uint64_t	sensor_time_th;	// [ms] Sensor time in ms
			uint16_t	sensor_time_tl;	// [us] Sensor time for sub-ms

			// So, we can get the sensor time in s
			double		sensor_time = ((double)sensor_time_th + (((double)sensor_time_tl) * 0.001)) * 0.001;

			// When we need to use the precise time, we can use time in us with integer
			uint64_t	sensor_time_us = (uint64_t)(1000 * sensor_time_th) + (uint64_t)sensor_time_tl;
		*/

		static double get_sensor_time(uint64_t sensor_time_th, uint16_t sensor_time_tl) {
			return (((double)sensor_time_th + ((double)sensor_time_tl) * 0.001) * 0.001);
		}

		static double get_sensor_time(status_full_t * status) {
			return (((double)status->sensor_time_th + ((double)status->sensor_time_tl) * 0.001) * 0.001);
		}

		static double get_sensor_time(status_t* status) {
			return (((double)status->sensor_time_th + ((double)status->sensor_time_tl) * 0.001) * 0.001);
		}

		static double get_sensor_time(sync_ack_t* sync_ack) {
			return (((double)sync_ack->sensor_time_th + ((double)sync_ack->sensor_time_tl) * 0.001) * 0.001);
		}

		static uint64_t get_sensor_time_in_us(uint64_t sensor_time_th, uint16_t sensor_time_tl) {
			return ((uint64_t)(1000 * sensor_time_th) + (uint64_t)sensor_time_tl);
		}

		static uint64_t get_sensor_time_in_us(status_full_t* status) {
			return ((uint64_t)(1000 * status->sensor_time_th) + (uint64_t)status->sensor_time_tl);
		}

		static uint64_t get_sensor_time_in_us(status_t* status) {
			return ((uint64_t)(1000 * status->sensor_time_th) + (uint64_t)status->sensor_time_tl);
		}

		static uint64_t get_sensor_time_in_us(sync_ack_t* sync_ack) {
			return ((uint64_t)(1000 * sync_ack->sensor_time_th) + (uint64_t)sync_ack->sensor_time_tl);
		}

		/*
			// About iLidar sensor CRC16
			CRC-16 CCITT standard is used
		*/

		constexpr uint16_t CRC16Table[] = {
			0x0000,	0x1021,	0x2042,	0x3063,	0x4084,	0x50a5,	0x60c6,	0x70e7,
			0x8108,	0x9129,	0xa14a,	0xb16b,	0xc18c,	0xd1ad,	0xe1ce,	0xf1ef,
			0x1231,	0x0210,	0x3273,	0x2252,	0x52b5,	0x4294,	0x72f7,	0x62d6,
			0x9339,	0x8318,	0xb37b,	0xa35a,	0xd3bd,	0xc39c,	0xf3ff,	0xe3de,
			0x2462,	0x3443,	0x0420,	0x1401,	0x64e6,	0x74c7,	0x44a4,	0x5485,
			0xa56a,	0xb54b,	0x8528,	0x9509,	0xe5ee,	0xf5cf,	0xc5ac,	0xd58d,
			0x3653,	0x2672,	0x1611,	0x0630,	0x76d7,	0x66f6,	0x5695,	0x46b4,
			0xb75b,	0xa77a,	0x9719,	0x8738,	0xf7df,	0xe7fe,	0xd79d,	0xc7bc,
			0x48c4,	0x58e5,	0x6886,	0x78a7,	0x0840,	0x1861,	0x2802,	0x3823,
			0xc9cc,	0xd9ed,	0xe98e,	0xf9af,	0x8948,	0x9969,	0xa90a,	0xb92b,
			0x5af5,	0x4ad4,	0x7ab7,	0x6a96,	0x1a71,	0x0a50,	0x3a33,	0x2a12,
			0xdbfd,	0xcbdc,	0xfbbf,	0xeb9e,	0x9b79,	0x8b58,	0xbb3b,	0xab1a,
			0x6ca6,	0x7c87,	0x4ce4,	0x5cc5,	0x2c22,	0x3c03,	0x0c60,	0x1c41,
			0xedae,	0xfd8f,	0xcdec,	0xddcd,	0xad2a,	0xbd0b,	0x8d68,	0x9d49,
			0x7e97,	0x6eb6,	0x5ed5,	0x4ef4,	0x3e13,	0x2e32,	0x1e51,	0x0e70,
			0xff9f,	0xefbe,	0xdfdd,	0xcffc,	0xbf1b,	0xaf3a,	0x9f59,	0x8f78,
			0x9188,	0x81a9,	0xb1ca,	0xa1eb,	0xd10c,	0xc12d,	0xf14e,	0xe16f,
			0x1080,	0x00a1,	0x30c2,	0x20e3,	0x5004,	0x4025,	0x7046,	0x6067,
			0x83b9,	0x9398,	0xa3fb,	0xb3da,	0xc33d,	0xd31c,	0xe37f,	0xf35e,
			0x02b1,	0x1290,	0x22f3,	0x32d2,	0x4235,	0x5214,	0x6277,	0x7256,
			0xb5ea,	0xa5cb,	0x95a8,	0x8589,	0xf56e,	0xe54f,	0xd52c,	0xc50d,
			0x34e2,	0x24c3,	0x14a0,	0x0481,	0x7466,	0x6447,	0x5424,	0x4405,
			0xa7db,	0xb7fa,	0x8799,	0x97b8,	0xe75f,	0xf77e,	0xc71d,	0xd73c,
			0x26d3,	0x36f2,	0x0691,	0x16b0,	0x6657,	0x7676,	0x4615,	0x5634,
			0xd94c,	0xc96d,	0xf90e,	0xe92f,	0x99c8,	0x89e9,	0xb98a,	0xa9ab,
			0x5844,	0x4865,	0x7806,	0x6827,	0x18c0,	0x08e1,	0x3882,	0x28a3,
			0xcb7d,	0xdb5c,	0xeb3f,	0xfb1e,	0x8bf9,	0x9bd8,	0xabbb,	0xbb9a,
			0x4a75,	0x5a54,	0x6a37,	0x7a16,	0x0af1,	0x1ad0,	0x2ab3,	0x3a92,
			0xfd2e,	0xed0f,	0xdd6c,	0xcd4d,	0xbdaa,	0xad8b,	0x9de8,	0x8dc9,
			0x7c26,	0x6c07,	0x5c64,	0x4c45,	0x3ca2,	0x2c83,	0x1ce0,	0x0cc1,
			0xef1f,	0xff3e,	0xcf5d,	0xdf7c,	0xaf9b,	0xbfba,	0x8fd9,	0x9ff8,
			0x6e17,	0x7e36,	0x4e55,	0x5e74,	0x2e93,	0x3eb2,	0x0ed1,	0x1ef0
		};

		static uint16_t get_CRC16(const uint8_t* packet, int length) {
			// use CRC-16 CCITT standard with initial 0xFFFF
			uint16_t crc = 0xFFFF;
			int i;
			for (i = 0; i < length; i++) {
				crc = (crc << 8) ^ CRC16Table[(crc >> 8) ^ packet[i]];
				crc &= 0xFFFF;
			}
			return crc;
		}
	}
}

