//
//  SCSActionItem.h
//  ServiceCommon
//
//  Created by Michael Nachbaur on 2/29/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Protocol defining the type of views capable of being added to an `SCSActionItemContainer` object.
 
 @see `SCSActionManager`
 */
@protocol SCSActionItem <NSObject>

@optional

/**
 Text label to show on the button, or `nil` to hide the badge view.
 */
@property (nullable, nonatomic, copy) NSString *badgeText;

@end

NS_ASSUME_NONNULL_END
