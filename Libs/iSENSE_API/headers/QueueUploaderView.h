//
// QueueUploaderView.h
// iSENSE_API
//
// Created by Jeremy Poulin on 6/26/13.
// Modified by Mike Stowell
//
// (c) 2015
// University of Massachusetts
// All Rights Reserved
//

#import <UIKit/UIKit.h>

#import "DataSaver.h"
#import "API.h"
#import "ProjectBrowserViewController.h"
#import "Waffle.h"
#import "ISKeys.h"

#import "QueueConstants.h"
#import "QueueCell.h"
#import "QueueUploadStatus.h"

#import "DataManager.h"
#import "FieldMatchingViewController.h"

#import <AVFoundation/AVFoundation.h>
#import <AVFoundation/AVCaptureDevice.h>

// Parent name constants: add a new one for each app
#define PARENT_AUTOMATIC    @"Automatic"
#define PARENT_MANUAL       @"Manual"
#define PARENT_DATA_WALK    @"DataWalk"
#define PARENT_CAR_RAMP     @"CarRampPhysics"
#define PARENT_CANOBIE      @"CanobiePhysics"
#define PARENT_MOTION       @"ISMotion"
#define PARENT_WRITER       @"ISWriter"

@class QueueUploaderView;
@protocol QueueUploaderDelegate <NSObject>

@required
- (void) didFinishUploadingDataWithStatus:(QueueUploadStatus *)status;

@end

@interface QueueUploaderView : UIViewController <UIGestureRecognizerDelegate, UIActionSheetDelegate, UITextFieldDelegate, ProjectBrowserDelegate> {

    int projID;
    NSMutableArray *lastSelectedFields;
    
    // bundle for resource files in the iSENSE_API_Bundle
    NSBundle *isenseBundle;
}

- (IBAction) upload:(id)sender;

- (id) initWithParentName:(NSString *)parentName andDelegate:(id <QueueUploaderDelegate>)delegateObj;

@property (nonatomic, weak) id <QueueUploaderDelegate> delegate;

@property (nonatomic, assign) API *api;
@property (nonatomic, copy)   NSString *parent;
@property (nonatomic, strong) DataSaver *dataSaver;
@property (nonatomic, assign) IBOutlet UITableView *mTableView;
@property (assign)            int currentIndex;
@property (nonatomic, strong) NSIndexPath *lastClickedCellIndex;
@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong) NSMutableDictionary *limitedTempQueue;

@end
