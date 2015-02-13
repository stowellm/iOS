//
// RPerson.m
// iSENSE_API
//
// Created by Michael Stowell on 8/21/13.
//
// (c) 2015
// University of Massachusetts
// All Rights Reserved
//

#import "RPerson.h"

@implementation RPerson

@synthesize person_id, name, url, timecreated, gravatar, hidden;

- (id) init {
    if (self = [super init]) {
        name = @"";
        url = @"";
        timecreated = @"";
        gravatar = @"";
    }
    return self;
}

-(NSString *)description {
    NSString *objString = [NSString stringWithFormat:@"RPerson: {\n\tperson_id: %@\n\tname: %@\n\turl: %@\n\ttimecreated: %@\n\tgravatar:= %@\n\thidden:= %@\n}", person_id, name, url, timecreated, gravatar, hidden];
    return objString;
}

@end
