//
// DataManager.h
// iSENSE_API
//
// Created by Mike Stowell on 9/19/14.
//
// (c) 2015
// University of Massachusetts
// All Rights Reserved
//

#import <Foundation/Foundation.h>
#import "RProjectField.h"
#import "DataContainer.h"
#import "API.h"

@interface DataManager : NSObject {
    
    API *api;

    // the current project ID
    int projectID;
    
    // a list of the fields as they appear on iSENSE
    NSMutableArray *projectFields;
}

+ (DataManager *)getInstance;
- (void) retrieveProjectFields;

- (int) getProjectID;
- (void) setProjectID:(int)projID;

- (NSArray *) getProjectFields;
- (void) setProjectFields:(NSArray *)projFields;

- (NSArray *) getUserDefinedFields;
- (NSArray *) getRecognizedFields;
- (NSArray *) getProjectFieldIDs;

- (NSDictionary *) writeDataToJSONObject:(DataContainer *)dc;

// a statically available row-to-column major formatting of data
+ (NSDictionary *) convertDataToColumnMajor:(NSMutableArray *)data forProjectID:(int)projID;

// a statically available row-to-column major formatting of data that has been recorded.
// strictly for an arbitrary project (utilized by the DataSaver)
+ (NSDictionary *) convertArbitraryDataToColumnMajor:(NSArray *)data forProjectID:(int)projID andRecognizedFields:(NSArray *)recognizedFields;

@end
