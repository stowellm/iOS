//
//  Constants.h
//  Motion
//
//  Created by Mike Stowell on 9/17/14.
//  Copyright (c) 2014 iSENSE. All rights reserved.
//

#ifndef Motion_Constants_h
#define Motion_Constants_h

// NSUserDefault (preferences) constants
#define pPROJECT_ID @"curr_project_id_as_nsnumber"
#define pSAMPLE_RATE @"curr_sample_rate"
#define pRECORDING_LENGTH @"curr_recording_length"
#define pDISPLAYED_TUTORIAL @"displayed_tutorial"

// Dialog constants
#define kLOGIN_DIALOG_TAG 500
#define kLOGIN_USER_TEXT 501
#define kLOGIN_PASS_TEXT 502

#define kNAME_DIALOG_TAG 600
#define kLOCATION_DIALOG_IOS_8_AND_LATER_TAG 601
#define kLOCATION_DIALOG_IOS_7_AND_EARLIER_TAG 602

#define kVISUALIZE_DIALOG_TAG 700

#define kMENU_DIALOG_TAG 800
#define kBTN_SPLASH 1
#define kBTN_TUTORIALS 2
#define kBTN_PRESETS 3

// Earth's gravity constant
#define kGRAVITY 9.80665

// Project constants
#define kNO_PROJECT @"Not Set"

// Preferences location constant
#define kOPT_OUT_LOCATION @"user_opt_out_location"

// Default projects for production and dev
#define kDEFAULT_ACCEL_PRODUCTION 570
#define kDEFAULT_ACCEL_DEV 12
#define kDEFAULT_GPS_PRODUCTION 13
#define kDEFAULT_GPS_DEV 156
#define kDEFAULT_PROJ_PRODUCTION kDEFAULT_ACCEL_PRODUCTION
#define kDEFAULT_PROJ_DEV kDEFAULT_ACCEL_DEV

// Preset constants
#define kPRESET_GPS 0
#define kPRESET_ACCEL 1
#define kPRESET_DEFAULT 2

// Recording length
#define kREC_LENGTH_ONE_S 1
#define kREC_LENGTH_TWO_S 2
#define kREC_LENGTH_FIVE_S 5
#define kREC_LENGTH_TEN_S 10
#define kREC_LENGTH_THIRTY_S 30
#define kREC_LENGTH_ONE_M 60
#define kREC_LENGTH_TWO_M 120
#define kREC_LENGTH_FIVE_M 300
#define kREC_LENGTH_TEN_M 600
#define kREC_LENGTH_THIRTY_M 1800
#define kREC_LENGTH_ONE_H 3600
#define kREC_LENGTH_PUSH_TO_STOP -1

// Recording length strings
#define sREC_LENGTH_ONE_S @"1 s"
#define sREC_LENGTH_TWO_S @"2 s"
#define sREC_LENGTH_FIVE_S @"5 s"
#define sREC_LENGTH_TEN_S @"10 s"
#define sREC_LENGTH_THIRTY_S @"30 s"
#define sREC_LENGTH_ONE_M @"1 m"
#define sREC_LENGTH_TWO_M @"2 m"
#define sREC_LENGTH_FIVE_M @"5 m"
#define sREC_LENGTH_TEN_M @"10 m"
#define sREC_LENGTH_THIRTY_M @"30 m"
#define sREC_LENGTH_ONE_H @"1 hr"
#define sREC_LENGTH_PUSH_TO_STOP @"Push to Stop"

// Sample rate
#define kS_RATE_TWENTY_MS 0.02
#define kS_RATE_FIFTY_MS 0.05
#define kS_RATE_ONE_HUNDRED_MS 0.1
#define kS_RATE_TWO_HUNDRED_FIFTY_MS 0.25
#define kS_RATE_FIVE_HUNDRED_MS 0.5
#define kS_RATE_ONE_S 1
#define kS_RATE_TWO_S 2
#define kS_RATE_THREE_S 3
#define kS_RATE_FIVE_S 5
#define kS_RATE_TEN_S 10
#define kS_RATE_FIFTEEN_S 15
#define kS_RATE_THIRTY_S 30

// Sample rate strings
#define sS_RATE_TWENTY_MS @"Fastest"
#define sS_RATE_FIFTY_MS @"50 ms"
#define sS_RATE_ONE_HUNDRED_MS @"100 ms"
#define sS_RATE_TWO_HUNDRED_FIFTY_MS @"250 ms"
#define sS_RATE_FIVE_HUNDRED_MS @"500 ms"
#define sS_RATE_ONE_S @"1 s"
#define sS_RATE_TWO_S @"2 s"
#define sS_RATE_THREE_S @"3 s"
#define sS_RATE_FIVE_S @"5 s"
#define sS_RATE_TEN_S @"10 s"
#define sS_RATE_FIFTEEN_S @"15 s"
#define sS_RATE_THIRTY_S @"30 s"

// Default sample rate, recording length, and data set name
#define kDEFAULT_SAMPLE_RATE kS_RATE_FIFTY_MS
#define kDEFAULT_RECORDING_LENGTH kREC_LENGTH_TEN_S
#define kDEFAULT_DATA_SET_NAME @"My Data Set"

#endif
