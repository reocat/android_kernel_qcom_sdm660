#ifndef __DRV2605L_H__
#define __DRV2605L_H__
/*
** =============================================================================
** Copyright (c)2014  Texas Instruments Inc.
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
** File:
**     drv2605l.h
**
** Description:
**     Header file for drv2605l.c
**
** =============================================================================
*/

//#include <linux/switch.h>
#include <linux/regmap.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
//#include <../../../drivers/staging/android/timed_output.h>
#include <linux/hrtimer.h>
//#include <linux/wakelock.h>
#include <linux/mutex.h>
#include <linux/cdev.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif

#define HAPTICS_DEVICE_NAME "drv2605L"

#define LIBRARY_A 0x01
#define LIBRARY_B 0x02
#define LIBRARY_C 0x03
#define LIBRARY_D 0x04
#define LIBRARY_E 0x05
#define LIBRARY_F 0x06

#define GO_BIT_POLL_INTERVAL    15
#define STANDBY_WAKE_DELAY      1
#define WAKE_STANDBY_DELAY      3

/* Commands */
#define HAPTIC_CMDID_PLAY_SINGLE_EFFECT     0x01
#define HAPTIC_CMDID_PLAY_EFFECT_SEQUENCE   0x02
#define HAPTIC_CMDID_PLAY_TIMED_EFFECT      0x03
#define HAPTIC_CMDID_GET_DEV_ID             0x04
#define HAPTIC_CMDID_RUN_DIAG               0x05
#define HAPTIC_CMDID_AUDIOHAPTIC_ENABLE     0x06
#define HAPTIC_CMDID_AUDIOHAPTIC_DISABLE    0x07
#define HAPTIC_CMDID_AUDIOHAPTIC_GETSTATUS  0x08

#define HAPTIC_CMDID_REG_WRITE  	0x09
#define HAPTIC_CMDID_REG_READ   	0x0a
#define HAPTIC_CMDID_REG_SETBIT  	0x0b

#define HAPTIC_CMDID_PATTERN_RTP      0x0c
#define HAPTIC_CMDID_RTP_SEQUENCE	  0x0d
#define HAPTIC_CMDID_GET_EFFECT_COUNT		0x10
#define HAPTIC_CMDID_UPDATE_FIRMWARE		0x11
#define HAPTIC_CMDID_READ_FIRMWARE			0x12
#define HAPTIC_CMDID_STOP                   0xFF

/*
** Go
*/
#define GO_REG 	0x0C
#define GO_MASK	0x01
#define GO     	0x01
#define STOP   	0x00

/*
** Status
*/
#define STATUS_REG          0x00
#define STATUS_DEFAULT      0x00

#define DIAG_RESULT_MASK    (1 << 3)
#define AUTO_CAL_PASSED     (0 << 3)
#define AUTO_CAL_FAILED     (1 << 3)
#define DIAG_GOOD           (0 << 3)
#define DIAG_BAD            (1 << 3)

#define DEV_ID_MASK (7 << 5)

#define DRV2605_VER_1DOT1 (3 << 5)
#define DRV2605_VER_1DOT0 (5 << 5)
#define DRV2604 (4 << 5)
#define DRV2604L (6 << 5)
#define DRV2605L (7 << 5)

/*
** Mode
*/
#define MODE_REG            0x01
#define MODE_STANDBY_MASK           0x40
#define MODE_STANDBY        0x40
#define MODE_RESET                  0x80
#define DRV2605_MODE_MASK           0x07
#define MODE_INTERNAL_TRIGGER       0
#define MODE_EXTERNAL_TRIGGER_EDGE  1
#define MODE_EXTERNAL_TRIGGER_LEVEL 2
#define MODE_PWM_OR_ANALOG_INPUT    3
#define MODE_AUDIOHAPTIC            4
#define MODE_REAL_TIME_PLAYBACK     5
#define MODE_DIAGNOSTICS            6
#define AUTO_CALIBRATION            7

/*
** Real Time Playback
*/
#define REAL_TIME_PLAYBACK_REG		0x02

/*
** Library Selection
*/
#define LIBRARY_SELECTION_REG       0x03
#define LIBRARY_SELECTION_DEFAULT   0x00
#define LIBRARY_SELECTION_HIZ_MASK          0x10
#define LIBRARY_SELECTION_HIZ_EN            1
#define LIBRARY_SELECTION_HIZ_DIS           0

/*
** Waveform Sequencer
*/
#define WAVEFORM_SEQUENCER_REG      0x04
#define WAVEFORM_SEQUENCER_REG2     0x05
#define WAVEFORM_SEQUENCER_REG3     0x06
#define WAVEFORM_SEQUENCER_REG4     0x07
#define WAVEFORM_SEQUENCER_REG5     0x08
#define WAVEFORM_SEQUENCER_REG6     0x09
#define WAVEFORM_SEQUENCER_REG7     0x0A
#define WAVEFORM_SEQUENCER_REG8     0x0B
#define WAVEFORM_SEQUENCER_MAX      8
#define WAVEFORM_SEQUENCER_DEFAULT  0x00

/*
** OverDrive Time Offset
*/
#define OVERDRIVE_TIME_OFFSET_REG  0x0D

/*
** Sustain Time Offset, postive
*/
#define SUSTAIN_TIME_OFFSET_POS_REG 0x0E

/*
** Sustain Time Offset, negative
*/
#define SUSTAIN_TIME_OFFSET_NEG_REG 0x0F

/*
** Brake Time Offset
*/
#define BRAKE_TIME_OFFSET_REG       0x10

/*
** Audio to Haptics Control
*/
#define AUDIO_HAPTICS_CONTROL_REG   0x11

#define AUDIO_HAPTICS_RECT_10MS     (0 << 2)
#define AUDIO_HAPTICS_RECT_20MS     (1 << 2)
#define AUDIO_HAPTICS_RECT_30MS     (2 << 2)
#define AUDIO_HAPTICS_RECT_40MS     (3 << 2)

#define AUDIO_HAPTICS_FILTER_100HZ  0
#define AUDIO_HAPTICS_FILTER_125HZ  1
#define AUDIO_HAPTICS_FILTER_150HZ  2
#define AUDIO_HAPTICS_FILTER_200HZ  3

/*
** Audio to Haptics Minimum Input Level
*/
#define AUDIO_HAPTICS_MIN_INPUT_REG 0x12

/*
** Audio to Haptics Maximum Input Level
*/
#define AUDIO_HAPTICS_MAX_INPUT_REG 0x13

/*
** Audio to Haptics Minimum Output Drive
*/
#define AUDIO_HAPTICS_MIN_OUTPUT_REG 0x14

/*
** Audio to Haptics Maximum Output Drive
*/
#define AUDIO_HAPTICS_MAX_OUTPUT_REG 0x15

/*
** Rated Voltage
*/
#define RATED_VOLTAGE_REG           0x16

/*
** Overdrive Clamp Voltage
*/
#define OVERDRIVE_CLAMP_VOLTAGE_REG 0x17

/*
** Auto Calibrationi Compensation Result
*/
#define AUTO_CALI_RESULT_REG        0x18

/*
** Auto Calibration Back-EMF Result
*/
#define AUTO_CALI_BACK_EMF_RESULT_REG 0x19

/*
** Feedback Control
*/
#define FEEDBACK_CONTROL_REG        0x1A
#define FEEDBACK_CONTROL_DEVICE_TYPE_MASK        0x80
#define FEEDBACK_CONTROL_BEMF_ERM_GAIN0 0 // 0.33x
#define FEEDBACK_CONTROL_BEMF_ERM_GAIN1 1 // 1.0x
#define FEEDBACK_CONTROL_BEMF_ERM_GAIN2 2 // 1.8x
#define FEEDBACK_CONTROL_BEMF_ERM_GAIN3 3 // 4.0x

#define FEEDBACK_CONTROL_BEMF_LRA_GAIN0 0 // 5x
#define FEEDBACK_CONTROL_BEMF_LRA_GAIN1 1 // 10x
#define FEEDBACK_CONTROL_BEMF_LRA_GAIN2 2 // 20x
#define FEEDBACK_CONTROL_BEMF_LRA_GAIN3 3 // 30x

#define FEEDBACK_CONTROL_LOOP_GAIN_MASK        0x0C
#define LOOP_RESPONSE_SLOW      (0 << 2)
#define LOOP_RESPONSE_MEDIUM    (1 << 2) // default
#define LOOP_RESPONSE_FAST      (2 << 2)
#define LOOP_RESPONSE_VERY_FAST (3 << 2)

#define FEEDBACK_CONTROL_FB_BRAKE_MASK        0x70
#define FB_BRAKE_FACTOR_1X   (0 << 4) // 1x
#define FB_BRAKE_FACTOR_2X   (1 << 4) // 2x
#define FB_BRAKE_FACTOR_3X   (2 << 4) // 3x (default)
#define FB_BRAKE_FACTOR_4X   (3 << 4) // 4x
#define FB_BRAKE_FACTOR_6X   (4 << 4) // 6x
#define FB_BRAKE_FACTOR_8X   (5 << 4) // 8x
#define FB_BRAKE_FACTOR_16X  (6 << 4) // 16x
#define FB_BRAKE_DISABLED    (7 << 4)

#define FEEDBACK_CONTROL_MODE_ERM 0 // default
#define FEEDBACK_CONTROL_MODE_LRA (1 << 7)

/*
** Control1
*/
#define Control1_REG            	0x1B
#define Control1_REG_AC_COUPLE_MASK	0x20
#define Control1_REG_DRIVE_TIME_MASK	0x1f

#define STARTUP_BOOST_ENABLED   (1 << 7)
#define STARTUP_BOOST_DISABLED  (0 << 7) // default
#define AC_COUPLE_ENABLED       (1 << 5)
#define AC_COUPLE_DISABLED      (0 << 5) // default

#define DEFAULT_DRIVE_TIME      0x13
#define AUDIOHAPTIC_DRIVE_TIME  0x13

/*
** Control2
*/
#define Control2_REG            0x1C
#define Control2_REG_BIDIR_INPUT_MASK   0x80

#define	BIDIR_INPUT_UNIDIRECTIONAL	(0<<7)
#define	BIDIR_INPUT_BIDIRECTIONAL	(1<<7)
#define IDISS_TIME_MASK         0x03
#define IDISS_TIME_VERY_SHORT   0
#define IDISS_TIME_SHORT        1
#define IDISS_TIME_MEDIUM       2 // default
#define IDISS_TIME_LONG         3

#define BLANKING_TIME_MASK          0x0C
#define BLANKING_TIME_VERY_SHORT    (0 << 2)
#define BLANKING_TIME_SHORT         (1 << 2)
#define BLANKING_TIME_MEDIUM        (2 << 2) // default
#define BLANKING_TIME_VERY_LONG     (3 << 2)

#define AUTO_RES_SAMPLE_TIME_MASK	0x30
#define AUTO_RES_SAMPLE_TIME_150us	(0 << 4)
#define AUTO_RES_SAMPLE_TIME_200us  (1 << 4)
#define AUTO_RES_SAMPLE_TIME_250us  (2 << 4) // default
#define AUTO_RES_SAMPLE_TIME_300us  (3 << 4)

#define SOFT_BRAKE_MASK            0x40

#define BIDIR_INPUT_MASK           0x80
#define UNIDIRECT_INPUT            (0 << 7)
#define BRAKE_STABLIZER   (1<<6)
#define BIDIRECT_INPUT             (1 << 7) // default

/*
** Control3
*/
#define Control3_REG 0x1D
#define Control3_REG_LOOP_MASK		0x21
#define Control3_REG_PWMANALOG_MASK	0x02
#define Control3_REG_FORMAT_MASK	0x08
#define INPUT_PWM               (0 << 1) // default
#define INPUT_ANALOG            (1 << 1)
#define ERM_OpenLoop_Enabled    (1 << 5)
#define ERM_OpenLoop_Disable    (0 << 5)
#define LRA_OpenLoop_Enabled    (1 << 0)
#define LRA_OpenLoop_Disable    (0 << 0)
#define RTP_FORMAT_SIGNED	    (0 << 3)
#define RTP_FORMAT_UNSIGNED	    (1 << 3)
#define NG_Thresh_DISABLED      (0 << 6)
#define NG_Thresh_1             (1 << 6)
#define NG_Thresh_2             (2 << 6)
#define NG_Thresh_3             (3 << 6)

/*
** Control4
*/
#define Control4_REG 	0x1E
#define Control4_REG_OTP_MASK   0x04
#define Control4_REG_CAL_TIME_MASK 	0x30
#define AUTOCAL_TIME_150MS          (0 << 4)
#define AUTOCAL_TIME_250MS          (1 << 4)
#define AUTOCAL_TIME_500MS          (2 << 4)
#define AUTOCAL_TIME_1000MS         (3 << 4)
#define Control4_REG_ZC_DET_MASK   	0xC0
#define ZC_DET_TIME_100us          	(0 << 4)
#define ZC_DET_TIME_200us          	(1 << 4)
#define ZC_DET_TIME_300us          	(2 << 4)
#define ZC_DET_TIME_390us        	(3 << 4)

/*
** Control5
*/
#define Control5_REG 	0x1F
#define	BLANK_IDISS_MSB_MASK	0x0f
#define	BLANK_IDISS_MSB_CLEAR	0

/*
** LRA Open Loop Period
*/
#define LRA_OPENLOOP_PERIOD_REG 0x20
#define SILICON_REVISION_REG        0x3B
#define SILICON_REVISION_MASK       0x07

//reset values
#define AUDIO_HAPTICS_MIN_INPUT_VOLTAGE     0x19
#define AUDIO_HAPTICS_MAX_INPUT_VOLTAGE     0xff
#define AUDIO_HAPTICS_MIN_OUTPUT_VOLTAGE    0x19
#define AUDIO_HAPTICS_MAX_OUTPUT_VOLTAGE    0xFF

#define MAX_TIMEOUT 	10000 /* 10s */
#define	MAX_READ_BYTES	0xff

#define SW_STATE_IDLE				0x00
#define SW_STATE_AUDIO2HAPTIC			0x01
#define SW_STATE_SEQUENCE_PLAYBACK		0x02
#define SW_STATE_RTP_PLAYBACK			0x04

#define DEV_IDLE	                0 // default
#define DEV_STANDBY					1
#define DEV_READY					2

#define	WORK_IDLE					0x00
#define WORK_AUDIO2HAPTIC	      	0x05
#define WORK_RTP			      	0x06
#define WORK_CALIBRATION	      	0x07
#define WORK_VIBRATOR		      	0x08
#define	WORK_PATTERN_RTP_ON			0x09
#define WORK_PATTERN_RTP_OFF      	0x0a
#define WORK_SEQ_RTP_ON		      	0x0b
#define WORK_SEQ_RTP_OFF    	  	0x0c
#define WORK_SEQ_PLAYBACK    	  	0x0d

#define YES 1
#define NO  0
/* recommendations from data sheet */
#define		FB_BRAKE_FACTOR			FB_BRAKE_FACTOR_3X
#define		LOOP_GAIN				LOOP_RESPONSE_FAST
//#define		AUTO_CAL_TIME			AUTOCAL_TIME_1000MS
#define		AUTO_CAL_TIME			AUTOCAL_TIME_150MS
#define		AUTO_RES_SAMPLE_TIME	AUTO_RES_SAMPLE_TIME_300us
#define		BLANKING_TIME			BLANKING_TIME_SHORT
#define		IDISS_TIME				IDISS_TIME_SHORT
#define		ZC_DET_TIME				ZC_DET_TIME_100us

enum actuator_type {
	ERM,
	LRA
};

enum loop_type {
	OPEN_LOOP,
	CLOSE_LOOP
};

enum RTP_Format {
	Signed,
	Unsigned
};

enum BIDIR_Input {
	UniDirectional,
	BiDirectional
};

struct actuator_data {
	enum actuator_type device_type;
	unsigned char   g_effect_bank;
	unsigned char 	rated_vol;
	unsigned char 	over_drive_vol;
	unsigned char   LRAFreq;	
};

struct audio2haptics_data {
	unsigned char 	a2h_min_input;
	unsigned char 	a2h_max_input;
	unsigned char 	a2h_min_output;
	unsigned char 	a2h_max_output;
};

struct drv2605_platform_data {
	int				GpioEnable;
	int 			GpioTrigger;
	enum loop_type	loop; 
	enum RTP_Format RTPFormat;
	enum BIDIR_Input BIDIRInput;
	struct actuator_data actuator;
	struct audio2haptics_data a2h;
	bool support_pattern;
};

#define	MAX_RTP_SEQ		16

struct RTP_Seq{
	unsigned short RTPData[MAX_RTP_SEQ]; //RTPTime<<8||RTPAmp
	int RTPCounts;
	int RTPindex;
};

struct drv2605L_data {
	struct drv2605_platform_data PlatData;
	int	device_id;

	struct regmap *regmap;
	
	struct class* class;
	struct device* device;
	dev_t version;
	struct semaphore sem;
	struct cdev cdev;
	struct switch_dev sw_dev;
	volatile int audio_haptics_enabled;
	volatile int vibrator_is_playing;
	char ReadBuff[MAX_READ_BYTES];
	int ReadLen;
	
	int vibration_time;
	int silience_time;
	char repeat_times;
	volatile char work_mode;
	char dev_mode;
	
	struct RTP_Seq RTPSeq;
	
	int OTP;
	
    struct wake_lock wklock;
    struct hrtimer timer;
    struct mutex lock;
    struct work_struct vibrator_work;
    struct work_struct vibrator_pattern_work;
    unsigned char sequence[WAVEFORM_SEQUENCER_MAX];
    volatile int should_stop;
	struct timed_output_dev to_dev;	
#ifdef CONFIG_HAS_EARLYSUSPEND   
    struct early_suspend    early_suspend;   
#endif	
};

static void vibrator_pattern_enable_peek(struct drv2605L_data *pDrv2605Ldata);
static void vibrator_pattern_enable_peek2(struct drv2605L_data *pDrv2605Ldata);
static void vibrator_set_normal_vibration_B2N(struct drv2605L_data *pDrv2605Ldata);
int vibrator_get_pattern_value(void);
void vibrator_set_pattern_value(int value);
#endif
