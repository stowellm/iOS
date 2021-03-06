//
//  ISMViewController.h
//  Motion
//
//  Created by Mike Stowell on 9/9/14.
//  Copyright (c) 2014 iSENSE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>

#import "API.h"
#import "QueueUploaderView.h"
#import "CredentialManager.h"
#import "DLAVAlertViewController.h"
#import "ISMSampleRate.h"
#import "ISMRecordingLength.h"
#import "Waffle.h"
#import "DataManager.h"
#import "QueueUploadStatus.h"
#import "ISMTutorialViewController.h"
#import "GlobalColors.h"
#import "ISMPresets.h"

#define USE_DEV false

@interface ISMViewController : UIViewController
    <UIAlertViewDelegate,
    UITextFieldDelegate,
    CredentialManagerDelegate,
    ISMSampleRateDelegate,
    ISMRecordingLengthDelegate,
    CLLocationManagerDelegate,
    QueueUploaderDelegate,
    ISMPresetsDelegate>
{
    // API and DataManager
    API *api;
    DataManager *dm;

    // Label for when in dev mode
    UILabel *devLbl;
    
    // Credential Manager
    CredentialManager *credentialMgr;
    DLAVAlertView *credentialMgrAlert;
    
    // Sample rate, recording length, and data set name
    double sampleRate;
    int recordingLength;
    int countdown;
    NSString *dataSetName;

    // Recording state, timer, and sensor objects
    bool isRecording;
    NSTimer *dataRecordingTimer;
    NSTimer *recordingLengthTimer;
    CLLocationManager *locationManager;
    CMMotionManager *motionManager;

    // Data for a single run session and a corresponding mutex lock
    NSMutableArray *dataPoints;
    NSLock *dataPointsMutex;

    // Visualization URL constructed after data is uploaded
    NSString *visURL;

    // Dictionaries of sample rate and recording lengths whose key is an int/double
    // and value is the respective sample rate/recording length as a string
    NSDictionary *sampleRateStrings;
    NSDictionary *recLengthStrings;

    // UIView to display the splash screen and a boolean to track if it is displaying
    UIView *splashView;
    bool isSplashDisplaying;
}

// Queue Saver Properties
@property (nonatomic, strong) DataSaver *dataSaver;
@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;

// UI elements and click methods
@property (weak, nonatomic) IBOutlet UIBarButtonItem *menuBarBtn;
- (IBAction)menuBarBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *credentialBarBtn;
- (IBAction)credentialBarBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UILabel *xLbl;
@property (weak, nonatomic) IBOutlet UILabel *yLbl;
@property (weak, nonatomic) IBOutlet UILabel *zLbl;

@property (weak, nonatomic) IBOutlet UIButton *sampleRateBtn;
@property (weak, nonatomic) IBOutlet UIButton *recordingLengthBtn;

@property (weak, nonatomic) IBOutlet UIButton *startStopBtn;

@property (weak, nonatomic) IBOutlet UIButton *nameBtn;
- (IBAction)nameBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *uploadBtn;
- (IBAction)uploadBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *projectBtn;

@end