//
//  ISWViewController.h
//  Writer
//
//  Created by Mike Stowell on 11/4/14.
//  Copyright (c) 2014 iSENSE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import "Constants.h"
#import "API.h"
#import "DataManager.h"
#import "QueueUploaderView.h"
#import "CredentialManager.h"
#import "DLAVAlertViewController.h"
#import "Waffle.h"
#import "FieldCell.h"
#import "FieldData.h"
#import "GlobalColors.h"

#define USE_DEV false

@interface ISWViewController : UIViewController
    <UIAlertViewDelegate, UITextFieldDelegate, CredentialManagerDelegate, QueueUploaderDelegate,
    UITableViewDelegate, UITableViewDataSource, CLLocationManagerDelegate, UIPickerViewDelegate,
    UIPickerViewDataSource> {

    // iSENSE API, DataManager, and dev switch
    API *api;
    DataManager *dm;
    UILabel *devLbl;

    // Credentials
    CredentialManager *credentialMngr;
    DLAVAlertView *credentialMngrAlert;

    // Location Manager
    CLLocationManager *locationManager;

    // Visualization URL constructed after data is uploaded
    NSString *visURL;

    // Array to hold data for manual entry
    NSMutableArray *dataArr;

    // Dictionary of data to upload
    NSMutableDictionary *dataToUpload;

    // Current data source array for a restricted text field's picker view
    NSArray *pickerDataSource;

    // Reference to the active TextField, last clicked TextField, and current keyboard display
    // The active TextField is the TextField used to display the keyboard/picker, whereas the
    // last clicked TextField is always whatever was tapped last
    UITextField *activeTextField;
    UITextField *lastClickedTextField;
    bool isKeyboardDisplaying;

    // Toolbar with a "Done" button to be attached to all textfield keyboards
    UIToolbar *doneKeyboardView;

    // Amount of pixels the keyboard was shifted
    int keyboardShift;

    // Footer view for the table view
    UILabel *tableFooter;

    // UIView to display the splash screen and a boolean to track if it is displaying
    UIView *splashView;
    bool isSplashDisplaying;
}

// Queue Saver properties
@property (nonatomic, strong) DataSaver *dataSaver;
@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;

// UI properties
@property (weak, nonatomic) IBOutlet UIBarButtonItem *credentialBarBtn;
- (IBAction)credentialBarBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UIBarButtonItem *menuBarBtn;
- (IBAction)menuBarBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UILabel *dataSetNameLbl;
@property (weak, nonatomic) IBOutlet UITextField *dataSetNameTxt;

@property (weak, nonatomic) IBOutlet UIButton *projectBtn;

@property (weak, nonatomic) IBOutlet UIButton *saveRowBtn;
- (IBAction)saveRowBtnOnClick:(id)sender;
@property (weak, nonatomic) IBOutlet UIButton *saveDataSetBtn;
- (IBAction)saveDataSetBtnOnClick:(id)sender;

@property (weak, nonatomic) IBOutlet UITableView *contentView;

@property (weak, nonatomic) IBOutlet UIButton *uploadBtn;
- (IBAction)uploadBtnOnClick:(id)sender;

@end

