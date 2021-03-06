//
//  API.h
//  iSENSE_API
//
//  Created by Jeremy Poulin on 8/21/13.
//  Copyright (c) 2013 iSENSE Project, UMass Lowell. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RProject.h"
#import "RTutorial.h"
#import "RPerson.h"
#import "RDataSet.h"
#import "RNews.h"
#import "RProjectField.h"
#import "Reachability.h"
#import "ISKeys.h"
#import <MobileCoreServices/UTType.h>
#import <sys/time.h>

// Version number of the API tested and passed on this version
// number of the production iSENSE website.
#define VERSION_MAJOR @"4"
#define VERSION_MINOR @"1"

// Base URLs for use by any caller
#define BASE_LIVE_URL @"http://isenseproject.org"
#define BASE_DEV_URL @"http://rsense-dev.cs.uml.edu"

typedef enum {
    CREATED_AT_DESC,
    CREATED_AT_ASC,
    UPDATED_AT_DESC,
    UPDATED_AT_ASC
} SortType;

typedef enum {
    PROJECT,
    DATA_SET
} TargetType;

@interface API : NSObject {
}

// instance initializer
+ (API *)getInstance;

// connectivity checker
+ (BOOL)hasConnectivity;

// dev and base URL
- (void)useDev:(BOOL)useDev;
- (BOOL)isUsingDev;
- (void)setBaseUrl:(NSURL *)newUrl;

// user
- (RPerson *)createSessionWithEmail:(NSString *)p_email andPassword:(NSString *)p_password;
- (void)deleteSession;
- (bool)loadCurrentUserFromPrefs;
- (RPerson *)getCurrentUser;

// contributor keys
- (bool) validateKey:(NSString *)conKey forProject:(int)projectID;
- (NSString *)getCurrentContributorKey;

// project and data set GET
- (RProject *)getProjectWithId:(int)projectId;
- (RDataSet *)getDataSetWithId:(int)dataSetId;
- (NSArray *)getProjectFieldsWithId:(int)projectId;
- (NSArray *)getDataSetsWithId:(int)projectId;
- (NSArray *)getProjectsAtPage:(int)page withPageLimit:(int)perPage withFilter:(SortType)descending andQuery:(NSString *)search;

// project create
- (int)createProjectWithName:(NSString *)name  andFields:(NSArray *)fields;

// data set upload and append
- (bool)appendDataSetDataWithId:(int)dataSetId  andData:(NSDictionary *)data;
- (bool)appendDataSetDataWithId:(int)dataSetId  andData:(NSDictionary *)data withContributorKey:(NSString *)conKey;
- (int)uploadDataToProject:(int)projectId withData:(NSDictionary *)dataToUpload andName:(NSString *)name;
- (int)uploadDataToProject:(int)projectId withData:(NSDictionary *)dataToUpload withContributorKey:(NSString *)conKey as:(NSString *)conName andName:(NSString *)name;

// media upload
- (int)uploadMediaToProject:(int)projectId withFile:(NSData *)mediaToUpload andName:(NSString *) name withTarget: (TargetType) ttype;
- (int)uploadMediaToProject:(int)projectId withFile:(NSData *)mediaToUpload andName:(NSString *) name withTarget: (TargetType) ttype withContributorKey:(NSString *)conKey as:(NSString *)conName;

// etc
- (NSString *)getVersion;
+ (NSString *)getTimeStamp;

@end
