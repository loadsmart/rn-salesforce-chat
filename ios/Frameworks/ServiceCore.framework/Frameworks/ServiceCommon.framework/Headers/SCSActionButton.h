//
//  SCActionButton.h
//  ServiceSDK
//
//  Created by Michael Nachbaur on 8/14/15.
//  Copyright (c) 2015 Salesforce.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCSActionItem.h"

/**
 Default `SCSActionItem` instance that provides the circular button for the default experience.
 */
@interface SCSActionButton : UIButton<SCSActionItem>

/**
 The center point to show the badge view on the button, when used.
 */
@property (nonatomic, assign) CGPoint badgeCenterPoint UI_APPEARANCE_SELECTOR;

@end
