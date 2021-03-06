//
//  CredentialManager.m
//  iSENSE_API
//
//  Created by Virinchi Balabhadrapatruni on 2/28/14.
//  Copyright (c) 2014 iSENSE Project, UMass Lowell. All rights reserved.
//

#import "CredentialManager.h"

@class DLAVAlertViewTheme;
@class DLAVAlertViewButtonTheme;

@interface CredentialManager ()

@end

@implementation CredentialManager

@synthesize loginoutButton, nameLabel, gravatarView,  api, loginalert, delegate;

- (void) loadView {

    self.view = [[UIView alloc] initWithFrame:CGRectMake(0.0, 0.0, 276, 102)];
    gravatarView = [[UIImageView alloc] initWithFrame:CGRectMake(5, 0, 102, 102)];

    nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(115, 20, 148, 21)];
    [nameLabel setBackgroundColor:[UIColor colorWithWhite:0.9 alpha:1.0]];
    nameLabel.textAlignment = NSTextAlignmentCenter;
    
    self.view.autoresizesSubviews = NO;
    
    api = [API getInstance];
    
    self.view.clipsToBounds = YES;
    
    [self.view addSubview:gravatarView];
    [self.view addSubview:nameLabel];

    loginoutButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [loginoutButton setFrame:CGRectMake(150, 54, 75, 44)];
    [loginoutButton addTarget:self action:@selector(loginLogout) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginoutButton];
    
    [self.view setBackgroundColor:[UIColor colorWithWhite:0.9 alpha:1.0]];
    
    DLAVAlertViewButtonTheme *theme = [[DLAVAlertViewButtonTheme alloc] initWithTextShadowColor:[UIColor blackColor] andTextShadowOpacity:0.0f andTextShadowRadius:0.0 andTextShadowOffset:CGSizeMake(1.0f, 1.0f)];
    [theme setBackgroundColor:[UIColor colorWithWhite:0.9 alpha:1.0]];
    
    
    [DLAVAlertView applyTheme:theme toButton:loginoutButton animated:NO];
    
    [self loadUserInfo];
}

- (CredentialManager *) initWithDelegate:(__weak id<CredentialManagerDelegate>) delegateObject {

    self = [self init];
    self.delegate = delegateObject;
    return self;
}

- (CGRect)frameForOrientation:(UIInterfaceOrientation)orientation {

	CGRect frame;
	
	if ((orientation == UIInterfaceOrientationLandscapeLeft) || (orientation == UIInterfaceOrientationLandscapeRight)) {
		CGRect bounds = [UIScreen mainScreen].bounds;
		frame = CGRectMake(bounds.origin.x, bounds.origin.y, bounds.size.height, bounds.size.width);
	} else {
		frame = [UIScreen mainScreen].bounds;
	}
	
	return frame;
}


- (void) loadUserInfo {
    
    NSBundle *isenseBundle = [NSBundle bundleWithURL:[[NSBundle mainBundle] URLForResource:@"iSENSE_API_Bundle" withExtension:@"bundle"]];
    
    if ([api getCurrentUser] == nil) {

        NSString *path = [isenseBundle pathForResource:@"default_user" ofType:@"png"];
        UIImage *img = [UIImage imageWithContentsOfFile:path];
        [gravatarView setImage:img];
        [nameLabel setText:@"Not Logged In"];
        [loginoutButton setTitle:@"Login" forState:UIControlStateNormal];

        return;
    }
        
    [gravatarView setImage:[[api getCurrentUser] gravatarImage]];
    [nameLabel setText:[[api getCurrentUser] name]];
    [loginoutButton setTitle:@"Logout" forState:UIControlStateNormal];
}

- (void)loginLogout {
    
    if ([api getCurrentUser] == nil) {
        [self.delegate didPressLogin:self];
        return;
    }

    [api deleteSession];
    [self loadUserInfo];
}

@end
