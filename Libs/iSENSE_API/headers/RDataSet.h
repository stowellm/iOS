//
// RDataSet.h
// iSENSE_API
//
// Created by Michael Stowell on 8/21/13.
//
// (c) 2015
// University of Massachusetts
// All Rights Reserved
//

#import <Foundation/Foundation.h>

@interface RDataSet : NSObject {
    
}

@property (strong) NSNumber *ds_id;
@property (strong) NSNumber *project_id;
@property (strong) NSNumber *hidden;
@property (strong) NSString *name;
@property (strong) NSString *url;
@property (strong) NSString *timecreated;
@property (strong) NSNumber *fieldCount;
@property (strong) NSNumber *datapointCount;
@property (strong) NSDictionary *data;

@end