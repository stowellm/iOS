//
//  RestAPI.m
//  iSENSE_Data_Collector
//
//  Created by Jeremy Poulin on 11/6/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import "RestAPI.h"


@implementation RestAPI


- (id)initWithFrame:(CGRect)frame {
    
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code.
		login_key = -1;
    }
    return self;
}

- (BOOL) login:(NSString*)username:(NSString*)password {
	NSString *url = nil;
	url = @"method=login&username=";
	const char *temp;
	temp = [username UTF8String];
	username = [[NSString alloc] initWithUTF8String:temp];
	url = [[url stringByAppendingString:username] retain];
	temp = [password UTF8String];
	password = [[NSString alloc] initWithUTF8String:temp];
	url = [[url stringByAppendingString:@"&password="] retain];
	url = [[url stringByAppendingString:password] retain];
	
	if (url == nil) return FALSE;
	
	/*		String url = null;
		try {
			url = "method=login&username="
			+ URLEncoder.encode(username, "UTF-8") + "&password="
			+ URLEncoder.encode(password, "UTF-8");
		} catch (UnsupportedEncodingException e1) {
			e1.printStackTrace();
		}
		
		if (url == null)
			return false;
		
		if (isConnected()) {
			try {
				connection = "NONE";
				String data = makeRequest(url);
				
				// Parse JSON Result
				JSONObject o = new JSONObject(data);
				connection = o.getString("status");
				checkStatus(connection);
				if (connection.equals("600")) {
					Log.e(TAG, "Invalid username or password.");
					return false;
				}
				session_key = o.getJSONObject("data").getString("session");
				uid = o.getJSONObject("data").getInt("uid");
				
				if (isLoggedIn()) {
					this.username = username;
					return true;
				}
				
			} catch (MalformedURLException e) {
				e.printStackTrace();
				connection = "NONE";
				return false;
			} catch (IOException e) {
				e.printStackTrace();
				connection = "NONE";
				return false;
			} catch (Exception e) {
				e.printStackTrace();
				connection = "NONE";
				return false;
			}
			
			return true;
		}
		connection = "NONE";
		return false;
	}*/
	return TRUE;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code.
}
*/

- (void)dealloc {
    [super dealloc];
}


@end
