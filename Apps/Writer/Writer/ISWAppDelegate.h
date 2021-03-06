//
//  AppDelegate.h
//  Writer
//
//  Created by Mike Stowell on 11/4/14.
//  Copyright (c) 2014 iSENSE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QueueUploaderView.h"

@interface ISWAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

// DataSaver
@property (nonatomic, strong) IBOutlet DataSaver *dataSaver;

// Core Data
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

@end

